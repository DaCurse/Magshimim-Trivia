#pragma once

#include "stdafx.h"
#include "IDatabase.h"
#include "Communicator.h"
#include "RequestHandlerFactory.h"

class Server
{
	public:
		Server(IDatabase* database);
		~Server();

		void run();

	private:
		IDatabase* m_database;
		Communicator m_communicator;
		RequestHandlerFactory m_handlerFactory;
};

