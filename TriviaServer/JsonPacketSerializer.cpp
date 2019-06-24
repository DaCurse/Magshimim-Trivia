#include "JsonPacketSerializer.h"

std::vector<unsigned char> JsonPacketSerializer::serializeResponse(ErrorResponse res)
{
	json j;
	j["message"] = res.message;

	return buildPacket(ERROR, j.dump());
}

std::vector<unsigned char> JsonPacketSerializer::serializeResponse(LoginResponse res)
{
	return buildPacket(res.status, "{}");
}

std::vector<unsigned char> JsonPacketSerializer::serializeResponse(SignupResponse res)
{
	return buildPacket(res.status, "{}");
}

std::vector<unsigned char> JsonPacketSerializer::buildPacket(int code, std::string data)
{
	std::vector<unsigned char> packetBytes;
	packetBytes.push_back(static_cast<unsigned char>(code));
	std::vector<unsigned char> dataLengthBytes = intToBytes(data.size() + 1);
	std::copy(dataLengthBytes.begin(), dataLengthBytes.end(), std::back_inserter(packetBytes));
	std::copy(data.begin(), data.end(), std::back_inserter(packetBytes));

	return packetBytes;
}

std::vector<unsigned char> JsonPacketSerializer::intToBytes(int number)
{
	std::vector<unsigned char> arrayOfBytes(4);
	for (int i = 0; i < 4; i++)
	{
		arrayOfBytes[3 - i] = (number >> (i * 8));
	}
	return arrayOfBytes;
}

JsonPacketSerializer::JsonPacketSerializer()
{
}