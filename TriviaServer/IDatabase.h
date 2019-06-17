#pragma once
#include <list>
#include <map>
#include "LoggedUser.h"
#include "Question.h"

class IDatabase
{
	public:
		IDatabase();
		virtual ~IDatabase();
		
		virtual const std::map<LoggedUser, int> getHighscores() = 0;
		virtual const bool doesUserExist(std::string username) = 0;
		virtual const std::list<Question> getQuestions(int id) = 0;
};

