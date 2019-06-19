#pragma once

typedef enum STATUS_CODE {
	ERROR = 101,
	LOGIN_SUCCESS = 102,
	SIGNUP_SUCCESS = 103
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
