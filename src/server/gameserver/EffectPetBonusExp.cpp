//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectPetBonusExp.cpp
// Written by  : elca
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "EffectPetBonusExp.h"
#include "PlayerCreature.h"
#include "Player.h"
#include "DBExecuteManager.h"

#include <sstream>

#include "Gpackets/GCRemoveEffect.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectPetBonusExp::EffectPetBonusExp(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY 

	m_fBonusRate = 2.0f;

	setTarget(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectPetBonusExp::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY 
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectPetBonusExp::unaffect(Creature* pFromCreature)
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

	destroy( pPC->getPlayer()->getID() );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectPetBonusExp::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectPetBonusExp::create(const string & name) 
	throw(Error)
{
	__BEGIN_TRY
	
	Turn_t currentYearTime;
	getCurrentYearTime(currentYearTime);
	
	ostringstream os;
		
	os << "INSERT INTO EffectPetBonusExp (Name, YearTime, DayTime, BonusRate) VALUES("
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
void EffectPetBonusExp::destroy(const string & name)
	throw(Error)
{
	__BEGIN_TRY
	
	ostringstream os;
		
	os << "DELETE FROM EffectPetBonusExp WHERE Name = '" << name.c_str() << "'"; 
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());
	
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectPetBonusExp::save(const string & name) 
	throw(Error)
{
	__BEGIN_TRY
	
	Turn_t currentYearTime;
	getCurrentYearTime(currentYearTime);
	
	ostringstream os;
		
	os << "UPDATE EffectPetBonusExp SET "
		<< "YearTime=" << currentYearTime
		<< ", DayTime=" << m_Deadline.tv_sec
		<< ", BonusRate=" << GetBonusRate()
		<< " WHERE Name='" << name.c_str() << "'";
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());
	
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectPetBonusExp::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectPetBonusExp("
		<< "ObjectID:" << getObjectID()
		<< ",EffectLevel:" << m_fBonusRate
		<< ")";

	return msg.toString();

	__END_CATCH

}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectPetBonusExpLoader::load(Creature* pCreature) 
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);

	Statement* pStmt = NULL;

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		/*Result* pResult = pStmt->executeQuery(
			"SELECT DayTime FROM EffectPetBonusExp WHERE Name='%s'",
			pPC->getName().c_str()
		);

		while(pResult->next())
		{
			uint i = 0;

			DWORD DayTime = pResult->getDWORD(++i);

			Timeval currentTime;
			getCurrentTime(currentTime);

			EffectPetBonusExp* pEffectPetBonusExp = new EffectPetBonusExp(pCreature);
	
			if (currentTime.tv_sec < DayTime) 
			{
				pEffectPetBonusExp->setDeadline((DayTime - currentTime.tv_sec) * 10);

				pCreature->addEffect(pEffectPetBonusExp);
				pCreature->setFlag(pEffectPetBonusExp->getEffectClass());
			} 
			else
			{
				pEffectPetBonusExp->destroy( pPC->getName().c_str());
				SAFE_DELETE( pEffectPetBonusExp );
			}
		}*/

		Result* pResult = pStmt->executeQuery(
			"SELECT BonusRate, DayTime FROM EffectPetBonusExp WHERE Name='%s'",
			pPC->getName().c_str()
			);

		EffectPetBonusExp* pEffectPetBonusExp = NULL;

		while(pResult->next())
		{
			float fBonusRate = (float)atof(pResult->getField(1));
			DWORD DayTime = pResult->getDWORD(2);

			Timeval currentTime;
			getCurrentTime(currentTime);

			pEffectPetBonusExp = new EffectPetBonusExp(pCreature);

			if ( pEffectPetBonusExp != NULL )
			{
				if (currentTime.tv_sec < DayTime)
				{
					pEffectPetBonusExp->setDeadline((DayTime - currentTime.tv_sec) * 10);
					pEffectPetBonusExp->SetBonusRate(fBonusRate);
				}
				else
				{
					pEffectPetBonusExp->setDeadline(0);
				}

				pCreature->addEffect(pEffectPetBonusExp);
				pCreature->setFlag(pEffectPetBonusExp->getEffectClass());
			}
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)
	
	__END_CATCH
}

EffectPetBonusExpLoader* g_pEffectPetBonusExpLoader = NULL;
