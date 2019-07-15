#pragma once

#include "stdafx.h"

class IRequestHandler;

typedef enum RequestID {
	LOGIN_REQUEST = 101,
	SIGNUP_REQUEST = 102,
	GET_PLAYERS_REQUEST = 103,
	JOIN_ROOM_REQUEST = 104,
	CREATE_ROOM_REQUEST = 105
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

typedef struct GetPlayersInRoomRequest {
	unsigned int roomId;
} GetPlayersInRoomRequest;

typedef struct JoinRoomRequest {
	unsigned int roomId;
} JoinRoomRequest;

typedef struct CreateRoomRequest {
	std::string roomName;
	unsigned int maxUsers;
	unsigned int questionCount;
	unsigned int answerTimeout;
} CreateRoomRequest;

typedef struct Request {
	int id;
	time_t rt;
	std::vector<char> buffer;
} Request;

typedef struct RequestResult {
	std::vector<char> response;
	IRequestHandler* newHandler;
} RequestResult;