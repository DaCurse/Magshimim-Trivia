#include "RoomManager.h"

std::map<unsigned int, Room> RoomManager::rooms = {};
unsigned int RoomManager::lastId = 0;

void RoomManager::createRoom(LoggedUser u, RoomData meta)
{
	meta.id = lastId++;
	Room newRoom(meta);
	newRoom.addUser(u);
	rooms.insert(std::pair<unsigned int, Room>(meta.id, newRoom));
}

void RoomManager::deleteRoom(unsigned int roomId)
{
	rooms.erase(rooms.find(roomId));
}

unsigned int RoomManager::getRoomState(unsigned int roomId)
{
	return rooms.find(roomId)->second.getMeta().isActive;
}

std::vector<RoomData> RoomManager::getRooms()
{
	std::vector<RoomData> rooms;
	for (auto it = rooms.begin(); it != rooms.end(); ++it)
	{
		rooms.push_back(*it);
	}
	return rooms;
}

Room RoomManager::getRoom(unsigned int roomId)
{
	if (rooms.find(roomId) == rooms.end())
	{
		throw std::runtime_error("Room with id " + std::to_string(roomId) + " doesn't exist");
	}
	return rooms.find(roomId)->second;
}
