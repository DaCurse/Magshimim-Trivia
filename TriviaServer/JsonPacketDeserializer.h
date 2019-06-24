#pragma once

#include <exception>  
#include "Request.h"
#include "json.hpp"

using json = nlohmann::json;

class JsonPacketDeserializer
{
	public:
		static LoginRequest deserializeLoginRequest(unsigned char* buffer);
		static SignupRequest deserializeSignupRequest(unsigned char* buffer);

	private:
		JsonPacketDeserializer();

		static json extractData(unsigned char* buffer);
};

