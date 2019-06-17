#pragma once
#include <string>

class LoggedUser
{
	public:
		LoggedUser();
		~LoggedUser();
		
		std::string getUsername();

	private:
		std::string m_username;
};

