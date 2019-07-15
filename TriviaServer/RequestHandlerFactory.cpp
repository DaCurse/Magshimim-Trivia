#include "RequestHandlerFactory.h"
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* database) : m_loginManager(database), m_highscoreTable(database)
{
}

RequestHandlerFactory::~RequestHandlerFactory()
{
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	return new LoginRequestHandler(m_loginManager, this);
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(std::string username)
{
	return new MenuRequestHandler(username, m_roomManager, m_highscoreTable, this);
}

LoginManager RequestHandlerFactory::getLoginManager()
{
	return m_loginManager;
}
