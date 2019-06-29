#include "Communicator.h"

Communicator::Communicator()
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
	}
	catch (...) {}
}

void Communicator::bindAndListen()
{
	SOCKADDR_IN sa;
	sa.sin_port = Config::getConfig()["port"];
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
		SOCKET clientSock = ::accept(m_sock, NULL, NULL);
		if(clientSock == INVALID_SOCKET)
		{ 
			throw std::runtime_error("Invalid connection");
		}

		startThreadForNewClient(clientSock);

	}

}

void Communicator::handleRequests()
{
}

void Communicator::startThreadForNewClient(SOCKET clientSock)
{
	//std::thread clientThread(clientHandler, *this, clientSock);
	//clientThread.detach();
}

void clientHandler(Communicator& comm, SOCKET client)
{
	std::unique_lock<std::mutex> sockLocker(comm.m_sockMutex);
	char codeBuff[1];
	recv(client, codeBuff, 1, 0);

	sockLocker.unlock();
}
