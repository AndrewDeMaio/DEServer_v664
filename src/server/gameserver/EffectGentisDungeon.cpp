//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectMenegrothDoungeon.cpp
// Written by  : rappi76
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "Types.h"

#include "EffectGentisDungeon.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Monster.h"
#include "ZoneUtil.h"
#include "ZoneInfoManager.h"
#include "GamePlayer.h"
#include "EventTransport.h"
#include "GentisDungeonManager.h"
#include "StringPool.h"

#include "Gpackets/GCRemoveEffect.h"
#include "Gpackets/GCSystemMessage.h"
#include "DBExecuteManager.h"

#include <sstream>

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectGentisDungeon::EffectGentisDungeon(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);

	setTarget(pCreature);

	m_pCreature = pCreature;
	m_targetZoneID = 0;
	m_targetX = 0;
	m_targetY = 0;
	m_bTrans = false;
	
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGentisDungeon::affect()
	throw(Error)
{
	__BEGIN_TRY

	Assert(m_pCreature != NULL);
	cout<< "EffectGentisDungeon::afftect()" << endl;
	//affect(m_pCreature);
	
	__END_CATCH
}

void EffectGentisDungeon::affect(Creature* pCreature)
	throw(Error)
{
	Assert(pCreature != NULL); 

	cout << "EffectGentisDungeon" << "affect BEGIN" << endl;

//	pCreature->setFlag(Effect::EFFECT_CLASS_GENTIS_DUNGEON);

	Timeval currentTime;
	getCurrentTime(currentTime);
	Timeval remainTime = timediff( m_Deadline, currentTime );
	Turn_t remainTurn = remainTime.tv_sec * 10 + remainTime.tv_usec / 100000;

	char message[512];
	sprintf(message, g_pStringPool->c_str(STRID_MENEGROTH_DOUNGEON_LIMITED_TIMER), remainTurn);

	GCSystemMessage gcSystemMessage;
	gcSystemMessage.setType( SYSTEM_MESSAGE_TIMER );
	gcSystemMessage.setMessage(message);

	pCreature->getPlayer()->sendPacket(&gcSystemMessage);
}

void EffectGentisDungeon::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	cout << "EffectGentisDungeon" << "unaffect BEGIN" << endl;
	
	Assert(pCreature != NULL);

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	//  .
	pCreature->removeFlag(Effect::EFFECT_CLASS_GENTIS_DUNGEON);
	pCreature->deleteEffect(Effect::EFFECT_CLASS_GENTIS_DUNGEON);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);
	
	//   .
	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pCreature->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_GENTIS_DUNGEON);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcRemoveEffect);

	if(pZone->getZoneID() == 6051 || pZone->getZoneID() == 6052 || pZone->getZoneID() == 6053)
	{
		GamePlayer *pGamePlayer = dynamic_cast<GamePlayer *>(pCreature->getPlayer());
		EventTransport *pEventTransport = dynamic_cast<EventTransport*>(pGamePlayer->getEvent(Event::EVENT_CLASS_TRANSPORT));
		if ( pEventTransport == NULL )
		{
			pEventTransport = new EventTransport(pGamePlayer);
		}

		ZoneID_t targetZoneID = 0;
		ZoneCoord_t targetX;
		ZoneCoord_t targetY;

		if(m_bTrans)
		{
			targetZoneID = m_targetZoneID;
			targetX = m_targetX;
			targetY = m_targetY;
		}
			
		ZoneInfo *pZoneInfo = g_pZoneInfoManager->getZoneInfo(pZone->getZoneID());

		if ( targetZoneID != 0 && pZoneInfo != NULL )
		{
			pEventTransport->setDeadline(0);
			pEventTransport->setZoneName(pZoneInfo->getFullName());
			pEventTransport->setTargetZone(targetZoneID, targetX, targetY);

			pGamePlayer->addEvent(pEventTransport);
		}
	}

	destroy( pPC->getName() );

	//cout << "EffectGentisDungeon" << "unaffect END" << endl;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGentisDungeon::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

void EffectGentisDungeon::setTransportPos(ZoneID_t targetZoneID, ZoneCoord_t targetX, ZoneCoord_t targetY, bool bTrans)
	throw(Error)
{
	__BEGIN_TRY

	m_targetZoneID = targetZoneID;
	m_targetX = targetX;
	m_targetY = targetY;
	m_bTrans = bTrans;
	
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGentisDungeon::create( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY

	Turn_t currentYearTime;
	getCurrentYearTime(currentYearTime);
	
	ostringstream os;
	
	os << "INSERT INTO EffectGentisDungeon(Name, YearTime, DayTime) VALUES(" 
		<< "'" << ownerID.c_str() 
		<< "', " << currentYearTime 
		<< ", " << m_Deadline.tv_sec 
		<< ")";
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());
	
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGentisDungeon::destroy( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY
	
	ostringstream os;
		
	os << "DELETE FROM EffectGentisDungeon WHERE Name = '" << ownerID.c_str() << "'";
	 
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGentisDungeon::save( const string& ownerID )
	throw(Error)
{
	__BEGIN_TRY

	Turn_t currentYearTime;
	getCurrentYearTime(currentYearTime);
	
	ostringstream os;
	
	os << "UPDATE EffectGentisDungeon SET "
		<< "YearTime=" << currentYearTime 
		<< ", DayTime=" << m_Deadline.tv_sec
		<< " WHERE Name='" << ownerID.c_str() << "'"; 
	
	g_GameDBExecuteManager.RequestExecQuery(getEffectClass(), os.str());
	
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectGentisDungeon::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectGentisDungeon("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
		
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGentisDungeonLoader::load(Creature* pCreature) 
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
			"SELECT DayTime FROM EffectGentisDungeon WHERE Name='%s'", 
			pPC->getName().c_str()
		);

		EffectGentisDungeon* pEffect = NULL;
		
		while(pResult->next())
		{
			DWORD DayTime = pResult->getDWORD(1);

			Timeval currentTime;
			getCurrentTime(currentTime);

			pEffect = new EffectGentisDungeon(pCreature);
	
			if ( pEffect != NULL )
			{
				if (currentTime.tv_sec < DayTime) 
				{
					pEffect->setDeadline((DayTime - currentTime.tv_sec) * 10);
				} 
				else
				{
					pEffect->setDeadline(0);
				}
				
				pCreature->addEffect(pEffect);
				pCreature->setFlag( pEffect->getEffectClass() );
			}
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)
	
	__END_CATCH
}

EffectGentisDungeonLoader* g_pEffectGentisDungeonLoader = NULL;

