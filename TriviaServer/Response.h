#pragma once
#include <iostream>

typedef enum STATUS_CODE {

} STATUS_CODE;

typedef struct LoginResponse {
	unsigned int status;
} LoginResponse;

typedef struct SignupResponse {
	unsigned int status;
} SignupResponse;

typedef struct ErrorResponse {
	std::string message;
} ErrorResponse;
