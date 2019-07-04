#include "LoggedUser.h"



LoggedUser::LoggedUser(std::string username) : m_username(username)
{
}


LoggedUser::~LoggedUser()
{
}

std::string LoggedUser::getUsername()
{
	return m_username;
}

bool LoggedUser::operator==(std::string username)
{
	return m_username == username;
}
