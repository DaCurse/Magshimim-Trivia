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
