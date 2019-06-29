#pragma once

#include <stdexcept>  
#include "Request.h"
#include "json.hpp"

using json = nlohmann::json;

class JsonPacketDeserializer
{
	public:
		static LoginRequest deserializeLoginRequest(char* buffer, int len);
		static SignupRequest deserializeSignupRequest(char* buffer, int len);

	private:
		JsonPacketDeserializer();

};

