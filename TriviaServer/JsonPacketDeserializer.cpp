#include "JsonPacketDeserializer.h"

LoginRequest JsonPacketDeserializer::deserializeLoginRequest(char* buffer, int len)
{
	std::string data(buffer, len - 1);
	json jsonData = json::parse(data);
	return LoginRequest({jsonData["username"], jsonData["password"]});

}

SignupRequest JsonPacketDeserializer::deserializeSignupRequest(char* buffer, int len)
{
	std::string data(buffer, len - 1);
	json jsonData = json::parse(data);
	return SignupRequest({jsonData["username"], jsonData["password"], jsonData["email"]});
}

JsonPacketDeserializer::JsonPacketDeserializer()
{
}
