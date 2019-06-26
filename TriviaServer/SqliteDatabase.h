#pragma once

#include <exception>
#include <sstream>
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

		void sqlInsert(std::string table, std::vector<std::string> columns, std::vector<std::string> values); // Values need to get converted to a string beforehand
};

