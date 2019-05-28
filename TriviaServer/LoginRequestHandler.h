#pragma once
#include "IRequestHandler.h"
#include "Request.h"

class LoginRequestHandler : IRequestHandler
{
	public:
		LoginRequestHandler();
		~LoginRequestHandler();

		virtual const bool isRequestRelevant(Request r);
		virtual const RequestResult handleRequest(Request r);
		
	private:
		// m_loginManager;
		// m_handlerFactory;

		RequestResult signup(Request r);
		RequestResult login(Request r);

};

