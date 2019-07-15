#include "HighscoreTable.h"

HighscoreTable::HighscoreTable(IDatabase* database) : m_database(database)
{
}

HighscoreTable::~HighscoreTable()
{
}

std::vector<Highscore> HighscoreTable::getHighscores()
{
	return m_database->getHighscores();
}
