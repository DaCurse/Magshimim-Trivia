#pragma once

#include "stdafx.h"
#include "LoggedUser.h"
#include "Room.h"

class RoomManager
{
	public:
		void createRoom(LoggedUser u, RoomData meta);
		void deleteRoom(unsigned int roomId);
		unsigned int getRoomState(unsigned int roomId);
		std::vector<RoomData> getRooms();
		Room getRoom(unsigned int roomId);

	private:
		static std::map<unsigned int, Room> rooms;
		static unsigned int lastId;
};

