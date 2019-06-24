#include "JsonPacketDeserializer.h"

LoginRequest JsonPacketDeserializer::deserializeLoginRequest(unsigned char* buffer)
{
	return LoginRequest();
}

SignupRequest JsonPacketDeserializer::deserializeSignupRequest(unsigned char* buffer)
{
	return SignupRequest();
}

JsonPacketDeserializer::JsonPacketDeserializer()
{
}
