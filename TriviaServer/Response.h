#pragma once

typedef enum STATUS_CODE {
	ERROR = 201,
	LOGIN_SUCCESS = 202,
	SIGNUP_SUCCESS = 203
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
