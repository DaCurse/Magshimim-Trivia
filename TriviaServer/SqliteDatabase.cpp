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

	std::stringstream statementStream;
	statementStream << "INSERT INTO " << table << " ";

	std::ostringstream columnStringStream, valueStringStream;
	std::copy(columns.begin(), columns.end(), std::ostream_iterator<std::string>(columnStringStream, ","));
	std::copy(values.begin(), values.end(), std::ostream_iterator<std::string>(valueStringStream, "','"));
	std::string columnString = columnStringStream.str(), valueString = valueStringStream.str();
	statementStream << columnString.substr(0, columnString.size() - 1) << ") VALUES('" << valueString.substr(0, valueString.size() - 2) << ");";

	char* errMessage = nullptr;
	int res = sqlite3_exec(m_db, statementStream.str().c_str(), nullptr, nullptr, &errMessage);

	if (res != SQLITE_OK)
	{
		throw std::runtime_error("Failed to insert into database: '" + std::string(errMessage) + "'");
	}

}

void SqliteDatabase::sqlFetch(std::string table, std::vector<std::string> columns, std::string whereCondition, std::string orderBy, std::string groupBy, int limit, std::string extra)
{
	std::stringstream statementStream;
	statementStream << "SELECT ";

	std::ostringstream columnStringStream;
	std::copy(columns.begin(), columns.end(), std::ostream_iterator<std::string>(columnStringStream, ","));
	std::string columnString = columnStringStream.str();
	statementStream << columnString.substr(0, columnString.size() - 1) << " FROM " << table;

	if (!whereCondition.empty())
	{
		statementStream << " WHERE " << whereCondition;
	}

	if (!orderBy.empty())
	{
		statementStream << " ORDER BY " << orderBy;
	}

	if (!groupBy.empty())
	{
		statementStream << " GROUP BY " << groupBy;
	}

	if (limit != 0)
	{
		statementStream << " LIMIT " << limit;
	}

	if (!extra.empty())
	{
		statementStream << " " << extra;
	}

	statementStream << ";";	

	char* errMessage = nullptr;

	std::function<int(void * data, int argc, char ** argv, char ** colName)> callback = [&](void * data, int argc, char ** argv, char ** colName) -> int {
		
	};

	int res = sqlite3_exec(m_db, statementStream.str().c_str(), callback, nullptr, &errMessage);

	if (res != SQLITE_OK)
	{
		throw std::runtime_error("Failed to fetch from database: '" + std::string(errMessage) + "'");
	}
}

int(*sqliteCallback(SqliteDatabase &db))(void * data, int argc, char ** argv, char ** colName)
{
	return [&db](void * data, int argc, char ** argv, char ** colName) -> int
	{
		std::map<std::string, std::string> row;
		for (int i = 0; i < argc; i++)
		{
			row.insert(colName[i], argv[i]);
		}
		db.m_fetchTmp.push_back(row);
		return 0;
	};
}
