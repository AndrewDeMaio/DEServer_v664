//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectShrineShield.cpp
// Written by  : elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectCastleMihneaShield.h"
#include "Creature.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Monster.h"
#include "MonsterCorpse.h"
#include "Player.h"
#include "ZoneGroupManager.h"
#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCRemoveEffect.h"
#include "Gpackets/GCSystemMessage.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectCastleMihneaShield::EffectCastleMihneaShield(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	m_ShrineID = 0;
	setTarget(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectCastleMihneaShield::EffectCastleMihneaShield(Item* pItem)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pItem);

	__END_CATCH
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectCastleMihneaShield::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectCastleMihneaShield::affect(Item* pItem)
	throw(Error)
{
	__BEGIN_TRY

	__END_CATCH
}


void EffectCastleMihneaShield::unaffect() 
	throw(Error)
{
	__BEGIN_TRY	

	
	switch (m_pTarget->getObjectClass())
	{
		case OBJECT_CLASS_CREATURE :
		{
			Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
			unaffect(pCreature);
		}
		break;

		case OBJECT_CLASS_ITEM :
		{
			Item* pItem = dynamic_cast<Item *>(m_pTarget);
			unaffect(pItem);
		}
		break;

		default :
			throw Error("Wrong Object Class");
	}

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectCastleMihneaShield::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	//cout << "EffectCastleMihneaShield" << "unaffect BEGIN" << endl;

	Assert(pCreature != NULL);

	//      ,
	// initAllStat  .
	pCreature->removeFlag(Effect::EFFECT_CLASS_CASTLE_MIHNEA_SHIELD);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pCreature->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_CASTLE_MIHNEA_SHIELD);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcRemoveEffect);

	//cout << "EffectCastleMihneaShield" << "unaffect END" << endl;

	__END_DEBUG
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectCastleMihneaShield::unaffect(Item* pItem)
	throw(Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	//cout << "EffectCastleMihneaShield" << "unaffect BEGIN" << endl;

	Assert(pItem != NULL);

	Assert(pItem->getItemClass()==Item::ITEM_CLASS_CORPSE);
	Assert(pItem->getItemType()==MONSTER_CORPSE);

	MonsterCorpse* pCorpse = dynamic_cast<MonsterCorpse*>(pItem);

	pCorpse->removeFlag(Effect::EFFECT_CLASS_CASTLE_MIHNEA_SHIELD);

	Zone* pZone = pCorpse->getZone();
	Assert(pZone != NULL);

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pItem->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_CASTLE_MIHNEA_SHIELD);
	pZone->broadcastPacket(pCorpse->getX(), pCorpse->getY(), &gcRemoveEffect);

	//cout << "EffectCastleMihneaShield" << "unaffect END" << endl;

	__END_DEBUG
	__END_CATCH
}



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectCastleMihneaShield::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectCastleMihneaShield("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}
