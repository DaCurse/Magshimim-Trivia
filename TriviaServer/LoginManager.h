#pragma once

#include <vector>
#include "IDatabase.h"
#include "DatabaseModels.h"

class LoginManager
{
	public:
		LoginManager();
		~LoginManager();

		void signup(std::string email, std::string username, std::string password);
		void login(std::string email, std::string password);
		void logout();


	private:
		IDatabase& m_database;
		std::vector<LoggedUser> m_loggedUsers;

};

