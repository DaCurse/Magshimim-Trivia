#pragma once

#include "stdafx.h"

class LoggedUser
{
	public:
		LoggedUser(std::string username);
		~LoggedUser();

		std::string getUsername();
		bool operator ==(std::string username);

	private:
		std::string m_username;
};

