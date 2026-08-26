//////////////////////////////////////////////////////////////////////////////
// Filename    : ServerItemInfo.h
// Written by  : excel96
// Description : 
//        .
//////////////////////////////////////////////////////////////////////////////

#ifndef __SERVERITEMINFO_H__
#define __SERVERITEMINFO_H__

#include "Types.h"
#include <map>
#include <list>

enum ItemStyle
{
	ITEM_STYLE_NORMAL,
	ITEM_STYLE_UNIQUE,

	ITEM_STYLE_MAX
};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
enum ItemClass
{
	ITEM_CLASS_MOTORCYCLE,            //  0
	ITEM_CLASS_POTION,                //  1
	ITEM_CLASS_WATER,                 //  2
	ITEM_CLASS_HOLYWATER,             //  3
	ITEM_CLASS_MAGAZINE,              //  4
	ITEM_CLASS_BOMB_MATERIAL,         //  5
	ITEM_CLASS_ETC,                   //  6
	ITEM_CLASS_KEY,                   //  7
	ITEM_CLASS_RING,                  //  8
	ITEM_CLASS_BRACELET,              //  9
	ITEM_CLASS_NECKLACE,              // 10
	ITEM_CLASS_COAT,                  // 11
	ITEM_CLASS_TROUSER,               // 12
	ITEM_CLASS_SHOES,                 // 13
	ITEM_CLASS_SWORD,                 // 14
	ITEM_CLASS_BLADE,                 // 15
	ITEM_CLASS_SHIELD,                // 16
	ITEM_CLASS_CROSS,                 // 17
	ITEM_CLASS_GLOVE,                 // 18
	ITEM_CLASS_HELM,                  // 19
	ITEM_CLASS_SG,                    // 20
	ITEM_CLASS_SMG,                   // 21
	ITEM_CLASS_AR,                    // 22
	ITEM_CLASS_SR,                    // 23
	ITEM_CLASS_BOMB,                  // 24
	ITEM_CLASS_MINE,                  // 25
	ITEM_CLASS_BELT,                  // 26
	ITEM_CLASS_LEARNINGITEM,          // 27
	ITEM_CLASS_MONEY,                 // 28
	ITEM_CLASS_CORPSE,                // 29
	ITEM_CLASS_VAMPIRE_RING,          // 30
	ITEM_CLASS_VAMPIRE_BRACELET,      // 31
	ITEM_CLASS_VAMPIRE_NECKLACE,      // 32
	ITEM_CLASS_VAMPIRE_COAT,          // 33
	ITEM_CLASS_SKULL,                 // 34
	ITEM_CLASS_MACE,                  // 35
	ITEM_CLASS_SERUM,                 // 36
	ITEM_CLASS_VAMPIRE_ETC,           // 37
	ITEM_CLASS_SLAYER_PORTAL_ITEM,    // 38
	ITEM_CLASS_VAMPIRE_PORTAL_ITEM,   // 39
	ITEM_CLASS_EVENT_GIFT_BOX,        // 40
	ITEM_CLASS_EVENT_STAR,            // 41
	ITEM_CLASS_VAMPIRE_EARRING,       // 42
	ITEM_CLASS_RELIC,                 // 43
	ITEM_CLASS_VAMPIRE_WEAPON,        // 44
	ITEM_CLASS_VAMPIRE_AMULET,        // 45
	ITEM_CLASS_QUEST_ITEM,        	  // 46
	ITEM_CLASS_EVENT_TREE,			// 47
	ITEM_CLASS_EVENT_ETC,			// 48
	ITEM_CLASS_BLOOD_BIBLE,			// 49
	ITEM_CLASS_CASTLE_SYMBOL,		// 50
	ITEM_CLASS_COUPLE_RING,			// 51
	ITEM_CLASS_VAMPIRE_COUPLE_RING,	// 52			
	ITEM_CLASS_EVENT_ITEM,			// 53
	ITEM_CLASS_DYE_POTION,			// 54
	ITEM_CLASS_RESURRECT_ITEM,		// 55
	ITEM_CLASS_MIXING_ITEM,			// 56
	ITEM_CLASS_OUSTERS_ARMSBAND,     // 57
	ITEM_CLASS_OUSTERS_BOOTS,        // 58
	ITEM_CLASS_OUSTERS_CHAKRAM,      // 59
	ITEM_CLASS_OUSTERS_CIRCLET,      // 60
	ITEM_CLASS_OUSTERS_COAT,         // 61
	ITEM_CLASS_OUSTERS_PENDENT,      // 62
	ITEM_CLASS_OUSTERS_RING,         // 63
	ITEM_CLASS_OUSTERS_STONE,        // 64
	ITEM_CLASS_OUSTERS_WRISTLET,     // 65
	ITEM_CLASS_LARVA,                // 66
	ITEM_CLASS_PUPA,                 // 67
	ITEM_CLASS_COMPOS_MEI,           // 68
	ITEM_CLASS_OUSTERS_SUMMON_ITEM,  // 69
	ITEM_CLASS_EFFECT_ITEM,			 // 70
	ITEM_CLASS_CODE_SHEET,			 // 71
	ITEM_CLASS_MOON_CARD,			 // 72
	ITEM_CLASS_SWEEPER,				 // 73
	ITEM_CLASS_PET_ITEM,			 // 74
	ITEM_CLASS_PET_FOOD,             // 75
	ITEM_CLASS_PET_ENCHANT_ITEM,     // 76
	ITEM_CLASS_LUCKY_BAG,			 // 77
    	ITEM_CLASS_SMS_ITEM,             // 78
	ITEM_CLASS_CORE_ZAP,             // 79
	ITEM_CLASS_GQUEST_ITEM,          // 80
	ITEM_CLASS_TRAP_ITEM,			 // 81
	ITEM_CLASS_BLOOD_BIBLE_SIGN,     // 82
	ITEM_CLASS_WAR_ITEM,			 // 83 
	ITEM_CLASS_CARRYING_RECEIVER,    // 84
	ITEM_CLASS_SHOULDER_ARMOR,       // 85
	ITEM_CLASS_DERMIS,               // 86
	ITEM_CLASS_PERSONA,              // 87
	ITEM_CLASS_FASCIA,               // 88
	ITEM_CLASS_MITTEN,               // 89
	ITEM_CLASS_SUB_INVENTORY,		 // 90
	ITEM_CLASS_COMMON_QUEST_ITEM ,   // 91 
	ITEM_CLASS_ETHEREAL_CHAIN	  ,	 // 92 
	ITEM_CLASS_OUSTERS_HARMONIC_PENDENT , // 93
	ITEM_CLASS_CHECK_MONEY,			 // 94
	ITEM_CLASS_CUE_OF_ADAM ,		 // 95
	ITEM_CLASS_CONTRACT_OF_BLOOD,	 // 96
	ITEM_CLASS_SKILL_BOOK,			 // 97
	ITEM_CLASS_VAMPIREWING_ITEM,	 // 98
	ITEM_CLASS_OUSTERSWING_ITEM,	 // 99
	ITEM_CLASS_TUNING_SLAYER,		// 100
	ITEM_CLASS_TUNING_VAMPIRE,		// 101
	ITEM_CLASS_TUNING_OUSTERS,		// 102
	ITEM_CLASS_CALLNPC_CARD,		// 103
//	ITEM_CLASS_DARKNESS_OF_LILITH,		// 104
	ITEM_CLASS_MAX                    // 47
};

const string ItemClass2String[] = 
{
	"ITEM_CLASS_MOTORCYCLE",
	"ITEM_CLASS_POTION",
	"ITEM_CLASS_WATER",
	"ITEM_CLASS_HOLYWATER",
	"ITEM_CLASS_MAGAZINE",
	"ITEM_CLASS_BOMB_MATERIAL",
	"ITEM_CLASS_ETC",
	"ITEM_CLASS_KEY",
	"ITEM_CLASS_RING",
	"ITEM_CLASS_BRACELET",
	"ITEM_CLASS_NECKLACE",
	"ITEM_CLASS_COAT",
	"ITEM_CLASS_TROUSER",
	"ITEM_CLASS_SHOES",
	"ITEM_CLASS_SWORD",
	"ITEM_CLASS_BLADE",
	"ITEM_CLASS_SHIELD",
	"ITEM_CLASS_CROSS",
	"ITEM_CLASS_GLOVE",
	"ITEM_CLASS_HELM",
	"ITEM_CLASS_SG",
	"ITEM_CLASS_SMG",
	"ITEM_CLASS_AR",
	"ITEM_CLASS_SR",
	"ITEM_CLASS_BOMB",
	"ITEM_CLASS_MINE",
	"ITEM_CLASS_BELT",
	"ITEM_CLASS_LEARNINGITEM",
	"ITEM_CLASS_MONEY",
	"ITEM_CLASS_CORPSE",
	"ITEM_CLASS_VAMPIRE_RING",
	"ITEM_CLASS_VAMPIRE_BRACELET",
	"ITEM_CLASS_VAMPIRE_NECKLACE",
	"ITEM_CLASS_VAMPIRE_COAT",
	"ITEM_CLASS_SKULL",
	"ITEM_CLASS_MACE",
	"ITEM_CLASS_SERUM",
	"ITEM_CLASS_VAMPIRE_ETC",
	"ITEM_CLASS_SLAYER_PORTAL_ITEM",
	"ITEM_CLASS_VAMPIRE_PORTAL_ITEM", 
	"ITEM_CLASS_EVENT_GIFT_BOX",
	"ITEM_CLASS_EVENT_STAR",
	"ITEM_CLASS_VAMPIRE_EARRING",
	"ITEM_CLASS_RELIC",
	"ITEM_CLASS_VAMPIRE_WEAPON",
	"ITEM_CLASS_VAMPIRE_AMULET",
	"ITEM_CLASS_QUEST_ITEM",
	"ITEM_CLASS_EVENT_TREE",           // 47
	"ITEM_CLASS_EVENT_ETC",            // 48
	"ITEM_CLASS_BLOOD_BIBLE",		   // 49
	"ITEM_CLASS_CASTLE_SYMBOL",		   // 50
	"ITEM_CLASS_COUPLE_RING",		   // 51
	"ITEM_CLASS_VAMPIRE_COUPLE_RING",  // 52
	"ITEM_CLASS_EVENT_ITEM",  		   // 53
	"ITEM_CLASS_DYE_POTION",  		   // 54
	"ITEM_CLASS_RESURRECT_ITEM",	   // 55
	"ITEM_CLASS_MIXING_ITEM",	   	   // 56
	"ITEM_CLASS_OUSTERS_ARMSBAND",	   // 57
	"ITEM_CLASS_OUSTERS_BOOTS",	   	   // 58
	"ITEM_CLASS_OUSTERS_CHAKRAM",	   // 59
	"ITEM_CLASS_OUSTERS_CIRCLET",  	   // 60
	"ITEM_CLASS_OUSTERS_COAT",	   	   // 61
	"ITEM_CLASS_OUSTERS_PENDENT",  	   // 62
	"ITEM_CLASS_OUSTERS_RING",	   	   // 63
	"ITEM_CLASS_OUSTERS_STONE",	   	   // 64
	"ITEM_CLASS_OUSTERS_WRISTLET", 	   // 65
	"ITEM_CLASS_LARVA", 			   // 66
	"ITEM_CLASS_PUPA", 			 	   // 67
	"ITEM_CLASS_COMPOS_MEI",	 	   // 68
	"ITEM_CLASS_OUSTERS_SUMMON_ITEM",  // 69
	"ITEM_CLASS_EFFECT_ITEM",  		   // 70
	"ITEM_CLASS_CODE_SHEET",  		   // 71
	"ITEM_CLASS_MOON_CARD",			   // 72
	"ITEM_CLASS_SWEEPER",			   // 73
	"ITEM_CLASS_PET_ITEM",			   // 74
	"ITEM_CLASS_PET_FOOD",			   // 75
	"ITEM_CLASS_PET_ENCHANT_ITEM",	   // 76
	"ITEM_CLASS_LUCKY_BAG",            // 77
	"ITEM_CLASS_SMS_ITEM",             // 78
	"ITEM_CLASS_CORE_ZAP",				// 79
	"ITEM_CLASS_GQUEST_ITEM",			// 80
	"ITEM_CLASS_TRAP_ITEM",				// 81
	"ITEM_CLASS_BLOOD_BIBLE_SIGN",		// 82
	"ITEM_CLASS_WAR_ITEM",				// 83
	"ITEM_CLASS_CARRYING_RECEIVER",		// 84
	"ITEM_CLASS_SHOULDER_ARMOR",		// 85
	"ITEM_CLASS_DERMIS",				// 86
	"ITEM_CLASS_PERSONA",				// 87
	"ITEM_CLASS_FASCIA",				// 88
	"ITEM_CLASS_MITTEN",				// 89
	"ITEM_CLASS_SUB_INVENTORY",			// 90
	"ITEM_CLASS_COMMON_QUEST_ITEM",		// 91
	"ITEM_CLASS_ETHEREAL_CHAIN",		// 92
	"ITEM_CLASS_OUSTERS_HARMONIC_PENDENT", // 93
	"ITEM_CLASS_CHECK_MONEY",			// 94
	"ITEM_CLASS_CUE_OF_ADAM",			// 95
	"ITEM_CLASS_CONTACT_OF_BLOOD",		// 96
	"ITEM_CLASS_SKILL_BOOK",			// 97
	"ITEM_CLASS_VAMPIRE_WING_ITEM",			// 98
	"ITEM_CLASS_OUSTERS_WING_ITEM",		// 99
	"ITEM_CLASS_SLAYER_TUNNING_ITEM",	// 100
	"ITEM_CLASS_VAMPIRE_TUNNING_ITEM",	// 101
	"ITEM_CLASS_OUSTERS_TUNNING_ITEM"	// 102
	"ITEM_CLASS_CALLNPC_CARD",			// 103
//	"ITEM_CLASS_DARKNESS_OF_LILITH",		// 104
	"ITEM_CLASS_MAX"
};

const string ItemClassTableName[] = 
{
	"MotorcycleInfo",
	"PotionInfo",
	"WaterInfo",
	"HolyWaterInfo",
	"MagazineInfo",
	"BombMaterialInfo",
	"ETCInfo",
	"KeyInfo",
	"RingInfo",
	"BraceletInfo",
	"NecklaceInfo",
	"CoatInfo",
	"TrouserInfo",
	"ShoesInfo",
	"SwordInfo",
	"BladeInfo",
	"ShieldInfo",
	"CrossInfo",
	"GloveInfo",
	"HelmInfo",
	"SGInfo",
	"SMGInfo",
	"ARInfo",
	"SRInfo",
	"BombInfo",
	"MineInfo",
	"BeltInfo",
	"LearningItemInfo",
	"MoneyInfo",
	"", // CorpseInfo .
	"VampireRingInfo",
	"VampireBraceletInfo",
	"VampireNecklaceInfo",
	"VampireCoatInfo",
	"SkullInfo",
	"MaceInfo",
	"SerumInfo",
	"VampireETCInfo",
	"SlayerPortalItemInfo",
	"VampirePortalItemInfo",
	"EventGiftBoxInfo",
	"EventStarInfo",
	"VampireEarringInfo",
	"RelicInfo",
	"VampireWeaponInfo",
	"VampireAmuletInfo",
	"QuestItemInfo",
	"EventTreeInfo",				  // 47
	"EventETCInfo",				  // 48
	"BloodBibleInfo",				  // 49
	"CastleSymbolInfo",			  // 50
	"CoupleRingInfo",				  // 51
	"VampireCoupleRingInfo",		  // 52
	"EventItemInfo",		  		  // 53
	"DyePotionInfo",		  		  // 54
	"ResurrectItemInfo",			  // 55
	"MixingItemInfo",				  // 56
	"OustersArmsbandInfo",	  	  // 57
	"OustersBootsInfo",			  // 58
	"OustersChakramInfo",			  // 59
	"OustersCircletInfo",			  // 60
	"OustersCoatInfo",			  // 61
	"OustersPendentInfo",			  // 62
	"OustersRingInfo",			  // 63
	"OustersStoneInfo",			  // 64
	"OustersWristletInfo",		  // 65
	"LarvaInfo",		  			  // 66
	"PupaInfo",		  			  // 67
	"ComposMeiInfo",				  // 68
	"OustersSummonItemInfo",		  // 69
	"EffectItemInfo",				  // 70
	"CodeSheetInfo",				  // 71
	"MoonCardInfo",				  // 72
	"SweeperInfo",				  // 73
	"PetItemInfo",				  // 74
	"PetFoodInfo",				  // 75
	"PetEnchantItemInfo",			  // 76
	"LuckyBagInfo",	              // 77
	"SMSItemInfo",	              // 78
	"CoreZapInfo",	              // 79
	"GQuestItemInfo",               // 80
	"TrapItemInfo",				  // 81
	"BloodBibleSignInfo",							   	  // 82
	"WarItemInfo",			   	  // 83
	"CarryingReceiverInfo",		// 84
	"ShoulderArmorInfo",			// 85
	"DermisInfo",					// 86
	"PersonaInfo",				// 87
	"FasciaInfo",					// 88
	"MittenInfo",					// 89
	"SubInventoryInfo",			// 90
	"CommonQuestItemInfo",		// 91
	"EtherealChainInfo",			// 92
	"OustersHarmonicPendentInfo",		// 93
	"CheckMoneyInfo",				// 94
	"CueOfAdamInfo",				// 95
	"ContractOfBloodInfo",		// 96
	"SkillBookInfo",				// 97
	"VampireWingItemInfo",		// 98
	"OustersWingItemInfo",		// 99
	"SlayerTunningItemInfo",		// 100
	"VampireTunningItemInfo",		// 101
	"OustersTunningItemInfo",		// 102
	"CallNPCCardInfo",			// 103
//	"DarknessOfLilithInfo",
};

struct ITEM_INFO
{
	int HNameSize; string HName; // 0
	int ENameSize; string EName; // 1
	int DescriptionSize; string Description; // 2
	int Weight; // 3
	int Price; // 4
	int Durability; // 5
	int GridWidth; int GridHeight; // 6
	int Defense; // 7
	int MinDamage; // 8
	int MaxDamage; // 9
	int MPPlus; // 10
	int Range; // 11
	int Bullet; // 12
	int ToHitBonus; // 13
	int MotorCarry; // 14
	int HPRecover; int MPRecover; // 15
	int Pocket; // 16
	int ReqS; int ReqD; int ReqI; int ReqSum; int ReqL; int ReqG; int ReqA; // 17
	int MaxSilver; // 18
	int Speed; // 19
	int Protection; // 20
	int MaxCharge; // 21
	int CriticalBonus; // 22
	int DefaultOptionSize; list<int> DefaultOptions;	// 23
	int UpgradeCrashPercent; // 24
	int ItemStyle; // 25

	int ElementalType;  // 26
	int Elemental;  // 27
	int Race;  // 28
	int TunningItemClass;	//29
	int TunningItemType;	//30
	int MagicProtection;	//31


};

const int ITEM_INFO_FIELD_MAX = 32;

const string FieldName[] = 
{
	"Name",          // 0
	"EName",         // 1
	"Description",   // 2
	"Weight",        // 3
	"Price",         // 4
	"Durability",    // 5
	"Volume",        // 6
	"Defense",       // 7
	"minDamage",     // 8
	"maxDamage",     // 9
	"MPBonus",       // 10
	"Range",         // 11
	"MaxBullets",    // 12
	"ToHitBonus",    // 13
	"CC",            // 14
	"Effect",        // 15
	"PocketCount",   // 16
	"ReqAbility",    // 17
	"MaxSilver",     // 18
	"Speed",         // 19
	"Protection",    // 20
	"MaxCharge",     // 21
	"CriticalBonus", // 22
	"DefaultOption",  // 23
	"UpgradeCrashPercent",  // 24
	"ItemStyle", // 25
	"ElementalType",  // 25
	"Elemental",  // 26
	"Race",  // 27
	"TunningItemClass",  // 28
	"TunningItemType",  // 29
	"MagicProtection"  // 30
};


//////////////////////////////////////////////////////////////////////////////
//        ,  
//  ID  .
//////////////////////////////////////////////////////////////////////////////
int getFieldNameID(string name);

//////////////////////////////////////////////////////////////////////////////
// ITEM_INFO  .
//////////////////////////////////////////////////////////////////////////////
void initItemInfo(ITEM_INFO& info);

//////////////////////////////////////////////////////////////////////////////
// ITEM_INFO     .
//////////////////////////////////////////////////////////////////////////////
void outputItemInfo(ITEM_INFO& info);

//////////////////////////////////////////////////////////////////////////////
// ITEM_INFO    .
//////////////////////////////////////////////////////////////////////////////
void writeItemInfo(ofstream& file, ITEM_INFO& info);

//////////////////////////////////////////////////////////////////////////////
//     ReqAbility   
//   .
//////////////////////////////////////////////////////////////////////////////
void parseReqAbility(string req, int&reqSTR, int& reqDEX, int& reqINT, int& reqSum, int& reqLevel, int& reqGender, int& reqAdvLevel);

//////////////////////////////////////////////////////////////////////////////
// DefaultOptions string optionType intList .
//////////////////////////////////////////////////////////////////////////////
void parseDefaultOptions(const string& options, list<int>& intList);

//////////////////////////////////////////////////////////////////////////////
//     Effect  
//   .
//////////////////////////////////////////////////////////////////////////////
void parseEffect(string effect, int& hp, int& mp);

//////////////////////////////////////////////////////////////////////////////
// ServerItemInfo.inf  .
//////////////////////////////////////////////////////////////////////////////
void createServerItemInfoFile(const string& filename);

//////////////////////////////////////////////////////////////////////////////
// parseDefaultOptions .
//////////////////////////////////////////////////////////////////////////////
void initOptionNicknames();
int getOptionType(const string& nickname);
extern map<string, int> g_OptionNicknames;

//////////////////////////////////////////////////////////////////////////////
// Item Style
//////////////////////////////////////////////////////////////////////////////
void initItemStyles();
ItemStyle getItemStyle(int itemClass, int itemType);
typedef map<int, ItemStyle> STYLE_MAP;
typedef map<int, STYLE_MAP> ITEM_STYLE_MAP;
extern ITEM_STYLE_MAP g_ItemStyles;
extern string ItemStyleToString[ITEM_STYLE_MAX];

#endif

