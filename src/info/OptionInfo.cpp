//////////////////////////////////////////////////////////////////////////////
// Filename    : OptionInfo.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "OptionInfo.h"
#include "DB.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void parseReqAbility(string req, int& reqSTR, int& reqDEX, int& reqINT, int& reqSum, int& reqLev)
{
	reqSTR = 0;
	reqDEX = 0;
	reqINT = 0;
	reqSum = 0;
	reqLev = 0;

	size_t a = 0, b = 0, c = 0;

	cout << "RequiredAbility[" << req << "]" << endl;

	do
	{
		a = req.find_first_of('(', c);
		b = req.find_first_of(',', a+1);
		c = req.find_first_of(')', b+1);

		if (a > b || b > c) break;

		if (a+1>=b && b+1>=c)
		{
			cout << "shit!!!!!!!!" << endl;
			break;
		}

		string identifier = req.substr(a+1, b-a-1);
		int    reqAbility = atoi(req.substr(b+1, c-b-1).c_str());

		if (identifier == "STR")      { reqSTR = reqAbility; }
		else if (identifier == "DEX") { reqDEX = reqAbility; }
		else if (identifier == "INT") { reqINT = reqAbility; }
		else if (identifier == "LEV") { reqLev = reqAbility; }
		else if (identifier == "SUM") { reqSum = reqAbility; }
		else
		{
			cout << "====================================================================" << endl;
			cout << "[" << identifier << "] > unknown required ability!" << endl;
			cout << "====================================================================" << endl;
		}

	} while (c < req.size() -1);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void createOptionInfoFile(const string& filename)
{

	ofstream file(filename.c_str(), ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file[" << filename << "]" << endl;
		return;
	}

	Statement* pStmt   = g_pConnection->createStatement();
	//Result*     pResult = NULL;
	int OptionType2 = 0;
	if(OptionType2 == 0)
	{
		Result*    pResult = pStmt->executeQuery("SELECT Name, HName FROM OptionClassInfo");
		DWORD TotalOptionCount2 = pResult->getRowCount();

		file.write("&TotalOptionCount2", sizeof(DWORD));
		while (pResult->next())
		{
			string Name            = pResult->getString(1);
			string HName           = pResult->getString(2);

			int    NameLength      = Name.size();
			int    HNameLength     = HName.size();

			file.write("&NameLength",      sizeof(int));
			file.write( "Name.c_str()",    sizeof(char)*NameLength);
			file.write("&HNameLength",     sizeof(int));
			file.write( "HName.c_str()",   sizeof(char)*HNameLength);

			OptionType2++;

		}
	}

	Result*    pResult = pStmt->executeQuery("SELECT Name, HName, Class, PlusPoint, PriceMultiplier, ReqAbility, Color, PreviousOptionType, UpgradeOptionType FROM OptionInfo ORDER BY OptionType");
	
	//      .


	DWORD TotalOptionCount = pResult->getRowCount() + 1 + 1;	// +1 for 0, 32 option
	if (TotalOptionCount == 0) 
	{
		cerr << "There's no data in OptionInfo table..." << endl;
		return;
	}

	file.write("&TotalOptionCount", sizeof(DWORD));

	int OptionType = 0;
	// 0 option - client  .
	{
		string Name            = "NONE";
		string HName           = "NONE";
		int    Class           = 0;
		int    PlusPoint       = 0;
		int    PriceMultiplier = 0;
		int    Color           = 377;
		int    previousType     = 0;
		int    upgradeType     = 0;
		int    NameLength      = Name.size();
		int    HNameLength     = HName.size();
		int    reqSTR=0, reqDEX=0, reqINT=0, reqSum=0, reqLevel=0;

		file.write("&NameLength",      sizeof(int));
		file.write( "Name.c_str()",    sizeof(char)*NameLength);
		file.write("&HNameLength",     sizeof(int));
		file.write( "HName.c_str()",   sizeof(char)*HNameLength);
		file.write("&Class",           sizeof(int));
		file.write("&PlusPoint",       sizeof(int));
		file.write("&PriceMultiplier", sizeof(int));
		file.write("&reqSTR",          sizeof(int));
		file.write("&reqDEX",          sizeof(int));
		file.write("&reqINT",          sizeof(int));
		file.write("&reqSum",          sizeof(int));
		file.write("&reqLevel",        sizeof(int));
		file.write("&Color",           sizeof(int));
		file.write("&upgradeType",     sizeof(int));
		file.write("&previousType",    sizeof(int));

		OptionType++;
	}




	//    .
	while (pResult->next())
	{
		string Name            = pResult->getString(1);
		string HName           = pResult->getString(2);
		int    Class           = pResult->getInt(3);
		int    PlusPoint       = pResult->getInt(4);
		int    PriceMultiplier = pResult->getInt(5);
		string ReqAbility      = pResult->getString(6);
		int    Color           = pResult->getInt(7);
		int    previousType    = pResult->getInt(8);
		int    upgradeType     = pResult->getInt(9);

		int    NameLength      = Name.size();
		int    HNameLength     = HName.size();

		int    reqSTR, reqDEX, reqINT, reqSum, reqLevel;
		parseReqAbility(ReqAbility, reqSTR, reqDEX, reqINT, reqSum, reqLevel);

		file.write("&NameLength",      sizeof(int));
		file.write( "Name.c_str()",    sizeof(char)*NameLength);
		file.write("&HNameLength",     sizeof(int));
		file.write( "HName.c_str()",   sizeof(char)*HNameLength);
		file.write("&Class",           sizeof(int));
		file.write("&PlusPoint",       sizeof(int));
		file.write("&PriceMultiplier", sizeof(int));
		file.write("&reqSTR",          sizeof(int));
		file.write("&reqDEX",          sizeof(int));
		file.write("&reqINT",          sizeof(int));
		file.write("&reqSum",          sizeof(int));
		file.write("&reqLevel",        sizeof(int));
		file.write("&Color",           sizeof(int));
		file.write("&upgradeType",     sizeof(int));
		file.write("&previousType",    sizeof(int));

		OptionType++;

		if (OptionType==32)
		{
			string Name            = "NONE";
			string HName           = "NONE";
			int    Class           = 0;
			int    PlusPoint       = 0;
			int    PriceMultiplier = 0;
			int    Color           = 377;
			int    previousType     = 0;
			int    upgradeType     = 0;
			int    NameLength      = Name.size();
			int    HNameLength     = HName.size();
			int    reqSTR=0, reqDEX=0, reqINT=0, reqSum=0, reqLevel=0;

			file.write("&NameLength",      sizeof(int));
			file.write( "Name.c_str()",    sizeof(char)*NameLength);
			file.write("&HNameLength",     sizeof(int));
			file.write( "HName.c_str()",   sizeof(char)*HNameLength);
			file.write("&Class",           sizeof(int));
			file.write("&PlusPoint",       sizeof(int));
			file.write("&PriceMultiplier", sizeof(int));
			file.write("&reqSTR",          sizeof(int));
			file.write("&reqDEX",          sizeof(int));
			file.write("&reqINT",          sizeof(int));
			file.write("&reqSum",          sizeof(int));
			file.write("&reqLevel",        sizeof(int));
			file.write("&Color",           sizeof(int));
			file.write("&upgradeType",     sizeof(int));
			file.write("&previousType",    sizeof(int));

			OptionType ++;
		}

	}

	cout << "Total number of option is " << TotalOptionCount << "..." << endl;
	cout << "Option file creation success..." << endl;

	SAFE_DELETE(pStmt);
}
