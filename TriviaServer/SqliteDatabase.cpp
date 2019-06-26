#include "SqliteDatabase.h"

SqliteDatabase::SqliteDatabase()
{
	std::string dbFile = Config::getConfig()["db_path"];
	int res = sqlite3_open(dbFile.c_str(), &m_db);

	if (res != SQLITE_OK)
	{
		m_db = nullptr;
		throw std::runtime_error("Failed to open database");
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
	sqlInsert("users", { "username", "password", "email" }, { username, password, email });
}

void SqliteDatabase::sqlInsert(std::string table, std::vector<std::string> columns, std::vector<std::string> values)
{
	std::ostringstream columnStringStream, valueStringStream;
	std::copy(columns.begin(), columns.end(), std::ostream_iterator<std::string>(columnStringStream, ","));
	std::copy(values.begin(), values.end(), std::ostream_iterator<std::string>(valueStringStream, "','"));
	std::string columnString = columnStringStream.str(), valueString = valueStringStream.str();

	std::string statement = "INSERT INTO users (" + columnString.substr(0, columnString.size() - 1) + ") VALUES('" + valueString.substr(0, valueString.size() - 2) + ");";

	char* errMessage = nullptr;
	int res = sqlite3_exec(m_db, statement.c_str(), nullptr, nullptr, &errMessage);

	if (res != SQLITE_OK)
	{
		throw std::runtime_error("Failed to insert into database: '" + std::string(errMessage) + "'");
	}

}
