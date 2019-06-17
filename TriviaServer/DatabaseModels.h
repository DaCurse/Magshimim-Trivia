#pragma once

#include <string>

typedef struct Question {
	int question_id;
	std::string question;
	std::string correct_ans;
	std::string ans2;
	std::string ans3;
	std::string ans4;
} Question;

typedef struct LoggedUser {
	std::string username;
	std::string email;
	std::string password;
} LoggedUser;