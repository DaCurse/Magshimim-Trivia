#include "LoginManager.h"

std::vector<LoggedUser> LoginManager::loggedUsers = {};

LoginManager::LoginManager(IDatabase* database) : m_database(database)
{
}


LoginManager::~LoginManager()
{
}

void LoginManager::signup(std::string email, std::string username, std::string password)
{
	if (username.length() < 3 || username.length() > 16)
	{
		throw std::runtime_error("Username length must be 3-16 characters long");
	}
	if(password.length() < 8)
	{
		throw std::runtime_error("Password must be at least 8 characters long");
	}

	std::regex emailReg("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	if (!std::regex_match(email, emailReg))
	{
		throw std::runtime_error("Email is invalid");
	}

	m_database->signupUser(username, password, email);

}

void LoginManager::login(std::string username, std::string password)
{
	for(auto it = loggedUsers.begin(); it != loggedUsers.end(); ++it)
	{
		if (it->getUsername() == username)
		{
			throw std::runtime_error("User already logged in");
		}
	}
	loggedUsers.push_back(m_database->loginUser(username, password));
}

void LoginManager::logout(std::string username)
{
	loggedUsers.erase(std::remove(loggedUsers.begin(), loggedUsers.end(), username), loggedUsers.end());
}
