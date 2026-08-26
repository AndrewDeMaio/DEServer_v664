//////////////////////////////////////////////////////////////////////////////
// Filename    : ServerItemInfo.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "ServerItemInfo.h"
#include "DB.h"
#include "Utility.h"
#include "StringStream.h"
#include <list>
#include <map>

map<string, int> 	g_OptionNicknames;
ITEM_STYLE_MAP 		g_ItemStyles;

string ItemStyleToString[ITEM_STYLE_MAX] =
{
	"Normal",
	"Unique"
};


void initOptionNicknames()
{
	g_OptionNicknames.clear();

	StringStream sql;

	Statement* pStmt = g_pConnection->createStatement();

	Result* pResult = pStmt->executeQuery("SELECT OptionType, Nickname FROM OptionInfo");
	
	while (pResult->next())
	{
		int optionType = pResult->getInt(1);
		string nickname = pResult->getString(2);

		g_OptionNicknames[nickname] = optionType;
	}

	SAFE_DELETE(pStmt);
}

int getOptionType(const string& nickname)
{
	map<string, int>::const_iterator iInt = g_OptionNicknames.find(nickname);

	if (iInt!=g_OptionNicknames.end())
	{
		return iInt->second;
	}

	return 0;
}

void initItemStyles()
{
	Statement* pStmt = NULL;

	pStmt = g_pConnection->createStatement();

	// DB   .
	Result* pResult = pStmt->executeQuery("SELECT ItemClass, ItemType FROM UniqueItemInfo");

	//  itemClas, itemType Unique Item .
	while (pResult->next())
	{
		int itemClass = pResult->getInt(1);
		int itemType  = pResult->getInt(2);

		g_ItemStyles[itemClass][itemType] = ITEM_STYLE_UNIQUE;
	}

	SAFE_DELETE(pStmt);
}

ItemStyle getItemStyle(int itemClass, int itemType)
{
	ITEM_STYLE_MAP::const_iterator iStyleMap = g_ItemStyles.find( itemClass );

	if (iStyleMap==g_ItemStyles.end())
		return ITEM_STYLE_NORMAL;

	STYLE_MAP::const_iterator iStyle = g_ItemStyles[itemClass].find( itemType );

	if (iStyle==g_ItemStyles[itemClass].end())
		return ITEM_STYLE_NORMAL;

	return iStyle->second;
}

//////////////////////////////////////////////////////////////////////////////
//        ,  
//  ID  .
//////////////////////////////////////////////////////////////////////////////
int getFieldNameID(string name)
{
	for (int i=0; i<ITEM_INFO_FIELD_MAX; i++)
		if (name == FieldName[i]) return i;
	return -1;
}

//////////////////////////////////////////////////////////////////////////////
// ITEM_INFO  .
//////////////////////////////////////////////////////////////////////////////
void initItemInfo(ITEM_INFO& info)
{
	info.HNameSize       = 0;
	info.HName           = "";
	info.ENameSize       = 0;
	info.EName           = "";
	info.DescriptionSize = 0;
	info.Description     = "";
	info.Weight          = -1;
	info.Price           = -1;
	info.Durability      = -1;
	info.GridWidth       = -1;
	info.GridHeight      = -1;
	info.Defense         = -1;
	info.MinDamage       = -1;
	info.MaxDamage       = -1;
	info.MPPlus          = -1;
	info.Range           = -1;
	info.Bullet          = -1;
	info.ToHitBonus      = -1;
	info.MotorCarry      = -1;
	info.HPRecover       = -1;
	info.MPRecover       = -1;
	info.Pocket          = -1;
	info.ReqS            = 0;
	info.ReqD            = 0;
	info.ReqI            = 0;
	info.ReqSum          = 0;
	info.ReqL            = 0;
	info.ReqG            = 0;
	info.ReqA            = 0;
	info.MaxSilver       = -1;
	info.Speed           = -1;
	info.Protection      = -1;
	info.MaxCharge       = -1;
	info.CriticalBonus   = -1;
	info.DefaultOptionSize   = 0;
	info.DefaultOptions.clear();
	info.UpgradeCrashPercent = 0;
	info.ItemStyle = (int)ITEM_STYLE_NORMAL;

	info.ElementalType = -1;
	info.Elemental = -1;
	info.Race = -1;
	info.TunningItemClass = -1;
	info.TunningItemType = -1;
	info.MagicProtection = -1;



}

//////////////////////////////////////////////////////////////////////////////
// ITEM_INFO     .
//////////////////////////////////////////////////////////////////////////////
void outputItemInfo(ITEM_INFO& info)
{
	cout << "HNameSize:" << info.HNameSize;
	cout << " HName:" << info.HName;
	cout << " ENameSize:" << info.ENameSize;
	cout << " EName:" << info.EName;
	cout << " DescriptionSize:" << info.DescriptionSize;
	cout << " Description:" << info.Description;
	cout << " Weight:" << info.Weight;
	cout << " Price:" << info.Price;
	cout << " Durability:" << info.Durability;
	cout << " GridWidth:" << info.GridWidth;
	cout << " GridHeight:" << info.GridHeight;
	cout << " Defense:" << info.Defense;
	cout << " MinDamage:" << info.MinDamage;
	cout << " MaxDamage:" << info.MaxDamage;
	cout << " MPPlus:" << info.MPPlus;
	cout << " Range:" << info.Range;
	cout << " Bullet:" << info.Bullet;
	cout << " ToHitBonus:" << info.ToHitBonus;
	cout << " Motorcarry:" << info.MotorCarry;
	cout << " HPRecover:" << info.HPRecover;
	cout << " MPRecover:" << info.MPRecover;
	cout << " Pocket:" << info.Pocket;
	cout << " ReqSTR:" << info.ReqS;
	cout << " ReqDEX:" << info.ReqD;
	cout << " ReqINT:" << info.ReqI;
	cout << " ReqSum:" << info.ReqSum;
	cout << " ReqLevel:" << info.ReqL;
	cout << " ReqGender:" << info.ReqG;
	cout << " ReqADVLevel:" << info.ReqA;
	cout << " MaxSilver:" << info.MaxSilver;
	cout << " Speed:" << info.Speed;
	cout << " Protection:" << info.Protection;
	cout << " MaxCharge:" << info.MaxCharge;
	cout << " CriticalBonus:" << info.CriticalBonus;

	if (info.DefaultOptionSize!=0)
	{
		cout << " DefaultOptions[" << info.DefaultOptionSize << "] = ";
		list<int>::const_iterator iInt;
		for (iInt=info.DefaultOptions.begin(); iInt!=info.DefaultOptions.end(); iInt++)
		{
			int option = *iInt;
			cout << " " << option;
		}
		cout << endl;
	}

	cout << " UpgradeCrashPercent:" << info.UpgradeCrashPercent;


	cout << " ItemStyle:" << ItemStyleToString[info.ItemStyle];

	cout << " ElementalType:" << info.ElementalType;
	cout << " Elemental:" << info.Elemental;
	cout << " Race:" << info.Race;

	cout << " TunningItemClass:" << info.TunningItemClass;
	cout << " TunningItemType:" << info.TunningItemType;
	cout << " MagicProtection:" << info.MagicProtection<< endl;

}

//////////////////////////////////////////////////////////////////////////////
// ITEM_INFO    .
//////////////////////////////////////////////////////////////////////////////
void writeItemInfo(ofstream& file, ITEM_INFO& info)
{
	file.write("&(info.HNameSize          )", sizeof(int));
	file.write( "(info.HName.c_str()      )", info.HNameSize);
	file.write("&(info.ENameSize          )", sizeof(int));
	file.write( "(info.EName.c_str()      )", info.ENameSize);
	file.write("&(info.DescriptionSize    )", sizeof(int));
	file.write( "(info.Description.c_str())", info.DescriptionSize);
	file.write("&(info.Weight             )", sizeof(int));
	file.write("&(info.Price              )", sizeof(int));
	file.write("&(info.Durability         )", sizeof(int));
	file.write("&(info.GridWidth          )", sizeof(int));
	file.write("&(info.GridHeight         )", sizeof(int));
	file.write("&(info.Defense            )", sizeof(int));
	file.write("&(info.MinDamage          )", sizeof(int));
	file.write("&(info.MaxDamage          )", sizeof(int));
	file.write("&(info.MPPlus             )", sizeof(int));
	file.write("&(info.Range              )", sizeof(int));
	file.write("&(info.Bullet             )", sizeof(int));
	file.write("&(info.ToHitBonus         )", sizeof(int));
	file.write("&(info.MotorCarry         )", sizeof(int));
	file.write("&(info.HPRecover          )", sizeof(int));
	file.write("&(info.MPRecover          )", sizeof(int));
	file.write("&(info.Pocket             )", sizeof(int));
	file.write("&(info.ReqS               )", sizeof(int));
	file.write("&(info.ReqD               )", sizeof(int));
	file.write("&(info.ReqI               )", sizeof(int));
	file.write("&(info.ReqSum             )", sizeof(int));
	file.write("&(info.ReqL               )", sizeof(int));
	file.write("&(info.ReqG               )", sizeof(int));
	file.write("&(info.ReqA               )", sizeof(int));
	file.write("&(info.MaxSilver          )", sizeof(int));
	file.write("&(info.Speed              )", sizeof(int));
	file.write("&(info.Protection         )", sizeof(int));
	file.write("&(info.MaxCharge          )", sizeof(int));
	file.write("&(info.CriticalBonus      )", sizeof(int));
	file.write("&(info.UpgradeCrashPercent  )", sizeof(int));

	file.write("&(info.DefaultOptionSize  )", sizeof(int));

	list<int>::const_iterator iInt;
	for (iInt=info.DefaultOptions.begin(); iInt!=info.DefaultOptions.end(); iInt++)
	{
		int option = *iInt;
		file.write("&option", sizeof(int));
	}

	file.write("&(info.ItemStyle  )", sizeof(int));

	file.write("&(info.ElementalType  )", sizeof(int));
	file.write("&(info.Elemental  )", sizeof(int));
	file.write("&(info.Race  )", sizeof(int));

	file.write("&(info.TunningItemClass  )", sizeof(int));
	file.write("&(info.TunningItemType  )", sizeof(int));
	file.write("&(info.MagicProtection  )", sizeof(int));


}

//////////////////////////////////////////////////////////////////////////////
//    , ReqAbility   
//   .
//////////////////////////////////////////////////////////////////////////////
void parseReqAbility(string req, int&reqSTR, int& reqDEX, int& reqINT, int& reqSum, int& reqLevel, int& reqGender, int& reqAdvLevel)
{
	size_t a = 0, b = 0, c = 0;
	
	reqSTR    = 0;
	reqDEX    = 0;
	reqINT    = 0;
	reqSum    = 0;
	reqLevel  = 0;
	reqGender = 0;
	reqAdvLevel = 0;

	cout << "Requirements[" << req << "]" << endl;

	while (c < req.size() - 1)
	{
		a = req.find_first_of('(', c);
		b = req.find_first_of(',', a+1);
		c = req.find_first_of(')', b+1);

		////////////////////////////////////////////////////////
		//           11111
		// 012345678901234
		// (GEN,1)(SUM,30)
		//        a   b  c       
		////////////////////////////////////////////////////////

		if (a > b || b > c) break;

		string identifier = req.substr(a+1, b-a-1);
		int reqAbility = atoi(req.substr(b+1, c-b-1).c_str());

		if (identifier == "STR")      { reqSTR = reqAbility; }
		else if (identifier == "DEX") { reqDEX = reqAbility; }
		else if (identifier == "INT") { reqINT = reqAbility; }
		else if (identifier == "SUM") { reqSum = reqAbility; }
		else if (identifier == "LEV") { reqLevel = reqAbility; }
		else if (identifier == "GEN") { reqGender = reqAbility; }
		else if (identifier == "ADV") { reqAdvLevel = reqAbility; }
		else
		{
			cout << "========================================================" << endl;
			cout << "unknown required ability!" << endl;
			cout << "========================================================" << endl;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
//     Effect  
//   .
//////////////////////////////////////////////////////////////////////////////
void parseEffect(string effect, int& hp, int& mp)
{
	if (effect.size() < 6) return;

	size_t a = 0, b = 0, c = 0, d = 0, e  = 0;
	
	hp = 0;
	mp = 0;

	while (e < effect.size() - 1)
	{
		a = effect.find_first_of('(', e);
		b = effect.find_first_of(',', a+1);
		c = effect.find_first_of(',', b+1);
		d = effect.find_first_of(',', c+1);
		e = effect.find_first_of(')', d+1);

		if (a > b || b > c || c > d || d > e) break;

		string recover =       effect.substr(a+1, b-a-1);
		uint   amount  = atoi( effect.substr(b+1, c-b-1).c_str() );
		uint   delay   = atoi( effect.substr(c+1, d-c-1).c_str() );
		uint   unit    = atoi( effect.substr(d+1, e-d-1).c_str() );

		delay = delay; // warning 
		unit = unit;

		if (recover == "HP")      hp = (int)amount;
		else if (recover == "MP") mp = (int)amount;
	}
}

void parseDefaultOptions(const string& options, list<int>& intList)
{
	size_t a = 0, b = 0;

	intList.clear();

	//////////////////////////////////////////////
	// DEX+1,INT+2
	// a     ba     b
	//////////////////////////////////////////////
	if (options.size()<=1)
	{
		return;
	}

	do
	{
		b = options.find_first_of(',', a);

		string  optionName = trim( options.substr(a, b-a) );

		int optionType;
		
		optionType = getOptionType( optionName );

		if (optionType!=0)
			intList.push_back( optionType );

		a = b+1;

	} while (b!=string::npos && b < options.size() -1);
}

//////////////////////////////////////////////////////////////////////////////
// ServerItemInfo.inf  .
//////////////////////////////////////////////////////////////////////////////
void createServerItemInfoFile(const string& filename)
{
	initOptionNicknames();
	initItemStyles();

	ofstream file(filename.c_str(), ios::out | ios::binary | ios::trunc);
	if (!file)
	{
		StringStream msg;
		msg << "Cannot open [" << filename << "] for write!";
		cerr << msg.toString() << endl;
		return;
	}

	Statement*  pStmt          = NULL;
	Result*     pResult        = NULL;
	int         LastFieldIndex = -1;
	bool        bFieldExist[ITEM_INFO_FIELD_MAX];
	string      sql;
	ITEM_INFO   itemInfo;
	int         itemClassMax;
	int         itemTypeMax;

	//////////////////////////////////////////////////////////////////////
	//      ...
	//////////////////////////////////////////////////////////////////////
	itemClassMax = ITEM_CLASS_MAX;
	file.write("&itemClassMax", sizeof(int));
	
	for (int i=0; i<ITEM_CLASS_MAX; i++)
	{
		//////////////////////////////////////////////////////////////////////
		//   ...
		//////////////////////////////////////////////////////////////////////
		for (int j=0; j<ITEM_INFO_FIELD_MAX; j++)
		{
			bFieldExist[j] = false;
		}
		initItemInfo(itemInfo);
		LastFieldIndex = -1;

		//////////////////////////////////////////////////////////////////////
		//    DB  
		//////////////////////////////////////////////////////////////////////
		if (i == ITEM_CLASS_CORPSE)
		{
			itemTypeMax = 1;;
			file.write("&itemTypeMax", sizeof(int));

			itemInfo.HName = "";
			itemInfo.HNameSize = itemInfo.HName.size();
			itemInfo.EName = "Corpse";
			itemInfo.ENameSize = itemInfo.EName.size();
			itemInfo.Description = "";
			itemInfo.DescriptionSize = itemInfo.Description.size();

			writeItemInfo(file, itemInfo);
			continue;
		}

		//////////////////////////////////////////////////////////////////////
		// table   .
		//////////////////////////////////////////////////////////////////////
		pStmt = g_pConnection->createStatement();
		pResult = pStmt->executeQuery("DESC %s", ItemClassTableName[i].c_str());

		while (pResult->next())
		{
			string name = pResult->getString(1);
			int    id   = getFieldNameID(name);

			if (id >= 0) 
			{
				bFieldExist[id] = true;
				if (id > LastFieldIndex) LastFieldIndex  = id;
			}
		}
		SAFE_DELETE(pStmt);

		//cout << "LastFieldIndex( " << ItemClassTableName[i].c_str() << " ) = " << LastFieldIndex << endl;

		//////////////////////////////////////////////////////////////////////
		//   .
		//////////////////////////////////////////////////////////////////////
		sql = "SELECT ";
		for (int k=0; k<ITEM_INFO_FIELD_MAX; k++)
		{
			if (bFieldExist[k])
			{
				sql += FieldName[k];
				if (k == LastFieldIndex) sql += " ";
				else                     sql += ",";
			}
		}
		sql += "FROM " + ItemClassTableName[i];
		cout << sql << endl;

		pStmt   = g_pConnection->createStatement();
		pResult = pStmt->executeQuery(sql);
	
		//////////////////////////////////////////////////////////////////////
		//      .
		//////////////////////////////////////////////////////////////////////
		itemTypeMax = pResult->getRowCount();
		file.write("&itemTypeMax", sizeof(int));

		int itemType = 0;

		while (pResult->next())
		{
			int resultCount = 0;

			if (bFieldExist[0]) // Name
			{
				resultCount++;
				itemInfo.HName     = pResult->getString(resultCount);
				itemInfo.HNameSize = itemInfo.HName.size();
			}
			if (bFieldExist[1]) // EName
			{
				resultCount++;
				itemInfo.EName     = pResult->getString(resultCount);
				itemInfo.ENameSize = itemInfo.EName.size();
			}
			if (bFieldExist[2]) // Description
			{
				resultCount++;
				itemInfo.Description = pResult->getString(resultCount);
				itemInfo.DescriptionSize = itemInfo.Description.size();
			}
			if (bFieldExist[3]) // Weight
			{
				resultCount++;
				itemInfo.Weight = pResult->getInt(resultCount);
			}
			if (bFieldExist[4]) // Price
			{
				resultCount++;
				itemInfo.Price = pResult->getInt(resultCount);
			}
			if (bFieldExist[5]) // Durability
			{
				resultCount++;
				itemInfo.Durability = pResult->getInt(resultCount);
			}
			if (bFieldExist[6]) // Volume
			{
				resultCount++;
				int volumeType = pResult->getInt(resultCount);
				switch (volumeType)
				{
					case 0: itemInfo.GridWidth = 0; itemInfo.GridHeight = 0; break;
					case 1: itemInfo.GridWidth = 1; itemInfo.GridHeight = 1; break;
					case 2: itemInfo.GridWidth = 1; itemInfo.GridHeight = 2; break;
					case 3: itemInfo.GridWidth = 1; itemInfo.GridHeight = 3; break;
					case 4: itemInfo.GridWidth = 2; itemInfo.GridHeight = 1; break;
					case 5: itemInfo.GridWidth = 2; itemInfo.GridHeight = 2; break;
					case 6: itemInfo.GridWidth = 2; itemInfo.GridHeight = 3; break;
					default:
						cerr << "Unknown VOLUME TYPE!" << endl;
						return;
				}
			}
			if (bFieldExist[7]) // ACBonus
			{
				resultCount++;
				itemInfo.Defense = pResult->getInt(resultCount);
			}
			if (bFieldExist[8]) // minDamage
			{
				resultCount++;
				itemInfo.MinDamage = pResult->getInt(resultCount);
			}
			if (bFieldExist[9]) // maxDamage
			{
				resultCount++;
				itemInfo.MaxDamage = pResult->getInt(resultCount);
			}
			if (bFieldExist[10]) // MPBonus
			{
				resultCount++;
				itemInfo.MPPlus = pResult->getInt(resultCount);
			}
			if (bFieldExist[11]) // Range
			{
				resultCount++;
				itemInfo.Range = pResult->getInt(resultCount);
			}
			if (bFieldExist[12]) // MaxBullets
			{
				resultCount++;
				itemInfo.Bullet = pResult->getInt(resultCount);
			}
			if (bFieldExist[13]) // ToHitBonus
			{
				resultCount++;
				itemInfo.ToHitBonus = pResult->getInt(resultCount);
			}
			if (bFieldExist[14]) // CC
			{
				resultCount++;
				itemInfo.MotorCarry = pResult->getInt(resultCount);
			}
			if (bFieldExist[15]) // Effect
			{
				resultCount++;
				string effect = pResult->getString(resultCount);
				int hp, mp;
				parseEffect(effect, hp, mp);

				itemInfo.HPRecover = hp;
				itemInfo.MPRecover = mp;

				cout << "HP Recover : " << hp;
				cout << " MP Recover : " << mp << endl;
			}
			if (bFieldExist[16]) // PocketCount
			{
				resultCount++;
				itemInfo.Pocket = pResult->getInt(resultCount);
			}
			if (bFieldExist[17]) // ReqAbility
			{
				resultCount++;
				string reqability = pResult->getString(resultCount);
				int str, dex, inte, sum, level, gender, advlevel;
				parseReqAbility(reqability, str, dex, inte, sum, level, gender, advlevel);
				itemInfo.ReqS   = str;
				itemInfo.ReqD   = dex;
				itemInfo.ReqI   = inte;
				itemInfo.ReqSum = sum;
				itemInfo.ReqL   = level;
				itemInfo.ReqG   = gender;
				itemInfo.ReqA   = advlevel;
			}
			if (bFieldExist[18]) // MaxSilver
			{
				resultCount++;
				itemInfo.MaxSilver = pResult->getInt(resultCount);
			}
			if (bFieldExist[19]) // Speed
			{
				resultCount++;
				itemInfo.Speed = pResult->getInt(resultCount);
			}
			if (bFieldExist[20]) // Protection
			{
				resultCount++;
				itemInfo.Protection = pResult->getInt(resultCount);
			}
			if (bFieldExist[21]) // MaxCharge
			{
				resultCount++;
				itemInfo.MaxCharge = pResult->getInt(resultCount);
			}
			if (bFieldExist[22]) // CriticalBonus
			{
				resultCount++;
				itemInfo.CriticalBonus = pResult->getInt(resultCount);
			}

			if (bFieldExist[23]) // DefaultOptions
			{
				resultCount++;
				string defaultOptions = pResult->getString(resultCount);

				itemInfo.DefaultOptions.clear();
				parseDefaultOptions(defaultOptions, itemInfo.DefaultOptions);

				itemInfo.DefaultOptionSize = itemInfo.DefaultOptions.size();
			}
			if (bFieldExist[24]) // DefaultOptions
			{
				resultCount++;
				itemInfo.UpgradeCrashPercent = pResult->getInt(resultCount);


			}
			if (bFieldExist[25]) // DefaultOptions
			{
			itemInfo.ItemStyle = (int)getItemStyle( i, itemType );


			}


			if (bFieldExist[26]) // DefaultOptions
			{
				resultCount++;
				itemInfo.ElementalType = pResult->getInt(resultCount);
			}
			if (bFieldExist[27]) // DefaultOptions
			{
				resultCount++;
				itemInfo.Elemental = pResult->getInt(resultCount);
			}
			if (bFieldExist[28]) // DefaultOptions
			{
				resultCount++;
				itemInfo.Race = pResult->getInt(resultCount);
			}

			if (bFieldExist[29]) // DefaultOptions
			{
				resultCount++;
				itemInfo.TunningItemClass = pResult->getInt(resultCount);
			}

			if (bFieldExist[30]) // DefaultOptions
			{
				resultCount++;
				itemInfo.TunningItemType = pResult->getInt(resultCount);
			}
			if (bFieldExist[31]) // DefaultOptions
			{
				resultCount++;
				itemInfo.MagicProtection = pResult->getInt(resultCount);
			}





			//////////////////////////////////////////////////////////////////////
			// DB    .
			//////////////////////////////////////////////////////////////////////
			writeItemInfo(file, itemInfo);
			outputItemInfo(itemInfo);

			itemType++;
		}

		SAFE_DELETE(pStmt);
	}
}

