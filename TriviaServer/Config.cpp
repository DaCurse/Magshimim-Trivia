#include "Config.h"

json Config::m_config = {};

void Config::loadConfig()
{
	std::ifstream configFile("config.json");
	std::string data((std::istreambuf_iterator<char>(configFile)), std::istreambuf_iterator<char>());

	m_config = json::parse(data);
}

json Config::getConfig()
{
	return m_config;
}

Config::Config()
{
}

