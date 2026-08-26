//////////////////////////////////////////////////////////////////////////////
// Filename    : CLCreatePCHandler.cc
// Written By  :
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "CLCreatePC.h"

#ifdef __LOGIN_SERVER__
	#include "LoginPlayer.h"
	#include "PCSlayerInfo.h"
	#include "Assert.h"
	#include "GameServerInfoManager.h"
	#include "DB.h"
	#include <list>
	#include "Lpackets/LCCreatePCOK.h"
	#include "Lpackets/LCCreatePCError.h"
	#include <string.h>

	#include "chinabilling/CBillingInfo.h"
	#include "SystemAvailabilitiesManager.h"
	#include "Utility.h"

	#include "Properties.h"
#endif

#include <vector>

bool isAvailableID(const char* pID);
bool isAvailableCharName(const char* pID);
#ifdef __LOGIN_SERVER__
void freeInactiveCharName(Statement* pStmt, const string& name);
#endif

#ifdef __THAILAND_SERVER__
// tis620 charset filter functions
int extNumberic(string srcStr);
int extEnglish(string srcStr);
int extAsciiSpecial(string srcStr);
int extTis620Normal(string srcStr);
bool isAllowString(string str);
#endif

#ifdef __CHINA_SERVER__
// GB2312(simple chinese) charset filter functions 
int extNumberic(string srcStr);
int extEnglish(string srcStr);
int extGb2312Normal(string srcStr);
int extGb2312Special(string srcStr);
int extAsciiSpecial(string srcStr);
bool isAllowString(string str);
#endif


class GiveItem	
{
public :
	GiveItem(int iGoodID, int iGoodCount)
	{
		m_iGoodID = iGoodID;
		m_iGoodCount = iGoodCount;
	}

	int m_iGoodID;
	int m_iGoodCount;
};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void CLCreatePCHandler::execute (CLCreatePC* pPacket , Player* pPlayer)
	 throw (ProtocolException , Error)
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
		
#ifdef __LOGIN_SERVER__

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

#ifdef __GLOBAL_SERVER__
	SYSTEM_BEGIN_IF_NOT(SYSTEM_CREATE_OUSTERS)
	{
		if ( pPacket->getRace() == RACE_OUSTERS )
			return;
	}
	SYSTEM_END
#endif

	LoginPlayer*    pLoginPlayer = dynamic_cast<LoginPlayer*>(pPlayer);
	Statement*      pStmt        = NULL;
	Statement*      pLoginStmt   = NULL;
	Result*         pResult      = NULL;
	Statement*      pStmt2       = NULL;
	Result*         pResult2     = NULL;
	LCCreatePCError lcCreatePCError;
	WorldID_t		WorldID      = pLoginPlayer->getWorldID();

	string connectIP = pLoginPlayer->getSocket()->getHost();
	string strName = pPacket->getName();
	int iSlot = pPacket->getSlot() + 1;

    // SQL Injection 방어
    if ( CheckSQLInjectionString(strName) )
    {
        lcCreatePCError.setErrorID(ETC_ERROR);

        filelog("Attack_SQLInjection.log", "%s CLCreatePC : [PlayerID=%s Name=%s Slot=%d]",
       		connectIP.c_str(),
			pPlayer->getID().c_str(), 
			strName.c_str(),
			iSlot
		);
        
        return;
    }
    
    if ( (iSlot < 1) ||(iSlot > SLOT_MAX) )
    {
    	lcCreatePCError.setErrorID(ETC_ERROR);
    	
    	filelog("Attack_DataManipulation.log", "%s CLCreatePC : [PlayerID=%s Name=%s Slot=%d]",
   			connectIP.c_str(),
			pPlayer->getID().c_str(), 
			strName.c_str(),
			iSlot
		);
    	
    	return;
    }
    
#ifdef __METRO_SERVER__
	// 서버 통합용 임시 땜빵 코드
	// 트랜실베니아가 아닐 경우 신규 계정(2005년12월26일 이후 생성)만 케릭 생성이 가능하다.
	/*if ( WorldID != 2 )
	{
		BEGIN_DB
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			pResult = pStmt->executeQuery( "SELECT PlayerID FROM Player WHERE PlayerID = '%s' AND creation_date > '2005-12-14'", pLoginPlayer->getID().c_str() );

			if ( pResult->getRowCount() == 0 )
			{
				lcCreatePCError.setErrorID( NOT_AVAILABLE );
				pLoginPlayer->sendPacket( &lcCreatePCError );

				SAFE_DELETE(pStmt);
				return;
			}
		}
		END_DB(pStmt)
	}*/
#endif

#ifdef __CONNECT_CBILLING_SYSTEM__
	if ( pLoginPlayer->isCBillingVerified() )
	{
		if ( !pLoginPlayer->isPayPlayer() )
		{
			lcCreatePCError.setErrorID( CANNOT_CREATE_PC_BILLING );
			pLoginPlayer->sendPacket( &lcCreatePCError );
			return;
		}
	}
	else
	{
		lcCreatePCError.setErrorID( CANNOT_AUTHORIZE_BILLING );
		pLoginPlayer->sendPacket( &lcCreatePCError );
		return;
	}
#endif

	try 
	{
		pStmt = g_pDatabaseManager->getConnection( WorldID )->createStatement();
		pLoginStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		// 시스템에서 사용하거나, 금지된 이름은 아닌기 검증한다.
		// NONE, ZONE***, INV***, QUICK...
		//string text = pPacket->getName();

		if (!isAvailableID( pPacket->getName().c_str() ))
		{
			lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
			throw DuplicatedException("이미 존재하는 아이디입니다.");
		}

		if ( pPacket->getName().find(" ") != string::npos ||
			 pPacket->getName().find((char)0xFF) != string::npos ||
			 !isAvailableCharName( pPacket->getName().c_str() ))
		{
			lcCreatePCError.setErrorID(ETC_ERROR);
	        throw DuplicatedException("허용하지 않는 문자가 포함되어 있음");
		}
		
		/*
		list<string>::const_iterator itr = InvalidTokenList.begin();
		for (; itr != InvalidTokenList.end(); itr++)
		{
			if (text.find(*itr) != string::npos)
			{
				lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
				throw DuplicatedException("이미 존재하는 아이디입니다.");
			}
		}
		*/
#if defined(__THAILAND_SERVER__) || defined(__CHINA_SERVER__)

        /*
         * 태국어 문자셋 tis620 thailand charset 에서 허용하는 문자만을 케릭터 이름으로
         * 쓸 수 있도록 제어한다.
         *
         * */

         /*
         * 중국어 문자코드셋 gb2312-simple chinese 에서 허용하는 문자만을 케릭터 이름으로
         * 쓸 수 있도록 제어한다.
         *
         * */

       string tmpStr = pPacket->getName();
        bool isAllowStr = isAllowString(tmpStr);

        if(isAllowStr == false)
        {
            lcCreatePCError.setErrorID(ETC_ERROR);
            throw DuplicatedException("허용하지 않는 문자가 포함되어 있음");

        }

#endif

		// 이미 존재하는 캐릭터 이름이 아닌지 검증한다.
		///*
		// Only a LIVE character blocks the name. A soft-deleted one is renamed
		// out of the way below so the name can be reused.
		//
		// This checks all three races. It used to look at Slayer only, which let
		// a Slayer be created with the same name as a live Vampire or Ousters --
		// and because item ownership is keyed by NAME (OwnerID), two live
		// characters sharing one name share their items.
		pResult = pStmt->executeQuery(
			"SELECT Name FROM Slayer  WHERE Name='%s' AND Active='ACTIVE'"
			" UNION ALL SELECT Name FROM Vampire WHERE Name='%s' AND Active='ACTIVE'"
			" UNION ALL SELECT Name FROM Ousters WHERE Name='%s' AND Active='ACTIVE'",
			pPacket->getName().c_str(), pPacket->getName().c_str(), pPacket->getName().c_str());
		if (pResult->getRowCount() != 0) 
		{
			lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
			throw DuplicatedException("이미 존재하는 아이디입니다.");
		}

		// 해당 슬랏에 캐릭터가 이미 있지는 않은지 검증한다.
		pResult = pStmt->executeQuery("SELECT Name FROM Slayer WHERE PlayerID ='%s' and Slot ='%s' AND Active='ACTIVE'", pLoginPlayer->getID().c_str(), Slot2String[pPacket->getSlot()].c_str() );
		if (pResult->getRowCount() != 0) 
		{
			lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
			throw DuplicatedException("이미 존재하는 아이디입니다.");
		}

		// The name is free of live characters. If soft-deleted ones still hold
		// it, rename them (and everything keyed to them) out of the way now, so
		// the new character does not inherit a dead character's items.
		freeInactiveCharName(pStmt, pPacket->getName());
		//*/
		// 두 쿼리를 하나로. 2002. 7. 13 by sigi. 이거 안좋다. - -;
		/*
		pResult = pStmt->executeQuery("SELECT Name FROM Slayer WHERE Name='%s' OR PlayerID='%s' AND Slot='%s'", 
											pPacket->getName().c_str(), 
											pLoginPlayer->getID().c_str(), 
											Slot2String[pPacket->getSlot()].c_str() );

		if (pResult->getRowCount() != 0) 
		{
			lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
			throw DuplicatedException("이미 존재하는 아이디입니다.");
		}
		*/

#ifdef __METRO_SERVER__
		// 서버 통합용 임시 땜빵 코드
		// 서버 통합 신청 테이블에서 신청된 캐릭명이 있는지 검사한다.
		if ( WorldID != 2 )
		{
			pResult = pStmt->executeQuery( "SELECT FixName FROM NameChange WHERE FixName = '%s'", pPacket->getName().c_str() );

			if ( pResult->getRowCount() != 0 )
			{
				lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
				throw DuplicatedException("이미 존재하는 아이디입니다.");
			}

/*			pResult = pStmt->executeQuery( "SELECT NewName FROM ChangeWorld WHERE NewName = '%s'", pPacket->getName().c_str() );

			if ( pResult->getRowCount() != 0 )
			{
				lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
				throw DuplicatedException("이미 존재하는 아이디입니다.");
			}

			pResult = pStmt->executeQuery( "SELECT NewName FROM WebTemp WHERE NewName = '%s'", pPacket->getName().c_str() );
			
			if ( pResult->getRowCount() != 0 )
			{
				lcCreatePCError.setErrorID(ALREADY_REGISTER_ID);
				throw DuplicatedException("이미 존재하는 아이디입니다.");
			}*/
		}
#endif

		// 잘못된 능력치를 가지고 캐릭터를 생성하려 하는 것은 아닌지 검증한다.
		

		bool bInvalidAttr = false;
		int  nSTR         = pPacket->getSTR();
		int  nSTRExp      = 0;
		int  nSTRGoalExp  = 0;
		int  nDEX         = pPacket->getDEX();
		int  nDEXExp      = 0;
		int  nDEXGoalExp  = 0;
		int  nINT         = pPacket->getINT();
		int  nINTExp      = 0;
		int  nINTGoalExp  = 0;

		//int  Rank         = 1;
		//int  RankExp      = 0;

		// 
		static int  RankGoalExpSlayer  = -1;
		static int  GoalExpVampire  = -1;	// by sigi. 2002.12.20
		static int  RankGoalExpVampire  = -1;
		static int  GoalExpOusters = -1;
		static int  RankGoalExpOusters = -1;

		if (RankGoalExpSlayer==-1)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM RankEXPInfo WHERE Level=1 AND RankType=0");
			if (pResult->next()) RankGoalExpSlayer = pResult->getInt(1);
		}

		if (GoalExpVampire==-1)	// by sigi. 2002.12.20
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM VampEXPBalanceInfo WHERE Level=1");
			if (pResult->next()) GoalExpVampire = pResult->getInt(1);
		}

		if (GoalExpOusters==-1)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM OustersEXPBalanceInfo WHERE Level=1");
			if (pResult->next()) GoalExpOusters = pResult->getInt(1);
		}

		if (RankGoalExpVampire==-1)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM RankEXPInfo WHERE Level=1 AND RankType=1");
			if (pResult->next()) RankGoalExpVampire = pResult->getInt(1);
		}

		if (RankGoalExpOusters==-1)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM RankEXPInfo WHERE Level=1 AND RankType=2");
			if (pResult->next()) RankGoalExpOusters = pResult->getInt(1);
		}

		if (pPacket->getRace() == RACE_SLAYER)
		{
			if (nSTR < 5 || nSTR > 20)  bInvalidAttr = true;
			if (nDEX < 5 || nDEX > 20)  bInvalidAttr = true;
			if (nINT < 5 || nINT > 20)  bInvalidAttr = true;
			if (nSTR + nDEX + nINT > 30) bInvalidAttr = true;

			//cout << "Slayer: " << nSTR << ", " << nDEX << ", " << nINT << endl;
		}
		else if ( pPacket->getRace() == RACE_VAMPIRE )	// vampire인 경우. 무조건 20. by sigi. 2002.10.31
		{
			if (nSTR != 20
				|| nDEX != 20
				|| nINT != 20) 
			{
				bInvalidAttr = true;
			}
			else
			{
				// 정상적인 vampire인 경우
				// Slayer의 능력치를 다시 설정해줘야 한다. -_-;
				// by sigi. 2002.11.7
				nSTR = 5 + rand()%16;	// 5~20
				nDEX = 5 + rand()%(21-nSTR);
				nINT = 30 - nSTR - nDEX;

				pPacket->setSTR(nSTR);
				pPacket->setDEX(nDEX);
				pPacket->setINT(nINT);
			}
			// 

			//cout << "Vampire: " << nSTR << ", " << nDEX << ", " << nINT << endl;
		}
		else if ( pPacket->getRace() == RACE_OUSTERS )
		{
/*			if ( nSTR < 10 ) bInvalidAttr = true;
			if ( nDEX < 10 ) bInvalidAttr = true;
			if ( nINT < 10 ) bInvalidAttr = true;*/

			if ( nSTR < 10 || nDEX < 10 || nINT < 10 )
			{
				filelog("CreatePC.log", "Illegal PC Create [%s:%s] : %u/%u/%u", pPlayer->getID().c_str(), pPacket->getName().c_str(), nSTR, nDEX, nINT);
			}

			if ( nSTR + nDEX + nINT != 45 )
				bInvalidAttr = true;
		}

		if (bInvalidAttr)
		{
			SAFE_DELETE(pStmt);
			throw InvalidProtocolException("CLCreatePCHandler::too large character attribute");
		}

		// 모든 검사를 만족했다면 이제 캐릭터를 생성한다.
		ServerGroupID_t CurrentServerGroupID = pPlayer->getServerGroupID();

		// 우헤헤.. 일단 쿼리를 줄일려고 static으로 삽질을 했다.
		// 나중에 아예 로그인 서버 뜰때에 경험치 table들을 loading해 두도록해야할 것이다. 2002.7.13 by sigi
		static int STRGoalExp[100] = { 0, }; 
		static int STRAccumExp[100] = { 0, };
		static int DEXGoalExp[100] = { 0, }; 
		static int DEXAccumExp[100] = { 0, };
		static int INTGoalExp[100] = { 0, };
		static int INTAccumExp[100] = { 0, };

		nSTRGoalExp = STRGoalExp[nSTR];
		if (nSTRGoalExp==0)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM STRBalanceInfo WHERE Level = %d", nSTR);
			if (pResult->next()) nSTRGoalExp = STRGoalExp[nSTR] = pResult->getInt(1);
		}

		nSTRExp = STRAccumExp[nSTR-1];
		if (nSTRExp==0)
		{
			pResult = pStmt->executeQuery("SELECT AccumExp FROM STRBalanceInfo WHERE Level = %d", nSTR - 1);
			if (pResult->next()) nSTRExp = STRAccumExp[nSTR-1] = pResult->getInt(1);
		}

		nDEXGoalExp = DEXGoalExp[nDEX];
		if (nDEXGoalExp==0)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM DEXBalanceInfo WHERE Level = %d", nDEX);
			if (pResult->next()) nDEXGoalExp = DEXGoalExp[nDEX] = pResult->getInt(1);
		}

		nDEXExp = DEXAccumExp[nDEX-1];
		if (nDEXExp==0)
		{
			pResult = pStmt->executeQuery("SELECT AccumExp FROM DEXBalanceInfo WHERE Level = %d", nDEX - 1);
			if (pResult->next()) nDEXExp = DEXAccumExp[nDEX-1] = pResult->getInt(1);
		}

		nINTGoalExp = INTGoalExp[nINT];
		if (nINTGoalExp==0)
		{
			pResult = pStmt->executeQuery("SELECT GoalExp FROM INTBalanceInfo WHERE Level = %d", nINT);
			if (pResult->next()) nINTGoalExp = INTGoalExp[nINT] = pResult->getInt(1);
		}

		nINTExp = INTAccumExp[nINT-1];
		if (nINTExp==0)
		{
			pResult = pStmt->executeQuery("SELECT AccumExp FROM INTBalanceInfo WHERE Level = %d", nINT - 1);
			if (pResult->next()) nINTExp = INTAccumExp[nINT-1] = pResult->getInt(1);
		}

		// 일단 복장은 없고.. 남/녀 구분만..
		DWORD slayerShape = (pPacket->getSex()==1? 1 : 0);
		DWORD vampireShape = slayerShape;

		slayerShape |= (pPacket->getHairStyle() << PCSlayerInfo::SLAYER_BIT_HAIRSTYLE1);

		Color_t	HelmetColor = 0;
		Color_t JacketColor = 0;
		Color_t	PantsColor  = 0;
		Color_t	WeaponColor = 0;
		Color_t	ShieldColor = 0;

		/*
		StringStream slayerSQL;
		slayerSQL << "INSERT INTO Slayer ("
			<< " Race, Name, PlayerID, Slot, ServerGroupID, Active,"
			<< " Sex, HairStyle, HairColor, SkinColor, Phone, "
			<< " STR, STRExp, STRGoalExp, DEX, DEXExp, DEXGoalExp, INTE, INTExp, INTGoalExp, HP, CurrentHP, MP, CurrentMP,"
			<< " ZoneID, XCoord, YCoord, Sight, Gold, Alignment,"
			<< " Shape, HelmetColor, JacketColor, PantsColor, WeaponColor, ShieldColor,"
			<< " creation_date) VALUES ('"
			<< "SLAYER" << "', '"
			<< pPacket->getName() << "', '"
			<< pLoginPlayer->getID() << "', '"
			<< Slot2String[pPacket->getSlot()] << "', "
			<< (int)CurrentServerGroupID << " , "
			<< "'ACTIVE', '"
			<< Sex2String[pPacket->getSex()] << "', '"
			<< HairStyle2String[pPacket->getHairStyle()] << "', "
			<< (int)pPacket->getHairColor() << ", "
			<< (int)pPacket->getSkinColor() << ", '"
			<< (int)0 << "', "
			<< (int)pPacket->getSTR() << ", "
			<< nSTRExp << ", "
			<< nSTRGoalExp << ", "
			<< (int)pPacket->getDEX() << ", "
			<< nDEXExp << ", "
			<< nDEXGoalExp << ", "
			<< (int)pPacket->getINT() << ", "
			<< nINTExp << ", "
			<< nINTGoalExp << ", "
			<< (int)pPacket->getSTR()*2 << ","
			<< (int)pPacket->getSTR()*2 << ","
			<< (int)pPacket->getINT()*2 << ","
			<< (int)pPacket->getINT()*2 << ","
			<< "2101, 65, 45, 13, 0, 7500, "
			<< slayerShape << ", "
			<< (int)HelmetColor << ", "
			<< (int)JacketColor << ", "
			<< (int)PantsColor << ", "
			<< (int)WeaponColor << ", "
			<< (int)ShieldColor << ", "
			<< "now() "
			<< ")";

		StringStream vampireSQL;
		vampireSQL << "INSERT INTO Vampire ("
			<< " Name, PlayerID, Slot, ServerGroupID, Active,"
			<< " Sex, HairColor, SkinColor,"
			<< " STR, DEX, INTE, HP, CurrentHP,"
			<< " ZoneID, XCoord, YCoord, Sight, Alignment, Exp, GoalExp, Shape) VALUES ('"
			<< pPacket->getName() << "', '"
			<< pLoginPlayer->getID() << "', '"
			<< Slot2String[pPacket->getSlot()] << "', "
			<< (int)CurrentServerGroupID << " , "
			<< "'ACTIVE', '"
			<< Sex2String[pPacket->getSex()] << "', "
			<< (int)pPacket->getHairColor() << ", "
			<< (int)pPacket->getSkinColor() << ", "
			<< "20, 20, 20, 50, 50, "
			<< "2020, 233, 55, 13, 7500, 0, 125, "
			<< vampireShape
			<< ")";

		pStmt->executeQuery(slayerSQL.toString());
		pStmt->executeQuery(vampireSQL.toString());
		*/

		// 캐릭터 생성시에 뱀파이어를 선택할 수 있다.
		// by sigi. 2002.10.31
		string race;
		switch ( pPacket->getRace() )
		{
			case RACE_SLAYER:
				race = "SLAYER";
				break;
			case RACE_VAMPIRE:
				race = "VAMPIRE";
				break;
			case RACE_OUSTERS:
				race = "OUSTERS";
				break;
			default:
				cout << "send CLCreatePCError : " << "종족 선택 에러" << endl;

				lcCreatePCError.setErrorID(ETC_ERROR);
				pLoginPlayer->sendPacket(&lcCreatePCError); // 클라이언트에게 PC 생성 실패 패킷을 날린다.
				return;
		}

		// 2006.2.22 Slayer의 시작 위치 X=237, Y=138에서 X=209, Y=104로 변경 되었음.
		pStmt->executeQuery(
				"INSERT INTO Slayer (Race, Name, PlayerID, Slot, ServerGroupID, Active, Sex, HairStyle, HairColor, SkinColor, Phone, STR, STRExp, STRGoalExp, DEX, DEXExp, DEXGoalExp, INTE, INTExp, INTGoalExp, `Rank`, RankExp, RankGoalExp, HP, CurrentHP, MP, CurrentMP, ZoneID, XCoord, YCoord, Sight, Gold, Alignment, Shape, HelmetColor, JacketColor, PantsColor, WeaponColor, ShieldColor, creation_date) VALUES ('%s', '%s', '%s', '%s', %d, 'ACTIVE', '%s', '%s', %d, %d, 0, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, 12, 209, 104, 13, 0, 7500, %d, %d, %d, %d, %d, %d, now())",
				race.c_str(),
				pPacket->getName().c_str(), 
				pLoginPlayer->getID().c_str(), 
				Slot2String[pPacket->getSlot()].c_str(), 
				(int)CurrentServerGroupID,
				Sex2String[pPacket->getSex()].c_str(), 
				HairStyle2String[pPacket->getHairStyle()].c_str(), 
				(int)pPacket->getHairColor(), 
				(int)pPacket->getSkinColor(),
				(int)pPacket->getSTR(), nSTRExp, nSTRGoalExp, 
				(int)pPacket->getDEX(), nDEXExp, nDEXGoalExp, 
				(int)pPacket->getINT(), nINTExp, nINTGoalExp,
				1, 0, RankGoalExpSlayer,
				(int)pPacket->getSTR()*2,
				(int)pPacket->getSTR()*2,
				(int)pPacket->getINT()*2,
				(int)pPacket->getINT()*2,
				slayerShape,
				(int)HelmetColor,
				(int)JacketColor,
				(int)PantsColor,
				(int)WeaponColor,
				(int)ShieldColor);

		// 생성 위치 변경. by sigi. 2002.10.31
		// 아우스터스로의 종족간 변신이 없으므로 둘중에 하나만 만든다.
		// 근데 왠지 종족간 변신이 들어갈지도 모른다는 불길한 예간이 들고
		// 항상 그런 예감들은 맞아 왔기때문에 언젠가 이 주석을 보고 둘다 풀어주는게....으아~~
		if (  pPacket->getRace() != RACE_OUSTERS )
		{
			pStmt->executeQuery(
					"INSERT INTO Vampire ( Name, PlayerID, Slot, ServerGroupID, Active, Sex, SkinColor, STR, DEX, INTE, HP, CurrentHP, ZoneID, XCoord, YCoord, Sight, Alignment, Exp, GoalExp, `Rank`, RankExp, RankGoalExp, Shape, CoatColor) VALUES ( '%s', '%s', '%s', %d, 'ACTIVE', '%s', %d, 20, 20, 20, 50, 50, 1003, 62, 64, 13, 7500, 0, %d, 1, 0, %d, %d, 377 )",
					pPacket->getName().c_str(),
					pLoginPlayer->getID().c_str(),
					Slot2String[pPacket->getSlot()].c_str(),
					(int)CurrentServerGroupID,
					Sex2String[pPacket->getSex()].c_str(),
					(int)pPacket->getSkinColor(),
					GoalExpVampire,	// by sigi. 2002.12.20
					RankGoalExpVampire,
					vampireShape);
		} else
		{
			pStmt->executeQuery(
					"INSERT INTO Ousters ( Name, PlayerID, Slot, ServerGroupID, Active, Sex, STR, DEX, INTE, BONUS, HP, CurrentHP, MP, CurrentMP, ZoneID, XCoord, YCoord, Sight, Alignment, Exp, GoalExp, `Rank`, RankExp, RankGoalExp, CoatColor, HairColor, ArmColor, BootsColor ) Values ( '%s', '%s', '%s', %d, 'ACTIVE', 'FEMALE', %d, %d, %d, 0, 50, 50, 50, 50, 1311, 24, 73, 13, 7500, 0, %d, 1, 0,	%d, 377, %d, 377, 377 )",
					pPacket->getName().c_str(),
					pLoginPlayer->getID().c_str(),
					Slot2String[pPacket->getSlot()].c_str(),
					(int)CurrentServerGroupID,
					(int)pPacket->getSTR(),
					(int)pPacket->getDEX(),
					(int)pPacket->getINT(),
					GoalExpOusters,
					RankGoalExpOusters,
					(int)pPacket->getHairColor() );
		}

		if (pPacket->getRace()==RACE_SLAYER)
		{
			pStmt->executeQuery("INSERT IGNORE INTO FlagSet (OwnerID, FlagData) VALUES ('%s','11110010001')", pPacket->getName().c_str());
		}
		else
		{
			pStmt->executeQuery("INSERT IGNORE INTO FlagSet (OwnerID, FlagData) VALUES ('%s','00000010001')", pPacket->getName().c_str());
		}

		// 클라이언트에게 PC 생성 성공 패킷을 날린다.
		LCCreatePCOK lcCreatePCOK;
		pLoginPlayer->sendPacket(&lcCreatePCOK);
		pLoginPlayer->setPlayerStatus(LPS_WAITING_FOR_CL_GET_PC_LIST);

	} 
	catch (DuplicatedException & de) 
	{
		SAFE_DELETE(pStmt);
		SAFE_DELETE(pLoginStmt);
		pLoginPlayer->sendPacket(&lcCreatePCError); // 클라이언트에게 PC 생성 실패 패킷을 날린다.
	} 
	catch (SQLQueryException & sqe) 
	{
		SAFE_DELETE(pStmt);
		SAFE_DELETE(pLoginStmt);
		cout << "send CLCreatePCError : " << "Exception 발생" << endl;

		lcCreatePCError.setErrorID(ETC_ERROR);
		pLoginPlayer->sendPacket(&lcCreatePCError); // 클라이언트에게 PC 생성 실패 패킷을 날린다.
	}
	
	bool IsNewMakePC = false;
	
    BEGIN_DB
    {
        pStmt2 = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
        
        pResult2 = pStmt2->executeQuery(
        	"select unix_timestamp(PayPlayDate) - unix_timestamp(now()) from Player where PlayerID='%s' AND PayPlayDate > now()", 
        	pLoginPlayer->getID().c_str()
    	);
        
        if ( pResult2->getRowCount() == 0 )
        {
        	IsNewMakePC = true;
        }
        else
        {
        	IsNewMakePC = false;
        }

        SAFE_DELETE(pStmt2);
    }
    END_DB(pStmt2)

	//테스트 서버에 들어온 유저가 최초 캐릭터를 생성시에 기록을 남긴다.
	if ( g_pConfig->hasKey("IsTestServer") )
	{
		if(g_pConfig->getPropertyInt("IsTestServer") == 1 && IsNewMakePC == true)
		{
		    BEGIN_DB
			{
				pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
				pResult = pStmt->executeQuery( "SELECT PlayerID FROM MakePCLog WHERE PlayerID = '%s'", pLoginPlayer->getID().c_str() );
		
				if ( pResult->getRowCount() == 0 )
				{
					pStmt->executeQuery( "insert into `MakePCLog`(`PlayerID`,`EndDate`) values ( '%s', NOW() + INTERVAL 5 DAY)", pLoginPlayer->getID().c_str() );
				}
			}
			END_DB(pStmt)
		}
	}
	
	SAFE_DELETE(pStmt);
	SAFE_DELETE(pLoginStmt);
#endif

	__END_DEBUG_EX __END_CATCH
}

#ifdef __LOGIN_SERVER__
//////////////////////////////////////////////////////////////////////////////
// Free a character name that only soft-deleted characters still hold.
//
// This build takes CLDeletePCHandler's #else branch: deleting a character sets
// Active='INACTIVE' and deliberately keeps every row belonging to it. Only the
// CHINA/THAILAND/NETMARBLE builds hard-delete and purge. So a deleted name
// stays taken forever, and simply allowing its reuse would hand the new
// character the dead one's items -- ownership is keyed by NAME, not by any id.
//
// Instead, rename the dead character and everything pointing at it to
//     [D_<hex>]<OriginalName>      e.g. [D_001]Caravice
// Nothing is destroyed, and the form is unreachable for players: brackets and
// '_' both fail isAvailableCharName(), which whitelists a-z A-Z 0-9 and Korean
// only. With names capped at 10 characters and the columns at varchar(32),
// there is room for 18 hex digits before the form could ever overflow.
//////////////////////////////////////////////////////////////////////////////
void
freeInactiveCharName(Statement* pStmt, const string& name)
{
	Result* pResult = pStmt->executeQuery(
		"SELECT Name FROM Slayer  WHERE Name='%s' AND Active='INACTIVE'"
		" UNION ALL SELECT Name FROM Vampire WHERE Name='%s' AND Active='INACTIVE'"
		" UNION ALL SELECT Name FROM Ousters WHERE Name='%s' AND Active='INACTIVE'",
		name.c_str(), name.c_str(), name.c_str());

	// Nobody dead is holding it -- the name was simply unused.
	if (pResult->getRowCount() == 0)
		return;

	// Next suffix is the highest already used for this name, plus one -- one
	// query instead of probing upward from 1.
	//
	// The rows are compared in C++ rather than ordered in SQL on purpose: once
	// the counter passes 0xFFF the hex strings stop being equal width, and
	// string order no longer matches numeric order ('[D_1000]' sorts before
	// '[D_FFF]'). Note '_' is a single-character wildcard in LIKE, so the one
	// in the prefix has to be escaped.
	pResult = pStmt->executeQuery(
		"SELECT Name FROM Slayer  WHERE Name LIKE '[D\_%%]%s'"
		" UNION ALL SELECT Name FROM Vampire WHERE Name LIKE '[D\_%%]%s'"
		" UNION ALL SELECT Name FROM Ousters WHERE Name LIKE '[D\_%%]%s'",
		name.c_str(), name.c_str(), name.c_str());

	unsigned int highest = 0;

	while (pResult->next())
	{
		unsigned int used = 0;

		if (sscanf(pResult->getString(1), "[D_%X]", &used) == 1 && used > highest)
			highest = used;
	}

	char newName[64];
	sprintf(newName, "[D_%03X]%s", highest + 1, name.c_str());

	// The character rows. INACTIVE only -- never rename a live character out
	// from under its player.
	pStmt->executeQuery("UPDATE Slayer  SET Name='%s' WHERE Name='%s' AND Active='INACTIVE'", newName, name.c_str());
	pStmt->executeQuery("UPDATE Vampire SET Name='%s' WHERE Name='%s' AND Active='INACTIVE'", newName, name.c_str());
	pStmt->executeQuery("UPDATE Ousters SET Name='%s' WHERE Name='%s' AND Active='INACTIVE'", newName, name.c_str());

	// Everything else keyed to the character by name. The table list is read
	// from the schema rather than hardcoded: CLDeletePCHandler carries its own
	// list of ~190 OwnerID tables, and a hardcoded copy silently rots as tables
	// are added. Collect first -- the next query invalidates this Result.
	vector<string> tables;

	pResult = pStmt->executeQuery(
		"SELECT TABLE_NAME FROM information_schema.COLUMNS"
		" WHERE TABLE_SCHEMA=DATABASE() AND COLUMN_NAME='OwnerID'");

	while (pResult->next())
		tables.push_back(pResult->getString(1));

	for (uint i = 0; i < tables.size(); i++)
		pStmt->executeQuery("UPDATE `%s` SET OwnerID='%s' WHERE OwnerID='%s'",
			tables[i].c_str(), newName, name.c_str());

	filelog("NameReuse.log", "freed [%s] -> [%s] across %u owner tables",
		name.c_str(), newName, (uint)tables.size());
}

#endif // __LOGIN_SERVER__

bool
isAvailableCharName(const char* pID)
{
	const int minLength = 4;
	const int maxLength = 10;

	int len = 0;

	char strtempID[128];

	strcpy( strtempID, pID );

	char* str = strtempID;
	
	//--------------------------------------------------------
	// 공백이 들어가면 안된다.
	// 길이도 알아낸다. *_*;
	//--------------------------------------------------------
	while (*str != '\0')
	{
		if (*str == ' ')
		{
			return false;
		}

		len++;
		str++;
	}
	//--------------------------------------------------------
	// 길이가 잘못된 경우
	//--------------------------------------------------------
	if (len<minLength || len>maxLength)
	{
		return false;
	}
	//--------------------------------------------------------
	// 첫글자가 숫자이면 안된다.
	//--------------------------------------------------------
	if (strtempID[0]>='0' && strtempID[0]<='9')
	{
		return false;
	}
	//--------------------------------------------------------
	// 한글을 제외한 특수문자가 들어가면 안된다.
	//--------------------------------------------------------
	int bExistHangul = 0;
	int bExistEnglish = 0;

	str = strtempID;
	while (*str != '\0')
	{
		char ch = *str;
		//--------------------------------------------------------
		// 첫 bit가 '1'이면 한글..일까?
		//--------------------------------------------------------
		if (ch & 0x80)
		{
			// 한글이므로 두 byte 다음 거 체크
			str++;

			if (*str=='\0')
			{
				// 다음게 없으면 잘못된 ID이다.
				return false;				
			}

			char strKor[3] = { *str, ch };
			WORD wKor = *(WORD*)strKor;

			if( !( wKor >= 0xB0A1 && wKor < 0xC8FE ) ) {
				return false;
			}

			str++;

			bExistHangul = 1;
		}
		//--------------------------------------------------------
		// 아니면..
		//--------------------------------------------------------
		else
		{
			//--------------------------------------------------------
			// 영어 대소문자..
			//--------------------------------------------------------
			if (ch>='a' && ch<='z' 
				|| ch>='A' && ch<='Z')
			{				
				bExistEnglish = 1;
			}
			//--------------------------------------------------------
			// 숫자거나 
			// 허용된 문자인 경우는 괜찮다..
			//--------------------------------------------------------
			else if (ch>='0' && ch<='9')
			{				
			}
			//--------------------------------------------------------
			// 이상한 문자 쓰면 안된다.				
			//--------------------------------------------------------
			else
			{
				return false;
			}

			str++;

		}
	}
	//--------------------------------------------------------
	// 한글을 사용한 경우에는 영어를 사용할 수 없다.
	//--------------------------------------------------------
	if (bExistHangul && bExistEnglish)
	{
		return false;
	}
	
	return true;
}

bool
isAvailableID(const char* pID)
{
	const int maxInvalidID = 11;
	static const char* invalidID[maxInvalidID] =
	{
		"NONE",
		"관리자",
		"도우미",
		"담당자",
		"운영",
		"기획자",
		"개발자",
		"테스터",
		"직원",
		"GM",
		"NMCH"
	};
	
	// 좀 빠를까. - -; 2002.7.13 by sigi.
	for (int i=0; i<maxInvalidID; i++)
	{
		if (strstr(pID, invalidID[i])!=NULL) 
		{
			return false;
		}
	}

	return true;
}

#ifdef __THAILAND_SERVER__
int extNumberic(string srcStr)
{
    unsigned char   ch;
    int nNumChar    = 0;

    if(srcStr.size() <= 0 ) return 0;
    else
    {
        for ( unsigned int i=0; i < srcStr.size(); i++ )
        {
            ch = srcStr[i];
            if(ch >= '0' && ch <='9')
            {
                if(i == 0) { return -1; }
                else { nNumChar++; }
            }
        }
    }

    return nNumChar;
}
int extEnglish(string srcStr)
{
    unsigned char   ch;
    int nEngChar    = 0;

    if(srcStr.size() <= 0 ) return 0;
    else
    {
        for (  unsigned int i=0; i < srcStr.size(); i++)
        {
            ch = srcStr[i];
            if(ch >=97 && ch <=122)
            {
                nEngChar++;
            }
            else if(ch >=65 && ch <=90)
            {
                nEngChar++;
            }
        }
    }

    return nEngChar;
}
int extAsciiSpecial(string srcStr)
{
    unsigned char   ch;
    int nASPCChar   = 0;

    if(srcStr.size() <= 0 ) return 0;
    else
    {
        for ( int i=0; i < srcStr.size(); i++)
        {
            ch = srcStr[i];

            if(ch >=0x00 && ch <=47)
            {
                nASPCChar++;
            }
            else if(ch >=58 && ch <=64)
            {
                nASPCChar++;
            }
            else if(ch >=91 && ch <=96)
            {
                nASPCChar++;
            }
            else if(ch >=123 && ch <=160)
            {
                nASPCChar++;
            }
            else if(ch >=219 && ch <=222)
            {
                nASPCChar++;
            }
            else if(ch >=252)
            {
                nASPCChar++;
            }

        }
    }

    return nASPCChar;
}
int extTis620Normal(string srcStr)
{
    unsigned char   ch;
    int nNorChar   = 0;

    if(srcStr.size() <= 0 ) return 0;
    else
    {
        for ( int i=0; i < srcStr.size(); i++)
        {
            ch = srcStr[i];

            if(ch >=161  && ch <=218 )
            {
                nNorChar++;
            }
            else if(ch >=223 && ch <=251)
            {
                nNorChar++;
            }
        }
    }

    return nNorChar;

}

bool    isAllowString(string str)
{
    bool isAllow = true;

    if(str.size() <= 0) isAllow = false;
    else
    {
        int nEng = extEnglish(str);
        int nNum = extNumberic(str);
        int nASpc = extAsciiSpecial(str);
        int nNor = extTis620Normal(str);

        if(nNum == -1)  isAllow = false;      // 문자열의 처음이 숫자로 시작하면
        if(nEng && nNor)isAllow = false;      // 일반문자와 영문이 섞여 있다면
        if(nASpc)       isAllow = false;      // Ascii영역에서 특수문자가 발견되면
    }

    return isAllow;
}

#endif


#ifdef __CHINA_SERVER__
// 문자열에 숫자가 몇개 있는지 찾기
// return : -1 문자열의 처음에 숫자가 있다.
// return : 0  문자열에서 숫자를 찾지 못했다.
// return : x > 0 문자열에서 1개 이상의 숫자를 찾았다.
int extNumberic(string srcStr)
{
    unsigned char   ch;
    int nNumChar    = 0;

    if(srcStr.size() <= 0 ) return 0;
    else
    {
        for ( unsigned int i=0; i < srcStr.size(); i++ )
        {
            ch = srcStr[i];
            if(ch >= '0' && ch <='9')
            {
                if(i == 0) { return -1; }
                else { nNumChar++; }
            }
        }
    }

    return nNumChar;
}


// 문자열에서 영자가 몇개 있는지 찾는다
// return : 0 문자열에서 숫자를 찾지 못했다.
// return : x > 0 문자열에서 1개 이상의 숫자를 찾았다. x는 찾은 갯수
int extEnglish(string srcStr)
{
    unsigned char   ch;
    int nEngChar    = 0;

    if(srcStr.size() <= 0 ) return 0;
    else
    {
        for (  unsigned int i=0; i < srcStr.size(); i++)
        {
            ch = srcStr[i];
            if(ch >=97 && ch <=122)
            {
                nEngChar++;
            }
            else if(ch >=65 && ch <=90)
            {
                nEngChar++;
            }
        }
    }

    return nEngChar;
}
// GB2312 코드셋의 문자가 몇개 있는지 있는지 찾는다.
int extGb2312Normal(string srcStr)
{
    unsigned char   ch;
    int nNormalChar = 0;

    if(srcStr.size() <= 0 ) return 0;
    else
    {
        for (  unsigned int i=0; i < srcStr.size(); i++)
        {
            ch = srcStr[i];
            if(ch >= 0xB0 && ch <= 0xF7)
            {
                unsigned char ch2 = srcStr[i+1];
                if(ch2 > 0xA0 && ch < 0xFF)
                {
                    nNormalChar++;
                    i++;
                }
            }
            else if((ch >= 0xA1 && ch <= 0xAF) || (ch >=0xF8 && ch <= 0xFE))
            {
                unsigned char ch2 = srcStr[i+1];
                if(ch2 >= 0xA0 && ch <= 0xFF)
                {
                    i++;
                }
            }

        }
    }
    return nNormalChar;
}
int extGb2312Special(string srcStr)
{
    unsigned char   ch;
    int nSpecialChar    = 0;

    if(srcStr.size() <= 0 ) return 0;
    else
    {
        for (  unsigned int i=0; i < srcStr.size(); i++)
        {
            ch = srcStr[i];
            if(ch >= 0xB0 && ch <= 0xF7)
            {
                unsigned char ch2 = srcStr[i+1];
                if(ch2 > 0xA0 && ch < 0xFF)
                {
                    i++;
                }
            }
            else if((ch >= 0xA1 && ch <= 0xAF) || (ch >=0xF8 && ch <= 0xFE))
            {
                unsigned char ch2 = srcStr[i+1];
                if(ch2 >= 0xA0 && ch <= 0xFF)
                {
                    nSpecialChar++;
                    i++;
                }
            }
        }
    }
    return nSpecialChar;
}
int extAsciiSpecial(string srcStr)
{
    unsigned char   ch;
    int nASPCChar   = 0;

    if(srcStr.size() <= 0 ) return 0;
    else
    {
        for ( int i=0; i < srcStr.size(); i++)
        {
            ch = srcStr[i];

            if(ch >=0x00 && ch <=47)
            {
                nASPCChar++;
            }
            else if(ch >=58 && ch <=64)
            {
                nASPCChar++;
            }
            else if(ch >=91 && ch <=96)
            {
                nASPCChar++;
            }
            else if(ch >=123 && ch <=127)
            {
                nASPCChar++;
            }

        }
    }

    return nASPCChar;
}
bool    isAllowString(string str)
{
    bool isAllow = true;

    if(str.size() <= 0) isAllow = false;
    else
    {
        int nEng = extEnglish(str);
        int nNum = extNumberic(str);
        int nNor = extGb2312Normal(str);
        int nSpc = extGb2312Special(str);
        int nASpc = extAsciiSpecial(str);

        if(nNum == -1)  isAllow = false;      // 문자열의 처음이 숫자로 시작하면
        if(nSpc)        isAllow = false;      // 특수문자가 포함되어 있다면 (gb2312안에서만 체크한
        if(nEng && nNor)isAllow = false;      // 일반문자와 영문이 섞여 있다면
        if(nASpc)       isAllow = false;      // Ascii영역에서 특수문자가 발견되면
    }

    return isAllow;
}

#endif
