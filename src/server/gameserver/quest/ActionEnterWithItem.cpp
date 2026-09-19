////////////////////////////////////////////////////////////////////////////////
// Filename    : ActionEnterWithItem.cpp
// Description : See ActionEnterWithItem.h. One item is taken from the player's
//               inventory (one off a stack), then the player is transported the
//               same way ActionActivatePortal does it.
////////////////////////////////////////////////////////////////////////////////

#include "ActionEnterWithItem.h"
#include "PlayerCreature.h"
#include "GamePlayer.h"
#include "Inventory.h"
#include "Item.h"
#include "ItemUtil.h"
#include "PacketUtil.h"
#include "Zone.h"
#include "ZoneUtil.h"
#include "GQuestManager.h"

#include "Gpackets/GCSystemMessage.h"
#include "Gpackets/GCDeleteInventoryItem.h"
#include "Gpackets/GCCreateItem.h"
#include "Gpackets/GCNPCResponse.h"

static void sendSystemMessage(Player* pPlayer, const string& message)
{
	GCSystemMessage gcSystemMessage;
	gcSystemMessage.setMessage(message);
	pPlayer->sendPacket(&gcSystemMessage);
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
ActionEnterWithItem::ActionEnterWithItem()
	throw(Error)
	: m_ItemClass(0), m_ItemType(0), m_ZoneID(0), m_X(0), m_Y(0)
{
}

////////////////////////////////////////////////////////////////////////////////
// PropertyBuffer is strictly sequential: every field is required, in this order.
////////////////////////////////////////////////////////////////////////////////
void ActionEnterWithItem::read (PropertyBuffer & propertyBuffer)
	throw (Error)
{
	__BEGIN_TRY

	try
	{
		m_ItemClass = propertyBuffer.getPropertyInt("ItemClass");
		m_ItemType  = propertyBuffer.getPropertyInt("ItemType");
		m_ItemName  = propertyBuffer.getProperty("ItemName");
		m_ZoneID    = propertyBuffer.getPropertyInt("ZoneID");
		m_X         = propertyBuffer.getPropertyInt("X");
		m_Y         = propertyBuffer.getPropertyInt("Y");
	}
	catch (NoSuchElementException & nsee)
	{
		throw Error(nsee.toString());
	}

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
void ActionEnterWithItem::execute (Creature * pCreature1 , Creature * pCreature2)
	throw (Error)
{
	__BEGIN_TRY

	Assert(pCreature1 != NULL);
	Assert(pCreature2 != NULL);
	Assert(pCreature2->isPC());

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature2);
	Assert(pPC != NULL);

	Player* pPlayer = pPC->getPlayer();
	Assert(pPlayer != NULL);

	GCNPCResponse quitDialogue;
	quitDialogue.setCode(NPC_RESPONSE_QUIT_DIALOGUE);

	Inventory* pInventory = pPC->getInventory();
	CoordInven_t invenX = 0, invenY = 0;
	Item* pItem = pInventory->findItem((Item::ItemClass)m_ItemClass, m_ItemType, invenX, invenY);

	if (pItem == NULL)
	{
		sendSystemMessage(pPlayer, "You need " + m_ItemName + " to pass.");
		pPlayer->sendPacket(&quitDialogue);
		return;
	}

	ObjectID_t itemOID = pItem->getObjectID();

	GCDeleteInventoryItem gcDeleteInventoryItem;
	gcDeleteInventoryItem.setObjectID(itemOID);

	if (isStackable(pItem) && pItem->getNum() > 1)
	{
		// One off the stack: the client drops the old stack and is sent the smaller one.
		decreaseItemNum(pItem, pInventory, pPC->getName(), STORAGE_INVENTORY, 0, invenX, invenY);
		pPlayer->sendPacket(&gcDeleteInventoryItem);

		GCCreateItem gcCreateItem;
		makeGCCreateItem(&gcCreateItem, pItem, invenX, invenY);
		pPlayer->sendPacket(&gcCreateItem);
	}
	else
	{
		pInventory->deleteItem(itemOID);
		pItem->destroy();
		SAFE_DELETE(pItem);

		pPlayer->sendPacket(&gcDeleteInventoryItem);
	}

	sendSystemMessage(pPlayer, "You hand over " + m_ItemName + ". The gates open.");
	pPlayer->sendPacket(&quitDialogue);

	pPC->getGQuestManager()->illegalWarp();
	transportCreature(pCreature2, m_ZoneID, m_X, m_Y, true);

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// get debug string
////////////////////////////////////////////////////////////////////////////////
string ActionEnterWithItem::toString () const
	throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "ActionEnterWithItem("
		<< "ItemClass:" << m_ItemClass
		<< ",ItemType:" << (int)m_ItemType
		<< ",ItemName:" << m_ItemName
		<< ",ZoneID:" << (int)m_ZoneID
		<< ",X:" << (int)m_X
		<< ",Y:" << (int)m_Y
		<< ")";
	return msg.toString();

	__END_CATCH
}
