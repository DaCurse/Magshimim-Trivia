#include "LoginRequestHandler.h"
#include "RequestHandlerFactory.h"

LoginRequestHandler::LoginRequestHandler(LoginManager manager, RequestHandlerFactory* factory) : m_loginManager(manager), m_handlerFactory(factory)
{
}

LoginRequestHandler::~LoginRequestHandler()
{
}

const bool LoginRequestHandler::isRequestRelevant(Request r)
{
	return r.id >= LOGIN_REQUEST && r.id <= SIGNUP_REQUEST;
}

const RequestResult LoginRequestHandler::handleRequest(Request r)
{
	try
	{
		if (r.id == LOGIN_REQUEST)
		{
			LoginRequest req = JsonPacketDeserializer::deserializeLoginRequest(r.buffer.data(), r.buffer.size());
			m_loginManager.login(req.username, req.password);
			LoginResponse res = { LOGIN_SUCCESS };
			return { JsonPacketSerializer::serializeResponse(res), nullptr };
		}
		else if (r.id == SIGNUP_REQUEST)
		{
			SignupRequest req = JsonPacketDeserializer::deserializeSignupRequest(r.buffer.data(), r.buffer.size());
			m_loginManager.signup(req.email, req.username, req.password);
			SignupResponse res = { SIGNUP_SUCCESS };
			return { JsonPacketSerializer::serializeResponse(res), m_handlerFactory->createLoginRequestHandler() };
		}
	}
	catch(nlohmann::json::exception& e)
	{
		ErrorResponse res = { "Invalid json in request" };
		return { JsonPacketSerializer::serializeResponse(res), nullptr };
	}
	catch (std::exception& e)
	{
		ErrorResponse res = { e.what() };
		return {JsonPacketSerializer::serializeResponse(res), nullptr};
	}

	ErrorResponse res = { "Invalid request" };
	return { JsonPacketSerializer::serializeResponse(res), nullptr };
}

RequestResult LoginRequestHandler::signup(Request r)
{
	return RequestResult();
}

RequestResult LoginRequestHandler::login(Request r)
{
	return RequestResult();
}
