#pragma once

#include "stdafx.h"
#include "IDatabase.h"

class HighscoreTable
{

	public:
		HighscoreTable(IDatabase* database);
		~HighscoreTable();

		std::vector<Highscore> getHighscores();

	private:
		IDatabase* m_database;
};

