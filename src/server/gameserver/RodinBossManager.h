//////////////////////////////////////////////////////////////////////////////
// Filename    : RodinBossManager.h
// Description : Genuine Bathory (1069) and Genuine Tepez (1070) roam Rodin
//               (zones 41-44). Each boss waits a random delay, appears on a
//               random free tile of a random Rodin zone with a server-wide
//               announcement, and starts a new random delay once it is dead.
//               Driven from Zone::heartbeat, which runs whether or not a
//               player is in the zone (the monster heartbeat does not).
//////////////////////////////////////////////////////////////////////////////

#ifndef __RODIN_BOSS_MANAGER_H__
#define __RODIN_BOSS_MANAGER_H__

#include "Types.h"
#include "Exception.h"
#include "Mutex.h"
#include <time.h>

class Zone;

class RodinBossManager
{
public:
	RodinBossManager() throw (Error);

	static bool isRodinZone(ZoneID_t zoneID) { return zoneID >= 41 && zoneID <= 44; }

	// every Rodin zone's heartbeat, in that zone's thread
	void heartbeat(Zone* pZone) throw (Error);

	// GM: a boss that is not up appears in its target zone within a second
	string forceSpawn() throw (Error);

	string toString() const throw (Error);

private:
	enum { BOSS_MAX = 2, RODIN_ZONE_MAX = 4 };

	struct Boss
	{
		MonsterType_t	monsterType;
		const char*		name;
		ZoneID_t		zoneID;			// zone it is up in, 0 while waiting
		ObjectID_t		objectID;
		ZoneCoord_t		x, y;			// where it appeared
		ZoneID_t		targetZoneID;	// where it appears next
		time_t			spawnTime;		// when it appears next
	};

	// callers hold m_Mutex
	void initBosses(time_t now) throw ();
	void schedule(Boss& boss, time_t now, int minDelay, int maxDelay) throw ();
	bool spawn(Boss& boss, Zone* pZone) throw (Error);

	Boss			m_Bosses[BOSS_MAX];
	bool			m_bInit;
	time_t			m_LastCheck[RODIN_ZONE_MAX];	// one slot per zone, only touched by that zone's thread
	mutable Mutex	m_Mutex;
};

extern RodinBossManager g_RodinBossManager;

#endif
