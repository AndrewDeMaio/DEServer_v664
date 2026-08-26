//////////////////////////////////////////////////////////////////////////////
// Filename    : NPCShopTemplate.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "NPCShopTemplate.h"
#include "DB.h"
#include <iomanip>

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void createNPCShopTemplateFile(string npc_filename, string shop_filename)
{
	ofstream file;

	// NPC   
	int    numberOfNPC;
	
	//by kim 3개다 마춰준다.
	int    NPCID[1081];
	string NPCName[1081];
	string NPCDescription[1081];		//npc 설명
	int    NPCFace[1081];			//npc 사진

	int    templateCount[521] = {0,};
	int    totalCount = 0;

	// SHOP_TEMPLATE   .
	uint        ID;             // 4
	BYTE        rackType;       // 1 + 4 = 5
	int         itemClass;      // 4 + 5 = 9
	WORD        minItemType;    // 2 + 9 = 11
	WORD        maxItemType;    // 2 + 11 = 13
	BYTE        minOptionLevel; // 1 + 13 = 14
	BYTE        maxOptionLevel; // 1 + 14 = 15
	DWORD       totalNumber;
	int         stCount = 0;

	/////////////////////////////////////////////////////////////////////////////////////////////
	// DB  .
	/////////////////////////////////////////////////////////////////////////////////////////////
	Statement*  pStmt   = g_pConnection->createStatement();
	Result*     pResult = NULL;

	/////////////////////////////////////////////////////////////////////////////////////////////
	// NPC  
	/////////////////////////////////////////////////////////////////////////////////////////////
	
	cout << "NPC   ." << endl;
	
	//  .
	file.open(npc_filename.c_str(), ios::out | ios::binary | ios::trunc);
	if (!file)
	{
		cerr << npc_filename << "   ." << endl;
		return;
	}

	// NPC ID    .
	pResult = pStmt->executeQuery("SELECT NPCID, Name, Description, NpcFace FROM NPC");
	numberOfNPC = pResult->getRowCount();
	file.write("&numberOfNPC", sizeof(int));

	//  NPC ID   .
	int count = 0;
	while (pResult->next())
	{

		NPCID[count]          = pResult->getInt(1);
		NPCName[count]          = pResult->getString(2);
		NPCDescription[count] = pResult->getString(3);
		NPCFace[count] = pResult->getInt(4);
		count++;
	}
	
	//  NPC  ShopTemplate    .
	cout << "---------------------------------------------------------------" << endl;
	cout << "[NPCID] ShopTemplateIDs...." << endl;
	for (int i=0; i<numberOfNPC; i++)
	{
		pResult = pStmt->executeQuery("SELECT ID from ShopTemplate where ShopType in (0, 2) AND NPCID = %d", NPCID[i]);




		// NPCID
		file.write("&NPCID[i]", sizeof(int));

		int length2 = NPCName[i].size();
		file.write("&length2", sizeof(int));

		//  .
		file.write("NPCName[i].c_str()", length2);

		//    .
		int rowCount = pResult->getRowCount();
		file.write("&rowCount", sizeof(int));
		templateCount[i] = rowCount;

		cout << "[" << NPCID[i] << "] ";

		//  id .
		while (pResult->next())
		{
			int id = pResult->getInt(1);
			file.write("&id", sizeof(uint));
			totalCount++;

			cout << id << " ";
		}
		cout << endl;

		//   .
		int length = NPCDescription[i].size();
		file.write("&length", sizeof(int));

		//  .
		file.write("NPCDescription[i].c_str()", length);

		// NPCID
		file.write("&NPCFace[i]", sizeof(int));

		//cout << "length:"      << length << endl;
		//cout << "Description:" << NPCDescription[i] << endl;
	}

	//   
	cout << " NPC  [" << numberOfNPC << "]." << endl;
	cout << " NPC ID    ." << endl;
	for (int i=0; i<numberOfNPC; i++)
	{
		cout << "[" << i+1 << "] NPC ID : " << NPCID[i] << " >> ";
		cout << "  : " << templateCount[i] << endl;
	}
	cout << "    [" << totalCount << "]." << endl;
	cout << "NPC    ." << endl << endl;

	file.close();

	/////////////////////////////////////////////////////////////////////////////////////////////
	// SHOP_TEMPLATE  
	/////////////////////////////////////////////////////////////////////////////////////////////
	
	cout << "SHOP_TEMPLATE   ." << endl;
	
	file.open(shop_filename.c_str(), ios::out | ios::binary | ios::trunc);
	if (!file)
	{
		cerr << shop_filename << "   ." << endl;
		return;
	}

	pResult = pStmt->executeQuery("SELECT ID, ShopType, ItemClass, MinItemType, MaxItemType, MinOptionLevel, MaxOptionLevel from ShopTemplate where ShopType in (0, 2)");

	//       ...
	totalNumber = pResult->getRowCount();
	if (totalNumber == 0) 
	{
		cerr << "  ." << endl;
		return;
	}
	file.write("&totalNumber", sizeof(DWORD));

	stCount = 0;
	cout << setw(6)  << "####";
	cout << setw(8)  << "    ID";
	cout << setw(8)  << " RType";
	cout << setw(9) << " IClass";
	cout << setw(11) << " MinIType";
	cout << setw(11) << " MaxIType";
	cout << setw(12) << " MinOLevel";
	cout << setw(12) << " MaxOLevel" << endl;

	//    .
	while (pResult->next())
	{
		ID             = pResult->getUInt(1);
		rackType       = pResult->getBYTE(2);
		itemClass      = pResult->getInt(3);
		minItemType    = pResult->getWORD(4);
		maxItemType    = pResult->getWORD(5);
		minOptionLevel = pResult->getBYTE(6);
		maxOptionLevel = pResult->getBYTE(7);
		
		file.write("&ID",            sizeof(uint));
		file.write("&rackType",      sizeof(BYTE));
		file.write("&itemClass",     sizeof(int));
		file.write("&minItemType",   sizeof(WORD));
		file.write("&maxItemType",   sizeof(WORD));
		file.write("&minOptionLevel", sizeof(BYTE));
		file.write("&maxOptionLevel", sizeof(BYTE));

		cout << setw(6)  << (int)stCount+1;
		cout << setw(8)  << (int)ID;
		cout << setw(8) << (int)rackType;
		cout << setw(9) << (int)itemClass;
		cout << setw(11) << (int)minItemType;
		cout << setw(11) << (int)maxItemType;
		cout << setw(12) << (int)minOptionLevel;
		cout << setw(12) << (int)maxOptionLevel << endl;
				
		stCount++;
	}

	cout << "    " << totalNumber << "." << endl;
	cout << " SHOP_TEMPLATE  ." << endl;

	SAFE_DELETE(pStmt);

	file.close();
}

