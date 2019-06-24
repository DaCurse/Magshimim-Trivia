#pragma once

#include "Request.h"

class JsonPacketDeserializer
{
	public:
		static LoginRequest deserializeLoginRequest(unsigned char* buffer);
		static SignupRequest deserializeSignupRequest(unsigned char* buffer);

	private:
		JsonPacketDeserializer();
};

