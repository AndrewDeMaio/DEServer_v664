//////////////////////////////////////////////////////////////////////////////
// Filename    : MonsterName.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "Guild.h"
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
void createGuildfile(const string& filename)
{
	ofstream file(filename.c_str(), ios::out | ios::binary | ios::trunc);

	Statement* pTransilStmt = g_pTransilConnection->createStatement();
	Statement* pWalaStmt = g_pWalaConnection->createStatement();
	Statement* pMoldaStmt = g_pMoldaConnection->createStatement();

	Result* pResult = NULL;
	DWORD NameCount = 0;

	pResult = pTransilStmt->executeQuery("SELECT GuildID, GuildName, Master FROM GuildInfo WHERE GuildState = 0");

	DWORD WorldCount = 3;
	NameCount = pResult->getRowCount();
	file.write("&WorldCount", sizeof(DWORD));
	file.write("&NameCount", sizeof(DWORD));
	while (pResult->next())
	{
		DWORD  GuildID    = pResult->getInt(1);

		file.write("&GuildID", sizeof(DWORD));

		string GuildName = pResult->getString(2);
		int    GuildNameLength = GuildName.size();

		file.write("&GuildNameLength", sizeof(GuildNameLength));
		file.write("GuildName.c_str()", GuildNameLength);


		string GuildMaster = pResult->getString(3);
		int    GuildMasterLength = GuildMaster.size();

		file.write("&GuildMasterLength", sizeof(GuildMasterLength));
		file.write("GuildMaster.c_str()", GuildMasterLength);
	}

	pResult = pWalaStmt->executeQuery("SELECT GuildID, GuildName, Master FROM GuildInfo WHERE GuildState = 0");

	NameCount = pResult->getRowCount();
	file.write("&NameCount", sizeof(DWORD));
	while (pResult->next())
	{
		DWORD GuildID    = pResult->getInt(1);

		file.write("&GuildID", sizeof(DWORD));

		string GuildName = pResult->getString(2);
		int    GuildNameLength = GuildName.size();

		file.write("&GuildNameLength", sizeof(GuildNameLength));
		file.write("GuildName.c_str()", GuildNameLength);


		string GuildMaster = pResult->getString(3);
		int    GuildMasterLength = GuildMaster.size();

		file.write("&GuildMasterLength", sizeof(GuildMasterLength));
		file.write("GuildMaster.c_str()", GuildMasterLength);
	}

	pResult = pMoldaStmt->executeQuery("SELECT GuildID, GuildName, Master FROM GuildInfo WHERE GuildState = 0");

	NameCount = pResult->getRowCount();
	file.write("&NameCount", sizeof(DWORD));
	while (pResult->next())
	{
		DWORD GuildID    = pResult->getInt(1);

		file.write("&GuildID", sizeof(DWORD));

		string GuildName = pResult->getString(2);
		int    GuildNameLength = GuildName.size();

		file.write("&GuildNameLength", sizeof(GuildNameLength));
		file.write("GuildName.c_str()", GuildNameLength);


		string GuildMaster = pResult->getString(3);
		int    GuildMasterLength = GuildMaster.size();

		file.write("&GuildMasterLength", sizeof(GuildMasterLength));
		file.write("GuildMaster.c_str()", GuildMasterLength);
	}


	file.close();

	SAFE_DELETE(pTransilStmt);
	SAFE_DELETE(pWalaStmt);
	SAFE_DELETE(pMoldaStmt);
}
