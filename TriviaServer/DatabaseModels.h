#pragma once

#include "stdafx.h"

typedef struct Question {
	int question_id;
	std::string question;
	std::string correct_ans;
	std::string ans2;
	std::string ans3;
	std::string ans4;
} Question;

typedef struct User {
	std::string username;
	std::string email;
	std::string password;
} User;