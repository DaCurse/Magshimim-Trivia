#pragma once

#include "stdafx.h"

class Config
{
	public:
		static void loadConfig();
		static json getConfig();

	private:
		static json m_config;
		Config();
};

