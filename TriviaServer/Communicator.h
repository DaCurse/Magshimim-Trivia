#pragma once

#include "stdafx.h"
#include "RequestHandlerFactory.h"
#include "IRequestHandler.h"
#include "Response.h"
#include "JsonPacketSerializer.h"
#include "Config.h"

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

