//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectBonusExpAdvance.cpp
// Written by  : ksym555
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "EffectBonusExpAdvance.h"
#include "PlayerCreature.h"
#include "Player.h"
#include "DBExecuteManager.h"

#include <sstream>

#include "Gpackets/GCRemoveEffect.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectBonusExpAdvance::EffectBonusExpAdvance(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY 

	m_fBonusRate = 2.0f;
	
	setTarget(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBonusExpAdvance::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY 
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBonusExpAdvance::unaffect(Creature* pFromCreature)
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
void EffectBonusExpAdvance::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBonusExpAdvance::create(const string & name) 
	throw(Error)
{
	__BEGIN_TRY

	Turn_t currentYearTime;
	getCurrentYearTime(currentYearTime);
	
	ostringstream os;
	
	os << "INSERT INTO EffectBonusExpAdvance (Name, YearTime, DayTime, BonusRate) VALUES(" 
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
void EffectBonusExpAdvance::destroy(const string & name)
	throw(Error)
{
	__BEGIN_TRY
	
	ostringstream os;
	
	os << "DELETE FROM EffectBonusExpAdvance WHERE Name = '" << name.c_str() << "'", 
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());
	
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBonusExpAdvance::save(const string & name) 
	throw(Error)
{
	__BEGIN_TRY

	Turn_t currentYearTime;
	getCurrentYearTime(currentYearTime);
	
	ostringstream os;
	
	os << "UPDATE EffectBonusExpAdvance SET "
		<< "YearTime=" << currentYearTime 
		<< ", DayTime=" << m_Deadline.tv_sec
		<< ", BonusRate=" << GetBonusRate() 
		<< " WHERE Name='" << name.c_str() << "'"; 
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());
	
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectBonusExpAdvance::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectBonusExpAdvance("
		<< "ObjectID:" << getObjectID()
		<< ",BonusRate:" << m_fBonusRate
		<< ")";

	return msg.toString();

	__END_CATCH

}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBonusExpAdvanceLoader::load(Creature* pCreature) 
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
			"SELECT BonusRate, DayTime FROM EffectBonusExpAdvance WHERE Name='%s'", 
			pPC->getName().c_str()
		);

		EffectBonusExpAdvance* pEffectBonusExpAdvance = NULL;
		
		while(pResult->next())
		{
			float fBonusRate = (float)atof(pResult->getField(1));
			DWORD DayTime = pResult->getDWORD(2);

			Timeval currentTime;
			getCurrentTime(currentTime);

			pEffectBonusExpAdvance = new EffectBonusExpAdvance(pCreature);
	
			if ( pEffectBonusExpAdvance != NULL )
			{
				if (currentTime.tv_sec < DayTime) 
				{
					pEffectBonusExpAdvance->setDeadline((DayTime - currentTime.tv_sec) * 10);
					pEffectBonusExpAdvance->SetBonusRate(fBonusRate);
				} 
				else
				{
					pEffectBonusExpAdvance->setDeadline(0);
				}
				
				pCreature->addEffect(pEffectBonusExpAdvance);
				pCreature->setFlag(Effect::EFFECT_CLASS_BONUS_EXP_ADVANCE);
			}
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)
	
	__END_CATCH
}

EffectBonusExpAdvanceLoader* g_pEffectBonusExpAdvanceLoader = NULL;
