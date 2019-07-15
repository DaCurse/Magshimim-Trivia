#pragma once

#include "stdafx.h"
#include "LoggedUser.h"

typedef struct RoomData {
	unsigned int id;
	std::string name;
	unsigned int maxPlayers;
	unsigned int timePerQuestion;
	unsigned int isActive;
} RoomData;

class Room
{
	public:
		Room(RoomData meta);
		~Room();

		void addUser(LoggedUser u);
		void removeUser(std::string username);
		std::vector<LoggedUser> getAllUsers();

		RoomData getMeta();

	private:
		RoomData m_metadata;
		std::vector<LoggedUser> m_users;
};

