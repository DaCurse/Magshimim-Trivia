#pragma once

#include <exception>
#include <sstream>
#include <map>
#include <iostream>
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
		void sqlFetch(std::string table, std::vector<std::string> columns = { "*" }, std::string whereCondition = "", std::string orderBy = "", std::string groupBy = "", int limit = 0, std::string extra = "");

	private:
		sqlite3* m_db;
		std::vector<std::map<std::string, std::string>> m_fetchTmp;

		void sqlInsert(std::string table, std::vector<std::string> columns, std::vector<std::string> values); // Values need to get converted to a string beforehand
		// void sqlFetch(std::string table, std::vector<std::string> columns = { "*" }, std::string whereCondition = "", std::string orderBy = "", std::string groupBy = "", int limit = 0, std::string extra = "");

		friend int(*sqliteCallback(SqliteDatabase &db))(void * data, int argc, char ** argv, char ** colName)

};

