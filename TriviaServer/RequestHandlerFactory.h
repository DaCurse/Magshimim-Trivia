#pragma once

#include "stdafx.h"
#include "LoginManager.h"

class LoginRequestHandler;

class RequestHandlerFactory
{
	public:
		RequestHandlerFactory();
		~RequestHandlerFactory();

		LoginRequestHandler* createLoginRequestHandler();

	private:
		LoginManager m_loginManager;
};

