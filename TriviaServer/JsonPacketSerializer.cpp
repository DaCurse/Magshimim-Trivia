#include "JsonPacketSerializer.h"

std::vector<char> JsonPacketSerializer::serializeResponse(ErrorResponse res)
{
	json j;
	j["message"] = res.message;

	return buildPacket(ERROR, j.dump());
}

std::vector<char> JsonPacketSerializer::serializeResponse(LoginResponse res)
{
	return buildPacket(res.status, "{}");
}

std::vector<char> JsonPacketSerializer::serializeResponse(SignupResponse res)
{
	return buildPacket(res.status, "{}");
}

JsonPacketSerializer::JsonPacketSerializer()
{
}

std::vector<char> JsonPacketSerializer::buildPacket(int code, std::string data)
{
	char* codeBytes = CAST_TO_BYTES(code);
	std::vector<char> packetBytes(codeBytes, codeBytes + sizeof(char)); // 1 byte length code
	size_t dataLength = data.size() + 1; // Add 1 for null terminator
	char* dataLengthBytes = CAST_TO_BYTES(dataLength);
	packetBytes.insert(packetBytes.end(), dataLengthBytes, dataLengthBytes + sizeof(int)); // 4 byte length data length
	const char* dataBytes = data.c_str();
	packetBytes.insert(packetBytes.end(), dataBytes, dataBytes + dataLength);

	return packetBytes;
}
