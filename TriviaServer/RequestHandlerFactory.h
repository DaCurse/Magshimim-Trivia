#pragma once

#include "LoginManager.h"
#include "LoginRequestHandler.h"

class RequestHandlerFactory
{
	public:
		RequestHandlerFactory();
		~RequestHandlerFactory();

		LoginRequestHandler createLoginRequestHandler();

	private:
		LoginManager m_loginManager;
};

