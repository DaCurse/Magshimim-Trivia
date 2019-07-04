#include "Config.h"

json Config::m_config = {};

void Config::loadConfig()
{
	std::ifstream configFile("config.json");
	std::string data((std::istreambuf_iterator<char>(configFile)), std::istreambuf_iterator<char>());

	m_config = json::parse(data);

	std::cout << "Server config loaded" << std::endl;
}

json Config::getConfig()
{
	if (m_config.empty())
	{
		throw std::runtime_error("Failed to load config: config was not loaded yet");
	}
	return m_config;
}

Config::Config()
{
}

