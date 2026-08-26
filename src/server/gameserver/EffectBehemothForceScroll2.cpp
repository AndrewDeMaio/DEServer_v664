//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectBehemothForceScroll2.cpp
// Written by  : bezz
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectBehemothForceScroll2.h"
#include "PlayerCreature.h"
#include "Zone.h"
#include "Gpackets/GCRemoveEffect.h"
#include "Timeval.h"
#include "DBExecuteManager.h"

#include <sstream>

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectBehemothForceScroll2::EffectBehemothForceScroll2(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBehemothForceScroll2::affect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	affect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBehemothForceScroll2::affect(Creature* pCreature)
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
void EffectBehemothForceScroll2::unaffect() 
	throw(Error)
{
	__BEGIN_TRY	

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBehemothForceScroll2::unaffect(Creature* pCreature)
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
void EffectBehemothForceScroll2::create( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	Timeval currentTime;
	getCurrentTime(currentTime);

	Timeval remainTime = timediff( m_Deadline, currentTime );
	Turn_t remainTurn = remainTime.tv_sec * 10 + remainTime.tv_usec / 100000;
	
	ostringstream os;
	
	os << "INSERT INTO EffectBehemothForceScroll2 ( OwnerID, RemainTime ) VALUES('" 
		<< ownerID.c_str() << "'," << remainTurn << ")";
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());
	
	

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBehemothForceScroll2::destroy( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	ostringstream os;
	
	os << "DELETE FROM EffectBehemothForceScroll2 WHERE OwnerID = '" << ownerID.c_str() << "'",
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBehemothForceScroll2::save( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	Timeval currentTime;
	getCurrentTime(currentTime);

	Timeval remainTime = timediff( m_Deadline, currentTime );
	Turn_t remainTurn = remainTime.tv_sec * 10 + remainTime.tv_usec / 100000;
	
	ostringstream os;
	
	os << "UPDATE EffectBehemothForceScroll2 SET "
		<< "RemainTime = " << remainTurn << " WHERE OwnerID = '" << ownerID.c_str() << "'";
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectBehemothForceScroll2::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectBehemothForceScroll2("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBehemothForceScroll2Loader::load( Creature* pCreature )
	throw(Error)
{
	__BEGIN_TRY

	Assert( pCreature != NULL );

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		Result* pResult = pStmt->executeQuery( "SELECt RemainTime FROM EffectBehemothForceScroll2 WHERE OwnerID = '%s'",
													pCreature->getName().c_str() );

		if ( pResult->next() )
		{
			Turn_t remainTurn = pResult->getDWORD(1);

			Timeval currentTime;
			getCurrentTime(currentTime);

			EffectBehemothForceScroll2* pEffect = new EffectBehemothForceScroll2(pCreature);

			pEffect->setDeadline( remainTurn );
			pCreature->addEffect( pEffect );
			pCreature->setFlag( pEffect->getEffectClass() );
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	__END_CATCH
}

EffectBehemothForceScroll2Loader* g_pEffectBehemothForceScroll2Loader = NULL;

