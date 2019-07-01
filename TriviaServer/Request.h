#pragma once

#include <string>
#include <vector>
#include <ctime>

class IRequestHandler;

typedef enum RequestID {
	LOGIN_REQUEST = 101,
	SIGNUP_REQUEST = 102,
} RequestID;

typedef struct LoginRequest {
	std::string username;
	std::string password;
} LoginRequest;

typedef struct SignupRequest {
	std::string username;
	std::string password;
	std::string email;
} SignupRequest;

typedef struct Request {
	int id;
	time_t rt;
	std::vector<char> buffer;
} Request;

typedef struct RequestResult {
	std::vector<char> response;
	IRequestHandler* newHandler;
} RequestResult;