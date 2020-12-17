#pragma once

#include "stdafx.h"
#include "Response.h"

class JsonPacketSerializer
{
	public:
		static std::vector<char> serializeResponse(ErrorResponse res);
		static std::vector<char> serializeResponse(LoginResponse res);
		static std::vector<char> serializeResponse(SignupResponse res);
		static std::vector<char> serializeResponse(LogoutResponse res);
		static std::vector<char> serializeResponse(GetRoomsResponse res);
		static std::vector<char> serializeResponse(GetPlayersInRoomResponse res);
		static std::vector<char> serializeResponse(HighscoreResponse res);
		static std::vector<char> serializeResponse(JoinRoomResponse res);
		static std::vector<char> serializeResponse(CreateRoomResponse res);

		

	private:
		JsonPacketSerializer();

		static std::vector<char> buildPacket(int code, std::string data);
		static std::vector<char> intToBytes(int number);
		
};
