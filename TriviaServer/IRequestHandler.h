#pragma once

#include "stdafx.h"
#include "Request.h"

class IRequestHandler
{
	public:
		IRequestHandler();
		virtual ~IRequestHandler();

		virtual const bool isRequestRelevant(Request r) = 0;
		virtual const RequestResult handleRequest(Request r) = 0;

};

