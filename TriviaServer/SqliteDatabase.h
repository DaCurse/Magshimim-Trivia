#pragma once

#include <exception>
#include "IDatabase.h"
#include "Config.h"

class SqliteDatabase : public IDatabase
{
	public:
		SqliteDatabase();
		virtual ~SqliteDatabase();

		virtual const std::map<LoggedUser, int> getHighscores();
		virtual const bool doesUserExist(std::string username);
		virtual const std::list<Question> getQuestions(int id);
		virtual const LoggedUser loginUser(std::string username, std::string password);
		virtual const void signupUser(std::string username, std::string password, std::string email);

	private:
		sqlite3* m_db;
};

