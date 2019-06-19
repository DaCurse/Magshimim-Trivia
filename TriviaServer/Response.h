#pragma once

typedef enum STATUS_CODE {
	ERROR = 101,
	LOGIN_SUCCESS = 102,
	SIGNUP_SUCCESS = 103
} STATUS_CODE;

typedef struct LoginResponse {
	STATUS_CODE status;
} LoginResponse;

typedef struct SignupResponse {
	STATUS_CODE status;
} SignupResponse;

typedef struct ErrorResponse {
	std::string message;
} ErrorResponse;
