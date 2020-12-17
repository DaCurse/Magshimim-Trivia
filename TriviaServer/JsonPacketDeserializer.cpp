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

GetPlayersInRoomRequest JsonPacketDeserializer::deserializeGetPlayersInRoomRequest(char* buffer, int len)
{
	std::string data(buffer, len - 1);
	json jsonData = json::parse(data);
	return GetPlayersInRoomRequest({ jsonData["roomId"] });
}

JoinRoomRequest JsonPacketDeserializer::deserializeJoinRoomRequest(char* buffer, int len)
{
	std::string data(buffer, len - 1);
	json jsonData = json::parse(data);
	return JoinRoomRequest({ jsonData["roomId"] });
}

CreateRoomRequest JsonPacketDeserializer::deserializeCreateRoomRequest(char* buffer, int len)
{
	std::string data(buffer, len - 1);
	json jsonData = json::parse(data);
	return CreateRoomRequest({ jsonData["roomName"], jsonData["maxUsers"], jsonData["questionCount"], jsonData["answerTimeout"] });
}

JsonPacketDeserializer::JsonPacketDeserializer()
{
}
