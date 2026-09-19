//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectShadyDouble.cpp
// Written by  : elca
// Description : Shady Double pending hits (server-only effect class 984), v9 EffectShadyDouple: deals the
//               damage in m_TotalTimes hits m_Tick apart. Same as EffectAcidEruption (no client status).
//////////////////////////////////////////////////////////////////////////////

#include "EffectShadyDouble.h"
#include "Slayer.h"
#include "Player.h"
#include "SkillUtil.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"

EffectShadyDouble::EffectShadyDouble(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pCreature);

	__END_CATCH
}

void EffectShadyDouble::affect() throw(Error)
{
	__BEGIN_TRY

	if ( m_pTarget == NULL || m_pTarget->getObjectClass() != OBJECT_CLASS_CREATURE )
	{
		setDeadline(0);
		return;
	}
	affect( dynamic_cast<Creature*>(m_pTarget) );

	__END_CATCH
}

void EffectShadyDouble::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert( pCreature != NULL );
	if ( pCreature->isDead() )
	{
		setDeadline(0);
		return;
	}

	Creature* pAttacker = pCreature->getZone()->getCreature( m_CasterOID );
	Damage_t damage = m_Damage / m_TotalTimes;
	if ( m_Times == m_TotalTimes ) damage += m_Damage % m_TotalTimes;

	GCModifyInformation gcMI, gcAttackerMI;

	::setDamage( pCreature, damage, pAttacker, SKILL_SHADY_DOUPLE, &gcMI, &gcAttackerMI );

	if ( pCreature->isDead() && pAttacker != NULL && pAttacker->isVampire() )
	{
		Vampire* pVampire = dynamic_cast<Vampire*>(pAttacker);
		Exp_t exp = computeCreatureExp( pCreature, KILL_EXP );
		shareVampExp( pVampire, exp, gcAttackerMI );
		increaseAlignment( pAttacker, pCreature, gcAttackerMI );
	}

	if ( pAttacker != NULL && pAttacker->isPC() )
	{
		computeAlignmentChange(pCreature, damage, pAttacker, &gcMI, &gcAttackerMI);
		pAttacker->getPlayer()->sendPacket( &gcAttackerMI );
	}

	if ( pCreature->isPC() )
	{
		pCreature->getPlayer()->sendPacket( &gcMI );
	}

	--m_Times;

	if ( m_Times == 0 ) 
		setDeadline(0);
	else 
		setNextTime( m_Tick );

	__END_CATCH
}

void EffectShadyDouble::unaffect()
	    throw(Error)
{
    __BEGIN_TRY

    Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
    unaffect(pCreature);

    __END_CATCH
}

void EffectShadyDouble::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Assert(pCreature != NULL);

	pCreature->removeFlag(Effect::EFFECT_CLASS_SHADY_DOUPLE);

	__END_DEBUG
	__END_CATCH
}

string EffectShadyDouble::toString() const 
	throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectShadyDouble("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}
