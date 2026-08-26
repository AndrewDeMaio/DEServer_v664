//////////////////////////////////////////////////////////////////////////////
// Filename    : MonsterName.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "MonsterName.h"
#include "DB.h"
#include "Utility.h"
#include <iomanip>

//////////////////////////////////////////////////////////////////////////////
// int FirstNameCount
// {
//     int Length;
//     string Name;
// }
// int MiddleNameCount
// {
//     int Length;
//     string Name;
// }
// int LastNameCount
// {
//     int Length;
//     string Name;
// }
//////////////////////////////////////////////////////////////////////////////
void createMonsterNameFile(const string& filename)
{
	ofstream file(filename.c_str(), ios::out | ios::binary | ios::trunc);

	Statement* pStmt = g_pConnection->createStatement();
	Result* pResult = NULL;
	int NameCount = 0;

	pResult = pStmt->executeQuery("SELECT Name FROM FirstNameInfo WHERE MonsterType='BASIC'");
	NameCount = pResult->getRowCount();
	file.write("&NameCount", sizeof(NameCount));
	while (pResult->next())
	{
		string Name       = pResult->getString(1);
		int    NameLength = Name.size();

		file.write("&NameLength", sizeof(NameLength));
		file.write("Name.c_str()", NameLength);
	}

	cout << "FirstNameCount:" << NameCount << endl;

	pResult = pStmt->executeQuery("SELECT Name FROM MiddleNameInfo WHERE MonsterType='BASIC'");
	NameCount = pResult->getRowCount();
	file.write("&NameCount", sizeof(NameCount));
	while (pResult->next())
	{
		string Name       = pResult->getString(1);
		int    NameLength = Name.size();

		file.write("&NameLength", sizeof(NameLength));
		file.write("Name.c_str()", NameLength);
	}

	cout << "MiddleNameCount:" << NameCount << endl;

	pResult = pStmt->executeQuery("SELECT Name FROM LastNameInfo WHERE MonsterType='BASIC'");
	NameCount = pResult->getRowCount();
	file.write("&NameCount", sizeof(NameCount));
	while (pResult->next())
	{
		string Name       = pResult->getString(1);
		int    NameLength = Name.size();

		file.write("&NameLength", sizeof(NameLength));
		file.write("Name.c_str()", NameLength);
	}

	cout << "LastNameCount:" << NameCount << endl;

	file.close();

	SAFE_DELETE(pStmt);
}
