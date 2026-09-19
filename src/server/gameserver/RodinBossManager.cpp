//////////////////////////////////////////////////////////////////////////////
// Filename    : RodinBossManager.cpp
// Description : See RodinBossManager.h.
//
//               Spawn and death are logged to RodinBoss.log (bin/).
//               GM: *command rodinBoss (status), *command spawnRodinBoss.
//////////////////////////////////////////////////////////////////////////////

#include "RodinBossManager.h"
#include "Zone.h"
#include "Monster.h"
#include "MonsterManager.h"
#include "ZoneGroupManager.h"
#include "Utility.h"
#include "Gpackets/GCSystemMessage.h"

#include <stdio.h>
#include <stdlib.h>
#include <list>

// First appearance after server start, and the wait after each death, in seconds.
static const int FIRST_SPAWN_MIN = 10 * 60;
static const int FIRST_SPAWN_MAX = 30 * 60;
static const int RESPAWN_MIN     = 60 * 60;
static const int RESPAWN_MAX     = 120 * 60;

// No free tile found: try again, in another random Rodin zone, after this long.
static const int RETRY_DELAY     = 60;

static const ZoneID_t RODIN_FIRST_ZONE = 41;

RodinBossManager g_RodinBossManager;

namespace
{
	struct MutexGuard
	{
		Mutex& m_rMutex;
		MutexGuard(Mutex& rMutex) : m_rMutex(rMutex) { m_rMutex.lock(); }
		~MutexGuard() { m_rMutex.unlock(); }
	};

	const char* zoneName(ZoneID_t zoneID)
	{
		switch (zoneID)
		{
			case 41: return "Rodin NE";
			case 42: return "Rodin NW";
			case 43: return "Rodin SE";
			case 44: return "Rodin SW";
		}
		return "Rodin";
	}

	void announce(const string& message)
	{
		GCSystemMessage gcSystemMessage;
		gcSystemMessage.setType( SYSTEM_MESSAGE_MASTER_LAIR );
		gcSystemMessage.setMessage( message );
		g_pZoneGroupManager->pushBroadcastPacket( &gcSystemMessage );
	}
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
RodinBossManager::RodinBossManager()
	throw (Error)
	: m_bInit(false)
{
	static const MonsterType_t types[BOSS_MAX] = { 1069, 1070 };
	static const char* names[BOSS_MAX] = { "Genuine Bathory", "Genuine Tepez" };

	for (int i = 0; i < BOSS_MAX; i++)
	{
		Boss& boss = m_Bosses[i];

		boss.monsterType  = types[i];
		boss.name         = names[i];
		boss.zoneID       = 0;
		boss.objectID     = 0;
		boss.x            = 0;
		boss.y            = 0;
		boss.targetZoneID = 0;
		boss.spawnTime    = 0;
	}

	for (int i = 0; i < RODIN_ZONE_MAX; i++)
		m_LastCheck[i] = 0;
}

////////////////////////////////////////////////////////////////////////////////
// Timers start on the first call rather than at static construction, where
// rand() is not seeded yet.
////////////////////////////////////////////////////////////////////////////////
void RodinBossManager::initBosses(time_t now)
	throw ()
{
	if (m_bInit) return;

	for (int i = 0; i < BOSS_MAX; i++)
		schedule(m_Bosses[i], now, FIRST_SPAWN_MIN, FIRST_SPAWN_MAX);

	m_bInit = true;
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
void RodinBossManager::schedule(Boss& boss, time_t now, int minDelay, int maxDelay)
	throw ()
{
	boss.zoneID       = 0;
	boss.objectID     = 0;
	boss.targetZoneID = RODIN_FIRST_ZONE + rand() % RODIN_ZONE_MAX;
	boss.spawnTime    = now + minDelay + rand() % (maxDelay - minDelay + 1);

	filelog("RodinBoss.log", "%s next appears in %s (zone %d) in %d s",
		boss.name, zoneName(boss.targetZoneID), (int)boss.targetZoneID, (int)(boss.spawnTime - now));
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
bool RodinBossManager::spawn(Boss& boss, Zone* pZone)
	throw (Error)
{
	__BEGIN_TRY

	ZoneCoord_t x = 0, y = 0;

	try
	{
		// gives up (throws) after 300 blocked, portal or safe-zone tiles
		if (!pZone->getMonsterManager()->findPosition(boss.monsterType, x, y))
			return false;
	}
	catch (...)
	{
		filelog("RodinBoss.log", "%s: no free tile in zone %d", boss.name, (int)pZone->getZoneID());
		return false;
	}

	Monster* pMonster = new Monster(boss.monsterType);

	// Not from the zone's spawn lists: an index past every EventMonsterInfo slot keeps MonsterManager
	// from tying it to a slot or a sprite counter (the same marker the double-monster regen uses).
	pMonster->setEventMonsterIndex(0xFFFE);

	try
	{
		pZone->addCreature(pMonster, x, y, Directions(rand() % 8));
	}
	catch (EmptyTileNotExistException&)
	{
		SAFE_DELETE(pMonster);
		filelog("RodinBoss.log", "%s: no empty tile near %d,%d in zone %d", boss.name, (int)x, (int)y, (int)pZone->getZoneID());
		return false;
	}

	boss.zoneID   = pZone->getZoneID();
	boss.objectID = pMonster->getObjectID();
	boss.x        = pMonster->getX();
	boss.y        = pMonster->getY();

	filelog("RodinBoss.log", "%s (OID %d) appeared in %s (zone %d) at %d,%d",
		boss.name, (int)boss.objectID, zoneName(boss.zoneID), (int)boss.zoneID, (int)boss.x, (int)boss.y);

	return true;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
void RodinBossManager::heartbeat(Zone* pZone)
	throw (Error)
{
	__BEGIN_TRY

	Assert(pZone != NULL);

	ZoneID_t zoneID = pZone->getZoneID();
	if (!isRodinZone(zoneID)) return;

	// Zone::heartbeat runs many times a second; once a second per zone is plenty.
	time_t now = time(0);
	time_t& lastCheck = m_LastCheck[zoneID - RODIN_FIRST_ZONE];
	if (lastCheck == now) return;
	lastCheck = now;

	list<string> announcements;

	{
		MutexGuard guard(m_Mutex);

		initBosses(now);

		for (int i = 0; i < BOSS_MAX; i++)
		{
			Boss& boss = m_Bosses[i];

			if (boss.zoneID == zoneID)
			{
				// A corpse is only cleaned up while a PC is in the zone, so a dead body counts as gone.
				Monster* pMonster = dynamic_cast<Monster*>(pZone->getMonsterManager()->getCreature(boss.objectID));

				if (pMonster != NULL && pMonster->getMonsterType() == boss.monsterType && !pMonster->isDead())
					continue;

				filelog("RodinBoss.log", "%s (OID %d) is gone from %s (zone %d)",
					boss.name, (int)boss.objectID, zoneName(zoneID), (int)zoneID);

				announcements.push_back(string(boss.name) + " has been defeated in Rodin!");
				schedule(boss, now, RESPAWN_MIN, RESPAWN_MAX);
			}
			else if (boss.zoneID == 0 && boss.targetZoneID == zoneID && now >= boss.spawnTime)
			{
				if (spawn(boss, pZone))
					announcements.push_back(string(boss.name) + " has appeared somewhere in Rodin!");
				else
					schedule(boss, now, RETRY_DELAY, RETRY_DELAY);
			}
		}
	}

	for (list<string>::const_iterator itr = announcements.begin(); itr != announcements.end(); ++itr)
		announce(*itr);

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
string RodinBossManager::forceSpawn()
	throw (Error)
{
	__BEGIN_TRY

	time_t now = time(0);
	string result;
	char line[128];

	MutexGuard guard(m_Mutex);

	initBosses(now);

	for (int i = 0; i < BOSS_MAX; i++)
	{
		Boss& boss = m_Bosses[i];

		if (boss.zoneID != 0)
		{
			snprintf(line, sizeof(line), "%s: already up in %s (appeared at %d,%d)",
				boss.name, zoneName(boss.zoneID), (int)boss.x, (int)boss.y);
		}
		else
		{
			boss.spawnTime = now;
			snprintf(line, sizeof(line), "%s: appears in %s within a second", boss.name, zoneName(boss.targetZoneID));
		}

		if (i > 0) result += " | ";
		result += line;
	}

	return result;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
string RodinBossManager::toString() const
	throw (Error)
{
	__BEGIN_TRY

	time_t now = time(0);
	string result;
	char line[128];

	MutexGuard guard(m_Mutex);

	for (int i = 0; i < BOSS_MAX; i++)
	{
		const Boss& boss = m_Bosses[i];

		if (!m_bInit)
		{
			snprintf(line, sizeof(line), "%s: timer starts with the first Rodin heartbeat", boss.name);
		}
		else if (boss.zoneID != 0)
		{
			snprintf(line, sizeof(line), "%s: up in %s (appeared at %d,%d)",
				boss.name, zoneName(boss.zoneID), (int)boss.x, (int)boss.y);
		}
		else
		{
			int left = boss.spawnTime > now ? (int)(boss.spawnTime - now) : 0;
			snprintf(line, sizeof(line), "%s: next in %s in %dm%02ds",
				boss.name, zoneName(boss.targetZoneID), left / 60, left % 60);
		}

		if (i > 0) result += " | ";
		result += line;
	}

	return result;

	__END_CATCH
}
