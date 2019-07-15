#include "MenuRequestHandler.h"
#include "RequestHandlerFactory.h"



MenuRequestHandler::MenuRequestHandler(std::string username, RoomManager manager, HighscoreTable table, RequestHandlerFactory* factory) : m_user(username), m_roomManager(manager), m_highscoreTable(table), m_handlerFactory(factory)
{
}

MenuRequestHandler::~MenuRequestHandler()
{
}

const bool MenuRequestHandler::isRequestRelevant(Request r)
{
	return r.id >= GET_PLAYERS_REQUEST && r.id <= CREATE_ROOM_REQUEST;
}

const RequestResult MenuRequestHandler::handleRequest(Request r)
{
	try
	{
		if (r.id == GET_PLAYERS_REQUEST)
		{
			GetPlayersInRoomRequest req = JsonPacketDeserializer::deserializeGetPlayersInRoomRequest(r.buffer.data(), r.buffer.size());
			std::vector<std::string> players;
			std::vector<LoggedUser> users = m_roomManager.getRoom(req.roomId).getAllUsers();
			for (auto it = users.begin(); it != users.end(); ++it)
			{
				players.push_back(it->getUsername());
			}
			GetPlayersInRoomResponse res = { GOT_PLAYERS,  players };
			return { JsonPacketSerializer::serializeResponse(res), (IRequestHandler*)m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
		}
		else if (r.id == JOIN_ROOM_REQUEST)
		{
			JoinRoomRequest req = JsonPacketDeserializer::deserializeJoinRoomRequest(r.buffer.data(), r.buffer.size());
			m_roomManager.getRoom(req.roomId).addUser(m_user);
			JoinRoomResponse res = { JOINED_ROOM };
			return { JsonPacketSerializer::serializeResponse(res), (IRequestHandler*)m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
		}
		else if (r.id == CREATE_ROOM_REQUEST)
		{
			CreateRoomRequest req = JsonPacketDeserializer::deserializeCreateRoomRequest(r.buffer.data(), r.buffer.size());
			RoomData data = {
				0,
				req.roomName,
				req.maxUsers,
				req.answerTimeout,
				0
			};
			m_roomManager.createRoom(m_user, data);
			CreateRoomResponse res = { CREATED_ROOM };
			return { JsonPacketSerializer::serializeResponse(res), (IRequestHandler*)m_handlerFactory->createMenuRequestHandler(m_user.getUsername()) };
		}
	}
	catch (nlohmann::json::exception& e)
	{
		ErrorResponse res = { "Invalid json in request" };
		return { JsonPacketSerializer::serializeResponse(res), nullptr };
	}
	catch (std::exception& e)
	{
		ErrorResponse res = { e.what() };
		return { JsonPacketSerializer::serializeResponse(res), nullptr };
	}

	ErrorResponse res = { "Invalid request" };
	return { JsonPacketSerializer::serializeResponse(res), nullptr };
}

RequestResult MenuRequestHandler::signout(Request r)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::getRooms(Request r)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::getPlayersInRoom(Request r)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::getHighscores(Request r)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::joinRoom(Request r)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::createRoom(Request r)
{
	return RequestResult();
}
