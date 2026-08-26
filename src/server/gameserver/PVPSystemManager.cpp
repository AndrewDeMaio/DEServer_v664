////////////////////////////////////////////////////////////////////////////////
// Filename    : MenegrothDoungeonManager.cpp
// Written By  : rappi76 
// Description :
////////////////////////////////////////////////////////////////////////////////

#include "Types.h"

#include "Creature.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"

#include "StringPool.h"
#include "Player.h"
#include "PVPSystemManager.h"
//#include "EffectPVPSystem.h"

#include "Gpackets/GCSystemMessage.h"
//#include "EffectScript.h"
#include "EffectContinualGroundAttack.h"
#include "Monster.h"
#include "MonsterCorpse.h"

#include "EffectShrineGuard.h"
#include "EffectShrineShield.h"
#include "Gpackets/GCAddEffect.h"

//#include "EffectCastleMihneaShield.h"	//주석 by kim
#include "ItemFactoryManager.h"
#include "Gpackets/GCDeleteInventoryItem.h"
#include "RelicUtil.h"
//by viva
#include "ZoneGroupManager.h"
#include "ItemInfo.h"
#include "ItemInfoManager.h"
#include "ItemUtil.h"
#include "Gpackets/GCCreateItem.h"
#include "PacketUtil.h"
#include "GlobalItemPositionLoader.h"
#include "GamePlayer.h"
#include "MonsterManager.h"
#include "ZoneUtil.h"
#include "PCFinder.h"
#include "EventTransport.h"
#include "VariableManager.h"

PVPSystemManager g_PVPSystemManager;

Level_t PVPSystemManager::getPlayerLevel(Creature *pCreature)
{
	Level_t playerLevel = 0;

    if (pCreature->isSlayer() )
    {
       	Slayer *pSlayer = dynamic_cast<Slayer *>(pCreature);

       	playerLevel = pSlayer->getHighestSkillDomainLevel();
	}
	else if ( pCreature->isVampire() )
	{
       	Vampire *pVampire = dynamic_cast<Vampire *>(pCreature);

       	playerLevel = pVampire->getLevel();

	}
   	else if ( pCreature->isOusters() )
    {
		Ousters *pOusters = dynamic_cast<Ousters *>(pCreature);

		playerLevel = pOusters->getLevel();
    }

	return playerLevel;
}

bool PVPSystemManager::isValidLevel(Creature *pCreature)
{
//	if ( getFloorByLevel(pCreature) == 0 )
//	{ 
		//    
//		return false;
//	}

	if ( getPlayerLevel(pCreature) < 150 )
		return false;

	return true;
}

void PVPSystemManager::getRequiredEntranceItems(Creature *pCreature, TRequiredItems& requiredItems)
{
	if ( !isValidLevel(pCreature))
	{
		return;
	}

//	Level_t playerLevel = getPlayerLevel(pCreature);
//	int iFloorToMove;

//	iFloorToMove = getFloorByLevel(pCreature);

	RequiredItem item;
	
	item.m_ItemClass = Item::ITEM_CLASS_COMMON_QUEST_ITEM;
	item.m_ItemType = 52;
	item.m_iItemCount = 5;

	requiredItems.push_back(item);
	
}

bool PVPSystemManager::hasRequiredEntranceItems(Creature *pCreature)
{	
	TRequiredItems requiredItems;

	getRequiredEntranceItems(pCreature, requiredItems);

	return hasItems(pCreature, requiredItems);
}

bool PVPSystemManager::hasItems(Creature *pCreature, TRequiredItems& requiredItems)
{
	PlayerCreature *pPC = dynamic_cast<PlayerCreature*>(pCreature);
	Inventory* pInventory = pPC->getInventory();
	if ( pInventory == NULL )
	{
		return false;
	}

	TRequiredItems::iterator iter;

	iter = requiredItems.begin();
	for( ; iter != requiredItems.end() ; ++iter)
	{
		RequiredItem item = (*iter);

		if ( !pInventory->hasEnoughNumItem(item.m_ItemClass, item.m_ItemType, item.m_iItemCount) )
		{
			return false;
		}
	}

	return true;
}

void PVPSystemManager::takeItems(Creature *pCreature, TRequiredItems& requiredItems)
{
	PlayerCreature *pPC = dynamic_cast<PlayerCreature*>(pCreature);
	Inventory* pInventory = pPC->getInventory();
	if ( pInventory == NULL )
	{
		return;
	}

	TRequiredItems::iterator iter;

	iter = requiredItems.begin();
	for( ; iter != requiredItems.end() ; ++iter)
	{
		RequiredItem item = (*iter);

		pInventory->decreaseNumItem(item.m_ItemClass, item.m_ItemType, item.m_iItemCount, pCreature->getPlayer()); 
	}
}

void PVPSystemManager::takeRequiredEntranceItems(Creature *pCreature)
{
	TRequiredItems requiredItems;

	getRequiredEntranceItems(pCreature, requiredItems);
	takeItems(pCreature, requiredItems);
}

bool PVPSystemManager::getDoungeonZoneToMove(Creature *pCreature, ZoneID_t& ZoneIDToMove, ZoneCoord_t& XPosToMove, ZoneCoord_t& YPosToMove)
{
	if ( !isValidLevel(pCreature) )
	{
		return false;
	}

	ZoneIDToMove = 1006;
	XPosToMove = 15;
	YPosToMove = 30;

	return true;
}

const int NextPVPWarOpenDay[8]=
{
	0, 5, 4, 3, 2, 1, 0, 6
};

//by viva

PVPSystemManager::PVPSystemManager()
	throw(Error)
{
	__BEGIN_TRY

	m_hasWar = false;
	m_pZone = NULL;
	m_pPartyInfo1= NULL;
	m_pPartyInfo2 = NULL;

	m_bParty1Inside = true;
	m_bParty2Inside = true;
	m_MatchNum = 0;
	m_ResultMatch = 0;
	m_LevelRange = 0;
	
	getCurrentTime(m_MatchTime);
	setNextStartTime();

	//g_pVariableManager->setVariable(EVENT_PVP, 1);
	
	__END_CATCH
}

PVPSystemManager::~PVPSystemManager()
	throw(Error)
{
	__BEGIN_TRY


	__END_CATCH
}

bool PVPSystemManager::getAltarPosToMove(Creature *pCreature, ZoneID_t& ZoneIDToMove, ZoneCoord_t& XPosToMove, ZoneCoord_t& YPosToMove)
{
	if ( pCreature->isSlayer() )
    {
        ZoneIDToMove = 64;
        XPosToMove = 27;
        YPosToMove = 220;
    }
	else if ( pCreature->isVampire() )
	{
		ZoneIDToMove = 61;
	    XPosToMove = 102;
	    YPosToMove = 220;
    }
    else if ( pCreature->isOusters() )
    {
        ZoneIDToMove = 62;
        XPosToMove = 35;
        YPosToMove = 32;
    }
	else
	{
		return false;
	}

	return true;
}

const int StartPVPWarMessageMinuteMax = 5;
const int StartPVPWarMessageMinute[StartPVPWarMessageMinuteMax] = { 30, 20, 10, 5, 1 };

bool PVPSystemManager::isStartTime()
	throw(Error)
{
	__BEGIN_TRY
		
	Timeval 	currentTime;

	getCurrentTime(currentTime);

	unsigned int openLimitTime =  (m_StateTime.tv_sec - currentTime.tv_sec) / 60;

	if( StartPVPWarMessageMinute[m_StartPVPWarMessageMinuteStep] == (openLimitTime+1) && m_StartPVPWarMessageMinuteStep<StartPVPWarMessageMinuteMax)
	{
		char message[256];
		sprintf(message, "PVP Event will start after %d minutes.", openLimitTime+1); 
		GCSystemMessage	gcSystemMessage;
		gcSystemMessage.setType( SYSTEM_MESSAGE_INFO );
		gcSystemMessage.setMessage( message );
		g_pZoneGroupManager->pushBroadcastPacket( &gcSystemMessage );
		++m_StartPVPWarMessageMinuteStep;
	}

	if( m_StateTime.tv_sec < currentTime.tv_sec )
	{
		m_StartPVPWarMessageMinuteStep = 0;
		return true;
	}		

	return false;

	__END_CATCH
}

void PVPSystemManager::setNextStartTime()
	throw(Error)
{
	__BEGIN_TRY

	VSDateTime now, next;
	VSTime nextTime;

	Timeval currentTime;
	getCurrentTime(currentTime);

	//now.setTime_t( currentTime.tv_sec );
	//next = now.addDays( NextPVPWarOpenDay[now.date().dayOfWeek()] );
	//nextTime = VSTime( 20, 0, 0 );
	//next.setTime( nextTime );

	now = VSDateTime::currentDateTime();
	next = now.addDays( NextPVPWarOpenDay[now.date().dayOfWeek()] );
	next.setTime( VSTime(20, 0, 0));
	
	if ( next < VSDateTime::currentDateTime().addSecs( 5 * 60 ) )
	{
		//nextWarDateTime = nextWarDateTime.addDays( NextWarDay[warType][dt.addDays(1).date().dayOfWeek()] );
		next = next.addDays( 1 );
		next = next.addDays( NextPVPWarOpenDay[next.date().dayOfWeek()] );
	}

	m_StateTime.tv_sec = currentTime.tv_sec + now.secsTo( next );

	filelog("PVPWar.log", "State Close : reamin %d minutes", now.secsTo( next ) / 60 );
	
	__END_CATCH
}

void PVPSystemManager::startWar()
{
	__BEGIN_TRY

//	g_pVariableManager->setVariable(EVENT_PVP, 0);

	while(!m_queuePartyInfo.empty())
	{
		PPARTYINFO pPartyInfo = m_queuePartyInfo.front();
		SAFE_DELETE(pPartyInfo);
		m_queuePartyInfo.pop();
	}
	m_MatchNum = 0;

	if( m_LevelRange > 3 )
	{
		removeWar();
		m_LevelRange = 0;
		return;
	}
	
	Statement* pStmt = NULL;
	Statement* pStmt1 = NULL;
	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getDistConnection( "DARKEDEN" )->createStatement();
		pStmt1 = g_pDatabaseManager->getDistConnection( "DARKEDEN" )->createStatement();
		
		Result* pResult1 = pStmt->executeQuery("SELECT PartyID FROM PVPSystemObject WHERE isAttend=0 AND LevelRange=%d ORDER BY PartyID", m_LevelRange);

		while( pResult1->next() )
		{
			int PartyID = pResult1->getInt(1);
			Result* pResult2 = pStmt1->executeQuery("SELECT Name FROM PVPSystemPartyObject WHERE PartyID=%d", PartyID);
			PPARTYINFO pPartyInfo = new PARTYINFO();
			pPartyInfo->PartyID = PartyID;
			while(pResult2->next() )
				pPartyInfo->m_listPartyName.push_back( pResult2->getString(1) );

			m_queuePartyInfo.push(pPartyInfo);
		}

		pStmt->executeQuery("UPDATE PVPSystemObject SET isAttend=1 WHERE isAttend=0 AND LevelRange=%d", m_LevelRange);
		
		SAFE_DELETE( pStmt );
		SAFE_DELETE( pStmt1 );
	}
	END_DB(pStmt)

	m_hasWar = true;

	

	StringStream msg;
	if( m_LevelRange == 0)
		msg << "The 151-190 Level Match started.";
	else if( m_LevelRange == 1)
		msg << "The 191-250 Level Match started.";
	else if( m_LevelRange == 2)
		msg << "The 251-280 Level Match started.";
	else 
		msg << "The 281+ Level Match started.";
	
	GCSystemMessage	gcSystemMessage;
	gcSystemMessage.setType( SYSTEM_MESSAGE_OPERATOR );
	gcSystemMessage.setMessage( msg.toString() );
	g_pZoneGroupManager->pushBroadcastPacket( &gcSystemMessage );

	g_PVPSystemManager.transNextPartyToStage();
	
	__END_CATCH
}

void PVPSystemManager::transNextPartyToStage()
{
	__BEGIN_TRY


	if( m_queuePartyInfo.size() >=2 )
	{
		m_MatchNum++;
		StringStream msg;
		msg << "PVP Match " << m_MatchNum << ": Party A(";
		m_pPartyInfo1 = m_queuePartyInfo.front();
		m_queuePartyInfo.pop();
		
		m_pPartyInfo2 = m_queuePartyInfo.front();
		m_queuePartyInfo.pop();

		PARTYNAMELIST::iterator itr1 = m_pPartyInfo1->m_listPartyName.begin();
		for(; itr1!=m_pPartyInfo1->m_listPartyName.end(); ++itr1)
		{
			msg << *itr1 << ",";
			Creature* pCreature = g_pPCFinder->getCreature(*itr1);
			if( pCreature != NULL)
			{
				GamePlayer *pGamePlayer = dynamic_cast<GamePlayer *>(pCreature->getPlayer());
				
				EventTransport *pEventTransport = dynamic_cast<EventTransport*>(pGamePlayer->getEvent(Event::EVENT_CLASS_TRANSPORT));
				if ( pEventTransport == NULL )
				{
					pEventTransport = new EventTransport(pGamePlayer);
				}
				pEventTransport->setDeadline( 60*10 );
				pEventTransport->setTargetZone( 1006, 26, 26 );
				pEventTransport->setZoneName("Event Stadium");
				pGamePlayer->addEvent(pEventTransport);
				//pEventTransport->sendMessage();

				setParty1Inside(false);

				GCSystemMessage gcSystemMessage;
				gcSystemMessage.setMessage("In 60 seconds you will be teleported to Arena, be ready !");
				gcSystemMessage.setType(SYSTEM_MESSAGE_OPERATOR);
				pCreature->getPlayer()->sendPacket(&gcSystemMessage);
				
				char message[512];
				sprintf(message, g_pStringPool->c_str(STRID_MENEGROTH_DOUNGEON_LIMITED_TIMER), 60*10);

				GCSystemMessage gcSystemMessage2;
				gcSystemMessage2.setType( SYSTEM_MESSAGE_TIMER );
				gcSystemMessage2.setMessage(message);

				pCreature->getPlayer()->sendPacket(&gcSystemMessage2);
				//transportCreature( pCreature, 1006, 25, 25, false);
			}
		}

		msg << ") VS Party B(";
		PARTYNAMELIST::iterator itr2 = m_pPartyInfo2->m_listPartyName.begin();
		for(; itr2!=m_pPartyInfo2->m_listPartyName.end(); ++itr2)
		{
			msg<<*itr2<< ",";
			Creature* pCreature = g_pPCFinder->getCreature(*itr2);
			if( pCreature != NULL)
			{
				GamePlayer *pGamePlayer = dynamic_cast<GamePlayer *>(pCreature->getPlayer());
				//transportCreature( pCreature, 1006, 25, 25, false);
				EventTransport *pEventTransport = dynamic_cast<EventTransport*>(pGamePlayer->getEvent(Event::EVENT_CLASS_TRANSPORT));
				if ( pEventTransport == NULL )
				{
					pEventTransport = new EventTransport(pGamePlayer);
				}
				pEventTransport->setDeadline( 60*10 );
				pEventTransport->setTargetZone( 1006, 36, 36 );

				pEventTransport->setZoneName("Event Stadium");
				pGamePlayer->addEvent(pEventTransport);
				//pEventTransport->sendMessage();

				setParty2Inside(false);

				GCSystemMessage gcSystemMessage;
				gcSystemMessage.setMessage("In 60 seconds you will be teleported to Arena, be ready !");
				gcSystemMessage.setType(SYSTEM_MESSAGE_OPERATOR);
				pCreature->getPlayer()->sendPacket(&gcSystemMessage);
				
				char message[512];
				sprintf(message, g_pStringPool->c_str(STRID_MENEGROTH_DOUNGEON_LIMITED_TIMER), 60*10);

				GCSystemMessage gcSystemMessage2;
				gcSystemMessage2.setType( SYSTEM_MESSAGE_TIMER );
				gcSystemMessage2.setMessage(message);

				pCreature->getPlayer()->sendPacket(&gcSystemMessage2);
				//transportCreature( pCreature, 1006, 37, 37, false);
			}
		}
		msg<<")";

		GCSystemMessage gcSystemMessage;
		gcSystemMessage.setType(SYSTEM_MESSAGE_OPERATOR);
		gcSystemMessage.setMessage( msg.toString() );
		g_pZoneGroupManager->pushBroadcastPacket(&gcSystemMessage);

		Timeval currentTime;
		getCurrentTime(currentTime);
		m_MatchTime.tv_sec = currentTime.tv_sec + 300; //3mins 300/60 
		
	}
	else
	{
		StringStream msg;
		if(m_LevelRange == 0 )
			msg<<"151-190 Level Match End.";
		else if( m_LevelRange == 1)
			msg<<"191-250 Level Match End.";
		else if( m_LevelRange == 2)
			msg<<"251-280 Level Match End.";
		else
			msg<<"281+ Level Match End.";
		
		if(m_queuePartyInfo.size() == 1)
		{
			msg<<"The Final Winner is the Party(";
			PPARTYINFO pPartyInfo = m_queuePartyInfo.front();
			m_queuePartyInfo.pop();
			PARTYNAMELIST::iterator itr1 = pPartyInfo->m_listPartyName.begin();
			for(; itr1!=pPartyInfo->m_listPartyName.end(); ++itr1)
			{
				msg << *itr1 << ",";
			}
			msg<<")";
			//끝났을떄 보상아이템 키키킥
			/*
			//int coinNum = 10;
			if(m_LevelRange == 0)
			{
			    //getReward2(pPartyInfo, Item::ITEM_CLASS_EVENT_ETC,18,1);
			    getReward2(pPartyInfo, Item::ITEM_CLASS_COMMON_QUEST_ITEM, 56, 1); //Fobiddon Blood
			}
			else if(m_LevelRange == 1)
			{
			    //getReward2(pPartyInfo, Item::ITEM_CLASS_EVENT_ETC, 18, 2);
			    getReward2(pPartyInfo, Item::ITEM_CLASS_EFFECT_ITEM, 86, 1); //7x stone
			}
			else if(m_LevelRange == 2)
			{
			    //getReward2(pPartyInfo,Item::ITEM_CLASS_EVENT_ETC,18,3);
			    getReward2(pPartyInfo, Item::ITEM_CLASS_EVENT_GIFT_BOX, 56 ,1); //Lovely Box
			    
			}
			else if(m_LevelRange == 3)
			{
			    //getReward2(pPartyInfo,Item::ITEM_CLASS_EVENT_ETC,18,5);
			    getReward2(pPartyInfo, Item::ITEM_CLASS_EVENT_GIFT_BOX, 168 ,1); //Treasures of the pyramid box
			}*/
		}
		GCSystemMessage gcSystemMessage;
		gcSystemMessage.setType(SYSTEM_MESSAGE_OPERATOR);
		gcSystemMessage.setMessage( msg.toString() );
		g_pZoneGroupManager->pushBroadcastPacket(&gcSystemMessage);
		
		m_LevelRange++;
		startWar();
	}
	__END_CATCH
}

bool PVPSystemManager::isPartyDeadInStage()
{
	__BEGIN_TRY

	if( !isParty1Inside()  || !isParty2Inside() )
		return false;
	
	bool bResult = false;
	if( m_pPartyInfo1 != NULL && m_pPartyInfo2 != NULL)
	{
		bool isParty1Alive = false;
		bool isParty2Alive = false;
		
		PARTYNAMELIST::iterator itr1 = m_pPartyInfo1->m_listPartyName.begin();
		for(; itr1!=m_pPartyInfo1->m_listPartyName.end(); ++itr1)
		{
			Creature* pCreature = g_pPCFinder->getCreature(*itr1);
			if( pCreature != NULL)
				if( !pCreature->isDead() )
				{	
					GamePlayer *pGamePlayer = dynamic_cast<GamePlayer *>(pCreature->getPlayer());
					EventTransport *pEventTransport = dynamic_cast<EventTransport*>(pGamePlayer->getEvent(Event::EVENT_CLASS_TRANSPORT));
					if( pEventTransport != NULL)
					{
						if(pEventTransport->getTransportZoneID() == 1006)
							return false;
					}
					if( isInStage( pCreature ) )
					{
						isParty1Alive = true;
						break;
					}
				}
		}

		PARTYNAMELIST::iterator itr2 = m_pPartyInfo2->m_listPartyName.begin();
		for(; itr2!=m_pPartyInfo2->m_listPartyName.end(); ++itr2)
		{
			Creature* pCreature = g_pPCFinder->getCreature(*itr2);
			if( pCreature != NULL)
				if( !pCreature->isDead() )
				{
					GamePlayer *pGamePlayer = dynamic_cast<GamePlayer *>(pCreature->getPlayer());
					EventTransport *pEventTransport = dynamic_cast<EventTransport*>(pGamePlayer->getEvent(Event::EVENT_CLASS_TRANSPORT));
					if( pEventTransport != NULL)
					{
						if(pEventTransport->getTransportZoneID() == 1006)
							return false;
					}
					if( isInStage( pCreature ) )
					{
						isParty2Alive = true;
						break;
					}
				}
		}


		if( isParty1Alive && isParty2Alive ) //continue
		{
			bResult = false;
		}
		else if( !isParty1Alive && !isParty2Alive)//its a draw
		{
//			m_queuePartyInfo.push(m_pPartyInfo1);
//			m_queuePartyInfo.push(m_pPartyInfo2);

			//SAFE_DELETE(m_pPartyInfo1);
			//SAFE_DELETE(m_pPartyInfo2);
			bResult = true;
			m_ResultMatch = 0;
		}
		else if( isParty1Alive && !isParty2Alive )// Party1 win
		{
			int coinNum = 1;
			if(m_LevelRange == 0)	coinNum=2;
			else if(m_LevelRange == 1)	coinNum=4;
			else if(m_LevelRange == 2)	coinNum = 6;
			else if(m_LevelRange == 3)	coinNum =8;
			
			getReward(m_pPartyInfo1, coinNum);
			
			m_queuePartyInfo.push(m_pPartyInfo1);
			bResult = true;
			GCSystemMessage gcSystemMessage;
			gcSystemMessage.setMessage("Party A Won, transport players out after 5 second!");
			gcSystemMessage.setType(SYSTEM_MESSAGE_OPERATOR);
			m_pZone->broadcastPacket(&gcSystemMessage);
			
			Statement* pStmt = NULL;
			BEGIN_DB
			{
				pStmt = g_pDatabaseManager->getDistConnection( "DARKEDEN" )->createStatement();
				pStmt->executeQuery("UPDATE PVPSystemObject SET Status=Status+1 WHERE PartyID=%d", m_pPartyInfo1->PartyID);
				SAFE_DELETE(pStmt)
			}
			END_DB(pStmt)

			m_ResultMatch  = 1;
			//SAFE_DELETE(m_pPartyInfo2);	
					
		}
		else if( isParty2Alive && !isParty1Alive)// Party2 win
		{
			int coinNum = 1;
			if(m_LevelRange == 0)	coinNum=2;
			else if(m_LevelRange == 1)	coinNum=4;
			else if(m_LevelRange == 2)	coinNum = 6;
			else if(m_LevelRange == 3)	coinNum =8;

			
			getReward(m_pPartyInfo2, coinNum);
			
			m_queuePartyInfo.push(m_pPartyInfo2);
			bResult = true;
			GCSystemMessage gcSystemMessage;
			gcSystemMessage.setMessage("Party B Won, transport players out stash after 5 second!");
			gcSystemMessage.setType(SYSTEM_MESSAGE_OPERATOR);
			m_pZone->broadcastPacket(&gcSystemMessage);

			Statement* pStmt = NULL;
			BEGIN_DB
			{
				pStmt = g_pDatabaseManager->getDistConnection( "DARKEDEN" )->createStatement();
				pStmt->executeQuery("UPDATE PVPSystemObject SET Status=Status+1 WHERE PartyID=%d", m_pPartyInfo2->PartyID);
				SAFE_DELETE(pStmt)
			}
			END_DB(pStmt)

			m_ResultMatch = 2;
			//SAFE_DELETE(m_pPartyInfo1);
		}
	}

	return bResult;
	
	__END_CATCH
}
	
void PVPSystemManager::removeWar()
{
	__BEGIN_TRY

	m_hasWar = false;
	setNextStartTime();

	StringStream msg;
	msg << "The PVP Event End!";
	GCSystemMessage	gcSystemMessage;
	gcSystemMessage.setType( SYSTEM_MESSAGE_OPERATOR );
	gcSystemMessage.setMessage( msg.toString() );
	g_pZoneGroupManager->pushBroadcastPacket( &gcSystemMessage );
	
	__END_CATCH
}

void PVPSystemManager::transAllBodyOutStage() 
{
	__BEGIN_TRY

	if( m_pPartyInfo1 != NULL)
	{
		PARTYNAMELIST::iterator itr1 = m_pPartyInfo1->m_listPartyName.begin();
		for(; itr1!=m_pPartyInfo1->m_listPartyName.end(); ++itr1)
		{
			Creature* pCreature = g_pPCFinder->getCreature(*itr1);
			if( pCreature != NULL)
			{
				GamePlayer *pGamePlayer = dynamic_cast<GamePlayer *>(pCreature->getPlayer());
				EventTransport *pEventTransport = dynamic_cast<EventTransport*>(pGamePlayer->getEvent(Event::EVENT_CLASS_TRANSPORT));
				if ( pEventTransport == NULL )
				{
					pEventTransport = new EventTransport(pGamePlayer);
				}
				pEventTransport->setDeadline( 5*10 );
				if( m_ResultMatch  == 1)
				{
					if( pCreature->isSlayer() )
						pEventTransport->setTargetZone( 64, 27, 220 );
					else if( pCreature->isVampire())
						pEventTransport->setTargetZone( 61, 102, 220 );
					else if( pCreature->isOusters() )
						pEventTransport->setTargetZone( 62, 35, 32 );
					else
						pEventTransport->setTargetZone( 1006, 31, 15 );
				}
				else
					pEventTransport->setTargetZone( 1006, 31, 15 );
				
				//pEventTransport->setZoneName("Event Stadium");
				pGamePlayer->addEvent(pEventTransport);
				//pEventTransport->sendMessage();
				//transportCreature(pCreature, 1006, 31, 15, false);
			}
		}
	}

	if( m_pPartyInfo2 != NULL)
	{
		PARTYNAMELIST::iterator itr2 = m_pPartyInfo2->m_listPartyName.begin();
		for(; itr2!=m_pPartyInfo2->m_listPartyName.end(); ++itr2)
		{
			Creature* pCreature = g_pPCFinder->getCreature(*itr2);
			if( pCreature != NULL)
			{
				GamePlayer *pGamePlayer = dynamic_cast<GamePlayer *>(pCreature->getPlayer());
				EventTransport *pEventTransport = dynamic_cast<EventTransport*>(pGamePlayer->getEvent(Event::EVENT_CLASS_TRANSPORT));
				if ( pEventTransport == NULL )
				{
					pEventTransport = new EventTransport(pGamePlayer);
				}
				pEventTransport->setDeadline( 5*10 );
				
				if( m_ResultMatch  == 2)
				{
					if( pCreature->isSlayer() )
						pEventTransport->setTargetZone( 64, 27, 220 );
					else if( pCreature->isVampire())
						pEventTransport->setTargetZone( 61, 102, 220 );
					else if( pCreature->isOusters() )
						pEventTransport->setTargetZone( 62, 35, 32 );
					else
						pEventTransport->setTargetZone( 1006, 47, 31 );
				}
				else
					pEventTransport->setTargetZone( 1006, 47, 31 );

				//pEventTransport->setZoneName("Event Stadium");
				pGamePlayer->addEvent(pEventTransport);
				//pEventTransport->sendMessage();
				//transportCreature(pCreature, 1006, 47, 31, false);
			}

		}
	}

	//SAFE_DELETE(m_pPartyInfo1);
	//SAFE_DELETE(m_pPartyInfo2);
	
	__END_CATCH
}

bool PVPSystemManager::isInStage(Creature* pCreature)
{
	__BEGIN_TRY

	Assert( pCreature!= NULL);

	ZoneID_t ZoneID = pCreature->getZoneID();
	ZoneCoord_t X = pCreature->getX();
	ZoneCoord_t Y = pCreature->getY();

	if( ZoneID != 1006)
		return false;
	
	if( X >= 22 && X <= 39 && Y >=22 && Y <= 40)
	{
		if( X <= 26 && Y <= 26)
			if ( Y < (48-X) )	return false;
		else if( X >= 31 && Y <= 30)
			if( Y > ( X -9 ) )	return false;
		else if( X <= 30 && Y >= 32)
			if( Y > ( X+10 ) )	return false;
		else if( X >= 36 && Y >= 37 )
			if( Y > ( 76-X) )	return false;
	}
	else 
		return false;

	return true;
	
	__END_CATCH
}

bool PVPSystemManager::isInStageByXY(Coord_t X, Coord_t Y)
{
	__BEGIN_TRY

	if( X >= 22 && X <= 39 && Y >=22 && Y <= 40)
	{
		if( X <= 26 && Y <= 26)
			if ( Y < (48-X) )	return false;
		else if( X >= 31 && Y <= 30)
			if( Y > ( X -9 ) )	return false;
		else if( X <= 30 && Y >= 32)
			if( Y > ( X+10 ) )	return false;
		else if( X >= 36 && Y >= 37 )
			if( Y > ( 76-X) )	return false;
		
		return true;
	}
	else 
		return false;

	return false;
	
	__END_CATCH
}

void PVPSystemManager::getReward2(PPARTYINFO pPartyInfo, Item::ItemClass itemClass, ItemType_t itemType, int Num)
{
    __BEGIN_TRY
    
    if( Num <=0 )
        return;
    
    if(pPartyInfo!=NULL)
    {
        PARTYNAMELIST::iterator itr = pPartyInfo->m_listPartyName.begin();
        for(; itr!=pPartyInfo->m_listPartyName.end(); ++itr)
        {
            Creature* pCreature = g_pPCFinder->getCreature(*itr);
    
            if( pCreature==NULL)
                continue;
            
            if (pCreature->isPC())
            {
                PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
                list<OptionType_t> null;
                pPC->addItemToInventory(itemClass,itemType,Num,null);
            }
        }   
    }
    __END_CATCH
}

void PVPSystemManager::getReward(PPARTYINFO pPartyInfo, int coinNum)
{
	__BEGIN_TRY

//	int coinNum=g_pVariableManager->getVariable(EVENT_PVP_REWARD_COIN_NUM);
	if( coinNum <=0 )
		return;
	
	if(pPartyInfo!=NULL)
	{
		PARTYNAMELIST::iterator itr = pPartyInfo->m_listPartyName.begin();
		for(; itr!=pPartyInfo->m_listPartyName.end(); ++itr)
		{
			Creature* pCreature = g_pPCFinder->getCreature(*itr);

			if( pCreature==NULL)
				continue;
			
			if (pCreature->isPC())
			{
				PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
				Inventory* pInventory = pPC->getInventory();

				Item* pItem = NULL;

				list<OptionType_t> nullList;
				pItem = g_pItemFactoryManager->createItem(Item::ITEM_CLASS_EVENT_ETC, 18, nullList);
				ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo(Item::ITEM_CLASS_EVENT_ETC, 18);
				_TPOINT pt;
				pItem->setNum(coinNum);
				if( !pInventory->findAddStackItem( pItem, pt ) )
				{
					//        .
					if( !pInventory->getEmptySlot( pItem, pt) )
					{
						char msg[128];
						sprintf(msg, g_pStringPool->c_str(STRID_NOT_ENOUGH_INVENTORY_SPACE_NOT_GET_ITEM), pItemInfo->getName().c_str()); // 20070814
						GCSystemMessage gcSystemMessage;
						gcSystemMessage.setMessage(msg);
						pPC->getPlayer()->sendPacket(&gcSystemMessage);
						break;
					}


					(m_pZone->getObjectRegistry()).registerObject(pItem);

					if( pInventory->addItem( pItem, pt ) )
					{
						pItem->create( pPC->getName(), STORAGE_INVENTORY, 0, pt.x, pt.y );
						filelog( "Dracula.log", "%s %s .", pPC->getName().c_str(), pItemInfo->getName().c_str());

						remainTraceLog( pItem, "PVPREWARD", pPC->getName(), ITEM_LOG_CREATE, DETAIL_EVENTNPC );
						
						GCCreateItem gcCreateItem;
						makeGCCreateItem( &gcCreateItem, pItem, pt.x, pt.y );
						pCreature->getPlayer()->sendPacket(&gcCreateItem);
				
					}
					else
					{
						pInventory->deleteItem( pItem->getObjectID() );
						char msg[128];
						sprintf(msg, g_pStringPool->c_str(STRID_NOT_ENOUGH_INVENTORY_SPACE_NOT_GET_ITEM), pItemInfo->getName().c_str());
						GCSystemMessage gcSystemMessage;
						gcSystemMessage.setMessage(msg);
						pPC->getPlayer()->sendPacket(&gcSystemMessage);
						break;
					}

				}
				else
				{
					pItem = pInventory->findItem( pItem->getItemClass(), pItem->getItemType(), (CoordInven_t&)pt.x, (CoordInven_t&)pt.y );
					Assert(pItem != NULL);
						
					pItem->setNum( pItem->getNum() + coinNum );

					pItem->save( pPC->getName(), STORAGE_INVENTORY, 0, pt.x, pt.y );

					GCCreateItem gcCreateItem;
					makeGCCreateItem( &gcCreateItem, pItem, pt.x, pt.y );
					pCreature->getPlayer()->sendPacket(&gcCreateItem);
					filelog( "Dracula.log", "%s %s .", pPC->getName().c_str(), pItemInfo->getName().c_str());
				}			
			}
		}	
	}
	__END_CATCH
}

bool PVPSystemManager::isMatchTimeOut()
{
	__BEGIN_TRY
		
	if( !isParty1Inside()  || !isParty2Inside() )
		return false;

	if( m_pPartyInfo1 != NULL && m_pPartyInfo2 != NULL)
	{
		Timeval currentTime;
		getCurrentTime(currentTime);
		if( currentTime > m_MatchTime )
			return true;
		else 
			return false;
	}

	return false;
	
	__END_CATCH
}
//---------------------------PVPSystemZoneManager------------
PVPSystemZoneManager::PVPSystemZoneManager(Zone * pZone)
	throw(Error)
{
	__BEGIN_TRY

	cout << "PVPSystemManager, ZoneID:" << pZone->getZoneID() << endl;
	m_Mutex.setName("PVPSystemZoneManager");
	m_pZone = pZone;
	m_ZoneID = pZone->getZoneID();
	m_bIsTrap = false;
	m_nMaxPassPlayer = 15;
	m_nPassPlayer2F = 0;
	g_PVPSystemManager.setZone(pZone);
	
	pZone->stopTime();
	pZone->setTimeband( 2 );
	pZone->resetDarkLightInfo();
	
	__END_CATCH
}

PVPSystemZoneManager::~PVPSystemZoneManager()
	throw(Error)
{
	__BEGIN_TRY

	__END_CATCH
}

bool PVPSystemZoneManager::heartbeat() 
	throw (Error)
{
	__BEGIN_TRY
		
	if(!g_pVariableManager->getVariable(EVENT_PVP))
		return true;
	
	if( g_PVPSystemManager.hasWar() )
	{
		if( g_PVPSystemManager.isPartyDeadInStage() )
		{
			g_PVPSystemManager.transAllBodyOutStage();
			g_PVPSystemManager.transNextPartyToStage();
		}
		else if( g_PVPSystemManager.isMatchTimeOut() )
		{
			g_PVPSystemManager.transAllBodyOutStage();
			g_PVPSystemManager.transNextPartyToStage();
		}
//		else
//		{
//			g_PVPSystemManager.transNextPartyToStage();
//		}
	}
	else if( g_PVPSystemManager.isStartTime() )
	{
		g_PVPSystemManager.startWar();
		
	}


	__END_CATCH

	return true;
}

bool PVPSystemZoneManager::enter2FPC(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
		
	Assert(pCreature != NULL);
	Assert(pCreature->isPC());

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pCreature->getPlayer());		
	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	__ENTER_CRITICAL_SECTION(m_Mutex)

/*	if (pPC->isDM() || pPC->isGOD())
	{
		m_Mutex.unlock();
			
		filelog("Dracula.log", "enterPC - DM or GOD pass! - %s", pPC->getName().c_str() );
		return true;
	}
*/
	if (m_nPassPlayer2F >= m_nMaxPassPlayer )
	{
		m_Mutex.unlock();

		filelog("Dracula.log", "enterPC - over limited pass. deny! - %s, PassPlayerNum : %d, MaxNum : %d", pPC->getName().c_str(),m_nPassPlayer2F,m_nMaxPassPlayer );
		return false;
	}

	//     
	++m_nPassPlayer2F;

	filelog("Dracula.log", "enterPC - pass! - PassPlayerNum : %d", m_nPassPlayer2F );

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH

	return true;

}

bool PVPSystemZoneManager::leaveCreature(Creature * pCreature)
	throw(Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

/*	if (pCreature->isDM() || pCreature->isGOD())
	{
		m_Mutex.unlock();
		return true;
	}
	*/

	--m_nPassPlayer2F;

	filelog("Dracula.log", "leavePC - pass! - PassPlayerNum : %d", m_nPassPlayer2F );

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH

	return true;
}


