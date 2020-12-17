#include "Room.h"

Room::Room(RoomData meta) : m_metadata(meta)
{
}

Room::~Room()
{
}

void Room::addUser(LoggedUser u)
{
	if (m_users.size() >= m_metadata.maxPlayers)
	{
		throw std::runtime_error("Room is full");
	}
	if (std::find(m_users.begin(), m_users.end(), u) != m_users.end())
	{
		throw std::runtime_error("User already exists in room");
	}
	
	m_users.push_back(u);
}

void Room::removeUser(std::string username)
{
	auto it = m_users.begin();
	for (; it != m_users.end(); ++it)
	{
		if (*it == username)
		{
			break;
		}
	}
	m_users.erase(it);
}

std::vector<LoggedUser> Room::getAllUsers()
{
	return std::vector<LoggedUser>(m_users);
}

RoomData Room::getMeta()
{
	return m_metadata;
}
