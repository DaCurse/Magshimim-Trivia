#include "JsonPacketDeserializer.h"

LoginRequest JsonPacketDeserializer::deserializeLoginRequest(unsigned char* buffer)
{
	int code = static_cast<int>(buffer[0]);
	
	if (code != LOGIN_REQUEST)
	{
		throw std::exception("Cannot deserialize login request: Invalid request ID: " + code);
	}

	json jsonData = extractData(buffer);

	return LoginRequest({jsonData["username"], jsonData["password"]});

}

SignupRequest JsonPacketDeserializer::deserializeSignupRequest(unsigned char* buffer)
{
	int code = static_cast<int>(buffer[0]);

	if (code != SIGNUP_REQUEST)
	{
		throw std::exception("Cannot deserialize signup request: Invalid request ID: " + code);
	}

	json jsonData = extractData(buffer);

	return SignupRequest({jsonData["username"], jsonData["password"], jsonData["email"]});
}

json JsonPacketDeserializer::extractData(unsigned char * buffer)
{
	int dataLength = buffer[1] << 24 | buffer[2] << 16 | buffer[3] << 8 | buffer[4];
	std::string data(reinterpret_cast<char*>(&buffer[5]), dataLength - 1);
	return json::parse(data);
}

JsonPacketDeserializer::JsonPacketDeserializer()
{
}
