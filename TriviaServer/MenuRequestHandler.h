#pragma once

#include "stdafx.h"
#include "IRequestHandler.h"
#include "LoggedUser.h"
#include "Request.h"
#include "Response.h"
#include "JsonPacketDeserializer.h"
#include "JsonPacketSerializer.h"
#include "RoomManager.h"
#include "HighscoreTable.h"

class RequestHandlerFactory;

class MenuRequestHandler : public IRequestHandler
{
	public:
		MenuRequestHandler(std::string username, RoomManager manager, HighscoreTable table, RequestHandlerFactory* factory);
		~MenuRequestHandler();

		virtual const bool isRequestRelevant(Request r);
		virtual const RequestResult handleRequest(Request r);

	private:
		LoggedUser m_user;
		RoomManager m_roomManager;
		HighscoreTable m_highscoreTable;
		RequestHandlerFactory* m_handlerFactory;

		RequestResult signout(Request r);
		RequestResult getRooms(Request r);
		RequestResult getPlayersInRoom(Request r);
		RequestResult getHighscores(Request r);
		RequestResult joinRoom(Request r);
		RequestResult createRoom(Request r);


};

