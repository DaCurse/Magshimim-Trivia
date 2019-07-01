#include "LoginRequestHandler.h"
#include "RequestHandlerFactory.h"


LoginRequestHandler::LoginRequestHandler()
{
}


LoginRequestHandler::~LoginRequestHandler()
{
}

const bool LoginRequestHandler::isRequestRelevant(Request r)
{
	return r.id >= LOGIN_REQUEST && r.id <= SIGNUP_REQUEST;
}

const RequestResult LoginRequestHandler::handleRequest(Request r)
{
	return (RequestResult) {

	};
}

RequestResult LoginRequestHandler::signup(Request r)
{
	return RequestResult();
}

RequestResult LoginRequestHandler::login(Request r)
{
	return RequestResult();
}
