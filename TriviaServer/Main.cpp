#include "stdafx.h"
#include "SqliteDatabase.h"
#include "Server.h"

int main()
{
	try
	{
		Config::loadConfig();
		SqliteDatabase* db = new SqliteDatabase();
		Server serv(db);
		serv.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	::system("pause");
	return 0;
}                  
