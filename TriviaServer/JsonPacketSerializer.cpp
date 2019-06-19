#include "JsonPacketSerializer.h"

std::vector<char> JsonPacketSerializer::serializeResponse(ErrorResponse res)
{
	size_t messageSize = res.message.size() + 1; // Add 1 for null terminator
	std::vector<char> basePacket = buildBasePacket(STATUS_CODE::ERROR, messageSize);
	const char* messageBytes = res.message.c_str();
	basePacket.insert(basePacket.end(), messageBytes, messageBytes + messageSize);

	return basePacket;
}

JsonPacketSerializer::JsonPacketSerializer()
{
}

std::vector<char> JsonPacketSerializer::buildBasePacket(int code, size_t dataLength)
{
	char* codeBytes = CAST_TO_BYTES(code);
	std::vector<char> packetBytes(codeBytes, codeBytes + sizeof(char)); // 1 byte length code
	char* dataLengthBytes = CAST_TO_BYTES(dataLength);
	packetBytes.insert(packetBytes.end(), dataLengthBytes, dataLengthBytes + sizeof(int)); // 4 byte length data length

	return packetBytes;
}
