#include "JsonPacketSerializer.h"

std::vector<char> JsonPacketSerializer::serializeResponse(ErrorResponse res)
{
	json jsonData;
	jsonData["message"] = res.message;

	return buildPacket(ERROR, jsonData.dump());
}

std::vector<char> JsonPacketSerializer::serializeResponse(LoginResponse res)
{
	return buildPacket(res.status, "{}");
}

std::vector<char> JsonPacketSerializer::serializeResponse(SignupResponse res)
{
	return buildPacket(res.status, "{}");
}

std::vector<char> JsonPacketSerializer::buildPacket(int code, std::string data)
{
	std::vector<char> packetBytes;
	packetBytes.push_back(static_cast<unsigned char>(code));
	std::vector<char> dataLengthBytes = intToBytes(data.size() + 1);
	std::copy(dataLengthBytes.begin(), dataLengthBytes.end(), std::back_inserter(packetBytes));
	std::copy(data.begin(), data.end(), std::back_inserter(packetBytes));

	return packetBytes;
}

std::vector<char> JsonPacketSerializer::intToBytes(int number)
{
	std::vector<char> arrayOfBytes(4);
	for (int i = 0; i < 4; i++)
	{
		arrayOfBytes[3 - i] = (number >> (i * 8));
	}
	return arrayOfBytes;
}

JsonPacketSerializer::JsonPacketSerializer()
{
}