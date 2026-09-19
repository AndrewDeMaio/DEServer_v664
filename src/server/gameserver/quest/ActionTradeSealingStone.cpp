////////////////////////////////////////////////////////////////////////////////
// Filename    : ActionTradeSealingStone.cpp
// Written By  :
// Description : Trades a Master's bijous (beads) and pendant for a Sealing Stone
//               (QuestItem 10), the entry item for the Raohm B5F Mikllizz lair.
//
//               Recipe (2026-09-14): 5 bijous + 1 pendant of the SAME Master,
//               checked in the order Bathory (QuestItem 0/1), Tepez (2/3),
//               Gilles de Rais (8/9). No gold and no Blue Drops (the original
//               recipe was 7 Bathory bijous, 2 pendants, 10 Blue Drops and
//               600,000 gold, and no trigger ever used it).
////////////////////////////////////////////////////////////////////////////////
#include "ActionTradeSealingStone.h"
#include "Item.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
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
#include "Gpackets/GCSystemMessage.h"

#include <list>

namespace
{
	struct MasterNecklaceSet
	{
		ItemType_t	BijouType;
		ItemType_t	PendantType;
		const char*	MasterName;
	};

	const int MASTER_SET_MAX = 3;
	const MasterNecklaceSet MasterSets[MASTER_SET_MAX] =
	{
		{ 0, 1, "Bathory" },
		{ 2, 3, "Tepez" },
		{ 8, 9, "Gilles de Rais" },
	};

	const int NEED_BIJOU_NUM   = 5;
	const int NEED_PENDANT_NUM = 1;

	const ItemType_t SEALING_STONE_TYPE = 10;
}

////////////////////////////////////////////////////////////////////////////////
// ActionTradeSealingStone
////////////////////////////////////////////////////////////////////////////////
ActionTradeSealingStone::ActionTradeSealingStone()
{
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
ActionTradeSealingStone::~ActionTradeSealingStone()
	throw()
{
}

////////////////////////////////////////////////////////////////////////////////
// no properties
////////////////////////////////////////////////////////////////////////////////
void ActionTradeSealingStone::read(PropertyBuffer & propertyBuffer)
    throw (Error)
{
    __BEGIN_TRY
	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// execute
////////////////////////////////////////////////////////////////////////////////
void ActionTradeSealingStone::execute(Creature * pCreature1 , Creature * pCreature2)
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

	// the first Master whose bijous and pendant the player has enough of
	const MasterNecklaceSet* pSet = NULL;
	for ( int i = 0; i < MASTER_SET_MAX; ++i )
	{
		if ( pPC->getItemClassTypeNum( Item::ITEM_CLASS_QUEST_ITEM, MasterSets[i].BijouType ) >= NEED_BIJOU_NUM
			&& pPC->getItemClassTypeNum( Item::ITEM_CLASS_QUEST_ITEM, MasterSets[i].PendantType ) >= NEED_PENDANT_NUM )
		{
			pSet = &MasterSets[i];
			break;
		}
	}

	GCNPCResponse gcNPCResponse;

	if ( pSet == NULL )
	{
		GCSystemMessage gcMessage;
		gcMessage.setMessage( "A Sealing Stone needs 5 bijous and 1 pendant from the same Master (Bathory, Tepez or Gilles de Rais)." );
		pPlayer->sendPacket( &gcMessage );

		gcNPCResponse.setCode( NPC_NOT_ENOUGH_EXCHANGE_SEALING_STONE );
		pPlayer->sendPacket( &gcNPCResponse );

		gcNPCResponse.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
		pPlayer->sendPacket( &gcNPCResponse );

		return;
	}

	ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo( Item::ITEM_CLASS_QUEST_ITEM, SEALING_STONE_TYPE );
	Assert( pItemInfo != NULL );

	// room in the inventory?
	_TPOINT	pt;
	if( !pInventory->getEmptySlot(pItemInfo->getVolumeWidth(), pItemInfo->getVolumeHeight(), pt) )
	{
		GCNPCResponse response;
		response.setCode( NPC_RESPONSE_SHOW_COMMON_MESSAGE_DIALOG );
		response.setParameter( NOT_ENOUGH_INVENTORY_SPACE );
		pPlayer->sendPacket( &response );
		return;
	}

	list<OptionType_t> options;

	Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_QUEST_ITEM, SEALING_STONE_TYPE, options );
	Assert( pItem != NULL );

	pZone->registerObject( pItem );

	if( pInventory->addItem( pItem, pt) )
	{
		pPC->decreaseItemClassTypeNum( Item::ITEM_CLASS_QUEST_ITEM, pSet->BijouType, NEED_BIJOU_NUM );
		pPC->decreaseItemClassTypeNum( Item::ITEM_CLASS_QUEST_ITEM, pSet->PendantType, NEED_PENDANT_NUM );

		pItem->create( pPC->getName(), STORAGE_INVENTORY, 0, pt.x, pt.y );

		remainTraceLog( pItem, "Sealing Stone", pPC->getName(), ITEM_LOG_CREATE, DETAIL_EVENTNPC );

		GCCreateItem gcCreateItem;
		makeGCCreateItem(&gcCreateItem, pItem, pt.x, pt.y);
		pPlayer->sendPacket( &gcCreateItem );

		GCSystemMessage gcMessage;
		gcMessage.setMessage( string("You traded 5 ") + pSet->MasterName + " bijous and a pendant for a Sealing Stone." );
		pPlayer->sendPacket( &gcMessage );
	}
	else
	{
		pInventory->deleteItem( pItem->getObjectID() );

		SAFE_DELETE( pItem );

		gcNPCResponse.setCode( NPC_NOT_ENOUGH_EXCHANGE_SEALING_STONE );
		pPlayer->sendPacket( &gcNPCResponse );
	}

	// close the dialogue
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
string ActionTradeSealingStone::toString () const
	throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "ActionTradeSealingStone("
	    << ")";
	return msg.toString();

	__END_CATCH
}
