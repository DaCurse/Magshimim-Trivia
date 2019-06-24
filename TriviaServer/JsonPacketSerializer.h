#pragma once
#include <vector>
#include "Response.h"
#include "json.hpp"

using json = nlohmann::json;

class JsonPacketSerializer
{
	public:
		static std::vector<unsigned char> serializeResponse(ErrorResponse res);
		static std::vector<unsigned char> serializeResponse(LoginResponse res);
		static std::vector<unsigned char> serializeResponse(SignupResponse res);
		

	private:
		JsonPacketSerializer();

		static std::vector<unsigned char> buildPacket(int code, std::string data);
		static std::vector<unsigned char> intToBytes(int number);
		
};

