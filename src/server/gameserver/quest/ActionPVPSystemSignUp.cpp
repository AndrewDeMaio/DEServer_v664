////////////////////////////////////////////////////////////////////////////////
// Filename    : ActionGiveHellGardenSeedItem.cpp
// Written By  : 
// Description :
// 
// History.
//
//  Date        Writer         Description
// ---------- ----------- ------------------------------------------------------
//
////////////////////////////////////////////////////////////////////////////////

#include "ActionPVPSystemSignUp.h"
#include "PlayerCreature.h"
#include "GamePlayer.h"
#include "Item.h"
#include "ItemUtil.h"
#include "Inventory.h"
#include "Zone.h"
#include "ItemFactoryManager.h"
#include "DB.h"
#include "Thread.h"
#include "Treasure.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "MonsterInfo.h"
#include "QuestItem.h"
#include "ItemUtil.h"
#include "StringPool.h"
#include "ItemMineInfo.h"
#include "PacketUtil.h"
#include "ItemGradeManager.h"
#include "ItemInfoManager.h"
#include "FlagSet.h"
#include <list>

#include "Gpackets/GCCreateItem.h"
#include "Gpackets/GCNPCResponse.h"
#include "Gpackets/GCSystemMessage.h"
#include "Gpackets/GCDeleteInventoryItem.h"

#include "SystemAvailabilitiesManager.h"
#include "VariableManager.h"
#include "PVPSystemManager.h"
////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void ActionPVPSystemSignUp::read(PropertyBuffer & propertyBuffer)
    throw (Error)
{
    __BEGIN_TRY

 /*	try
	{
		m_Type = (ItemType_t)propertyBuffer.getPropertyInt("QuestItem");
	}
	catch (NoSuchElementException & nsee)
	{
		throw Error(nsee.toString());
	}
*/
   __END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//  .
////////////////////////////////////////////////////////////////////////////////
void ActionPVPSystemSignUp::execute(Creature * pCreature1 , Creature * pCreature2) 
	throw (Error)
{
	__BEGIN_TRY

	Assert(pCreature1 != NULL);
	Assert(pCreature2 != NULL);
	Assert(pCreature1->isNPC());
	Assert(pCreature2->isPC());
	
	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature2);
	Assert(pPC != NULL);

	Player* pPlayer = pPC->getPlayer();
	Assert(pPlayer != NULL);

	GCNPCResponse okpkt;
	pPlayer->sendPacket(&okpkt);
	StringStream message;

	Zone* pZone = pPC->getZone();
	Assert( pZone != NULL );

	if(!g_pVariableManager->getVariable(EVENT_PVP))
	{
		GCSystemMessage gcSystemMessage;
		gcSystemMessage.setMessage("PVP EVENT not open!");
		pPlayer->sendPacket(&gcSystemMessage);
		
		GCNPCResponse response;
		response.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
		return;
	}

	if(g_PVPSystemManager.hasWar() )
	{
		GCSystemMessage gcSystemMessage;
		gcSystemMessage.setMessage("Can't apply, cuz the pvp event is running!");
		pPlayer->sendPacket(&gcSystemMessage);
		
		GCNPCResponse response;
		response.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
		return;
	}
	
//	Inventory* pInventory = pPC->getInventory();
	int PartyID = 0;
	LocalPartyManager* pLPM = NULL;

	int AttendNum = g_pVariableManager->getVariable(EVENT_PVP_ATTEND_NUM);
	PartyID = pCreature2->getPartyID();

	int AdvancementLevel = pPC->getAdvancementClassLevel();

	if(AdvancementLevel == 0 )
	{
		GCSystemMessage gcSystemMessage;
		gcSystemMessage.setMessage("must 151+ level can participate!");
		pPlayer->sendPacket(&gcSystemMessage);
		
		GCNPCResponse response;
		response.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
		return;
	}

	int LevelRange = 0;
	if( AdvancementLevel >= 1 && AdvancementLevel < 41 ) //151 - 190
		LevelRange = 0;
	else if( AdvancementLevel >= 41 && AdvancementLevel < 101) // 191 - 250
		LevelRange = 1;
	else if( AdvancementLevel >= 101 && AdvancementLevel < 131) // 251 - 280
		LevelRange = 2;
	else													// 221+	
		LevelRange = 3;
		
	if ( PartyID != 0 && AttendNum >= 2 && AttendNum <=6)
	{
		//pLPM = pCreature2->getLocalPartyManager();

		//Party *pParty = pLPM->getParty(PartyID);
		Party* pParty = g_pGlobalPartyManager->getParty(PartyID);
		
		hash_map<string, Creature*> MemberMap = pParty->getMemberMap();
		hash_map<string, Creature*>::iterator MemberMapIter;
		list<Creature*> MemberList;

		Creature *pMemberCreature;
	
		MemberMapIter = MemberMap.begin();
		for( ; MemberMapIter != MemberMap.end() ; ++MemberMapIter)
		{
			pMemberCreature = MemberMapIter->second;
			if ( pMemberCreature != NULL )
				MemberList.push_back(pMemberCreature);
		}
		bool bCanSign=true;
		if( MemberList.size() == AttendNum)
		{
			Statement* pStmt = NULL;
			BEGIN_DB
			{
				pStmt = g_pDatabaseManager->getDistConnection( "DARKEDEN" )->createStatement();
				
				list<Creature*>::iterator litr = MemberList.begin();
				StringStream msg;
				msg << "Party(";
				for (; litr != MemberList.end(); litr++)
				{
					Creature* pCreature = (*litr);
					Assert(pCreature != NULL);
					Assert(pCreature->isPC());

					PlayerCreature* pPCPartyMember = dynamic_cast<PlayerCreature*>(pCreature);
					
					Result* pResult = pStmt->executeQuery("SELECT * FROM PVPSystemObject, PVPSystemPartyObject WHERE PVPSystemObject.PartyID = PVPSystemPartyObject.PartyID AND PVPSystemObject.isAttend=0 AND PVPSystemPartyObject.Name='%s'",
						pPCPartyMember->getName().c_str() );
					
					if(pResult->next())
					{
						bCanSign = false;
						char msg[100];
						sprintf(msg, "%s had joined other party!", pPCPartyMember->getName().c_str());
						GCSystemMessage gcSystemMessage;
						gcSystemMessage.setMessage(msg);
						pPlayer->sendPacket(&gcSystemMessage);
						
					}

					if( LevelRange == 0 )
					{
						if( !(pPCPartyMember->getAdvancementClassLevel() >= 1 && pPCPartyMember->getAdvancementClassLevel() < 41) )
							bCanSign = false;
						
					}
					else if( LevelRange == 1)
					{
						if( !(pPCPartyMember->getAdvancementClassLevel() >= 41 && pPCPartyMember->getAdvancementClassLevel() < 101) )
							bCanSign = false;
					}
					else if( LevelRange == 2)
					{
						if( !(pPCPartyMember->getAdvancementClassLevel() >= 101 && pPCPartyMember->getAdvancementClassLevel() < 131) )
							bCanSign = false;
					}
					else
					{
						if( !(pPCPartyMember->getAdvancementClassLevel() >= 131) )
							bCanSign = false;
					}
					
					
					msg << pPCPartyMember->getName() << ",";
				}
				msg << ") Joined PVP!";

				
				
				int Count = 0;
				Result* pResult = pStmt->executeQuery("SELECT count(*) FROM PVPSystemObject WHERE isAttend=0 AND LevelRange=%d", LevelRange);
				if(pResult->next())
					Count = pResult->getInt(1);

				int MatchNum = Count/2 + 1;

				msg << " In ";
				if( LevelRange == 0)
					msg << "151-190 Level ";
				else if( LevelRange == 1)
					msg << "191-250 Level ";
				else if(LevelRange == 2)
					msg << "251-280 Level ";
				else
					msg << "281+ Level ";

				msg << "Match "  << MatchNum << ".";
				
				if( bCanSign )
				{
				    int NeedMoney = 0;
				    ItemType_t itemType = 0;
					//int NeedMoney = g_pVariableManager->getVariable(EVENT_PVP_ATTEND_FEE);
					//NeedMoney *= AttendNum;
					if( LevelRange == 0)
					{
					    NeedMoney = 20000000;
					    itemType = 3;
					}
					else if( LevelRange == 1)
					{
					    NeedMoney = 40000000;
					    itemType = 1;
					}
					else if( LevelRange == 2)
					{
					    NeedMoney = 60000000;
					    itemType = 8;
					}
					else
					{
					    NeedMoney = 80000000;
					    itemType = 9;
					}
					    
					if( pPC->getGold() < NeedMoney )
					{	
						GCNPCResponse gcNPCResponse;
						//gcNPCResponse.setCode(NPC_RESPONSE_NOT_ENOUGH_MONEY);
						//pGamePlayer->sendPacket( &gcNPCResponse );
						gcNPCResponse.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
						pPlayer->sendPacket( &gcNPCResponse );

						GCSystemMessage gcSystemMessage;
						gcSystemMessage.setMessage( "You can't join PVP without enough money." );
						pPlayer->sendPacket( &gcSystemMessage );
						return;
					}
/*
					
                    if( pPC->getItemClassTypeNum( Item::ITEM_CLASS_QUEST_ITEM, itemType ) > 0)
					    pPC->decreaseItemClassTypeNum(Item::ITEM_CLASS_QUEST_ITEM, itemType, 1);
					else
					{
						GCNPCResponse gcNPCResponse;
						//gcNPCResponse.setCode(NPC_RESPONSE_NOT_ENOUGH_MONEY);
						//pGamePlayer->sendPacket( &gcNPCResponse );
						gcNPCResponse.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
						pPlayer->sendPacket( &gcNPCResponse );

						GCSystemMessage gcSystemMessage;
						gcSystemMessage.setMessage( "You can't join PVP without item." );
						pPlayer->sendPacket( &gcSystemMessage );
						return;					
					}
*/
					pPC->decreaseGoldEx( NeedMoney );
					GCModifyInformation gcModifyInformation;
					gcModifyInformation.addLongData( MODIFY_GOLD, pPC->getGold() );
					pPlayer->sendPacket( &gcModifyInformation );
          		
					int PartyID=1;
					
					pResult = pStmt->executeQuery("SELECT count(*) FROM PVPSystemObject");
					pResult->next();
					if( pResult->getInt(1) > 0 )
					{
						Result* pResult = pStmt->executeQuery("SELECT MAX(PartyID) FROM PVPSystemObject");
						if(pResult->next())
							PartyID = pResult->getInt(1) + 1;
					}

					pStmt->executeQuery("INSERT INTO PVPSystemObject(PartyID, SignName, SignDate, LevelRange) VALUES(%d, '%s', now(), %d)", 
						PartyID,
						pPC->getName().c_str(),
						LevelRange);

					litr = MemberList.begin();
					for (; litr != MemberList.end(); litr++)
					{
						Creature* pCreature = (*litr);
						PlayerCreature* pPCPartyMember = dynamic_cast<PlayerCreature*>(pCreature);
						pStmt->executeQuery("INSERT INTO PVPSystemPartyObject(Name, PartyID) VALUES('%s', %d)",
							pPCPartyMember->getName().c_str(), PartyID );

						GCSystemMessage gcSystemMessage;
						gcSystemMessage.setMessage(msg.toString());
						
						pPCPartyMember->getPlayer()->sendPacket(&gcSystemMessage);
					}
				}
				else 
				{
					char msg[100];
					sprintf(msg, "Please make sure for your party member's level in your level range!");
					GCSystemMessage gcSystemMessage;
					gcSystemMessage.setMessage(msg);
					pPlayer->sendPacket(&gcSystemMessage);					
				}


				SAFE_DELETE( pStmt );
			}
			END_DB(pStmt)
		}
		else
		{
			GCSystemMessage gcSystemMessage;
			StringStream msg;
			msg << "The Party Num must be " << AttendNum << "Num.";
			gcSystemMessage.setMessage(msg.toString());
			pPlayer->sendPacket(&gcSystemMessage);
		}

	}
	else if(AttendNum == 1)
	{
		bool bCanSign=true;
		Statement* pStmt = NULL;
		BEGIN_DB
		{
			pStmt = g_pDatabaseManager->getDistConnection( "DARKEDEN" )->createStatement();

			StringStream msg;
			
			Result* pResult = pStmt->executeQuery("SELECT * FROM PVPSystemObject, PVPSystemPartyObject WHERE PVPSystemObject.PartyID = PVPSystemPartyObject.PartyID AND PVPSystemObject.isAttend=0 AND PVPSystemPartyObject.Name='%s'",
				pPC->getName().c_str() );
			
			if(pResult->next())
			{
				bCanSign = false;
				char msg[100];
				sprintf(msg, "%s had joined PVP!", pPC->getName().c_str());
				GCSystemMessage gcSystemMessage;
				gcSystemMessage.setMessage(msg);
				pPlayer->sendPacket(&gcSystemMessage);
				
			}
			
			msg << pPC->getName() << ",";
			
			msg << " Joined PVP!";
			
			int Count = 0;
			pResult = pStmt->executeQuery("SELECT count(*) FROM PVPSystemObject WHERE isAttend=0 AND LevelRange=%d", LevelRange);
			if(pResult->next())
				Count = pResult->getInt(1);

			int MatchNum = Count/2 + 1;

			msg << " In ";
			if( LevelRange == 0)
				msg << "151-190 Level ";
			else if( LevelRange == 1)
				msg << "191-250 Level ";
			else if(LevelRange == 2)
				msg << "251-280 Level ";
			else
				msg << "281+ Level ";

			msg << "Match "  << MatchNum << ".";
			
			if( bCanSign )
			{
                    int NeedMoney = 0;
                    ItemType_t itemType = 0;
                    //int NeedMoney = g_pVariableManager->getVariable(EVENT_PVP_ATTEND_FEE);
                    //NeedMoney *= AttendNum;
                    if( LevelRange == 0)
                    {
                        NeedMoney = 20000000;
                        itemType = 3;
                    }
                    else if( LevelRange == 1)
                    {
                        NeedMoney = 40000000;
                        itemType = 1;
                    }
                    else if( LevelRange == 2)
                    {
                        NeedMoney = 60000000;
                        itemType = 8;
                    }
                    else
                    {
                        NeedMoney = 80000000;
                        itemType = 9;
                    }

					if( pPC->getGold() < NeedMoney )
					{	
						GCNPCResponse gcNPCResponse;
						//gcNPCResponse.setCode(NPC_RESPONSE_NOT_ENOUGH_MONEY);
						//pGamePlayer->sendPacket( &gcNPCResponse );
						gcNPCResponse.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
						pPlayer->sendPacket( &gcNPCResponse );

						GCSystemMessage gcSystemMessage;
						gcSystemMessage.setMessage( "You can't join PVP without enough money." );
						pPlayer->sendPacket( &gcSystemMessage );
						return;
					}
/*					
                    if( pPC->getItemClassTypeNum( Item::ITEM_CLASS_QUEST_ITEM, itemType ) > 0)
					    pPC->decreaseItemClassTypeNum(Item::ITEM_CLASS_QUEST_ITEM, itemType, 1);
					else
					{
						GCNPCResponse gcNPCResponse;
						//gcNPCResponse.setCode(NPC_RESPONSE_NOT_ENOUGH_MONEY);
						//pGamePlayer->sendPacket( &gcNPCResponse );
						gcNPCResponse.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
						pPlayer->sendPacket( &gcNPCResponse );

						GCSystemMessage gcSystemMessage;
						gcSystemMessage.setMessage( "You can't join PVP without item." );
						pPlayer->sendPacket( &gcSystemMessage );
						return;
				    }

*/

					pPC->decreaseGoldEx( NeedMoney );
					GCModifyInformation gcModifyInformation;
					gcModifyInformation.addLongData( MODIFY_GOLD, pPC->getGold() );
					pPlayer->sendPacket( &gcModifyInformation );
					
					int PartyID=1;
					pResult = pStmt->executeQuery("SELECT count(*) FROM PVPSystemObject");
					pResult->next();
					if( pResult->getInt(1) > 0 )
					{
						Result* pResult = pStmt->executeQuery("SELECT MAX(PartyID) FROM PVPSystemObject");
						if(pResult->next())
							PartyID = pResult->getInt(1) + 1;
					}

					pStmt->executeQuery("INSERT INTO PVPSystemObject(PartyID, SignName, SignDate, LevelRange) VALUES(%d, '%s', now(), %d)", 
						PartyID,
						pPC->getName().c_str(),
						LevelRange );
					
					pStmt->executeQuery("INSERT INTO PVPSystemPartyObject(Name, PartyID) VALUES('%s', %d)",
						pPC->getName().c_str(), PartyID );

					GCSystemMessage gcSystemMessage;
					gcSystemMessage.setMessage(msg.toString());
					
					pPC->getPlayer()->sendPacket(&gcSystemMessage);				
			}
			SAFE_DELETE( pStmt );
		}
		END_DB(pStmt)
	}
	else
	{
		GCSystemMessage gcSystemMessage;
		StringStream msg;
		msg << "Just the Party can join! and the Party Num must be " << AttendNum << " Num.";		
		gcSystemMessage.setMessage(msg.toString());
		pPlayer->sendPacket(&gcSystemMessage);		
	}

	
	GCNPCResponse response;
	response.setCode( NPC_RESPONSE_QUIT_DIALOGUE );

	pPlayer->sendPacket(&response);
	__END_CATCH
}


////////////////////////////////////////////////////////////////////////////////
// get debug string
////////////////////////////////////////////////////////////////////////////////
string ActionPVPSystemSignUp::toString () const 
	throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "ActionGiveDraculaCastleItem("
	    << ")";
	return msg.toString();

	__END_CATCH
}
