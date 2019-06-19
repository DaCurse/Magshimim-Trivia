#pragma once

#include "IDatabase.h"
#include "Communicator.h"
#include "RequestHandlerFactory.h"

class Server
{
	public:
		Server();
		~Server();

		void run();

	private:
		IDatabase* m_database;
		Communicator m_communicator;
		RequestHandlerFactory m_handlerFactory;
};

