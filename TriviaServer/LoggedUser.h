#pragma once

#include <string>

class LoggedUser
{
	public:
		LoggedUser(std::string username);
		~LoggedUser();

		std::string getUsername();

	private:
		std::string m_username;
};

