//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectMirForceScroll.cpp
// Written by  : ksym555
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectDragonOfForce.h"
#include "PlayerCreature.h"
#include "Zone.h"
#include "Gpackets/GCRemoveEffect.h"
#include "Timeval.h"
#include "DBExecuteManager.h"

#include <sstream>

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectDragonOfForce::EffectDragonOfForce(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pCreature);
//	m_OptionType = 0;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectDragonOfForce::affect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	affect(pCreature);

	__END_CATCH
}

bool EffectDragonOfForce::isPossibleAffect()
	throw(Error)
{
	__BEGIN_TRY
	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	PlayerCreature* pPC   = dynamic_cast<PlayerCreature*>(pCreature);
	
	return true;
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectDragonOfForce::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY


	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectDragonOfForce::unaffect() 
	throw(Error)
{
	__BEGIN_TRY	

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectDragonOfForce::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	Assert( pPC != NULL );

	Zone* pZone = pPC->getZone();
	Assert( pZone != NULL );

	pPC->removeFlag( getEffectClass() );
	pPC->initAllStatAndSend();

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID( pCreature->getObjectID() );
	gcRemoveEffect.addEffectList( getEffectClass() );
	pZone->broadcastPacket( pPC->getX(), pPC->getY(), &gcRemoveEffect );


	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectDragonOfForce::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectDragonOfForce("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}


