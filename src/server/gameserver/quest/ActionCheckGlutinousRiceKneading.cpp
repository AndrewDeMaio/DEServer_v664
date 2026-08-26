////////////////////////////////////////////////////////////////////////////////
// Filename    : ActionCheckGlutinousRiceKneading.cpp
// Written By  : 
// Description :
////////////////////////////////////////////////////////////////////////////////
#include "ActionCheckGlutinousRiceKneading.h"
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

#include "Gpackets/GCCreateItem.h"
#include "Gpackets/GCNPCResponse.h"
#include "Gpackets/GCNPCAsk.h"

#include <list>

struct EVENT_ITEM_TEMPLATE
{
	Item::ItemClass		ItemClass;
	ItemType_t			ItemType;
	string				ItemName;
    string              ItemOption;
	int					Ratio;
};

const int EVENT_ATNEMENT_ITEM_MAX = 16;
const EVENT_ITEM_TEMPLATE EventAtonementItemTemplate[EVENT_ATNEMENT_ITEM_MAX] =
{
	{ Item::ITEM_CLASS_EVENT_STAR, 54, "가멸찬 송편", "", 14252},
	{ Item::ITEM_CLASS_EFFECT_ITEM, 34, "알심 송편", "", 14252},
	{ Item::ITEM_CLASS_EFFECT_ITEM, 35, "날렵한 송편", "", 14252},
	{ Item::ITEM_CLASS_EFFECT_ITEM, 36, "알음알이 송편", "", 14252},
	{ Item::ITEM_CLASS_EFFECT_ITEM, 37, "옹골진 송편", "", 14252},
	{ Item::ITEM_CLASS_CUE_OF_ADAM, 4, "고대의 매듭 STR+3", "STR+3", 9564},
	{ Item::ITEM_CLASS_CUE_OF_ADAM, 4, "고대의 매듭 DEX+3", "DEX+3", 9563},
	{ Item::ITEM_CLASS_CUE_OF_ADAM, 4, "고대의 매듭 INT+3", "INT+3", 9563},
	{ Item::ITEM_CLASS_CUE_OF_ADAM, 4, "고대의 매듭 PORES+2,DAM+2", "PORES+2,DAM+2", 10},
	{ Item::ITEM_CLASS_CUE_OF_ADAM, 4, "고대의 매듭 ACRES+2,DAM+2", "ACRES+2,DAM+2", 10},
	{ Item::ITEM_CLASS_CUE_OF_ADAM, 4, "고대의 매듭 CURES+2,DAM+2", "CURES+2,DAM+2", 10},
	{ Item::ITEM_CLASS_CUE_OF_ADAM, 4, "고대의 매듭 BLRES+2,DAM+2", "BLRES+2,DAM+2", 10},
	{ Item::ITEM_CLASS_CUE_OF_ADAM, 4, "고대의 매듭 STR+2,RES+3", "STR+2,RES+3", 3},
	{ Item::ITEM_CLASS_CUE_OF_ADAM, 4, "고대의 매듭 DEX+2,RES+3", "DEX+2,RES+3", 3},
	{ Item::ITEM_CLASS_CUE_OF_ADAM, 4, "고대의 매듭 INT+2,RES+3", "INT+2,RES+3", 3},
	{ Item::ITEM_CLASS_CUE_OF_ADAM, 4, "고대의 매듭 ATTR+3,RES+4", "ATTR+3,RES+4", 1},
};

////////////////////////////////////////////////////////////////////////////////
// ActionCheckGlutinousRiceKneading
////////////////////////////////////////////////////////////////////////////////
ActionCheckGlutinousRiceKneading::ActionCheckGlutinousRiceKneading()
{
	m_TotalRatio = 0;
	for( int i = 0; i < EVENT_ATNEMENT_ITEM_MAX; ++i )
	{
		m_TotalRatio += EventAtonementItemTemplate[i].Ratio;
	}
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
ActionCheckGlutinousRiceKneading::~ActionCheckGlutinousRiceKneading()
	throw()
{
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void ActionCheckGlutinousRiceKneading::read(PropertyBuffer & propertyBuffer)
    throw (Error)
{
    __BEGIN_TRY

/*	try
	{
		// read script id
		m_QuestItemNum = 100;
//		m_EnoughGetItemScriptID = (ScriptID_t)propertyBuffer.getPropertyInt("EnoughGetItemScriptID");
//		m_NotEnoughGetItemScriptID = (ScriptID_t)propertyBuffer.getPropertyInt("NotEnoughGetItemScriptID");
	}
	catch (NoSuchElementException & nsee)
	{
		throw Error(nsee.toString());
	}
	*/
	m_QuestItemNum = 20; // 20개 모아오면 된다.

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// 액션을 실행한다.
////////////////////////////////////////////////////////////////////////////////
void ActionCheckGlutinousRiceKneading::execute(Creature * pCreature1 , Creature * pCreature2) 
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

	ItemType_t		itemType = 47;

	int				 itemNum = 0;

	itemNum = pPC->getItemClassTypeNum( Item::ITEM_CLASS_EVENT_STAR, itemType );

	// 선택한 퀘스트 아템의 갯수가 충분하지 않을때 처리
	if( itemNum < m_QuestItemNum )
	{
		GCNPCResponse response;
		response.setCode( NPC_NOT_ENOUGH_EVENT_ITEM );
		pPlayer->sendPacket( &response );

		return;

//		GCNPCAsk gcNPCAsk;
//		gcNPCAsk.setObjectID( pCreature1->getObjectID() );
//		gcNPCAsk.setScriptID( m_NotEnoughGetItemScriptID );
//		gcNPCAsk.setNPCID( dynamic_cast<NPC*>(pCreature1)->getNPCID() );

//		pPlayer->sendPacket( &gcNPCAsk );
	}

	int Sum = 0;
	int Ratio = rand()%m_TotalRatio + 1;
	int array = 0;

	for( int i = 0; i < EVENT_ATNEMENT_ITEM_MAX; ++i )
	{
		Sum += EventAtonementItemTemplate[i].Ratio;
		if( Sum >= Ratio )
		{
			array = i; 
			break;
		}
	}

	ItemInfo* pItemInfo = NULL;
	if(array == 0)
	{
		if(pPC->isSlayer())
			pItemInfo = g_pItemInfoManager->getItemInfo( Item::ITEM_CLASS_POTION, 18 );
		else if(pPC->isVampire())
			pItemInfo = g_pItemInfoManager->getItemInfo( Item::ITEM_CLASS_SERUM, 7 );
		else if(pPC->isOusters())
			pItemInfo = g_pItemInfoManager->getItemInfo( Item::ITEM_CLASS_PUPA, 7 );
	}
	else
	{
		pItemInfo = g_pItemInfoManager->getItemInfo( EventAtonementItemTemplate[array].ItemClass, EventAtonementItemTemplate[array].ItemType );
	}

	Assert( pItemInfo != NULL );

	cout << "array : " << array << endl;

	_TPOINT pt;
	if( !pInventory->getEmptySlot(pItemInfo->getVolumeWidth(), pItemInfo->getVolumeHeight(), pt) )
	{
		GCNPCResponse response;
		response.setCode( NPC_RESPONSE_SHOW_COMMON_MESSAGE_DIALOG );
		response.setParameter( NOT_ENOUGH_INVENTORY_SPACE );
		pPlayer->sendPacket( &response );
		return;
	}

	list<OptionType_t> options;

	if(array >= 5)
		makeOptionList( EventAtonementItemTemplate[array].ItemOption, options );

	
	Item* pItem = g_pItemFactoryManager->createItem( pItemInfo->getItemClass(), pItemInfo->getItemType(), options );
	Assert( pItem != NULL );

	pZone->registerObject( pItem );

	if( pInventory->addItem( pItem, pt )
		&& pPC->getItemClassTypeNum( Item::ITEM_CLASS_EVENT_STAR, itemType ) >= m_QuestItemNum )
	{
		pPC->decreaseItemClassTypeNum( Item::ITEM_CLASS_EVENT_STAR, itemType, m_QuestItemNum );

		pItem->create( pPC->getName(), STORAGE_INVENTORY, 0, pt.x, pt.y );
		if(array >= 5 && array <= 7)
		{
	        pPC->addTimeLimitItem( pItem, 1296000 );        // 360시간 
    	    pPC->sendTimeLimitItemInfo();
		}
								
		remainTraceLog( pItem, "EventItem(2007 추석)", pPC->getName(), ITEM_LOG_CREATE, DETAIL_EVENTNPC );

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
string ActionCheckGlutinousRiceKneading::toString () const 
	throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "ActionCheckGlutinousRiceKneading("
	    << ")";
	return msg.toString();

	__END_CATCH
}
