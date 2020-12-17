#pragma once

#include "stdafx.h"
#include "LoginManager.h"
#include "RoomManager.h"
#include "HighscoreTable.h"

class LoginRequestHandler;
class MenuRequestHandler;

class RequestHandlerFactory
{
	public:
		RequestHandlerFactory(IDatabase* database);
		~RequestHandlerFactory();

		LoginRequestHandler* createLoginRequestHandler();
		MenuRequestHandler* createMenuRequestHandler(std::string username);

	private:
		LoginManager m_loginManager;
		RoomManager m_roomManager;
		HighscoreTable m_highscoreTable;
};

