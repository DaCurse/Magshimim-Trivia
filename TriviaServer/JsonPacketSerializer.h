#pragma once

#include "stdafx.h"
#include "Response.h"

class JsonPacketSerializer
{
	public:
		static std::vector<char> serializeResponse(ErrorResponse res);
		static std::vector<char> serializeResponse(LoginResponse res);
		static std::vector<char> serializeResponse(SignupResponse res);
		

	private:
		JsonPacketSerializer();

		static std::vector<char> buildPacket(int code, std::string data);
		static std::vector<char> intToBytes(int number);
		
};

