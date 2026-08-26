//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectChannelMicroPhone.cpp
// Written by  : ksym555
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectChannelMicroPhone.h"
#include "PlayerCreature.h"
#include "Zone.h"
#include "Gpackets/GCRemoveEffect.h"
#include "Timeval.h"
#include "DBExecuteManager.h"

#include <sstream>

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectChannelMicroPhone::EffectChannelMicroPhone(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	
	m_fBonusRate = 0.0f;

	setTarget(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectChannelMicroPhone::affect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	affect(pCreature);

	__END_CATCH
}

bool EffectChannelMicroPhone::isPossibleAffect()
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
void EffectChannelMicroPhone::affect(Creature* pCreature)
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
void EffectChannelMicroPhone::unaffect() 
	throw(Error)
{
	__BEGIN_TRY	

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectChannelMicroPhone::unaffect(Creature* pCreature)
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
void EffectChannelMicroPhone::create( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	Timeval currentTime;
	getCurrentTime(currentTime);

	Timeval remainTime = timediff( m_Deadline, currentTime );
	Turn_t remainTurn = remainTime.tv_sec * 10 + remainTime.tv_usec / 100000;
	
	ostringstream os;
		
	os << "INSERT INTO EffectChannelMicroPhone ( OwnerID, BonusRate, RemainTime ) VALUES(" 
		<< "'" << ownerID.c_str()
		<< "', " << GetBonusRate()
		<< "," << remainTurn << ")";
	 
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());	

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectChannelMicroPhone::destroy( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	ostringstream os;
		
	os << "DELETE FROM EffectChannelMicroPhone WHERE OwnerID = '" << ownerID.c_str() << "'";
	 
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectChannelMicroPhone::save( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY

	Timeval currentTime;
	getCurrentTime(currentTime);

	Timeval remainTime = timediff( m_Deadline, currentTime );
	Turn_t remainTurn = remainTime.tv_sec * 10 + remainTime.tv_usec / 100000;
	
	ostringstream os;
		
	os << "UPDATE EffectChannelMicroPhone SET "
		<< "RemainTime = " << remainTurn 
		<< ", BonusRate=" << GetBonusRate() 
		<< " WHERE OwnerID = '" << ownerID.c_str() << "'";
	 
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectChannelMicroPhone::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectChannelMicroPhone("
		<< "ObjectID:" << getObjectID()
		<< ",BonusRate:" << m_fBonusRate
		<< ")";
	return msg.toString();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectChannelMicroPhoneLoader::load( Creature* pCreature )
	throw(Error)
{
	__BEGIN_TRY

	Assert( pCreature != NULL );

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		Result* pResult = pStmt->executeQuery( "SELECT BonusRate, RemainTime FROM EffectChannelMicroPhone WHERE OwnerID = '%s'",
													pCreature->getName().c_str() );

		if ( pResult->next() )
		{
			float fBonusRate = (float)atof(pResult->getField(1));
			Turn_t remainTurn = pResult->getDWORD(2);

			Timeval currentTime;
			getCurrentTime(currentTime);

			EffectChannelMicroPhone* pEffect = new EffectChannelMicroPhone(pCreature);

			pEffect->setDeadline( remainTurn );
			pEffect->SetBonusRate(fBonusRate);
			pCreature->addEffect( pEffect );
			pCreature->setFlag( pEffect->getEffectClass() );
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	__END_CATCH
}

EffectChannelMicroPhoneLoader* g_pEffectChannelMicroPhoneLoader = NULL;

