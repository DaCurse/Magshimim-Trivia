#pragma once

typedef enum ResponseID {
	ERROR = 201,
	LOGIN_SUCCESS = 202,
	SIGNUP_SUCCESS = 203
} ResponseID;

typedef struct LoginResponse {
	ResponseID status;
} LoginResponse;

typedef struct SignupResponse {
	ResponseID status;
} SignupResponse;

typedef struct ErrorResponse {
	std::string message;
} ErrorResponse;
