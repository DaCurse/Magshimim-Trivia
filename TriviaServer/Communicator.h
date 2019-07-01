#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <map>
#include <thread>
#include <mutex>
#include <stdexcept>
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
#include "Config.h"

#pragma comment(lib, "ws2_32.lib")

class Communicator
{
	public:
		Communicator();
		~Communicator();

		void bindAndListen();
		void handleRequests();

	private:
		SOCKET m_sock;
		std::map<SOCKET, IRequestHandler*> m_clients;
		RequestHandlerFactory m_factory;
		std::mutex m_clientsMu;

		void clientHandler(SOCKET client);
		void startThreadForNewClient(SOCKET clientSock);

};

