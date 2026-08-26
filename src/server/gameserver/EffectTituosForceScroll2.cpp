//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectTituosForceScroll2.cpp
// Written by  : bezz
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectTituosForceScroll2.h"
#include "PlayerCreature.h"
#include "Zone.h"
#include "Gpackets/GCRemoveEffect.h"
#include "Timeval.h"
#include "DBExecuteManager.h"

#include <sstream>

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectTituosForceScroll2::EffectTituosForceScroll2(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pCreature);

	__END_CATCH
}

bool EffectTituosForceScroll2::isPossibleAffect()
	throw(Error)
{
	__BEGIN_TRY
	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	PlayerCreature* pPC   = dynamic_cast<PlayerCreature*>(pCreature);
	
	if (pPC->isFlag(Effect::EFFECT_CLASS_BEHEMOTH_FORCE_SCROLL) || 
		 pPC->isFlag(Effect::EFFECT_CLASS_SAFE_FORCE_SCROLL) ||
		 pPC->isFlag(Effect::EFFECT_CLASS_CARNELIAN_FORCE_SCROLL) || 
	     pPC->isFlag(Effect::EFFECT_CLASS_BEHEMOTH_FORCE_SCROLL_2) || 
		 pPC->isFlag(Effect::EFFECT_CLASS_SAFE_FORCE_SCROLL_2) ||
		 pPC->isFlag(Effect::EFFECT_CLASS_CARNELIAN_FORCE_SCROLL_2) ||
		 pPC->isFlag(Effect::EFFECT_CLASS_TITUOS_FORCE_SCROLL) ||
		 pPC->isFlag(Effect::EFFECT_CLASS_TITUOS_FORCE_SCROLL_2)
		 )
		return false;
	return true;
	__END_CATCH
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectTituosForceScroll2::affect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	affect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectTituosForceScroll2::affect(Creature* pCreature)
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
void EffectTituosForceScroll2::unaffect() 
	throw(Error)
{
	__BEGIN_TRY	

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectTituosForceScroll2::unaffect(Creature* pCreature)
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
void EffectTituosForceScroll2::create( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	Timeval currentTime;
	getCurrentTime(currentTime);

	Timeval remainTime = timediff( m_Deadline, currentTime );
	Turn_t remainTurn = remainTime.tv_sec * 10 + remainTime.tv_usec / 100000;
	
	ostringstream os;
		
	os << "INSERT INTO EffectTituosForceScroll2 ( OwnerID, RemainTime ) VALUES(" 
		<< "'" << ownerID.c_str()
		<< "'," << remainTurn << ")";
	 
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectTituosForceScroll2::destroy( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	ostringstream os;
		
	os <<"DELETE FROM EffectTituosForceScroll2 WHERE OwnerID = '" << ownerID.c_str() << "'";
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectTituosForceScroll2::save( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	Timeval currentTime;
	getCurrentTime(currentTime);

	Timeval remainTime = timediff( m_Deadline, currentTime );
	Turn_t remainTurn = remainTime.tv_sec * 10 + remainTime.tv_usec / 100000;
	
	ostringstream os;
		
	os << "UPDATE EffectTituosForceScroll2 SET "
		<< "RemainTime = " << remainTurn
		<< " WHERE OwnerID = '" << ownerID.c_str() << "'";
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectTituosForceScroll2::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectTituosForceScroll2("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectTituosForceScroll2Loader::load( Creature* pCreature )
	throw(Error)
{
	__BEGIN_TRY

	Assert( pCreature != NULL );

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		Result* pResult = pStmt->executeQuery( "SELECt RemainTime FROM EffectTituosForceScroll2 WHERE OwnerID = '%s'",
													pCreature->getName().c_str() );

		if ( pResult->next() )
		{
			Turn_t remainTurn = pResult->getDWORD(1);

			Timeval currentTime;
			getCurrentTime(currentTime);

			EffectTituosForceScroll2* pEffect = new EffectTituosForceScroll2(pCreature);

			pEffect->setDeadline( remainTurn );
			pCreature->addEffect( pEffect );
			pCreature->setFlag( pEffect->getEffectClass() );
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	__END_CATCH
}

EffectTituosForceScroll2Loader* g_pEffectTituosForceScroll2Loader = NULL;

