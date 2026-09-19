////////////////////////////////////////////////////////////////////////////////
// Filename    : ActionMonsterSummon.cpp
// Description : See ActionMonsterSummon.h.
//
//               v9 behaviour, kept: optionally find the DeleteMonster alive in the
//               NPC's zone and set its HP to 0 so the zone kills it (its
//               EventMonsterList regen brings it back later), announce the summon
//               server-wide, and add the summoned monster at X/Y.
//               Added: refuse while a summoned monster of the same type is still
//               alive, and take one offering item from the player first.
////////////////////////////////////////////////////////////////////////////////

#include "ActionMonsterSummon.h"
#include "PlayerCreature.h"
#include "GamePlayer.h"
#include "Inventory.h"
#include "Item.h"
#include "ItemUtil.h"
#include "PacketUtil.h"
#include "Zone.h"
#include "ZoneUtil.h"
#include "ZoneGroupManager.h"
#include "MonsterManager.h"
#include "Monster.h"
#include "MonsterInfo.h"
#include "MonsterSummonInfo.h"

#include "Gpackets/GCSystemMessage.h"
#include "Gpackets/GCDeleteInventoryItem.h"
#include "Gpackets/GCCreateItem.h"

static void sendSystemMessage(Player* pPlayer, const string& message)
{
	GCSystemMessage gcSystemMessage;
	gcSystemMessage.setMessage(message);
	pPlayer->sendPacket(&gcSystemMessage);
}

// First live monster of the given type in the zone, or NULL.
static Monster* findLiveMonster(Zone* pZone, MonsterType_t monsterType)
{
	hash_map<ObjectID_t, Creature*>& creatures = pZone->getMonsterManager()->getCreatures();

	for (hash_map<ObjectID_t, Creature*>::iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
	{
		Monster* pMonster = dynamic_cast<Monster*>(itr->second);

		if (pMonster != NULL && pMonster->getMonsterType() == monsterType && pMonster->isAlive())
			return pMonster;
	}

	return NULL;
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
ActionMonsterSummon::ActionMonsterSummon()
	throw(Error)
	: m_MonsterType(0), m_DeleteMonsterType(0), m_X(0), m_Y(0), m_Num(1),
	  m_RequireItemClass(-1), m_RequireItemType(0)
{
}

////////////////////////////////////////////////////////////////////////////////
// PropertyBuffer is strictly sequential: every getProperty() consumes the next
// line even when the key does not match, so a missing "optional" key would
// swallow the following property - or the next action. Every field is therefore
// required, in this exact order.
////////////////////////////////////////////////////////////////////////////////
void ActionMonsterSummon::read (PropertyBuffer & propertyBuffer)
	throw (Error)
{
	__BEGIN_TRY

	try
	{
		m_MonsterType       = propertyBuffer.getPropertyInt("Monster");
		m_X                 = propertyBuffer.getPropertyInt("X");
		m_Y                 = propertyBuffer.getPropertyInt("Y");
		m_Num               = propertyBuffer.getPropertyInt("Num");
		m_DeleteMonsterType = propertyBuffer.getPropertyInt("DeleteMonster");
		m_RequireItemClass  = propertyBuffer.getPropertyInt("RequireItemClass");
		m_RequireItemType   = propertyBuffer.getPropertyInt("RequireItemType");
	}
	catch (NoSuchElementException & nsee)
	{
		throw Error(nsee.toString());
	}

	if (m_Num < 1) m_Num = 1;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
void ActionMonsterSummon::execute (Creature * pCreature1 , Creature * pCreature2)
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

	Zone* pZone = pCreature1->getZone();
	Assert(pZone != NULL);

	const MonsterInfo* pMonsterInfo = g_pMonsterInfoManager->getMonsterInfo(m_MonsterType);
	Assert(pMonsterInfo != NULL);

	if (findLiveMonster(pZone, m_MonsterType) != NULL)
	{
		sendSystemMessage(pPlayer, pMonsterInfo->getEName() + " is already awake.");
		return;
	}

	Monster* pStatue = NULL;
	if (m_DeleteMonsterType != 0)
	{
		pStatue = findLiveMonster(pZone, m_DeleteMonsterType);

		if (pStatue == NULL)
		{
			sendSystemMessage(pPlayer, "The altar is silent. Come back when the statue stands again.");
			return;
		}
	}

	if (m_RequireItemClass > 0)
	{
		Inventory* pInventory = pPC->getInventory();
		CoordInven_t invenX = 0, invenY = 0;
		Item* pOffering = pInventory->findItem((Item::ItemClass)m_RequireItemClass, m_RequireItemType, invenX, invenY);

		if (pOffering == NULL)
		{
			sendSystemMessage(pPlayer, "Nothing happens. The statue asks for an offering.");
			return;
		}

		ObjectID_t offeringOID = pOffering->getObjectID();

		GCDeleteInventoryItem gcDeleteInventoryItem;
		gcDeleteInventoryItem.setObjectID(offeringOID);

		if (isStackable(pOffering) && pOffering->getNum() > 1)
		{
			// One off the stack. The client has no packet for a new stack count here, so
			// it drops the old stack and is sent the smaller one in the same slot.
			decreaseItemNum(pOffering, pInventory, pPC->getName(), STORAGE_INVENTORY, 0, invenX, invenY);
			pPlayer->sendPacket(&gcDeleteInventoryItem);

			GCCreateItem gcCreateItem;
			makeGCCreateItem(&gcCreateItem, pOffering, invenX, invenY);
			pPlayer->sendPacket(&gcCreateItem);
		}
		else
		{
			pInventory->deleteItem(offeringOID);
			pOffering->destroy();
			SAFE_DELETE(pOffering);

			pPlayer->sendPacket(&gcDeleteInventoryItem);
		}
	}

	if (pStatue != NULL)
		pStatue->setHP(0, ATTR_CURRENT);

	SUMMON_INFO summonInfo;
	summonInfo.scanEnemy = true;
	summonInfo.hasItem   = true;

	// SType 0: add by monster type. addMonstersToZone() prefers a sprite lookup when SType is
	// set, and the Ruper monsters' STypes are not registered sprite sets, so that path throws.
	list<Monster*> summoned;
	addMonstersToZone(pZone, m_X, m_Y, 0, m_MonsterType, m_Num, summonInfo, &summoned);

	if (summoned.empty())
	{
		sendSystemMessage(pPlayer, "The statue trembles, but nothing answers.");
		return;
	}

	GCSystemMessage gcSystemMessage;
	gcSystemMessage.setMessage(pMonsterInfo->getEName() + " has awakened on Ruper Island!");
	g_pZoneGroupManager->broadcast(&gcSystemMessage);

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// get debug string
////////////////////////////////////////////////////////////////////////////////
string ActionMonsterSummon::toString () const
	throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "ActionMonsterSummon("
		<< "Monster:" << (int)m_MonsterType
		<< ",X:" << (int)m_X
		<< ",Y:" << (int)m_Y
		<< ",Num:" << m_Num
		<< ",DeleteMonster:" << (int)m_DeleteMonsterType
		<< ",RequireItemClass:" << m_RequireItemClass
		<< ",RequireItemType:" << (int)m_RequireItemType
		<< ")";
	return msg.toString();

	__END_CATCH
}
