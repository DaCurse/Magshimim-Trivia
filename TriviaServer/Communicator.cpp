#include "Communicator.h"

Communicator::Communicator(RequestHandlerFactory factory) : m_factory(factory)
{
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		throw std::runtime_error("Failed to startup WSA");
	}

	m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_sock == INVALID_SOCKET)
	{
		throw std::runtime_error("Failed to create socket");
	}
}


Communicator::~Communicator()
{
	try
	{
		WSACleanup();
		closesocket(m_sock);

		std::lock_guard<std::mutex> locker(m_clientsMu);
		for (auto it = m_clients.begin(); it != m_clients.end(); ++it)
		{
			delete[] it->second;
		}

	}
	catch (...) {}
}

void Communicator::bindAndListen()
{
	SOCKADDR_IN sa;
	sa.sin_port = htons(Config::getConfig()["port"]);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = INADDR_ANY;

	if (bind(m_sock, (const SOCKADDR*) & sa, sizeof(sa)) == SOCKET_ERROR)
	{
		throw std::runtime_error("Failed to bind socket");
	}

	if (listen(m_sock, SOMAXCONN) == SOCKET_ERROR)
	{
		throw std::runtime_error("Failed to start listening");
	}

	
	while (true)
	{
		SOCKET clientSock = accept(m_sock, NULL, NULL);
		
		if(clientSock == INVALID_SOCKET)
		{ 
			throw std::runtime_error("Invalid connection");
		}

		std::cout << "Client connected" << std::endl;

		{
			std::lock_guard<std::mutex> locker(m_clientsMu);
			m_clients[clientSock] = (IRequestHandler*)m_factory.createLoginRequestHandler();
		}
		startThreadForNewClient(clientSock);

	}

}

void Communicator::clientHandler(SOCKET client)
{
	try
	{
		while (true)
		{
			char codeBuff[1];
			if (recv(client, codeBuff, 1, 0) == SOCKET_ERROR)
			{
				break;
			}
			int code = static_cast<int>(static_cast<unsigned char>(codeBuff[0]));

			char lengthBuff[4];
			recv(client, lengthBuff, 4, 0);
			int dataLength = lengthBuff[3];
			for (int i = 2; i >= 0; i--)
			{
				dataLength |= lengthBuff[i] << ((3 - i) * 8);
			}

			char* dataBuff = new char[dataLength];
			recv(client, dataBuff, dataLength, 0);
			dataBuff[dataLength - 1] = 0;
			std::vector<char> dataVec(dataBuff, dataBuff + dataLength);
			delete[] dataBuff;

			Request r = {
				code,
				std::time(nullptr),
				dataVec
			};

			IRequestHandler* handler = nullptr;
			{
				std::lock_guard<std::mutex> locker(m_clientsMu);
				handler = m_clients.find(client)->second;
				if (handler == nullptr) break;
			}

			if (handler->isRequestRelevant(r))
			{
				RequestResult res = handler->handleRequest(r);
				{
					std::lock_guard<std::mutex> locker(m_clientsMu);
					delete[] m_clients.find(client)->second;
					m_clients.find(client)->second = res.newHandler;
				}
				send(client, res.response.data(), res.response.size(), 0);
			}
			else
			{
				ErrorResponse res = { "Invalid request type" };
				std::vector<char> packet = JsonPacketSerializer::serializeResponse(res);
				send(client, packet.data(), packet.size(), 0);
			}
		}
	}
	catch (...)
	{
		closesocket(client);
	}
	closesocket(client);
}

void Communicator::startThreadForNewClient(SOCKET clientSock)
{
	std::thread clientThread(&Communicator::clientHandler, this, clientSock);	
	clientThread.detach();
}
