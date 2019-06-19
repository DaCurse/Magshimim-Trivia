#include "RequestHandlerFactory.h"
#include "LoginRequestHandler.h"


RequestHandlerFactory::RequestHandlerFactory()
{
}


RequestHandlerFactory::~RequestHandlerFactory()
{
}

LoginRequestHandler RequestHandlerFactory::createLoginRequestHandler()
{
	return LoginRequestHandler();
}
