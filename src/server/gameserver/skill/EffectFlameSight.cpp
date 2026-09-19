//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectFlameSight.cpp
// Written by  :
// Description : Flame Sight buff (effect 631), v9 EffectFlameSight without the DB persistence.
//               Works like EffectLightness for Ousters.
//////////////////////////////////////////////////////////////////////////////

#include "EffectFlameSight.h"
#include "Creature.h"
#include "Zone.h"
#include "Player.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCRemoveEffect.h"
#include "Gpackets/GCModifyInformation.h"

//////////////////////////////////////////////////////////////////////////////
// Re-evaluates the sight (Creature::getEffectedSight knows Flame Sight) like Lightness does.
//////////////////////////////////////////////////////////////////////////////
static void updateFlameSightVision(Creature* pCreature, ModifyInfo* pMI)
{
	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	Sight_t oldSight = pCreature->getSight();
	Sight_t newSight = pCreature->getEffectedSight();

	if ( oldSight == newSight ) return;

	pCreature->setSight( newSight );
	pZone->updateScan(pCreature, oldSight, newSight);

	if ( pMI != NULL )
	{
		pMI->addShortData(MODIFY_VISION, newSight);
	}
	else if ( pCreature->getPlayer() != NULL )
	{
		GCModifyInformation gcMI;
		gcMI.addShortData(MODIFY_VISION, newSight);
		pCreature->getPlayer()->sendPacket( &gcMI );
	}
}

void addFlameSight(Creature* pCreature, Turn_t Duration, ModifyInfo* pMI)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	EffectFlameSight* pEffect = new EffectFlameSight(pCreature);
	pEffect->setDeadline(Duration);
	pCreature->addEffect(pEffect);
	pCreature->setFlag(Effect::EFFECT_CLASS_FLAME_SIGHT);

	updateFlameSightVision(pCreature, pMI);

	GCAddEffect gcAddEffect;
	gcAddEffect.setObjectID(pCreature->getObjectID());
	gcAddEffect.setEffectID(Effect::EFFECT_CLASS_FLAME_SIGHT);
	gcAddEffect.setDuration(Duration);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcAddEffect);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectFlameSight::EffectFlameSight(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectFlameSight::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Assert(pCreature != NULL);

	pCreature->removeFlag(Effect::EFFECT_CLASS_FLAME_SIGHT);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pCreature->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_FLAME_SIGHT);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcRemoveEffect);

	updateFlameSightVision(pCreature, NULL);

	__END_DEBUG
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectFlameSight::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectFlameSight::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectFlameSight("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}
