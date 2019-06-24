#pragma once

#include "Request.h"

class JsonPacketDeserializer
{
	public:
		JsonPacketDeserializer();
		~JsonPacketDeserializer();

		LoginRequest deserializeLoginRequest(std::vector<char> buffer);
		LoginRequest deserializeSignupRequest(std::vector<char> buffer);

	private:

};

