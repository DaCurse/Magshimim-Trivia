#pragma once

#include "stdafx.h"
#include "IDatabase.h"
#include "LoggedUser.h"

class LoginManager
{
	public:
		LoginManager(IDatabase* database);
		~LoginManager();

		void signup(std::string email, std::string username, std::string password);
		void login(std::string username, std::string password);
		void logout(std::string username);

	private:
		IDatabase* m_database;
		static std::vector<LoggedUser> loggedUsers;

};

