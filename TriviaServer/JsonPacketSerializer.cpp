#include "JsonPacketSerializer.h"

std::vector<char> JsonPacketSerializer::serializeResponse(ErrorResponse res)
{
	json jsonData = {
		{"message", res.message}
	};
	return buildPacket(REQUEST_ERROR, jsonData.dump());
}

std::vector<char> JsonPacketSerializer::serializeResponse(LoginResponse res)
{
	json jsonData = {
		{"status", res.status}
	};
	return buildPacket(res.status, jsonData.dump());
}

std::vector<char> JsonPacketSerializer::serializeResponse(SignupResponse res)
{
	json jsonData = {
		{"status", res.status}
	};
	return buildPacket(res.status, jsonData.dump());
}

std::vector<char> JsonPacketSerializer::serializeResponse(LogoutResponse res)
{
	json jsonData = {
		{"status", res.status}
	};
	return buildPacket(res.status, jsonData.dump());
}

std::vector<char> JsonPacketSerializer::serializeResponse(GetRoomsResponse res)
{
	json jsonData = {
		{"status", res.status},
		{"rooms", {}}
	};

	for (auto it = res.rooms.begin(); it != res.rooms.end(); ++it)
	{
		jsonData["rooms"].push_back({
			{"id", it->id},
			{"name", it->name},
			{"maxPlayers", it->maxPlayers},
			{"timePerQuestion", it->timePerQuestion},
			{"isActive", it->isActive},

		});
	}

	return buildPacket(res.status, jsonData.dump());
}

std::vector<char> JsonPacketSerializer::serializeResponse(GetPlayersInRoomResponse res)
{
	json jsonData = {
		{"status", res.status},
		{"players", res.players}
	}; 
	return buildPacket(res.status, jsonData.dump());
}

std::vector<char> JsonPacketSerializer::serializeResponse(HighscoreResponse res)
{
	json jsonData = {
		{"status", res.status},
		{"highscores", {}}
	}; 
	
	for (auto it = res.highscores.begin(); it != res.highscores.end(); ++it)
	{
		jsonData["highscores"].push_back({
			{"username", it->username},
			{"score", it->score}
		});
	}

	return buildPacket(res.status, jsonData.dump());
}

std::vector<char> JsonPacketSerializer::serializeResponse(JoinRoomResponse res)
{
	json jsonData = {
		{"status", res.status}
	};
	return std::vector<char>();
}

std::vector<char> JsonPacketSerializer::serializeResponse(CreateRoomResponse res)
{
	json jsonData = {
		{"status", res.status}
	};
	return buildPacket(res.status, jsonData.dump());
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