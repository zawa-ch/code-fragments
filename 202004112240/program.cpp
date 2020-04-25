#include <iostream>
#include "sqlite3.h"
using namespace std;

int main()
{
	const char* DBName = "testdb.db";
	do
	{
		sqlite3* DataBase = nullptr;
		if (sqlite3_open(DBName, &DataBase))
		{
			cout << "[E] Can't open database\"" << DBName << "\"." << endl;
			sqlite3_close(DataBase);
			return -1;
		}
		sqlite3_close(DataBase);
	} while(0);
	return 0;
}

