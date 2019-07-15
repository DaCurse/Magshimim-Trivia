#pragma once

#include "stdafx.h"

class LoggedUser
{
	public:
		LoggedUser(std::string username);
		~LoggedUser();

		std::string getUsername();
		bool operator ==(std::string username);
		bool operator ==(LoggedUser other);

	private:
		std::string m_username;
};

