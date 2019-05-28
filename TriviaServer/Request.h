#pragma once
#include <iostream>
#include <vector>
#include <ctime>

typedef enum RequestID {

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
	RequestID id;
	time_t rt;
	std::vector<char> buffer;
} Request;

typedef struct RequestResult {
	std::vector<char> response;
	IRequestHandler* newHandler;
} RequestResult;