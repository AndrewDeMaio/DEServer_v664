//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectLifeForceScroll2.cpp
// Written by  : ksym555
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectLifeForceScroll2.h"
#include "PlayerCreature.h"
#include "Zone.h"
#include "Gpackets/GCRemoveEffect.h"
#include "Timeval.h"
#include "DBExecuteManager.h"

#include <sstream>

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectLifeForceScroll2::EffectLifeForceScroll2(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectLifeForceScroll2::affect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	affect(pCreature);

	__END_CATCH
}

bool EffectLifeForceScroll2::isPossibleAffect()
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
void EffectLifeForceScroll2::affect(Creature* pCreature)
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
void EffectLifeForceScroll2::unaffect() 
	throw(Error)
{
	__BEGIN_TRY	

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectLifeForceScroll2::unaffect(Creature* pCreature)
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
void EffectLifeForceScroll2::create( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	Timeval currentTime;
	getCurrentTime(currentTime);

	Timeval remainTime = timediff( m_Deadline, currentTime );
	Turn_t remainTurn = remainTime.tv_sec * 10 + remainTime.tv_usec / 100000;
	
	ostringstream os;
		
	os << "INSERT INTO EffectLifeForceScroll2 ( OwnerID, RemainTime ) VALUES(" 
		<< "'" << ownerID.c_str()
		<< "'," << remainTurn << ")";
	 
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());	

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectLifeForceScroll2::destroy( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	ostringstream os;
		
	os << "DELETE FROM EffectLifeForceScroll2 WHERE OwnerID = '" << ownerID.c_str() << "'";
	 
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectLifeForceScroll2::save( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY

	Timeval currentTime;
	getCurrentTime(currentTime);

	Timeval remainTime = timediff( m_Deadline, currentTime );
	Turn_t remainTurn = remainTime.tv_sec * 10 + remainTime.tv_usec / 100000;
	
	ostringstream os;
		
	os << "UPDATE EffectLifeForceScroll2 SET "
		<< "RemainTime = " << remainTurn << " WHERE OwnerID = '" << ownerID.c_str() << "'";
	 
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectLifeForceScroll2::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectLifeForceScroll2("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectLifeForceScroll2Loader::load( Creature* pCreature )
	throw(Error)
{
	__BEGIN_TRY

	Assert( pCreature != NULL );

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		Result* pResult = pStmt->executeQuery( "SELECt RemainTime FROM EffectLifeForceScroll2 WHERE OwnerID = '%s'",
													pCreature->getName().c_str() );

		if ( pResult->next() )
		{
			Turn_t remainTurn = pResult->getDWORD(1);

			Timeval currentTime;
			getCurrentTime(currentTime);

			EffectLifeForceScroll2* pEffect = new EffectLifeForceScroll2(pCreature);

			pEffect->setDeadline( remainTurn );
			pCreature->addEffect( pEffect );
			pCreature->setFlag( pEffect->getEffectClass() );
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	__END_CATCH
}

EffectLifeForceScroll2Loader* g_pEffectLifeForceScroll2Loader = NULL;

