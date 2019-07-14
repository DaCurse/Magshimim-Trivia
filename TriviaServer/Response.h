#pragma once

#include "stdafx.h"

typedef enum ResponseID {
	REQUEST_ERROR = 201,
	LOGIN_SUCCESS = 202,
	SIGNUP_SUCCESS = 203,
	LOGOUT_SUCCESS = 204,
	GOT_ROOMS = 205,
	GOT_PLAYERS = 206,
	GOT_HIGHSCORE = 207,
	JOINED_ROOM = 208,
	CREATED_ROOM = 209
} ResponseID;

typedef struct LoginResponse {
	ResponseID status;
} LoginResponse;

typedef struct SignupResponse {
	ResponseID status;
} SignupResponse;

typedef struct LogoutResponse {
	ResponseID status;
};

typedef struct GetRoomsResponse {
	ResponseID status;
	// vec
};

typedef struct GetPlayersInRoomResponse {
	ResponseID status;
	std::vector<std::string> rooms;
};

typedef struct HighscoreResponse {
	ResponseID status;
	// vec
};

typedef struct JoinRoomResponse {
	ResponseID status;
};

typedef struct CreateRoomResponse {
	ResponseID status;
};

typedef struct ErrorResponse {
	std::string message;
} ErrorResponse;
