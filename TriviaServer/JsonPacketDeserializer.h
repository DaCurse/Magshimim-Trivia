#pragma once

#include "stdafx.h"
#include "Request.h"

class JsonPacketDeserializer
{
	public:
		static LoginRequest deserializeLoginRequest(char* buffer, int len);
		static SignupRequest deserializeSignupRequest(char* buffer, int len);
		static GetPlayersInRoomRequest deserializeGetPlayersInRoomRequest(char* buffer, int len);
		static JoinRoomRequest deserializeJoinRoomRequest(char* buffer, int len);
		static CreateRoomRequest deserializeCreateRoomRequest(char* buffer, int len);


	private:
		JsonPacketDeserializer();

};

