#pragma once
#include <vector>
#include "Response.h"
#include "json.hpp"

#define CAST_TO_BYTES(OBJ) static_cast<char*>(static_cast<void*>(&OBJ));

using json = nlohmann::json;

class JsonPacketSerializer
{
	public:
		static std::vector<char> serializeResponse(ErrorResponse res);
		

	private:
		JsonPacketSerializer();

		static std::vector<char> buildBasePacket(int code, size_t dataLength);
		
};

