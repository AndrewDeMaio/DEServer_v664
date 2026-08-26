//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectBonusExpSecond.cpp
// Written by  : elca
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "EffectBonusExpSecond.h"
#include "PlayerCreature.h"
#include "Player.h"
#include "DBExecuteManager.h"

#include <sstream>

#include "Gpackets/GCRemoveEffect.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectBonusExpSecond::EffectBonusExpSecond(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY 

	m_fBonusRate = 2.0f;
	
	setTarget(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBonusExpSecond::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY 
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBonusExpSecond::unaffect(Creature* pFromCreature)
	throw(Error)
{
	__BEGIN_TRY 

	Assert(pFromCreature != NULL);

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pFromCreature);
	Assert( pPC != NULL );

	Player* pPlayer = pPC->getPlayer();
	Assert( pPlayer != NULL );

	pPC->removeFlag( getEffectClass() );

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID( pPC->getObjectID() );
	gcRemoveEffect.addEffectList( getEffectClass() );

	pPlayer->sendPacket( &gcRemoveEffect );

	destroy( pPC->getName().c_str() );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBonusExpSecond::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBonusExpSecond::create(const string & name) 
	throw(Error)
{
	__BEGIN_TRY

	Turn_t currentYearTime;
	getCurrentYearTime(currentYearTime);
	
	ostringstream os;
	
	os << "INSERT INTO EffectBonusExpSecond (Name, YearTime, DayTime, BonusRate) VALUES(" 
		<< "'" << name.c_str() 
		<< "', " << currentYearTime 
		<< ", " << m_Deadline.tv_sec 
		<< ", " << GetBonusRate()
		<< ")";
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());
	
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBonusExpSecond::destroy(const string & name)
	throw(Error)
{
	__BEGIN_TRY
	
	ostringstream os;
	
	os << "DELETE FROM EffectBonusExpSecond WHERE Name = '" << name.c_str() << "'", 
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());
	
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBonusExpSecond::save(const string & name) 
	throw(Error)
{
	__BEGIN_TRY

	Turn_t currentYearTime;
	getCurrentYearTime(currentYearTime);
	
	ostringstream os;
	
	os << "UPDATE EffectBonusExpSecond SET "
		<< "YearTime=" << currentYearTime 
		<< ", DayTime=" << m_Deadline.tv_sec
		<< ", BonusRate=" << GetBonusRate() 
		<< " WHERE Name='" << name.c_str() << "'"; 
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());
	
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectBonusExpSecond::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectBonusExpSecond("
		<< "ObjectID:" << getObjectID()
		<< ",BonusRate:" << m_fBonusRate
		<< ")";

	return msg.toString();

	__END_CATCH

}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBonusExpSecondLoader::load(Creature* pCreature) 
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);

	Statement* pStmt = NULL;

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		Result* pResult = pStmt->executeQuery( 
			"SELECT BonusRate, DayTime FROM EffectBonusExpSecond WHERE Name='%s'", 
			pPC->getName().c_str()
		);

		EffectBonusExpSecond* pEffectBonusExpSecond = NULL;
		
		while(pResult->next())
		{
			float fBonusRate = (float)atof(pResult->getField(1));
			DWORD DayTime = pResult->getDWORD(2);

			Timeval currentTime;
			getCurrentTime(currentTime);

			pEffectBonusExpSecond = new EffectBonusExpSecond(pCreature);
	
			if ( pEffectBonusExpSecond != NULL )
			{
				if (currentTime.tv_sec < DayTime) 
				{
					pEffectBonusExpSecond->setDeadline((DayTime - currentTime.tv_sec) * 10);
					pEffectBonusExpSecond->SetBonusRate(fBonusRate);
				} 
				else
				{
					pEffectBonusExpSecond->setDeadline(0);
				}
				
				pCreature->addEffect(pEffectBonusExpSecond);
				pCreature->setFlag(Effect::EFFECT_CLASS_BONUS_EXP_SECOND);
			}
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)
	
	__END_CATCH
}

EffectBonusExpSecondLoader* g_pEffectBonusExpSecondLoader = NULL;
