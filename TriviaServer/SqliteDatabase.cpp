#include "SqliteDatabase.h"



SqliteDatabase::SqliteDatabase()
{
	std::string dbFile = Config::getConfig()["db_path"];
	int res = sqlite3_open(dbFile.c_str(), &m_db);

	if (res != SQLITE_OK)
	{
		m_db = nullptr;
		throw std::exception("Failed to open database");
	}

}

SqliteDatabase::~SqliteDatabase()
{
	sqlite3_close(m_db);
	m_db = nullptr;
}

const std::map<LoggedUser, int> SqliteDatabase::getHighscores()
{
	return std::map<LoggedUser, int>();
}

const bool SqliteDatabase::doesUserExist(std::string username)
{
	return false;
}

const std::list<Question> SqliteDatabase::getQuestions(int id)
{
	return std::list<Question>();
}

const LoggedUser SqliteDatabase::loginUser(std::string username, std::string password)
{
	return LoggedUser();
}

const void SqliteDatabase::signupUser(std::string username, std::string password, std::string email)
{
	return void();
}
