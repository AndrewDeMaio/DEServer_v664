////////////////////////////////////////////////////////////////////////////////
// Filename    : ActionCheckLevelWarReward.cpp
// Written By  : 
// Description :
////////////////////////////////////////////////////////////////////////////////
#include "ActionCheckLevelWarReward.h"
#include "Item.h"
#include "Slayer.h"
#include "Vampire.h"
#include "NPC.h"
#include "Player.h"
#include "Inventory.h"
#include "ItemFactoryManager.h"
#include "ItemUtil.h"
#include "ItemInfoManager.h"
#include "OptionInfo.h"
#include "Zone.h"
#include "VariableManager.h"
#include "FlagSet.h"
#include "DB.h"
#include "PacketUtil.h"
#include "LevelWarZoneInfoManager.h"

#include "Gpackets/GCCreateItem.h"
#include "Gpackets/GCNPCResponse.h"
#include "Gpackets/GCNPCAsk.h"

#include <list>

////////////////////////////////////////////////////////////////////////////////
// ActionCheckLevelWarReward
////////////////////////////////////////////////////////////////////////////////
ActionCheckLevelWarReward::ActionCheckLevelWarReward()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	Result*    pResult = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery("SELECT Orders, ItemClass, ItemType, OptionType, Ratio FROM LevelWarRewardItemInfo WHERE Race = 0");

		int rowCount = pResult->getRowCount();
		// Empty reward table for this race: leave the list empty rather than
		// aborting. The TotalRatio stays 0 and the draw below is guarded.

		m_SlayerLevelWarRewardItemInfo.reserve(rowCount);
		m_SlayerTotalRatio = 0;
		while(pResult->next())
		{
			int order = pResult->getInt(1);
			Item::ItemClass itemClass = (Item::ItemClass)pResult->getInt(2);
			int itemType = pResult->getInt(3);
			string option = pResult->getString(4);
			int ratio = pResult->getInt(5);
			m_SlayerLevelWarRewardItemInfo.push_back(NULL);
			m_SlayerLevelWarRewardItemInfo[order] = new EVENT_ITEM_TEMPLATE;
			m_SlayerLevelWarRewardItemInfo[order]->ItemClass = itemClass;
			m_SlayerLevelWarRewardItemInfo[order]->ItemType = itemType;
			m_SlayerLevelWarRewardItemInfo[order]->ItemOption = option;
			m_SlayerLevelWarRewardItemInfo[order]->Ratio = ratio;
			m_SlayerTotalRatio += ratio;
			cout << "Slayer LevelWarRewardItemInfo order : " << order << ", itemClass : " << itemClass << ", itemType : " << itemType << ", option : " << option << ", Ratio : " << ratio << endl;
		}
		cout << "Slayer m_SlayerTotalRatio : " << m_SlayerTotalRatio << endl;
		cout << "m_SlayerLevelWarRewardItemInfo.size(): " << m_SlayerLevelWarRewardItemInfo.size() << endl;

		pResult = pStmt->executeQuery("SELECT Orders, ItemClass, ItemType, OptionType, Ratio FROM LevelWarRewardItemInfo WHERE Race = 1");

		rowCount = pResult->getRowCount();
		// Empty reward table for this race: leave the list empty rather than
		// aborting. The TotalRatio stays 0 and the draw below is guarded.

		m_VampireLevelWarRewardItemInfo.reserve(rowCount);
		m_VampireTotalRatio = 0;

		while(pResult->next())
		{
			int order = pResult->getInt(1);
			Item::ItemClass itemClass = (Item::ItemClass)pResult->getInt(2);
			int itemType = pResult->getInt(3);
			string option = pResult->getString(4);
			int ratio = pResult->getInt(5);
			m_VampireLevelWarRewardItemInfo.push_back(NULL);
			m_VampireLevelWarRewardItemInfo[order] = new EVENT_ITEM_TEMPLATE;
			m_VampireLevelWarRewardItemInfo[order]->ItemClass = itemClass;
			m_VampireLevelWarRewardItemInfo[order]->ItemType = itemType;
			m_VampireLevelWarRewardItemInfo[order]->ItemOption = option;
			m_VampireLevelWarRewardItemInfo[order]->Ratio = ratio;
			m_VampireTotalRatio += ratio;
			cout << "Vampire LevelWarRewardItemInfo order : " << order << ", itemClass : " << itemClass << ", itemType : " << itemType << ", option : " << option << ", Ratio : " << ratio << endl;
		}
		cout << "m_VampireTotalRatio : " << m_VampireTotalRatio << endl;
		cout << "m_VampireLevelWarRewardItemInfo.size() : " << m_VampireLevelWarRewardItemInfo.size() << endl;

		pResult = pStmt->executeQuery("SELECT Orders, ItemClass, ItemType, OptionType, Ratio FROM LevelWarRewardItemInfo WHERE Race = 2");

		rowCount = pResult->getRowCount();
		// Empty reward table for this race: leave the list empty rather than
		// aborting. The TotalRatio stays 0 and the draw below is guarded.

		m_OustersLevelWarRewardItemInfo.reserve(rowCount);
		m_OustersTotalRatio = 0;

		while(pResult->next())
		{
			int order = pResult->getInt(1);
			Item::ItemClass itemClass = (Item::ItemClass)pResult->getInt(2);
			int itemType = pResult->getInt(3);
			string option = pResult->getString(4);
			int ratio = pResult->getInt(5);
			m_OustersLevelWarRewardItemInfo.push_back(NULL);
			m_OustersLevelWarRewardItemInfo[order] = new EVENT_ITEM_TEMPLATE;
			m_OustersLevelWarRewardItemInfo[order]->ItemClass = itemClass;
			m_OustersLevelWarRewardItemInfo[order]->ItemType = itemType;
			m_OustersLevelWarRewardItemInfo[order]->ItemOption = option;
			m_OustersLevelWarRewardItemInfo[order]->Ratio = ratio;
			m_OustersTotalRatio += ratio;
			cout << "Ousters LevelWarRewardItemInfo order : " << order << ", itemClass : " << itemClass << ", itemType : " << itemType << ", option : " << option << ", Ratio : " << ratio << endl;
		}
		cout << "m_OustersTotalRatio : " << m_OustersTotalRatio << endl;
		cout << "m_OustersLevelWarRewardItemInfo.size() : " << m_OustersLevelWarRewardItemInfo.size() << endl;

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt);

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
ActionCheckLevelWarReward::~ActionCheckLevelWarReward()
throw(Error)
{
	for ( int i=0; i<m_SlayerLevelWarRewardItemInfo.size(); ++i )
	{
		SAFE_DELETE( m_SlayerLevelWarRewardItemInfo[i] );
	}
	for ( int i=0; i<m_VampireLevelWarRewardItemInfo.size(); ++i )
	{
		SAFE_DELETE( m_VampireLevelWarRewardItemInfo[i] );
	}
	for ( int i=0; i<m_OustersLevelWarRewardItemInfo.size(); ++i )
	{
		SAFE_DELETE( m_OustersLevelWarRewardItemInfo[i] );
	}
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void ActionCheckLevelWarReward::read(PropertyBuffer & propertyBuffer)
    throw (Error)
{
    __BEGIN_TRY

	try
	{
		m_Type = propertyBuffer.getProperty("Type");
	}
	catch (NoSuchElementException & nsee)
	{
		throw Error(nsee.toString());
	}

	m_QuestItemNum = 1; // 20개 모아오면 된다.

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// 액션을 실행한다.
////////////////////////////////////////////////////////////////////////////////
void ActionCheckLevelWarReward::execute(Creature * pCreature1 , Creature * pCreature2) 
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

	Inventory* pInventory = pPC->getInventory();
	Assert( pInventory != NULL );

	Zone* pZone = pPC->getZone();
	Assert( pZone != NULL );

	// 레벨 체크, 종족 체크, 아이템 유무 체크를 해야한다.

	ItemType_t		itemType = 0; 

	if(m_Type == "Level1")
	{
		if(pPC->isSlayer())
		{
			itemType = 18;
		}
		else if(pPC->isVampire())
		{
			itemType = 19;
		}
		else if(pPC->isOusters())
		{
			itemType = 20;
		}
	}
	else if(m_Type == "Level2")
	{
		if(pPC->isSlayer())
		{
			itemType = 21;
		}
		else if(pPC->isVampire())
		{
			itemType = 22;
		}
		else if(pPC->isOusters())
		{
			itemType = 23;
		}
	}
	else if(m_Type == "Level3")
	{
		if(pPC->isSlayer())
		{
			itemType = 24;
		}
		else if(pPC->isVampire())
		{
			itemType = 25;
		}
		else if(pPC->isOusters())
		{
			itemType = 26;
		}
	}
	else if(m_Type == "Level4")
	{
		if(pPC->isSlayer())
		{
			itemType = 27;
		}
		else if(pPC->isVampire())
		{
			itemType = 28;
		}
		else if(pPC->isOusters())
		{
			itemType = 29;
		}
	}


	int				 itemNum = 0;

	itemNum = pPC->getItemClassTypeNum( Item::ITEM_CLASS_COMMON_QUEST_ITEM, itemType );

	// 선택한 퀘스트 아템의 갯수가 충분하지 않을때 처리
	if( itemNum < m_QuestItemNum )
	{
		GCNPCResponse response;
		response.setCode( NPC_NOT_ENOUGH_EVENT_ITEM );
		pPlayer->sendPacket( &response );

		return;
	}

	int Sum = 0;
	int Ratio = 0;
	int array = 0;
	_TPOINT pt;
	ItemInfo* pItemInfo = NULL;
	list<OptionType_t> options;

	if(pPC->isSlayer())
	{
		if( m_SlayerTotalRatio <= 0 )   // no reward data configured
			return;

		Ratio = rand()%m_SlayerTotalRatio + 1;
		array = 0;
		Sum = 0;

		for( int i = 0; i < m_SlayerLevelWarRewardItemInfo.size(); ++i )
		{
			Sum += m_SlayerLevelWarRewardItemInfo[i]->Ratio;
			if( Sum >= Ratio )
			{
				array = i; 
				break;
			}
		}		
		pItemInfo = g_pItemInfoManager->getItemInfo( m_SlayerLevelWarRewardItemInfo[array]->ItemClass, m_SlayerLevelWarRewardItemInfo[array]->ItemType );
		Assert( pItemInfo != NULL );

		cout << "array : " << array << endl;

//		if( !pInventory->getEmptySlot(pItemInfo->getVolumeWidth(), pItemInfo->getVolumeHeight(), pt) )
		if( !pInventory->getEmptySlot(2, 3, pt) )
		{
			GCNPCResponse response;
			response.setCode( NPC_RESPONSE_SHOW_COMMON_MESSAGE_DIALOG );
			response.setParameter( NOT_ENOUGH_INVENTORY_SPACE );
			pPlayer->sendPacket( &response );
			return;
		}


		if(m_SlayerLevelWarRewardItemInfo[array]->ItemOption.size() > 0)
			makeOptionList( m_SlayerLevelWarRewardItemInfo[array]->ItemOption, options );
	}
	else if(pPC->isVampire())
	{
		if( m_VampireTotalRatio <= 0 )   // no reward data configured
			return;

		Ratio = rand()%m_VampireTotalRatio + 1;
		array = 0;
		Sum = 0;

		for( int i = 0; i < m_VampireLevelWarRewardItemInfo.size(); ++i )
		{
			Sum += m_VampireLevelWarRewardItemInfo[i]->Ratio;
			if( Sum >= Ratio )
			{
				array = i; 
				break;
			}
		}		
		pItemInfo = g_pItemInfoManager->getItemInfo( m_VampireLevelWarRewardItemInfo[array]->ItemClass, m_VampireLevelWarRewardItemInfo[array]->ItemType );
		Assert( pItemInfo != NULL );

		cout << "array : " << array << endl;

//		if( !pInventory->getEmptySlot(pItemInfo->getVolumeWidth(), pItemInfo->getVolumeHeight(), pt) )
		if( !pInventory->getEmptySlot(2, 3, pt) )
		{
			GCNPCResponse response;
			response.setCode( NPC_RESPONSE_SHOW_COMMON_MESSAGE_DIALOG );
			response.setParameter( NOT_ENOUGH_INVENTORY_SPACE );
			pPlayer->sendPacket( &response );
			return;
		}


		if(m_VampireLevelWarRewardItemInfo[array]->ItemOption.size() > 0)
			makeOptionList( m_VampireLevelWarRewardItemInfo[array]->ItemOption, options );	
	}
	else if(pPC->isOusters())
	{
		if( m_OustersTotalRatio <= 0 )   // no reward data configured
			return;

		Ratio = rand()%m_OustersTotalRatio + 1;
		array = 0;
		Sum = 0;

		for( int i = 0; i < m_OustersLevelWarRewardItemInfo.size(); ++i )
		{
			Sum += m_OustersLevelWarRewardItemInfo[i]->Ratio;
			if( Sum >= Ratio )
			{
				array = i; 
				break;
			}
		}		
		pItemInfo = g_pItemInfoManager->getItemInfo( m_OustersLevelWarRewardItemInfo[array]->ItemClass, m_OustersLevelWarRewardItemInfo[array]->ItemType );
		Assert( pItemInfo != NULL );

		cout << "array : " << array << endl;

//		if( !pInventory->getEmptySlot(pItemInfo->getVolumeWidth(), pItemInfo->getVolumeHeight(), pt) )
		if( !pInventory->getEmptySlot(2, 3, pt) )
		{
			GCNPCResponse response;
			response.setCode( NPC_RESPONSE_SHOW_COMMON_MESSAGE_DIALOG );
			response.setParameter( NOT_ENOUGH_INVENTORY_SPACE );
			pPlayer->sendPacket( &response );
			return;
		}


		if(m_OustersLevelWarRewardItemInfo[array]->ItemOption.size() > 0)
			makeOptionList( m_OustersLevelWarRewardItemInfo[array]->ItemOption, options );	
	}


	
	Item* pItem = g_pItemFactoryManager->createItem( pItemInfo->getItemClass(), pItemInfo->getItemType(), options );
	Assert( pItem != NULL );

	pZone->registerObject( pItem );

	if( pInventory->addItem( pItem, pt )
		&& pPC->getItemClassTypeNum( Item::ITEM_CLASS_COMMON_QUEST_ITEM, itemType ) >= m_QuestItemNum )
	{
		pPC->decreaseItemClassTypeNum( Item::ITEM_CLASS_COMMON_QUEST_ITEM, itemType, m_QuestItemNum );

		pItem->create( pPC->getName(), STORAGE_INVENTORY, 0, pt.x, pt.y );

		int timeRatio = rand()%100;
		if(m_Type == "Level1")
		{
			if(timeRatio > 5)
			{
				pPC->addTimeLimitItem( pItem, 7776000 );        
				pPC->sendTimeLimitItemInfo();
			}
		}
		else if(m_Type == "Level2")
		{
			if(timeRatio > 10)
			{
				pPC->addTimeLimitItem( pItem, 7776000 );        
				pPC->sendTimeLimitItemInfo();
			}
		}
		else if(m_Type == "Level3")
		{
			if(timeRatio > 15)
			{
				pPC->addTimeLimitItem( pItem, 7776000 );        
				pPC->sendTimeLimitItemInfo();
			}
		}
		else if(m_Type == "Level4")
		{
			if(timeRatio > 20)
			{
				pPC->addTimeLimitItem( pItem, 7776000 );        
				pPC->sendTimeLimitItemInfo();
			}
		}
		else
		{
			pPC->addTimeLimitItem( pItem, 7776000 );        
			pPC->sendTimeLimitItemInfo();
		}

		remainTraceLog( pItem, "LevelWarReward", pPC->getName(), ITEM_LOG_CREATE, DETAIL_EVENTNPC );

		GCCreateItem gcCreateItem;
		makeGCCreateItem(&gcCreateItem, pItem, pt.x, pt.y);

		pPlayer->sendPacket( &gcCreateItem );
	}

	GCNPCResponse response;
	response.setCode( NPC_RESPONSE_GIVE_EVENT_ITEM_OK );
	pPlayer->sendPacket( &response );

	response.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
	pPlayer->sendPacket( &response );

	__END_CATCH
}


////////////////////////////////////////////////////////////////////////////////
// get debug string
////////////////////////////////////////////////////////////////////////////////
string ActionCheckLevelWarReward::toString () const 
	throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "ActionCheckLevelWarReward("
	    << ")";
	return msg.toString();

	__END_CATCH
}
