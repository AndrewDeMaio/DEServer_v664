//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectGreyfellForceScroll2.cpp
// Written by  : bezz
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectGreyfellForceScroll2.h"
#include "PlayerCreature.h"
#include "Zone.h"
#include "Gpackets/GCRemoveEffect.h"
#include "Timeval.h"
#include "DBExecuteManager.h"

#include <sstream>

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectGreyfellForceScroll2::EffectGreyfellForceScroll2(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGreyfellForceScroll2::affect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	affect(pCreature);

	__END_CATCH
}

//20081029 wlzzi - Extreme Force Scroll  
bool EffectGreyfellForceScroll2::isPossibleAffect()
	throw(Error)
{
	__BEGIN_TRY
	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	PlayerCreature* pPC   = dynamic_cast<PlayerCreature*>(pCreature);
	
	if ( pPC->isFlag(Effect::EFFECT_CLASS_EXTREME_FORCE_SCROLL) || pPC->isFlag(Effect::EFFECT_CLASS_EXTREME_FORCE_SCROLL_2) ||
	    pPC->isFlag(Effect::EFFECT_CLASS_GREYFELL_FORCE_SCROLL) || pPC->isFlag(Effect::EFFECT_CLASS_GREYFELL_FORCE_SCROLL_2)
	    )
		return false;
	return true;
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGreyfellForceScroll2::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	Assert( pPC != NULL );

	pPC->initAllStatAndSend();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGreyfellForceScroll2::unaffect() 
	throw(Error)
{
	__BEGIN_TRY	

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGreyfellForceScroll2::unaffect(Creature* pCreature)
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

	destroy( pPC->getName() );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGreyfellForceScroll2::create( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	Timeval currentTime;
	getCurrentTime(currentTime);

	Timeval remainTime = timediff( m_Deadline, currentTime );
	Turn_t remainTurn = remainTime.tv_sec * 10 + remainTime.tv_usec / 100000;
	
	ostringstream os;
	
	os << "INSERT INTO EffectGreyfellForceScroll2 ( OwnerID, RemainTime ) VALUES(" 
		<< "'" << ownerID.c_str() 
		<< "'," << remainTurn << ")";
	 
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGreyfellForceScroll2::destroy( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	ostringstream os;
	
	os << "DELETE FROM EffectGreyfellForceScroll2 WHERE OwnerID = '" << ownerID.c_str() << "'";
	 
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGreyfellForceScroll2::save( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	Timeval currentTime;
	getCurrentTime(currentTime);

	Timeval remainTime = timediff( m_Deadline, currentTime );
	Turn_t remainTurn = remainTime.tv_sec * 10 + remainTime.tv_usec / 100000;
	
	ostringstream os;
	
	os << "UPDATE EffectGreyfellForceScroll2 SET "
		<< "RemainTime = " << remainTurn << " WHERE OwnerID = '" << ownerID.c_str() << "'";
	 
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectGreyfellForceScroll2::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectGreyfellForceScroll2("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGreyfellForceScroll2Loader::load( Creature* pCreature )
	throw(Error)
{
	__BEGIN_TRY

	Assert( pCreature != NULL );

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		Result* pResult = pStmt->executeQuery( "SELECt RemainTime FROM EffectGreyfellForceScroll2 WHERE OwnerID = '%s'",
													pCreature->getName().c_str() );

		if ( pResult->next() )
		{
			Turn_t remainTurn = pResult->getDWORD(1);

			Timeval currentTime;
			getCurrentTime(currentTime);

			EffectGreyfellForceScroll2* pEffect = new EffectGreyfellForceScroll2(pCreature);

			pEffect->setDeadline( remainTurn );
			pCreature->addEffect( pEffect );
			pCreature->setFlag( pEffect->getEffectClass() );
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	__END_CATCH
}

EffectGreyfellForceScroll2Loader* g_pEffectGreyfellForceScroll2Loader = NULL;

