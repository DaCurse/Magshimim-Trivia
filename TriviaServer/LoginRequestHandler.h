#pragma once

#include "stdafx.h"
#include "IRequestHandler.h"
#include "Request.h"
#include "Response.h"
#include "JsonPacketSerializer.h"
#include "LoginManager.h"

class RequestHandlerFactory;

class LoginRequestHandler : public IRequestHandler
{
	public:
		LoginRequestHandler(LoginManager manager, RequestHandlerFactory* factory);
		~LoginRequestHandler();

		virtual const bool isRequestRelevant(Request r);
		virtual const RequestResult handleRequest(Request r);
		
	private:
		LoginManager m_loginManager;
		RequestHandlerFactory* m_handlerFactory;

		RequestResult signup(Request r);
		RequestResult login(Request r);

};