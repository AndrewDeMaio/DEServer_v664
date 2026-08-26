//////////////////////////////////////////////////////////////////////////////
// Filename    : CGConnectHandler.cpp
// Written By  : Reiot
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "CGConnect.h"

#ifdef __GAME_SERVER__
	#include "PlayerCreature.h"
	#include "GamePlayer.h"
	#include "Slayer.h"
	#include "Vampire.h"
	#include "Ousters.h"
	#include "Zone.h"
	#include "ZoneInfoManager.h"
	#include "ZoneUtil.h"
	#include "ZoneGroup.h"
	#include "ZoneGroupManager.h"
	#include "ZonePlayerManager.h"
	#include "IncomingPlayerManager.h"
	#include "WeatherManager.h"
	#include "PCFinder.h"
	#include "GuildManager.h"
	#include "Guild.h"
	#include "TelephoneCenter.h"
	#include "EventSave.h"
	#include "EventRegeneration.h"
	#include "EventHeadCount.h"
	#include "PCSlayerInfo2.h"
	#include "PCVampireInfo2.h"
	#include "NPCInfo.h"
	#include "PacketUtil.h"
	#include "DB.h"
	#include "Properties.h"
	#include "LogClient.h"
	#include "Thread.h"
	#include "PacketUtil.h"
	#include "ResurrectLocationManager.h"
	#include "SharedServerManager.h"
	#include "BillingPlayerManager.h"
	#include "Encrypter.h"
	#include "LogDef.h"
	#include "EventSystemMessage.h"
	#include "CastleInfoManager.h"
	#include "PKZoneInfoManager.h"
	#include "EventZoneInfo.h"
	#include "NicknameBook.h"

	#include "EffectGhost.h"
	#include "skill/EffectGnomesWhisper.h"
	#include "EffectDSG.h"
	#include "EffectPremiumService.h"

	#include "mission/QuestManager.h"

	#include "CreatureUtil.h"

	#include <fstream>
	#include <list>
	#include <stdio.h>

	#include "Gpackets/GCDisconnect.h"
	#include "Gpackets/GCUpdateInfo.h"
	#include "Gpackets/GCSystemMessage.h"
	#include "Gpackets/GSGuildMemberLogOn.h"
	#include "Gpackets/GSLogin.h"

	#include "SystemAvailabilitiesManager.h"
	#include "types/ServerType.h"
	#include "GDRLairManager.h"

	#include "chinabilling/CBillingInfo.h"
#ifdef __CONNECT_CBILLING_SYSTEM__
	#include "chinabilling/CBillingPlayerManager.h"
	#include "EventCBilling.h"
#endif

	#include "EventAuth.h"
	#include "DynamicZoneManager.h"
	#include "Viewable.h"
#ifdef __MENEGROTH_DOUNGEON_SYSTEM__
	#include "MenegrothDoungeonManager.h"
#endif

	#include "GameServerInfo.h"
	#include "GameServerInfoManager.h"

	#include "Gpackets/GCUpdateWeekItemList.h"
	#include "WeekItemListManager.h"

#endif

bool isAdultByBirthdayDate(const string& birthday);


//////////////////////////////////////////////////////////////////////////////
// CGConnectHandler::execute()
//
// �� ��Ŷ�� �α��μ������� ���ʷ� ���� ������ ������ ��, �Ǵ� ���� ��������
// �ٸ� ���� ������ �̵��� ��, Ŭ���̾�Ʈ�� ������ �����ϴ� ������ ��Ŷ�̴�.
// �̶� �÷��̾� ��ü�� ���� ���ܳ� �����̰�, �� �÷��̾� ��ü�� IPM ����
// �����Ǵ� �����̴�. 
//
// �翬�� ������ ��Ŷ���� �ٸ� ��Ŷ�� �Ѿ���� �����, �̰��� ��ŷ �õ����
// ���� �����ϹǷ� �� ��Ŷ�� �������� �˻��ؾ� �Ѵ�. �̸� ���ؼ� �÷��̾� ��ü��
// ���� ��Ŷ�� �����ϰ� �����Ƿ�, �� ���� NULL ������ ���� �ǰڴ�.
//
// �߸��� ��Ŷ�̶��, ban �� ����ϰ� ������ �����Ѵ�.
//////////////////////////////////////////////////////////////////////////////
void CGConnectHandler::execute (CGConnect* pPacket , Player* pPlayer)
	 throw (ProtocolException , Error)
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
	__BEGIN_DEBUG
		
#ifdef __GAME_SERVER__

	cout << "connect Player" << endl;

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
	
	string          connectIP            = pGamePlayer->getSocket()->getHost();

	// set MAC Address
	pGamePlayer->setMacAddress( pPacket->getMacAddress() );

	// �� ��Ŷ�� ConnectionInfo ��ü�� ���� �´�.
	// ũ��Ŀ�� Ű���� ĳ���� �̸��� ���� �ð��ȿ� ����߸� ������ �����ϴ�.
	try 
	{
		ConnectionInfo* pConnectionInfo = g_pConnectionInfoManager->getConnectionInfo(pGamePlayer->getSocket()->getHost());

		GameServerInfo* pGameServerInfo = g_pGameServerInfoManager->getGameServerInfo( 1, g_pConfig->getPropertyInt("ServerID") , g_pConfig->getPropertyInt("WorldID")  );
			
		if(g_pConnectionInfoManager->getCurrentUserNumber() >= pGameServerInfo->getMaxUser())
		{
			//2008.04.29 rappi76, ����� ���� �ʰ� �α׸� �ۼ��ϰ� ���� ���� ��Ű���� �ʴ´�.

			filelog("ServerMaxUserFull.log", "Server ID: %d\tUserNumber: %d\tMaxUser: %d\tPlayerID: %s ", 
				g_pConfig->getPropertyInt("ServerID"),
				g_pConnectionInfoManager->getCurrentUserNumber(), 
				pGameServerInfo->getMaxUser(),
				pGamePlayer->getID().c_str()
			);

			/*
			pGamePlayer->setPenaltyFlag(PENALTY_TYPE_KICKED);
			pGamePlayer->setItemRatioBonusPoint(20);

			pGamePlayer->setKickForLogin(true);
//			pGamePlayer->setKickRequestHost(  );
			*/

		}

		// Ű���� �����Ѵ�.
		if (pPacket->getKey() != pConnectionInfo->getKey())
		{
			FILELOG_INCOMING_CONNECTION("connectionError.log", "Wrong Key: [%s] %s", pConnectionInfo->getPCName().c_str(), pGamePlayer->getSocket()->getHost().c_str());
			throw InvalidProtocolException("invalid key");
		}

		// �̸��� �����Ѵ�.
		if (pPacket->getPCName() != pConnectionInfo->getPCName())
		{
			FILELOG_INCOMING_CONNECTION("connectionError.log", "Wrong PCName: [%s] %s", pConnectionInfo->getPCName().c_str(), pGamePlayer->getSocket()->getHost().c_str());
			throw InvalidProtocolException("invalid pc name");
		}

		// �ϴ� �̸��� �����Ѵ�. ������ ������ �����ϸ� ��ü�� �����ϴϱ� �����ϴ�.
		pGamePlayer->setID(pConnectionInfo->getPlayerID());

		// CIM�� heartbeat�� ����Ǳ� ���� ������� ������ ���ɼ��� �ִ�.
		// (Ÿ�̹��� ������ heartbeat �����ֱ�*2 �ȿ��� �����ϸ� �ȴ�.)
		// ����, ���� �ð��� expire time �� ���Ѵ�.
		Timeval currentTime;
		getCurrentTime(currentTime);
		if (pConnectionInfo->getExpireTime() < currentTime) 
		{
			FILELOG_INCOMING_CONNECTION("connectionError.log", "Expired: [%s] %s", pConnectionInfo->getPCName().c_str(), pGamePlayer->getSocket()->getHost().c_str());

			// �ϴ� �����Ѵ�.
			g_pConnectionInfoManager->deleteConnectionInfo(pConnectionInfo->getClientIP());
			throw InvalidProtocolException("session already expired");
		}
		
       	// by sigi. 2002.12.7
		FILELOG_INCOMING_CONNECTION("connectionInfo.log", "Login [%s:%s] %s (%u)",
										pConnectionInfo->getPlayerID().c_str(),
										pConnectionInfo->getPCName().c_str(),
										pConnectionInfo->getClientIP().c_str(),
										pConnectionInfo->getKey());

		// �����Ǿ�����, ConnectionInfo �� �����Ѵ�.
		try {
			g_pConnectionInfoManager->deleteConnectionInfo(pConnectionInfo->getClientIP());
		} catch (NoSuchElementException& nsee)
		{
			FILELOG_INCOMING_CONNECTION("connectionInfoDelete.log", "DeleteNoSuch [%s:%s] %s (%u)",
										pConnectionInfo->getPlayerID().c_str(),
										pConnectionInfo->getPCName().c_str(),
										pConnectionInfo->getClientIP().c_str(),
										pConnectionInfo->getKey());
		}
	} 
	catch (NoSuchElementException & nsee) // �׷� IP�� ���� CI �� ���� ���
	{ 
		FILELOG_INCOMING_CONNECTION("connectionError.log", "NoSuchConnectionInfo: %s", pGamePlayer->getSocket()->getHost().c_str());

		// ��.. ���� ���� CGConnect ��Ŷ�� ������ �����̰� �ʹ� �� ���
		// session �� expire �ȴ�. �̷� ��쿡�� ¥����!
		// (���� ��, ���� ���ῡ���� ���������� �״����� ����� ���·�
		// �� ���, CGConnect ��Ŷ�� ���� ���뿡�� expire �ȴ�.)
		GCDisconnect gcDisconnect;
		gcDisconnect.setMessage(nsee.toString());

		pGamePlayer->sendPacket(&gcDisconnect);

		// �̷��� ������ ���� IPM::processCommands()���� disconnect ó���Ѵ�.
		throw InvalidProtocolException(nsee.toString().c_str());
	} 
	catch (InvalidProtocolException & ipe) 
	{
		FILELOG_INCOMING_CONNECTION("connectionError.log", "%s: %s", ipe.toString().c_str(), pGamePlayer->getSocket()->getHost().c_str());
		cout << endl
			 << "+-----------------------+" << endl
			 << "| Level 2 Access Denied |" << endl
			 << "+-----------------------+" << endl
			 << endl;

		GCDisconnect gcDisconnect;
		gcDisconnect.setMessage(ipe.toString());

		pGamePlayer->sendPacket(&gcDisconnect);

		// �̷��� ������ ���� IPM::processCommands()���� disconnect ó���Ѵ�.
		throw;
	}

	//----------------------------------------------------------------------
	// �α��� üũ
	//----------------------------------------------------------------------
	Statement* pStmt   = NULL;
	Result*    pResult = NULL;
 
	// ����~
	PayType         payType;
	string          payPlayDate;
	uint            payPlayHours;
	uint            payPlayFlag;
	int				billingUserKey = 0;	// by sigi. 2002.11.18
	string          familyPayPlayDate;


	try
	{
		BEGIN_DB
		{
			pStmt   = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			pResult = pStmt->executeQuery("SELECT PlayerID FROM Slayer WHERE Name = '%s' LIMIT 1",pPacket->getPCName().c_str());



			if (pResult->getRowCount() != 1)
			{
				StringStream msg;
				msg << "Failed to load PlayerCreature data from DB. Not 1 PlayerID (" 
					<< pPacket->getPCName().c_str() << ")";

				filelog("connectDB_BUG.txt", "%s", msg.toString().c_str());

				SAFE_DELETE(pStmt);
				throw ProtocolException( msg.toString().c_str() );
			}

			if (pResult->next()) 
			{
				string spID = pResult->getString(1);
				if (strcasecmp(spID.c_str(), pGamePlayer->getID().c_str()) != 0) 
				{
					StringStream msg;
					msg << "Failed to load PlayerCreature data from DB. No Character(" 
						<< spID.c_str() << "!="
						<< pGamePlayer->getID().c_str() << ")";

					filelog("connectDB_BUG.txt", "%s", msg.toString().c_str());

					SAFE_DELETE(pStmt);
					throw ProtocolException( msg.toString().c_str() );
				}
			}

			SAFE_DELETE(pStmt);
		}
		END_DB(pStmt)

		//pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		BEGIN_DB
		{
			pStmt = g_pDatabaseManager->getDistConnection("PLAYER_DB")->createStatement();

#ifdef __THAILAND_SERVER__

			pResult = pStmt->executeQuery("SELECT PlayerID, CurrentServerGroupID, LogOn, SpecialEventCount, PayType, PayPlayDate, PayPlayHours, PayPlayFlag, BillingUserKey, FamilyPayPlayDate, Birthday FROM Player WHERE PlayerID = '%s'", pGamePlayer->getID().c_str());

#else

			pResult = pStmt->executeQuery("SELECT PlayerID, CurrentServerGroupID, LogOn, SpecialEventCount, PayType, PayPlayDate, PayPlayHours, PayPlayFlag, BillingUserKey, FamilyPayPlayDate FROM Player WHERE PlayerID = '%s'", pGamePlayer->getID().c_str());

#endif
			if (pResult->getRowCount() != 1)
			{
				StringStream msg;
				msg << "Failed to load PlayerCreature data from DB. No Player(" 
					<< pPacket->getPCName().c_str() << ")";

				filelog("connectDB_BUG.txt", "%s", msg.toString().c_str());

				SAFE_DELETE(pStmt);
				throw ProtocolException(msg.toString().c_str());
			}

			pResult->next();

			int i = 0;

			string          playerID = pResult->getString(++i);
			ServerGroupID_t GID      = pResult->getInt(++i);
			string          logon    = pResult->getString(++i);
			uint            scount	= pResult->getDWORD(++i);

			payType      = (PayType)pResult->getInt(++i);
			payPlayDate  = pResult->getString(++i);
			payPlayHours = pResult->getInt(++i);
			payPlayFlag  = pResult->getInt(++i);
			billingUserKey  	= pResult->getInt(++i);
			familyPayPlayDate	= pResult->getString(++i);

#ifdef __THAILAND_SERVER__
			string Birthday = pResult->getString(++i);
			pGamePlayer->setPermission( isAdultByBirthdayDate( Birthday ) );
#endif

			pGamePlayer->setServerGroupID(GID);
			pGamePlayer->setSpecialEventCount(scount);
			pGamePlayer->setBillingUserKey( billingUserKey );

			// 'LOGON' is accepted as well as 'LOGOFF'.
			//
			// The loginserver sets LogOn='LOGON' at login (CLLoginHandler) and
			// only clears it back to 'LOGOFF' from its *disconnect* handler
			// (LoginPlayer.cpp:442/520), which runs when the client drops the
			// login socket on its way here. That is a race: over loopback the
			// client reconnects and CGConnect lands before the loginserver has
			// written the row, so this saw 'LOGON' and rejected a perfectly
			// legitimate handoff every time.
			//
			// 'GAME' is still refused, so a genuine double-login is caught.
			if (logon != "LOGOFF" && logon != "LOGON")
			{
				SAFE_DELETE(pStmt);
				char str[80];
				sprintf(str, "Already connected player ID: %s, %s", playerID.c_str(), logon.c_str());
				throw ProtocolException(str);
			}

			pStmt->executeQuery("UPDATE Player SET LogOn='GAME' WHERE PlayerID = '%s' AND LogOn IN ('LOGOFF','LOGON')", playerID.c_str());

			// LogOn�� LOGOFF�� �ƴϰų�.. ���.. by sigi. 2002.5.15
			if (pStmt->getAffectedRowCount()==0)
			{
				SAFE_DELETE(pStmt);
				char str[80];
				sprintf(str, "Already connected player ID2: %s, %s", playerID.c_str(), logon.c_str());
				throw ProtocolException(str);
			}

			string connectIP = pGamePlayer->getSocket()->getHost();

			// ���� by sigi. 2002.5.31
#if defined(__CONNECT_BILLING_SYSTEM__)
			if ( payType == PAY_TYPE_FREE )
			{
				pGamePlayer->setMetroFreePlayer();
			}
#elif defined(__PAY_SYSTEM_LOGIN__)
			if (pGamePlayer->loginPayPlay(payType, 
						payPlayDate, payPlayHours, payPlayFlag,
						connectIP, playerID))
			{
				sendPayInfo(pGamePlayer);
			}
			else
			{
				SAFE_DELETE(pStmt);
				throw ProtocolException("no pay account");
			}
			// by sigi. 2002.11.18. ������ ���� �����. - -; �ϴ� login
#elif defined(__PAY_SYSTEM_FREE_LIMIT__)
			if (pGamePlayer->loginPayPlay(payType, 
						payPlayDate, payPlayHours, payPlayFlag,
						connectIP, playerID))
			{
				sendPayInfo(pGamePlayer);
			}
#else //defined(__PAY_SYSTEM_ZONE__)
	#ifdef __NETMARBLE_SERVER__
			// do nothing
	#else
//			pGamePlayer->isPlayInPayPCRoom(connectIP, playerID);
	#endif
//			pGamePlayer->setPayPlayValue(payType, payPlayDate, payPlayHours, payPlayFlag, familyPayPlayDate);
			
//			if (pGamePlayer->loginPayPlay(payType, 
//									payPlayDate, payPlayHours, payPlayFlag,
//									connectIP, playerID))
			if(pGamePlayer->CheckPayFunction(connectIP, playerID))
			{
				sendPayInfo(pGamePlayer);
			}
#endif
			

			SAFE_DELETE(pStmt);
		}
		END_DB(pStmt)

		
	}
	catch (SQLQueryException & sqe)
	{
		SAFE_DELETE(pStmt);
		throw Error(sqe.toString());
	}

	//----------------------------------------------------------------------
	// �����̾� �Ǵ� �����̾� ĳ���͸� �ε��Ѵ�.
	//----------------------------------------------------------------------
	Slayer*  pSlayer  = NULL;
	Vampire* pVampire = NULL;
	Ousters* pOusters = NULL;

	bool bAlreadyConnected = false;

	//try
	//{
		if ( g_pPCFinder->getCreature( pPacket->getPCName() ) != NULL )
		{
			// PCFinder �� �̹� ��ϵ� �̸��� �ִٸ� ������ �Ǿ� �ִ�.
			// ������ ���ϰ� ���´�.
			bAlreadyConnected = true;
		}
		else if (pPacket->getPCType() == PC_SLAYER) 
		{
			pSlayer = new Slayer();
			pSlayer->setName(pPacket->getPCName());
			pSlayer->setPlayer(pGamePlayer);
			
			pSlayer->loadEventNewStartSupplyItemList();
			pSlayer->loadEventComebackSupplyItemList();
			pSlayer->loadEventPresentItemList();

			if (!pSlayer->load())
			{
				filelog("connectDB_BUG.txt", "Failed to load SLAYER(%s) data from DB", pPacket->getPCName().c_str());

				throw ProtocolException("Failed to load SLAYER data from DB");
			}

			// ������������ ����Ǵ� ������ ������ �ؿ��� üũ
			//pSlayer->loadItem();
			//Assert(pSlayer->getName() == pPacket->getPCName());
			if (pSlayer->getName() != pPacket->getPCName())
			{
				cout << "Different Name : " << pSlayer->getName().c_str()
						<< ", " << pPacket->getPCName().c_str() << endl;

				Assert(pSlayer->getName() == pPacket->getPCName());
			}

			pGamePlayer->setCreature(pSlayer);

			// Slayer�� TelephoneCenter�� ����Ѵ�.
			//g_pTelephoneCenter->addSlayer(pSlayer);
		
			// �ֱ� ȸ�� �̺�Ʈ�� �÷��̾� ��ü�� �߰��Ѵ�.
			// �̶� �⺻������ 10�� ȸ���� ��Ģ���� �Ѵ�.
			// (setDeadline�� �Ķ���ʹ� 0.1 �ʶ�� �� ������ ��)
			EventRegeneration* pEventRegeneration = new EventRegeneration(pGamePlayer);
			pEventRegeneration->setDeadline(10* 10);
			pGamePlayer->addEvent(pEventRegeneration);

			// PCFinder�� �߰��Ѵ�.
			// PCFinder�� ������ ~GamePlayer()������ �Ѵ�.
			try {
				g_pPCFinder->addCreature(pSlayer);
			} catch (DuplicatedException& de) {
				bAlreadyConnected = true;
			}

			// �̹� �������� ��찡 �ƴ϶��.. by sigi. 2002.8.29
			if (!bAlreadyConnected)
			{
				// ��� ���� ���� ��� ����Ʈ�� �߰��Ѵ�.
				if ( pSlayer->getGuildID() != 99 )
				{
					Guild* pGuild = g_pGuildManager->getGuild( pSlayer->getGuildID() );
					if ( pGuild != NULL )
					{
						// sharedserver�� ������ �˸��� DB �� update �Ѵ�.
						try {
							pGuild->addCurrentMember( pSlayer->getName() );

							GSGuildMemberLogOn gsGuildMemberLogOn;
							gsGuildMemberLogOn.setGuildID( pGuild->getID() );
							gsGuildMemberLogOn.setName( pSlayer->getName() );
							gsGuildMemberLogOn.setLogOn( true );
							gsGuildMemberLogOn.setServerID(  g_pConfig->getPropertyInt("ServerID") );

							g_pSharedServerManager->sendPacket( &gsGuildMemberLogOn );

							// DB ������Ʈ
							BEGIN_DB
							{
								pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
								pStmt->executeQuery( "UPDATE GuildMember SET LogOn = 1 WHERE Name = '%s'", pSlayer->getName().c_str() );

								SAFE_DELETE( pStmt );
							}
							END_DB( pStmt )

						} catch (DuplicatedException& t) {
							// �ϴ� �����Ѵ�. by sigi. 2002.8.29
							filelog( "guildBug.log", "%s", t.toString().c_str());
						}
					}
					else
						filelog( "GuildMissing.log", "[NoSuchGuild] GuildID : %d, Name : %s\n", (int)pSlayer->getGuildID(), pSlayer->getName().c_str() );
				}
			}
		} 
		else if (pPacket->getPCType() == PC_VAMPIRE) 
		{
			pVampire = new Vampire();
			pVampire->setName(pPacket->getPCName());
			pVampire->setPlayer(pGamePlayer);
			
			pVampire->loadEventNewStartSupplyItemList();
			pVampire->loadEventComebackSupplyItemList();
			pVampire->loadEventPresentItemList();

			if (!pVampire->load())
			{
				filelog("connectDB_BUG.txt", "Failed to load VAMPIRE(%s) data from DB", pPacket->getPCName().c_str());
				throw ProtocolException("Failed to VAMPIRE data from DB");
			}

			// ������������ ����Ǵ� ������ ������ �ؿ��� üũ
			//pVampire->loadItem();
			Assert(pVampire->getName() == pPacket->getPCName());

			pGamePlayer->setCreature(pVampire);

			// �ֱ� ȸ�� �̺�Ʈ�� �÷��̾� ��ü�� �߰��Ѵ�.
			// �̶� �⺻������ 10�� ȸ���� ��Ģ���� �Ѵ�.
			// (setDeadline�� �Ķ���ʹ� 0.1 �ʶ�� �� ������ ��)
			EventRegeneration* pEventRegeneration = new EventRegeneration(pGamePlayer);
			pEventRegeneration->setDeadline(10* 10);
			pGamePlayer->addEvent(pEventRegeneration);

			// PCFinder�� �߰��Ѵ�.
			// PCFinder�� ������ ~GamePlayer()������ �Ѵ�.
			try {
				g_pPCFinder->addCreature(pVampire);
			} catch (DuplicatedException& de) {
				bAlreadyConnected = true;
			}

			// �̹� �������� ��찡 �ƴ϶��.. by sigi. 2002.8.29
			if (!bAlreadyConnected)
			{
				// ��� ���� ���� ��� ����Ʈ�� �߰��Ѵ�.
				if ( pVampire->getGuildID() != 0 )
				{
					Guild* pGuild = g_pGuildManager->getGuild( pVampire->getGuildID() );
					if ( pGuild != NULL )
					{
						// sharedserver �� ������ �˸��� DB �� update �Ѵ�.
						try {
							pGuild->addCurrentMember( pVampire->getName() );

							GSGuildMemberLogOn gsGuildMemberLogOn;
							gsGuildMemberLogOn.setGuildID( pGuild->getID() );
							gsGuildMemberLogOn.setName( pVampire->getName() );
							gsGuildMemberLogOn.setLogOn( true );
							gsGuildMemberLogOn.setServerID(  g_pConfig->getPropertyInt("ServerID") );

							g_pSharedServerManager->sendPacket( &gsGuildMemberLogOn );

							// DB ������Ʈ
							BEGIN_DB
							{
								pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
								pStmt->executeQuery( "UPDATE GuildMember SET LogOn = 1 WHERE Name = '%s'", pVampire->getName().c_str() );

								SAFE_DELETE( pStmt );
							}
							END_DB( pStmt )
						} catch (DuplicatedException& t) {
							// �ϴ� �����Ѵ�. by sigi. 2002.8.29
							filelog( "guildBug.log", "%s", t.toString().c_str());
						}
					}
					else
						filelog( "GuildMissing.log", "[NoSuchGuild] GuildID : %d, Name : %s\n", (int)pVampire->getGuildID(), pVampire->getName().c_str() );
				}
			}
		}
		else if (pPacket->getPCType() == PC_OUSTERS) 
		{
			pOusters = new Ousters();
			pOusters->setName(pPacket->getPCName());
			pOusters->setPlayer(pGamePlayer);

			pOusters->loadEventNewStartSupplyItemList();
			pOusters->loadEventComebackSupplyItemList();
			pOusters->loadEventPresentItemList();
			
			if (!pOusters->load())
			{
				filelog("connectDB_BUG.txt", "Failed to load VAMPIRE(%s) data from DB", pPacket->getPCName().c_str());
				throw ProtocolException("Failed to VAMPIRE data from DB");
			}

			// ������������ ����Ǵ� ������ ������ �ؿ��� üũ
			//pVampire->loadItem();
			Assert(pOusters->getName() == pPacket->getPCName());

			pGamePlayer->setCreature(pOusters);

			// �ֱ� ȸ�� �̺�Ʈ�� �÷��̾� ��ü�� �߰��Ѵ�.
			// �̶� �⺻������ 10�� ȸ���� ��Ģ���� �Ѵ�.
			// (setDeadline�� �Ķ���ʹ� 0.1 �ʶ�� �� ������ ��)
			EventRegeneration* pEventRegeneration = new EventRegeneration(pGamePlayer);
			pEventRegeneration->setDeadline(10* 10);
			pGamePlayer->addEvent(pEventRegeneration);

			// PCFinder�� �߰��Ѵ�.
			// PCFinder�� ������ ~GamePlayer()������ �Ѵ�.
			try {
				g_pPCFinder->addCreature(pOusters);
			} catch (DuplicatedException& de) {
				bAlreadyConnected = true;
			}

			// �̹� �������� ��찡 �ƴ϶��.. by sigi. 2002.8.29
			if (!bAlreadyConnected)
			{
				// ��� ���� ���� ��� ����Ʈ�� �߰��Ѵ�.
				if ( pOusters->getGuildID() != 66 )
				{
					Guild* pGuild = g_pGuildManager->getGuild( pOusters->getGuildID() );
					if ( pGuild != NULL )
					{
						// sharedserver �� ������ �˸��� DB �� update �Ѵ�.
						try {
							pGuild->addCurrentMember( pOusters->getName() );

							GSGuildMemberLogOn gsGuildMemberLogOn;
							gsGuildMemberLogOn.setGuildID( pGuild->getID() );
							gsGuildMemberLogOn.setName( pOusters->getName() );
							gsGuildMemberLogOn.setLogOn( true );
							gsGuildMemberLogOn.setServerID(  g_pConfig->getPropertyInt("ServerID") );

							g_pSharedServerManager->sendPacket( &gsGuildMemberLogOn );

							// DB ������Ʈ
							BEGIN_DB
							{
								pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
								pStmt->executeQuery( "UPDATE GuildMember SET LogOn = 1 WHERE Name = '%s'", pOusters->getName().c_str() );

								SAFE_DELETE( pStmt );
							}
							END_DB( pStmt )
						} catch (DuplicatedException& t) {
							// �ϴ� �����Ѵ�. by sigi. 2002.8.29
							filelog( "guildBug.log", "%s", t.toString().c_str());
						}
					}
					else
						filelog( "GuildMissing.log", "[NoSuchGuild] GuildID : %d, Name : %s\n", (int)pOusters->getGuildID(), pOusters->getName().c_str() );
				}
			}
		}
	//}
	/*
	catch (DuplicatedException& de)
	{
		// PC finder���� ������ �ڲ� �ߴµ�, �׳� ���⼭ ����ָ� ���� ������?
		// by �輺��
		// ���⼭ ũ���� ��ü�� ����������, ���� �÷��̾ ������ �ִ� m_pCreature �����ʹ�
		// ������ ���� ����Ű�� �ȴ�. �׷��� GamePlayer::~GamePlayer() ���� �ڽ��� m_pCreature�� ������ ��
		// �߸��� �޸� ������ �����ϸ鼭 �װ� �ȴ�. �׷��Ƿ� �ּ��� Ǯ�� �� ��.

		// GamePlayer�� ����鼭 
		// m_pCreature�� �ִ� ��쿡�� PCFinder�����ִµ�..
		// �̰Ͷ����� ��Ƽ �α����� �����ϰ� �ȴ�.
		// �̰� ���� ���ؼ� ĳ���͸� ���⼭ �����ش�.
		// by sigi. 2002.5.9

		// Ȥ�� PCFinder���� �� �����ְ� ��ü�� �����
		// PCFinder���� �о�� pointer�� delete�ȰŶ� ������ ����ٰ� �����ߴµ�
		// �и��� GamePlayer�� delete�ɶ��� PCFinder���� �������ְ�
		// ���⼭ ����� ĳ���ʹ� �̹� ���ӵ� ĳ���Ϳʹ� ������� ���ο� ��ü�̹Ƿ�
		// ����� ����. 2002.8.29. by sigi
		SAFE_DELETE(pSlayer);
		SAFE_DELETE(pVampire);

		pGamePlayer->setID( string("") );	// LogOn�� 'LOGOFF'�� �Ǵ°� ���´�.
		pGamePlayer->setCreature( NULL );	// PCFinder���� delete�ϴ°� ���´�.

		char str[80];
		sprintf(str, "Already connected player ID3(Dup): %s", pPacket->getPCName().c_str());
		throw ProtocolException(str);
	}
	*/

	// �̹� ���� ���� ����� ó��. 
	// PCFinder������ DuplicatedException�� ��Ȯ�ϰ� ó���ϱ� ���ؼ�
	// ������ �ּ� üũ�Ѵ�. 
	// �Ƹ� ����� DuplicatedException������ 
	// PCFinder���� ������ ����� ����.
	// by sigi. 2002.8.29
	if (bAlreadyConnected)
	{
		SAFE_DELETE(pSlayer);
		SAFE_DELETE(pVampire);
		SAFE_DELETE(pOusters);

		pGamePlayer->setID( string("") );	// LogOn�� 'LOGOFF'�� �Ǵ°� ���´�.
		pGamePlayer->setCreature( NULL );	// PCFinder���� delete�ϴ°� ���´�.

		char str[80];
		sprintf(str, "Already connected player ID3(Dup): %s", pPacket->getPCName().c_str());
		throw ProtocolException(str);
	}

	//----------------------------------------------------------------------
	// PC�� PCFinder�� ���� ����Ѵ�.
	//----------------------------------------------------------------------

//	EventHeadCount* pEventHeadCount = new EventHeadCount(pGamePlayer);
//	pEventHeadCount->setDeadline(18000);
//	pGamePlayer->addEvent(pEventHeadCount);
	
	Creature* pCreature = pGamePlayer->getCreature();
			
	Assert(pCreature != NULL);
	
	Statement* pStmtGOD = NULL;
//	bool bIsGodConnect = false;
	bool bIsGodConnect = true;


	BEGIN_DB
	{
		size_t i = connectIP.find_first_of('.',0);
		size_t j = connectIP.find_first_of('.',i+1);
		size_t k = connectIP.find_first_of('.',j+1);

		/*
		 * ip = 61.78.53.228
		 * classA = 61
		 * classB = 61.78
		 * classC = 61.78.53
		 */

		string classA = connectIP.substr(0, i);
		string classB = connectIP.substr(0, j);
		string classC = connectIP.substr(0, k);

		pStmtGOD = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		
		Result* pResult;
		
		// 20070727 �������� \ �߰�
		pResult = pStmtGOD->executeQuery(
			"SELECT class, first, last FROM IPAllowInfo"
			" WHERE "
			"(IP = '0.0.0'  AND class=3) OR "
			"(IP = '%s' AND class=1) OR "
			"(IP = '%s' AND class=2) OR "
			"(IP = '%s')",
			classA.c_str(), classB.c_str(), classC.c_str() );

		while ( pResult->next() )
		{
			int ipClass = pResult->getInt(1);
			int first = pResult->getInt(2);
			int last = pResult->getInt(3);
			int index;

			switch ( ipClass )
			{
				// classC �� �°� ������ ������ ���
				case 0:
					index = atoi(connectIP.substr(k+1, connectIP.size()-k-1).c_str());
					break;
				// classA �� �°� ������ ������ ���
				case 1:
					index = atoi(connectIP.substr(i+1, j-i-1).c_str());
					break;
				// classB �� �°� ������ ������ ���
				case 2:
					index = atoi(connectIP.substr(j+1, k-j-1).c_str());
					break;
				case 3:
					index = atoi(connectIP.substr(j+1, k-j-1).c_str());
					break;
				default:
					index = -1;
					break;
			}

			if ( index < 0 ) 
			{
				bIsGodConnect = true;
			}
			if ( index >= first && index <= last )
			{
				bIsGodConnect = true;
			}
		}

		SAFE_DELETE(pStmtGOD); // 2002.1.16 by sigi
	}
	END_DB(pStmtGOD)
	
	if( bIsGodConnect == false && pCreature->isGOD())
	{
		FILELOG_INCOMING_CONNECTION("GodConnectFailed.log", "Wrong PCName: [%s] %s", pPacket->getPCName().c_str(), pGamePlayer->getSocket()->getHost().c_str());
		throw InvalidProtocolException("invalid Connect IP GOD");
	}

	// GM ghost mode is remembered per character in the GMGhost table, so that
	// "*command ghost on|off" survives a logout.  A character with no saved row
	// keeps the old behaviour: GOD connects as a ghost, everyone else does not.
	bool bWantGhost = pCreature->isGOD();

	{
		Statement* pStmtGhost = NULL;

		try
		{
			pStmtGhost = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResultGhost = pStmtGhost->executeQuery(
				"SELECT Ghost FROM GMGhost WHERE Name = '%s'", pCreature->getName().c_str());

			if (pResultGhost->next()) bWantGhost = (pResultGhost->getInt(1) != 0);

			SAFE_DELETE(pStmtGhost);
		}
		catch (Throwable& t)
		{
			// a missing or unreadable GMGhost table must not block the login
			SAFE_DELETE(pStmtGhost);
			filelog("DBError.log", "CGConnectHandler::execute() GMGhost : %s", t.toString().c_str());
		}
		catch (...)
		{
			SAFE_DELETE(pStmtGhost);
		}
	}

	if ( bWantGhost )
	{
		EffectGhost* pEffect = new EffectGhost(pCreature);
		pCreature->getEffectManager()->addEffect( pEffect );
		pCreature->setFlag(Effect::EFFECT_CLASS_GHOST);
		pCreature->setMoveMode(Creature::MOVE_MODE_FLYING);
		pCreature->getViewable()->addViewEffect( Effect::EFFECT_CLASS_GHOST, 0 );
	}

	if ( !pCreature->isGOD() )
	{
#ifdef __TEST_SERVER__
		EventAuth* pAuth = new EventAuth( pGamePlayer );
		pGamePlayer->addEvent( pAuth );
		cout << "��������Ʈ ���� Ÿ�̸� ���Դϴ� : " << pGamePlayer->getID() << endl;
#endif
	}

	if ( pCreature->getCompetenceShape() == 0 )
	{
		EffectGnomesWhisper* pEffect = new EffectGnomesWhisper( pCreature );
		pEffect->setLevel(30);

		pCreature->addEffect( pEffect );
		pCreature->setFlag( pEffect->getEffectClass() );
	}

	// ���̳� �� ���� ������ �α����� �� ����.
	ZoneID_t castleZoneID;
	ZoneInfo* pZoneInfo = g_pZoneInfoManager->getZoneInfo(pCreature->getZoneID());

	bool isCastleZone = g_pCastleInfoManager->getCastleZoneID( pCreature->getZoneID(), castleZoneID );
	bool isMasterLair = pZoneInfo->isMasterLair() || GDRLairManager::Instance().isGDRLairZone( pCreature->getZoneID() );
	bool isMikllizzLair = pZoneInfo->isMikllizzLair();
	bool isPKZone = g_pPKZoneInfoManager->isPKZone( pCreature->getZoneID() );
	bool isMaze = ( pCreature->getZoneID() == 3001 ) ||
					( pCreature->getZoneID() == 3002 ) ||
					( pCreature->getZoneID() == 3003 );
	bool isEventZone = EventZoneInfoManager::Instance().getEventZoneInfo( pCreature->getZoneID() ) != NULL;
	bool isBeginnerZone = pCreature->getZoneID() == 1122 && !canEnterBeginnerZone(pCreature);
	bool isDynamicZone = g_pDynamicZoneManager->isDynamicZone( pCreature->getZoneID() );
	bool isSurvivalZone = pCreature->getZoneID() == 8001;
	bool isHellGardenZone = ( pCreature->getZoneID() == 5000 ) ||
							( pCreature->getZoneID() == 5010 ) ||
							( pCreature->getZoneID() == 5020 ) ||
							( pCreature->getZoneID() == 5030 ) ||
							( pCreature->getZoneID() == 5040 ) ||
							( pZoneInfo->isHellGardenTower() ); 
#ifdef __MENEGROTH_DOUNGEON_SYSTEM__	
	bool isMenegrothDoungeonZone = pZoneInfo->isMenegrothDoungeonZone(); 
#endif
	
	if ( pCreature->isPC() ) //&& pCreature->isPLAYER() )
	{
		ZONE_COORD zoneCoord;
		PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
		Assert( pPC != NULL );

		if ( isCastleZone || isMasterLair || isPKZone || isMaze || isEventZone || isBeginnerZone || isDynamicZone || 
				isMikllizzLair || isSurvivalZone || 
				isHellGardenZone )
		{
			if ( g_pResurrectLocationManager->getPosition( pPC, zoneCoord ) )
			{
				pCreature->setZoneID( zoneCoord.id );
				pCreature->setXY( zoneCoord.x, zoneCoord.y );
			}
		}
#ifdef __MENEGROTH_DOUNGEON_SYSTEM__	
		else if ( isMenegrothDoungeonZone )
		{

			g_MenegrothDoungeonManager.getAltarPosToMove(pCreature, zoneCoord.id, zoneCoord.x, zoneCoord.y);

			pCreature->setZoneID( zoneCoord.id );
			pCreature->setXY( zoneCoord.x, zoneCoord.y );
		}
#endif
	}

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);
	
#if defined(__PAY_SYSTEM_FREE_LIMIT__)
	try {
		ZoneInfo* pZoneInfo = g_pZoneInfoManager->getZoneInfo(pZone->getZoneID());
		Assert( pZoneInfo != NULL );

		Assert( pCreature->isPC() );
		PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
		Assert( pPC != NULL );

		// ���� ���̳� �����̾� ���� �ƴ� ��� 30 ���� ������ ������ ����ڿ��Դ� �������� �ʴ´�.
		if ( ( pGamePlayer->isPayPlaying() || pGamePlayer->isPremiumPlay() )
			&& pGamePlayer->getPayType() == PAY_TYPE_TIME
			&& pPC->canPlayFree()
			&& ! ( pZoneInfo->isPayPlay() || pZone->isPremiumZone() )
		)
		{
			pGamePlayer->logoutPayPlay( pGamePlayer->getID(), false, false );
		}

		// ����ȭ ���̰� ���������� �ƴϸ�..
		// ��.�� 2003.03.16 �Ϲ� �ʵ嵵 �����̾����̴�. �������ڵ� �ʵ�δ� �α��� �Ǿ�� �Ѵ�.
		if ( (pZoneInfo->isPayPlay()) //|| pZoneInfo->isPremiumZone())
			&& !pGamePlayer->isPayPlaying() )
		{
			// ���� ���� ��� �Ұ��� ���
			// �����̾�� ������������ ��Ȱ�ϴ� ������ ����.
			// �����̾�� ������������ ��Ȱ�ϴ� ������ ����.
			ZONE_COORD zoneCoord;

			if ( g_pResurrectLocationManager->getRaceDefaultPosition( pPC->getRace(), zoneCoord ) )
			{
				pCreature->setZoneID( zoneCoord.id );
				pCreature->setXY( zoneCoord.x, zoneCoord.y );
			}
		}
	} catch (NoSuchElementException&) {
		throw Error("ZoneInfo�� zoneID�� ����.");
	}
#elif defined(__CONNECT_BILLING_SYSTEM__)
	if ( pGamePlayer->isMetroFreePlayer() )
	{
		pGamePlayer->setBillingUserStatus( "MT" );
		pGamePlayer->setPremiumPlay();
	}
	else
	{
		try {
			ZoneInfo* pZoneInfo = g_pZoneInfoManager->getZoneInfo(pZone->getZoneID());
			Assert( pZoneInfo != NULL );

			Assert( pCreature->isPC() );
			PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
			Assert( pPC != NULL );

			// ���� ���� �������� ���� ��������� ���� Ȯ���� ���� �ʾҴ�.
			// ����ȭ ���̶�� �ϴ� ���� ����ڶ�� �����Ѵ�.
			// premium �� �� ���ƾ��� ���� ����϶� ZonePlayerManager ���� ���������� �Ű��ش�.
			if ( pZoneInfo->isPayPlay() )
			{
				pGamePlayer->setPremiumPlay();
			}

			} catch (NoSuchElementException&) {
				throw Error("ZoneInfo�� zoneID�� ����.");
		}

		// session ���� ���صд�. by sigi. 2002.11.18
		pGamePlayer->setBillingSession();

		// ���������� ���� ������ �˸���.
		pGamePlayer->sendBillingLogin();
	}

#elif defined(__PAY_SYSTEM_ZONE__)
	try {
		ZoneInfo* pZoneInfo = g_pZoneInfoManager->getZoneInfo(pZone->getZoneID());

		// ����ȭ ���̰� ���������� �ƴϸ�..
		if (pZoneInfo!=NULL)
//			&& (pZoneInfo->isPayPlay() || pZoneInfo->isPremiumZone()) 20080313 �������� �ƴ� ��� �� ������ �ȵ��� �̤� �ѹ��� ���� ��
//			&& !pGamePlayer->isPayPlaying() )
		{
			bool bEnterZone = true;

			string connectIP = pGamePlayer->getSocket()->getHost();

			// ���� ���� ����� �����Ѱ�?
			// ���� ���� ����� �ȵǰ� ���� ���̶�� �� �� ����.
//			if ( !pGamePlayer->loginPayPlay(connectIP, pGamePlayer->getID())
			if ( !pGamePlayer->CheckPayFunction(connectIP, pGamePlayer->getID())
				&& pZoneInfo->isPayPlay() )
			{
				bEnterZone = false;
			}

//			if ( !pGamePlayer->loginPayPlay(connectIP, pGamePlayer->getID())
			if ( !pGamePlayer->CheckPayFunction(connectIP, pGamePlayer->getID())
				&& ( pZone->getZoneID() == 1131 ||
					 pZone->getZoneID() == 1132 ||
					 pZone->getZoneID() == 1133 ||
					 pZone->getZoneID() == 1134 ) )
			{
				bEnterZone = false;
			}

			Assert( pCreature->isPC() );
			PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
			Assert( pPC != NULL );

			if (!bEnterZone)
			{
				// ���� ���� ��� �Ұ��� ���
				// �����̾�� ������������ ��Ȱ�ϴ� ������ ����.
				// �����̾�� ������������ ��Ȱ�ϴ� ������ ����.
				ZONE_COORD zoneCoord;
//				bool bFindPos = false;

				if ( g_pResurrectLocationManager->getRaceDefaultPosition( pPC->getRace(), zoneCoord ) )
				{
					pCreature->setZoneID( zoneCoord.id );
					pCreature->setXY( zoneCoord.x, zoneCoord.y );
				}
			}
		}
	} catch (NoSuchElementException&) {
		throw Error("ZoneInfo�� zoneID�� ����.");
	}
#elif defined(__CONNECT_CBILLING_SYSTEM__)
	// ���� ������ �ֱ������� minus point/minute ��Ŷ�� ������ �̺�Ʈ�� ���δ�.
	EventCBilling* pEvent = new EventCBilling( pGamePlayer );
	pEvent->setDeadline( g_pCBillingPlayerManager->getMinusIntervalInt() * 600 );
	pGamePlayer->addEvent( pEvent );

	// �߱� ������ ���� ����ȭ �̹Ƿ� ������� �Դٸ� ���� ������̴�. ���� ������� ��� �α��� �������� ������.
	pGamePlayer->setPayPlayer( true );
	pGamePlayer->setPremiumPlay();

	// send Login
	pGamePlayer->setCBillingVerified( g_pCBillingPlayerManager->sendLogin( pGamePlayer ) );
#else
	// �ƹ��͵� �����Ǿ� ���� ������
	// �� ���� ����ڶ�� �ع�����
	pGamePlayer->setPremiumPlay();
#endif

	Timeval currentTime;
	getCurrentTime(currentTime);
	Timeval payTime = pGamePlayer->getPayPlayTime(currentTime);

	int usedMin = payTime.tv_sec/60;
	int remainMin = pGamePlayer->getPayPlayAvailableHours()-usedMin;
	
	if (pGamePlayer->getPayPlayType()==PAY_PLAY_TYPE_PCROOM && remainMin != 0)
	{
		EventSystemMessage* pESM = new EventSystemMessage( pGamePlayer );
		pESM->setDeadline( 0 );
		pESM->addMessage("���� PC�濡�� ���� �ϼ̽��ϴ�.");
		pGamePlayer->addEvent( pESM );
	}
	
	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	
	// ������������ ����Ǵ� ������ ������ ���⼭ üũ
	// 2002.8.26. by sigi
	if (pPacket->getPCType() == PC_SLAYER) 
	{
		Assert(pSlayer!=NULL);
		pSlayer->loadItem( true );
	}
	else if ( pPacket->getPCType() == PC_VAMPIRE )
	{
		Assert(pVampire!=NULL);
		pVampire->loadItem( true );
	}
	else if ( pPacket->getPCType() == PC_OUSTERS )
	{
		Assert(pOusters!=NULL);
		pOusters->loadItem( true );
	}


	// �����̾��� ��� ����, �����̾��� ���� ���ο��� 
	// �����ϴ� ���, HP�� �������� ä���ش�. 
	if (pCreature->isSlayer())
	{
		Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

		switch (pZone->getZoneID())
		{
			case 2000:
			case 2001:
			case 2002:
			case 2003:
			case 2004:
			case 2010:
			case 2011:
			case 2012:
			case 2013:
			case 2014:
			case 2020:
			case 2021:
			case 2022:
			case 2023:
			case 2024:
				pSlayer->setHP(pSlayer->getHP(ATTR_MAX), ATTR_CURRENT);
				break;
			default:
				break;
		}
	}
	else if (pCreature->isVampire())
	{
		Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

		switch (pZone->getZoneID())
		{
			case 1003:
			case 1007:
				pVampire->setHP(pVampire->getHP(ATTR_MAX), ATTR_CURRENT);
				break;
			default:
				break;
		}
	}
	else if ( pCreature->isOusters() )
	{
		Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);

		switch ( pZone->getZoneID() )
		{
			case 1311:
				pOusters->setHP(pOusters->getHP(ATTR_MAX), ATTR_CURRENT);
			default:
				break;
		}
	}

	// ����Ʈ �Ŵ����� �ε��Ѵ�.
	pPC->getQuestManager()->load();

	// ũ��ó �ڽŰ� ���� �����۵��� OID�� �Ҵ�޴´�.
	// �̹� Creature::load()���� Zone �� �����Ǿ� �־�� �Ѵ�.
	pCreature->registerObject();

	// �ֱ� ���� �̺�Ʈ�� �÷��̾� ��ü�� �߰��Ѵ�.
	// �̶� �⺻������ 10�� ������ ��Ģ���� �Ѵ�.
	// (setDeadline�� �Ķ���ʹ� 0.1 �ʶ�� �� ������ ��)
	//EventSave* pEventSave = new EventSave(pGamePlayer);
	//pEventSave->setDeadline(600* 10);
	//pGamePlayer->addEvent(pEventSave);


//DSG 20080226 Kim Sung Yong
//	cout << " ��¼���!!!! ���Ⱑ �ٷ� DSG ��ƾ �����ϱ� ���̴�! " << endl;
	Turn_t Dead_line;

	BEGIN_DB
	{	
		pStmt   = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery("SELECT greatest(unix_timestamp(DsgEndTime) - unix_timestamp(now()), 0) from DSGMemberList WHERE Name  = '%s' and DsgStat = 1", pCreature->getName().c_str() );
		
//		cout << "DB���� ���� ���� �༮�� DSG ���� Ȯ���Ѵ�! " << endl;
		if (pResult->getRowCount() != 0)
		{
//			cout << "DSG ����!!!! ������ " << endl;
			pResult->next();
			Dead_line= pResult->getDWORD(1);


			if(Dead_line != 0 )
			{
//				cout << " �Դٰ� ���� DSG �ð��� �����ֱ�~!!!! " <<  endl;
				EffectDSG *pEffect = new EffectDSG( pCreature );

				if(!pPC->findEffect(Effect::EFFECT_CLASS_DSG))
				{
					pCreature->getEffectManager()->addEffect( pEffect );		
					pCreature->setFlag( Effect::EFFECT_CLASS_DSG );

					pEffect->setObjectID(pCreature->getObjectID());
					pEffect->setDeadline( Dead_line * 10 );
				}
			}
			
		}
		SAFE_DELETE( pStmt );
	}
	END_DB( pStmt )	
//DSG 20080226 Kim Sung Yong 

	pPC->loadWeekItemList();
	
//JOYMAX PREMIUM SERVICE 20080128 KimSungYong
    Turn_t 		Dead_line2;
	
	if(pGamePlayer->isPremiumPlay())
		cout << "!!!!! isPremiumPlay !!!!!" << endl;
	
    if(pGamePlayer->isPayPlaying() || pGamePlayer->isPremiumPlay())
    {
    	cout << "!!!!!! Pay Playing... 20080929 Test Code... !!!!!!!" << endl;
        BEGIN_DB
        {
            pStmt   = g_pDatabaseManager->getDistConnection("PLAYER_DB")->createStatement();
//          pResult = pStmt->executeQuery("SELECT time_to_sec(timediff(PayPlayDate, now())) from Player WHERE PlayerID= '%s' ", pGamePlayer->getID().c_str());
//2008 1113 - wlzzi - ���ǹ� �߰� : PayPlayDate�� ���糯¥���� Ŭ ��� 
            pResult = pStmt->executeQuery("SELECT unix_timestamp(PayPlayDate) - unix_timestamp(now()) from Player WHERE PlayerID= '%s' AND PayPlayDate > now() ", pGamePlayer->getID().c_str());
            
            //select �� ���� ���ٴ� ����.. ������ �ڰ� �ƴ϶�� �ǹ�.
            //Ư��!! ����(20081113) �ݸ����� ���, PayPlayDate�� �� ���� ������.. ������.. (���Ƿ� ������ ��� ĳ���� ����) ���� ���ǿ� �����ϴ� ������ ���� ���̴�. 
            if (pResult->getRowCount() > 0)
            {
	            pResult->next();
	            Dead_line2= pResult->getDWORD(1);
            }
            else
            	Dead_line2 = 0;
            
            SAFE_DELETE( pStmt );
        }
        END_DB( pStmt )
	
		if(Dead_line2 > 0)
		{
        	EffectPremiumService *pEffect = new EffectPremiumService( pCreature );

        	if(!pPC->findEffect(Effect::EFFECT_CLASS_JOYMAX_PREMIUM_SERVICE))
        	{
            	pCreature->getEffectManager()->addEffect( pEffect );
           		pCreature->setFlag( Effect::EFFECT_CLASS_JOYMAX_PREMIUM_SERVICE );
            	pEffect->setDeadline( Dead_line2 * 10 );
            	cout << " !!!!!! Dead Line Value = " << Dead_line2 << "    .... " << endl;
        	}
		}
    }
    else
    {
    	if ( g_pConfig->hasKey("IsTestServer") )
    	{
    		if(g_pConfig->getPropertyInt("IsTestServer") == 1)
    		{
    			PayType         payType 		= PAY_TYPE_PERIOD;
			    string          payPlayDate;
			    uint            payPlayHours	= 0;
			    uint            payPlayFlag		= 0;
    			
    		    BEGIN_DB
    			{
    		    	pStmt   = g_pDatabaseManager->getDistConnection("PLAYER_DB")->createStatement();
    				pResult = pStmt->executeQuery( "SELECT unix_timestamp(EndDate) - unix_timestamp(now()), EndDate from MakePCLog WHERE PlayerID= '%s' AND EndDate > now() ", pGamePlayer->getID().c_str() );
    		
    				if ( pResult->getRowCount() > 0 )
    				{
    					pResult->next();
    					Dead_line2		= pResult->getDWORD(1);
    					payPlayDate     = pResult->getString(2);
    				}
    				else
    				{
    					Dead_line2 = 0;
    				}
    				SAFE_DELETE( pStmt );
    			}
    			END_DB(pStmt)
    			
    			if(Dead_line2 > 0)
    			{			
    	        	EffectPremiumService *pEffect = new EffectPremiumService( pCreature );

    	        	if(!pPC->findEffect(Effect::EFFECT_CLASS_JOYMAX_PREMIUM_SERVICE))
    	        	{
    	            	pCreature->getEffectManager()->addEffect( pEffect );
    	           		pCreature->setFlag( Effect::EFFECT_CLASS_JOYMAX_PREMIUM_SERVICE );
    	            	pEffect->setDeadline( Dead_line2 * 10 );
    	            	cout << " !!!!!! Dead Line Value = " << Dead_line2 << "    .... " << endl;
    	            	
    	                string connectIP = pGamePlayer->getSocket()->getHost();
    	                pGamePlayer->loginPayPlay(payType, payPlayDate, payPlayHours, payPlayFlag, connectIP, pGamePlayer->getID().c_str());
    	                pGamePlayer->setPayPlayValue(payType, payPlayDate, payPlayHours, payPlayFlag, "2002-07-15 00:00:00");
    	        	}
    			}
    		}
    	}
    }

#ifdef __USE_ENCRYPTER__
	// ��ȣȭ �ڵ� ���. ������ objectID�� �ϱ� ������.. by sigi. 2002.11.27
    pGamePlayer->setEncryptCode();
#endif

//	pGamePlayer->sendPacket( SystemAvailabilitiesManager::getInstance()->getAvailabilitiesPacket() );
	SEND_SYSTEM_AVAILABILITIES(pGamePlayer);

	//----------------------------------------------------------------------
	// GCUpdateInfo �� PC ����, SkillInfo �� �����Ѵ�.
	//----------------------------------------------------------------------
	GCUpdateInfo gcUpdateInfo;
	makeGCUpdateInfo(&gcUpdateInfo, pCreature);
	pGamePlayer->sendPacket(&gcUpdateInfo);

	sendPetInfo( pGamePlayer );

	string host = pGamePlayer->getSocket()->getHost();

	IP_t IP = pGamePlayer->getSocket()->getHostIP();

	// ���������� IP�� ������ DB�� INSERT �Ѵ�.
	try 
	{

		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		/*
		StringStream inputsql;

		inputsql << "INSERT INTO UserIPInfo (Name, IP, ServerID) VALUES ('"
			<< pCreature->getName().c_str() << "'," 
			<< IP << "," << g_pConfig->getPropertyInt("ServerID") 
			<< ")";
		
		pStmt->executeQuery(inputsql.toString());
		*/
		
		pStmt->executeQuery( "INSERT IGNORE INTO UserIPInfo (Name, IP, ServerID) VALUES ( '%s', %lu, %d )", 
								pCreature->getName().c_str(), IP, g_pConfig->getPropertyInt("ServerID") );

		SAFE_DELETE(pStmt);

		log(LOG_CGCONNECT, pPacket->getPCName(), "", host);
	} 
	catch (SQLQueryException & se) 
	{
		// �ٲٱ� �õ�. by sigi. 2002.6.21
		try {
			pStmt->executeQuery( "UPDATE UserIPInfo Set IP=%ld, ServerID=%d WHERE Name='%s'",
									IP, 
									g_pConfig->getPropertyInt("ServerID"), 
									pCreature->getName().c_str());

			log(LOG_CGCONNECT, pPacket->getPCName(), "", host);

			SAFE_DELETE(pStmt);

		} catch (SQLQueryException & se) {
			SAFE_DELETE(pStmt);
			throw ProtocolException("Duplicated IPInfo");
		}
	}
	
	
	WeekItemListManager *pWeekItemListManager  = pPC->getWeekItemListManager();
	
	if ( pWeekItemListManager != NULL && pWeekItemListManager->GetWeekItemCount() > 0 )
	{
		PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
		Assert( pPC != NULL );
				
		GCUpdateWeekItemList gcWeekItemList;

		makeGCUpdateWeekItemList(&gcWeekItemList, pPC);
		
		pPC->getPlayer()->sendPacket( &gcWeekItemList );
	}
	
	GSLogin gsLogin;
	makeGSLogin(&gsLogin, pPC);
	
	g_pSharedServerManager->sendPacket( &gsLogin );

	//--------------------------------------------------
	// change player status
	//--------------------------------------------------
	pGamePlayer->setPlayerStatus(GPS_WAITING_FOR_CG_READY);
	
	#ifdef __NETMARBLE_SERVER__
			pGamePlayer->Netmb_LoginLog();	// do nothing
	#endif	

#endif
		
	__END_DEBUG
	__END_DEBUG_EX __END_CATCH
}



#ifdef __GAME_SERVER__

//////////////////////////////////////////////////////////////////////////////
//
// YYYY-MM-DD �� ���� �Ǻ�
//
//////////////////////////////////////////////////////////////////////////////
bool
isAdultByBirthdayDate(const string& birthday)
{
    StringStream AdultSSN;

    time_t daytime = time(0);
    tm Timec;
    localtime_r( &daytime, &Timec );

    AdultSSN << Timec.tm_year - 18;
    // tm_mon - range 0 to 11
    if ( (Timec.tm_mon+1) < 10 ) AdultSSN << "0";
    AdultSSN << (Timec.tm_mon+1);
    if ( Timec.tm_mday < 10 ) AdultSSN << "0";
    AdultSSN << Timec.tm_mday;

    cout << "Birthday = " << birthday.c_str() << " ADULTSSN = " << AdultSSN.toString().c_str() << endl;

    int year  = atoi( birthday.substr(0,4).c_str() );
    int month = atoi( birthday.substr(5,2).c_str() );
    int day   = atoi( birthday.substr(8,2).c_str() );

    if ( Timec.tm_year - 18 + 1900 > year )
    {
        cout << "�" << endl;
        return true;
    }
    else if ( Timec.tm_year - 18 + 1900 == year )
    {
        if ( Timec.tm_mon + 1 > month )
        {
            cout << "�" << endl;
            return true;
        }
        else if ( Timec.tm_mon + 1 == month )
        {
            if ( Timec.tm_mday >= day )
            {
                cout << "�" << endl;
                return true;
            }
        }
    }

    cout << "�ֵ�" << endl;
    return false;
}

#endif

