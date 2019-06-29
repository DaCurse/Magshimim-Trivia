#include "SqliteDatabase.h"

std::vector<std::map<std::string, std::string>> SqliteDatabase::fetchTmp = {};

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
	return sqlFetch("users", { "*" }, "username = '" + username + "'").size() > 0;
}

const std::list<Question> SqliteDatabase::getQuestions(int id)
{
	std::vector<std::map<std::string, std::string>> questionsVector = sqlFetch("questions", { "*" }, "game_id = " + id);
	std::list<Question> questions;

	for (auto it = questionsVector.begin(); it != questionsVector.end(); ++it)
	{
		questions.push_back({
			std::stoi(it->find("question_id")->second),
			it->find("question")->second,
			it->find("correct_ans")->second,
			it->find("ans2")->second,
			it->find("ans3")->second,
			it->find("ans4")->second,
		});
	}

	return questions;

}

const LoggedUser SqliteDatabase::loginUser(std::string username, std::string password)
{
	std::vector <std::map<std::string, std::string>> user = sqlFetch("users", { "username" }, "username = '" + username + "' AND password = '" + password + "'");
	if (user.size() < 1)
	{
		throw std::runtime_error("Failed to log in user: invalid password or username");
	}
	return LoggedUser(user[0].begin()->second);
}

const void SqliteDatabase::signupUser(std::string username, std::string password, std::string email)
{
	if (doesUserExist(username))
	{
		throw std::runtime_error("Failed to sign up user: Username already exists");
	}
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

std::vector<std::map<std::string, std::string>> SqliteDatabase::sqlFetch(std::string table, std::vector<std::string> columns, std::string whereCondition, std::string orderBy, std::string groupBy, int limit, std::string extra)
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
	
	int res = sqlite3_exec(m_db, statementStream.str().c_str(), sqliteCallback, nullptr, &errMessage);

	if (res != SQLITE_OK)
	{
		throw std::runtime_error("Failed to fetch from database: '" + std::string(errMessage) + "'");
	}

	std::vector<std::map<std::string, std::string>> rows(SqliteDatabase::fetchTmp);
	SqliteDatabase::fetchTmp.clear();

	return rows;
}

int SqliteDatabase::sqliteCallback(void * data, int argc, char ** argv, char ** colName)
{
	std::map<std::string, std::string> row;
	for (int i = 0; i < argc; i++)
	{
		row.insert(std::make_pair(colName[i], argv[i]));
	}
	SqliteDatabase::fetchTmp.push_back(row);
	return 0;
}
