#pragma once

#include <winsock2.h>
#include <map>
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class Communicator
{
	public:
		Communicator();
		~Communicator();

		void bindAndListen();
		void handleRequests();

	private:

		std::map<SOCKET, IRequestHandler*> m_clients;
		RequestHandlerFactory m_factory;

		void startThreadForNewClient();

};

