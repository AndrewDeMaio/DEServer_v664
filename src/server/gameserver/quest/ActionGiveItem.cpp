////////////////////////////////////////////////////////////////////////////////
// Filename    : ActionGiveItem.cpp
// Written By  : 
// Description :
////////////////////////////////////////////////////////////////////////////////

#include "ActionGiveItem.h"
#include "Creature.h"
#include "PlayerCreature.h"
#include "GamePlayer.h"
#include "ItemFactoryManager.h"
#include "Inventory.h"
#include "ItemUtil.h"
#include "Zone.h"
#include "PacketUtil.h"
#include "DB.h"

#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"

#include "Gpackets/GCCreateItem.h"
#include "Gpackets/GCNPCResponse.h"

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void ActionGiveItem::read (PropertyBuffer & propertyBuffer)
    throw (Error)
{
    __BEGIN_TRY

	try 
	{
		m_ItemClass = (Item::ItemClass)propertyBuffer.getPropertyInt("ItemClass");
		m_ItemType = (ItemType_t)propertyBuffer.getPropertyInt("ItemType");
		
		if (propertyBuffer.hasKey("EventItemClass"))
		{
			m_EventItemClass = (Item::ItemClass)propertyBuffer.getPropertyInt("EventItemClass");
			m_EventItemType = (ItemType_t)propertyBuffer.getPropertyInt("EventItemType");
			
			m_bEventItem = true;
		}
		else
		{
			m_bEventItem = false;
		}
		
		if (propertyBuffer.hasKey("RequiredItemClass"))
		{
			m_RequiredItemClass = (Item::ItemClass)propertyBuffer.getPropertyInt("RequiredItemClass");
			m_RequiredItemType = (ItemType_t)propertyBuffer.getPropertyInt("RequiredItemType");
			m_RequiredItemCount = propertyBuffer.getPropertyInt("RequiredItemCount");
			
			m_bRequiredItem = true;
		}
		else
		{
			m_bRequiredItem = false;
		}
		
		if (propertyBuffer.hasKey("RequiredItem2Class"))
		{
			m_RequiredItem2Class = (Item::ItemClass)propertyBuffer.getPropertyInt("RequiredItem2Class");
			m_RequiredItem2Type = (ItemType_t)propertyBuffer.getPropertyInt("RequiredItem2Type");
			m_RequiredItem2Count = propertyBuffer.getPropertyInt("RequiredItem2Count");
			
			m_bRequiredItem2 = true;
		}
		else
		{
			m_bRequiredItem2 = false;
		}
		
		if (propertyBuffer.hasKey("RequiredItem3Class"))
		{
			m_RequiredItem3Class = (Item::ItemClass)propertyBuffer.getPropertyInt("RequiredItem3Class");
			m_RequiredItem3Type = (ItemType_t)propertyBuffer.getPropertyInt("RequiredItem3Type");
			m_RequiredItem3Count = propertyBuffer.getPropertyInt("RequiredItem3Count");
			
			m_bRequiredItem3 = true;
		}
		else
		{
			m_bRequiredItem3 = false;
		}
		
		if (propertyBuffer.hasKey("RequiredItem4Class"))
		{
			m_RequiredItem4Class = (Item::ItemClass)propertyBuffer.getPropertyInt("RequiredItem4Class");
			m_RequiredItem4Type = (ItemType_t)propertyBuffer.getPropertyInt("RequiredItem4Type");
			m_RequiredItem4Count = propertyBuffer.getPropertyInt("RequiredItem4Count");
			
			m_bRequiredItem4 = true;
		}
		else
		{
			m_bRequiredItem4 = false;
		}
		
		if (propertyBuffer.hasKey("RequiredItem5Class"))
		{
			m_RequiredItem5Class = (Item::ItemClass)propertyBuffer.getPropertyInt("RequiredItem5Class");
			m_RequiredItem5Type = (ItemType_t)propertyBuffer.getPropertyInt("RequiredItem5Type");
			m_RequiredItem5Count = propertyBuffer.getPropertyInt("RequiredItem5Count");
			
			m_bRequiredItem5 = true;
		}
		else
		{
			m_bRequiredItem5 = false;
		}
		
		if (propertyBuffer.hasKey("RequiredItem6Class"))
		{
			m_RequiredItem6Class = (Item::ItemClass)propertyBuffer.getPropertyInt("RequiredItem6Class");
			m_RequiredItem6Type = (ItemType_t)propertyBuffer.getPropertyInt("RequiredItem6Type");
			m_RequiredItem6Count = propertyBuffer.getPropertyInt("RequiredItem6Count");
			
			m_bRequiredItem6 = true;
		}
		else
		{
			m_bRequiredItem6 = false;
		}
		
		if (propertyBuffer.hasKey("RequiredItem7Class"))
		{
			m_RequiredItem7Class = (Item::ItemClass)propertyBuffer.getPropertyInt("RequiredItem7Class");
			m_RequiredItem7Type = (ItemType_t)propertyBuffer.getPropertyInt("RequiredItem7Type");
			m_RequiredItem7Count = propertyBuffer.getPropertyInt("RequiredItem7Count");
			
			m_bRequiredItem7 = true;
		}
		else
		{
			m_bRequiredItem7 = false;
		}
		
		if (propertyBuffer.hasKey("RequiredItem8Class"))
		{
			m_RequiredItem8Class = (Item::ItemClass)propertyBuffer.getPropertyInt("RequiredItem8Class");
			m_RequiredItem8Type = (ItemType_t)propertyBuffer.getPropertyInt("RequiredItem8Type");
			m_RequiredItem8Count = propertyBuffer.getPropertyInt("RequiredItem8Count");
			
			m_bRequiredItem8 = true;
		}
		else
		{
			m_bRequiredItem8 = false;
		}
		
		if (propertyBuffer.hasKey("RequiredItem9Class"))
		{
			m_RequiredItem9Class = (Item::ItemClass)propertyBuffer.getPropertyInt("RequiredItem9Class");
			m_RequiredItem9Type = (ItemType_t)propertyBuffer.getPropertyInt("RequiredItem9Type");
			m_RequiredItem9Count = propertyBuffer.getPropertyInt("RequiredItem9Count");
			
			m_bRequiredItem9 = true;
		}
		else
		{
			m_bRequiredItem9 = false;
		}
		
		if (propertyBuffer.hasKey("ItemLimitTime"))
		{
			m_ItemLimitTime = propertyBuffer.getPropertyInt("ItemLimitTime");
		}
		else
		{
			m_ItemLimitTime = 0;
		}
		
		if (propertyBuffer.hasKey("EventItemTime"))
		{
			m_EventItemLimitTime = propertyBuffer.getPropertyInt("EventItemTime");
		}
		else
		{
			m_EventItemLimitTime = 0;
		}
		
		if (propertyBuffer.hasKey("RequiredContribute"))
		{
			m_RequiredContribute = propertyBuffer.getPropertyInt("RequiredContribute");
			m_bRequiredContribute = true;
		}
		else
		{
			m_bRequiredContribute = false;
		}
	
	} 
	catch (NoSuchElementException & nsee)
	{
		throw Error(nsee.toString());
	}
	
    __END_CATCH
}


////////////////////////////////////////////////////////////////////////////////
// 액션을 실행한다.
////////////////////////////////////////////////////////////////////////////////
void ActionGiveItem::execute (Creature * pCreature1 , Creature * pCreature2) 
	throw (Error)
{
	__BEGIN_TRY

	Assert(pCreature2 != NULL);
	Assert(pCreature2->isPC());

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature2);
	Assert( pPC != NULL );

	Player* pPlayer = pCreature2->getPlayer();
	Assert( pPlayer != NULL );

	Inventory* pInventory = pPC->getInventory();
	Assert( pInventory != NULL );
	
	Statement* pStmt   = NULL;
	Result*    pResult = NULL;
	
	uint EventCount = 0;
	bool bEventGiveItem = false;
	Item* pItem = NULL;
	list<OptionType_t> optionTypeList;
	
	if (m_bRequiredItem == true)
	{
		if ( !pInventory->hasEnoughNumItem(m_RequiredItemClass, m_RequiredItemType, m_RequiredItemCount) )
		{
			// 아이템 없음
			GCNPCResponse response;
			response.setCode(NPC_RESPONSE_NOT_ENOUGH_ITEM);
			pPlayer->sendPacket(&response);
			
			return ;
		}
	}
	if (m_bRequiredItem2 == true)
	{
		if ( !pInventory->hasEnoughNumItem(m_RequiredItem2Class, m_RequiredItem2Type, m_RequiredItem2Count) )
		{
			// 아이템 없음
			GCNPCResponse response;
			response.setCode(NPC_RESPONSE_NOT_ENOUGH_ITEM);
			pPlayer->sendPacket(&response);
			
			return ;
		}
	}
	if (m_bRequiredItem3 == true)
	{
		if ( !pInventory->hasEnoughNumItem(m_RequiredItem3Class, m_RequiredItem3Type, m_RequiredItem3Count) )
		{
			// 아이템 없음
			GCNPCResponse response;
			response.setCode(NPC_RESPONSE_NOT_ENOUGH_ITEM);
			pPlayer->sendPacket(&response);
			
			return ;
		}
	}
	if (m_bRequiredItem4 == true)
	{
		if ( !pInventory->hasEnoughNumItem(m_RequiredItem4Class, m_RequiredItem4Type, m_RequiredItem4Count) )
		{
			// 아이템 없음
			GCNPCResponse response;
			response.setCode(NPC_RESPONSE_NOT_ENOUGH_ITEM);
			pPlayer->sendPacket(&response);
			
			return ;
		}
	}
	if (m_bRequiredItem5 == true)
	{
		if ( !pInventory->hasEnoughNumItem(m_RequiredItem5Class, m_RequiredItem5Type, m_RequiredItem5Count) )
		{
			// 아이템 없음
			GCNPCResponse response;
			response.setCode(NPC_RESPONSE_NOT_ENOUGH_ITEM);
			pPlayer->sendPacket(&response);
			
			return ;
		}
	}
	if (m_bRequiredItem6 == true)
	{
		if ( !pInventory->hasEnoughNumItem(m_RequiredItem6Class, m_RequiredItem6Type, m_RequiredItem6Count) )
		{
			// 아이템 없음
			GCNPCResponse response;
			response.setCode(NPC_RESPONSE_NOT_ENOUGH_ITEM);
			pPlayer->sendPacket(&response);
			
			return ;
		}
	}
	if (m_bRequiredItem7 == true)
	{
		if ( !pInventory->hasEnoughNumItem(m_RequiredItem7Class, m_RequiredItem7Type, m_RequiredItem7Count) )
		{
			// 아이템 없음
			GCNPCResponse response;
			response.setCode(NPC_RESPONSE_NOT_ENOUGH_ITEM);
			pPlayer->sendPacket(&response);
			
			return ;
		}
	}
	if (m_bRequiredItem8 == true)
	{
		if ( !pInventory->hasEnoughNumItem(m_RequiredItem8Class, m_RequiredItem8Type, m_RequiredItem8Count) )
		{
			// 아이템 없음
			GCNPCResponse response;
			response.setCode(NPC_RESPONSE_NOT_ENOUGH_ITEM);
			pPlayer->sendPacket(&response);
			
			return ;
		}
	}
	if (m_bRequiredItem9 == true)
	{
		if ( !pInventory->hasEnoughNumItem(m_RequiredItem9Class, m_RequiredItem9Type, m_RequiredItem9Count) )
		{
			// 아이템 없음
			GCNPCResponse response;
			response.setCode(NPC_RESPONSE_NOT_ENOUGH_ITEM);
			pPlayer->sendPacket(&response);
			
			return ;
		}
	}

	if (m_bRequiredContribute == true)
	{
       	if ( pPC->getContributePoint() < m_RequiredContribute )
		{
			// 아이템 없음
			GCNPCResponse response;
			response.setCode(NPC_RESPONSE_NOT_ENOUGH_ITEM);
			pPlayer->sendPacket(&response);
			
			return ;
		}
	}

	
	if (m_bEventItem == true)
	{
		BEGIN_DB
		{
			pStmt   = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			pResult = pStmt->executeQuery("SELECT * from EventNPCRewardItemLog WHERE CharName  = '%s' and GiveItemDate=now()", pCreature2->getName().c_str() );
					
			if (pResult->getRowCount() == 0)
			{
				pItem = g_pItemFactoryManager->createItem( m_EventItemClass, m_EventItemType, optionTypeList );
				bEventGiveItem = true;
			}
			else
			{
				pItem = g_pItemFactoryManager->createItem( m_ItemClass, m_ItemType, optionTypeList );
			}
			
			SAFE_DELETE( pStmt );
		}
		END_DB( pStmt )
	}
	else
	{
		pItem = g_pItemFactoryManager->createItem( m_ItemClass, m_ItemType, optionTypeList );
	}
	
//	list<OptionType_t> optionTypeList;

//	Item* pItem = g_pItemFactoryManager->createItem( m_ItemClass, m_ItemType, optionTypeList );
	cout << " Item Create :: Action Give Item " << endl;
	Assert( pItem != NULL );
	
	_TPOINT pt;
	
	if (!pInventory->getEmptySlot(pItem, pt))
	{
//		// ConditionHasInvenSpace 컨디션과 반드시 함께 써야만 한다.
//		throw Error("ActionGiveItem: 제발 ConditionHasInvenSpace랑 같이 쓰자. 인벤토리에 자리없다.");
		
		GCNPCResponse response;
		response.setCode(NPC_RESPONSE_NO_EMPTY_SLOT);
		pPlayer->sendPacket(&response);
		
		return;		
	}

	if (m_bRequiredItem == true)
	{
		pInventory->decreaseNumItem(m_RequiredItemClass, m_RequiredItemType, m_RequiredItemCount, pPlayer);
	}
	if (m_bRequiredItem2 == true)
	{
		pInventory->decreaseNumItem(m_RequiredItem2Class, m_RequiredItem2Type, m_RequiredItem2Count, pPlayer);
	}
	if (m_bRequiredItem3 == true)
	{
		pInventory->decreaseNumItem(m_RequiredItem3Class, m_RequiredItem3Type, m_RequiredItem3Count, pPlayer);
	}
	if (m_bRequiredItem4 == true)
	{
		pInventory->decreaseNumItem(m_RequiredItem4Class, m_RequiredItem4Type, m_RequiredItem4Count, pPlayer);
	}
	if (m_bRequiredItem5 == true)
	{
		pInventory->decreaseNumItem(m_RequiredItem5Class, m_RequiredItem5Type, m_RequiredItem5Count, pPlayer);
	}
	if (m_bRequiredItem6 == true)
	{
		pInventory->decreaseNumItem(m_RequiredItem6Class, m_RequiredItem6Type, m_RequiredItem6Count, pPlayer);
	}
	if (m_bRequiredItem7 == true)
	{
		pInventory->decreaseNumItem(m_RequiredItem7Class, m_RequiredItem7Type, m_RequiredItem7Count, pPlayer);
	}
	if (m_bRequiredItem8 == true)
	{
		pInventory->decreaseNumItem(m_RequiredItem8Class, m_RequiredItem8Type, m_RequiredItem8Count, pPlayer);
	}
	if (m_bRequiredItem9 == true)
	{
		pInventory->decreaseNumItem(m_RequiredItem9Class, m_RequiredItem9Type, m_RequiredItem9Count, pPlayer);
	}

	if (m_bRequiredContribute == true)
	{
		int iUserContributePoint = pPC->getContributePoint();
		iUserContributePoint -= m_RequiredContribute;

		if(pPC->isSlayer())
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pPC);
			Assert( pSlayer != NULL );

			SLAYER_RECORD prev;
			pSlayer->getSlayerRecord( prev );

			pPC->setContributePoint( iUserContributePoint );
			pSlayer->sendModifyInfo(prev);
		}
		else if(pPC->isVampire())
		{
			Vampire* pVampire = dynamic_cast<Vampire*>(pPC);
			Assert( pVampire != NULL );

			VAMPIRE_RECORD prev;
			pVampire->getVampireRecord( prev );

			pPC->setContributePoint( iUserContributePoint );
			pVampire->sendModifyInfo( prev );
		}
		else if(pPC->isOusters())
		{
			Ousters* pOusters = dynamic_cast<Ousters*>(pPC);
			Assert( pOusters != NULL );

			OUSTERS_RECORD prev;
			pOusters->getOustersRecord( prev );

			pPC->setContributePoint( iUserContributePoint );
			pOusters->sendModifyInfo( prev );
		}
		
	}
		
	CoordInven_t X = pt.x;
	CoordInven_t Y = pt.y;

	pPC->getZone()->getObjectRegistry().registerObject( pItem );
	pInventory->addItem( X, Y, pItem );
	pItem->create( pPC->getName(), STORAGE_INVENTORY, 0, X, Y );
	
	if (m_ItemLimitTime != 0)
	{
		pPC->addTimeLimitItem( pItem, m_ItemLimitTime );
		pPC->sendTimeLimitItemInfo();
	}
	
	if (bEventGiveItem == true && m_EventItemLimitTime != 0)
	{
		pPC->addTimeLimitItem( pItem, m_EventItemLimitTime );
		pPC->sendTimeLimitItemInfo();
	}
	
	if(bEventGiveItem == true)
	{
		Statement* pStmt2 = NULL;

		BEGIN_DB
		{
			pStmt2 = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			pStmt2->executeQuery("INSERT INTO EventNPCRewardItemLog (PlayerID, CharName, GiveItemDate, GiveItemTime, ItemClass, ItemType) "
					"VALUES ('%s', '%s', now(), now(), %u, %u)",
					pPC->getPlayer()->getID().c_str(), pCreature2->getName().c_str(), pItem->getItemClass(), pItem->getItemType());
			SAFE_DELETE( pStmt2 );
		}
		END_DB(pStmt2);
	}
	
	if ( pItem != NULL && pItem->isTraceItem() )
	{
		remainTraceLog( pItem, "ActionGiveItem", pCreature2->getName(), ITEM_LOG_CREATE, DETAIL_EVENTNPC);
		remainTraceLogNew( pItem, pCreature2->getName(), ITL_GET, ITLD_EVENTNPC , pCreature2->getZone()->getZoneID() );
	}
				
	GCCreateItem gcCreateItem;
	makeGCCreateItem( &gcCreateItem, pItem, X, Y );
	pPlayer->sendPacket(&gcCreateItem);

	__END_CATCH
}


////////////////////////////////////////////////////////////////////////////////
// get debug string
////////////////////////////////////////////////////////////////////////////////
string ActionGiveItem::toString () const 
	throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "ActionGiveItem("
	    << ")";

	return msg.toString();

	__END_CATCH
}
