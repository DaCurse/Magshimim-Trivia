#pragma once

#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

class Config
{
	public:
		static void loadConfig();
		static json getConfig();

	private:
		static json m_config;
		Config();
};

