#pragma once

#include "stdafx.h"
#include "Room.h"
#include "DatabaseModels.h"

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
} LogoutResponse;

typedef struct GetRoomsResponse {
	ResponseID status;
	std::vector<RoomData> rooms;
} GetRoomsResponse;

typedef struct GetPlayersInRoomResponse {
	ResponseID status;
	std::vector<std::string> players;
} GetPlayersInRoomResponse;

typedef struct HighscoreResponse {
	ResponseID status;
	std::vector<Highscore> highscores;
} HighscoreResponse;

typedef struct JoinRoomResponse {
	ResponseID status;
} JoinRoomResponse;

typedef struct CreateRoomResponse {
	ResponseID status;
} CreateRoomResponse;

typedef struct ErrorResponse {
	std::string message;
} ErrorResponse;
