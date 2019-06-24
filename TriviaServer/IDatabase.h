#pragma once

#include <list>
#include <map>
#include "DatabaseModels.h"
#include "LoggedUser.h"
#include "sqlite3.h"

class IDatabase
{
	public:
		IDatabase();
		virtual ~IDatabase();
		
		virtual const std::map<LoggedUser, int> getHighscores() = 0;
		virtual const bool doesUserExist(std::string username) = 0;
		virtual const std::list<Question> getQuestions(int id) = 0;
		virtual const LoggedUser loginUser(std::string username, std::string password) = 0;
		virtual const void signupUser(std::string username, std::string password, std::string email) = 0;

};

