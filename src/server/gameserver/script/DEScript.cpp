#include "DEScript.h"

#include "Monster.h"
#include "Player.h"
#include "PlayerCreature.h"

#include "PCFinder.h"

#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCModifyInformation.h"

#include "ZoneGroupManager.h"

#include <string.h>
#include <time.h>

Mutex DEScript::m_Mutex;
TWhiteBoardOfInteger DEScript::m_WhiteBoardOfInteger;

DEScript::DEScript()
{
	m_Mutex.setName("DEScript");
	m_Mutex.lock();
	
   	m_pLuaState = lua_open(); // 루아 state를 생성한다.

	luaopen_base(m_pLuaState);
	luaopen_math(m_pLuaState);
	luaopen_table(m_pLuaState);
	//luaopen_io(m_pLuaState);
	//luaopen_os(m_pLuaState);
	luaopen_string(m_pLuaState);
	
	//luaopen_debug(m_pLuaState);
	//luaopen_package(m_pLuaState);
	//luaopen_openlibs(m_pLuaState);	
	
	lua_tinker::class_add<DEScript>(m_pLuaState, "DEScript");
	
	lua_tinker::class_def<DEScript>(m_pLuaState, "IsGod", &DEScript::IsGod);
	lua_tinker::class_def<DEScript>(m_pLuaState, "IsDM", &DEScript::IsDM);
	lua_tinker::class_def<DEScript>(m_pLuaState, "IsHELPER", &DEScript::IsHELPER);
	lua_tinker::class_def<DEScript>(m_pLuaState, "IsPLAYER", &DEScript::IsPLAYER);

	lua_tinker::class_def<DEScript>(m_pLuaState, "IsDead", &DEScript::IsDead);
	lua_tinker::class_def<DEScript>(m_pLuaState, "IsAlive", &DEScript::IsAlive);
	
	lua_tinker::class_def<DEScript>(m_pLuaState, "IsPC", &DEScript::IsPC);
	lua_tinker::class_def<DEScript>(m_pLuaState, "IsMonster", &DEScript::IsMonster);
	
	lua_tinker::class_def<DEScript>(m_pLuaState, "IsSlayer", &DEScript::IsSlayer);
	lua_tinker::class_def<DEScript>(m_pLuaState, "IsOusters", &DEScript::IsOusters);
	lua_tinker::class_def<DEScript>(m_pLuaState, "IsVampire", &DEScript::IsVampire);
	lua_tinker::class_def<DEScript>(m_pLuaState, "GetLevel", &DEScript::GetLevel);
	lua_tinker::class_def<DEScript>(m_pLuaState, "GetAdvancementClassLevel", &DEScript::GetAdvancementClassLevel);
	
	lua_tinker::class_def<DEScript>(m_pLuaState, "RemoveMonsterBrain", &DEScript::RemoveMonsterBrain);
	
	lua_tinker::class_def<DEScript>(m_pLuaState, "SetHP", &DEScript::SetHP);
	
	lua_tinker::class_def<DEScript>(m_pLuaState, "GetCurrentTime", &DEScript::GetCurrentTime);
	lua_tinker::class_def<DEScript>(m_pLuaState, "GetHour", &DEScript::GetHour);
	lua_tinker::class_def<DEScript>(m_pLuaState, "GetMin", &DEScript::GetMin);
	lua_tinker::class_def<DEScript>(m_pLuaState, "AddTime", &DEScript::AddTime);
	
	lua_tinker::class_def<DEScript>(m_pLuaState, "GoldenTimeEventCreatureInfo", &DEScript::GoldenTimeEventCreatureInfo);
	
	lua_tinker::class_def<DEScript>(m_pLuaState, "WriteIntegerOnWhiteBoard", &DEScript::WriteIntegerOnWhiteBoard);
	lua_tinker::class_def<DEScript>(m_pLuaState, "ReadIntegerOnWhiteBoard", &DEScript::ReadIntegerOnWhiteBoard);
	
	lua_tinker::class_def<DEScript>(m_pLuaState, "WriteFileLog", &DEScript::WriteFileLog);
	
	lua_tinker::set(m_pLuaState, "DEScript", this);
	
	m_Mutex.unlock();
}

DEScript::~DEScript()
{
	m_Mutex.lock();
	lua_close(m_pLuaState); // 루아 state를 해제한다.
	m_Mutex.unlock();
}

void DEScript::Load(char *strScript)
{
	lua_tinker::dofile(m_pLuaState, strScript);
}

lua_tinker::table DEScript::GoldenTimeEventCreatureInfo()
{
	g_pPCFinder->lock();
	
	vector<Creature*> allUserInfo;
	PCFinder::TCreatureMap::const_iterator iter;		
	iter = g_pPCFinder->getCreatures().begin();
	
	for(; iter != g_pPCFinder->getCreatures().end() ; ++iter )
	{
		Creature* pCreature = iter->second;
		
		if ( pCreature->isPC() )
		{
			allUserInfo.push_back( pCreature );
		}
	}
	
	g_pPCFinder->unlock();
	
	unsigned int maxCount = (unsigned int)allUserInfo.size();
		
	if(maxCount != 0)
	{
		srand((unsigned)time(NULL));
		unsigned int ratio = rand() % maxCount;
	
		printf("Test Ratio : %d \n", ratio);
	
		lua_tinker::table CreatureInfo(m_pLuaState);
		MakeCreatureInfo(CreatureInfo, allUserInfo[ratio]);
	
		return CreatureInfo;
	}
}

void DEScript::MakeCreatureInfo(lua_tinker::table& CreatureInfo, Creature *pCreature)
{
	if ( pCreature != NULL )
	{
		CreatureInfo.set<const char *>("Name", pCreature->getName().c_str());
		CreatureInfo.set<ObjectID_t>("ObjectID", pCreature->getObjectID());
		CreatureInfo.set<ZoneCoord_t>("X", pCreature->getX());
		CreatureInfo.set<ZoneCoord_t>("Y", pCreature->getY());
		
		if ( pCreature->isMonster())
		{
			Monster *pMonster = dynamic_cast<Monster *>(pCreature);
			
			CreatureInfo.set<HP_t>("MType", pMonster->getMonsterType());
			CreatureInfo.set<HP_t>("MaxHP", pMonster->getHP(ATTR_MAX));
			CreatureInfo.set<HP_t>("CurHP", pMonster->getHP(ATTR_CURRENT));
		}
		else if ( pCreature->isPC())
		{
			PlayerCreature *pPC = dynamic_cast<PlayerCreature *>(pCreature);
						
			CreatureInfo.set<HP_t>("MaxHP", pPC->getHP(ATTR_MAX));
			CreatureInfo.set<HP_t>("CurHP", pPC->getHP(ATTR_CURRENT));
			
		}
	}
	else
	{
		CreatureInfo.set<const char *>("Name", "");
		CreatureInfo.set<ObjectID_t>("ObjectID", 0);
		CreatureInfo.set<ZoneCoord_t>("X", 0);
		CreatureInfo.set<ZoneCoord_t>("Y", 0);
		CreatureInfo.set<HP_t>("MaxHP", 0);
		CreatureInfo.set<HP_t>("CurHP", 0);
	}
	
	CreatureInfo.set<Creature *>("_pCreature", pCreature);
}

void DEScript::MakeMonsterInfo(lua_tinker::table& MonsterInfo, Monster *pMonster)
{
	if ( pMonster != NULL )
	{
		MonsterInfo.set<const char *>("Name", pMonster->getName().c_str());
		MonsterInfo.set<ObjectID_t>("ObjectID", pMonster->getObjectID());
		MonsterInfo.set<MonsterType_t>("MType", pMonster->getMonsterType());
		MonsterInfo.set<SpriteType_t>("SType", pMonster->getSpriteType());
		
		MonsterInfo.set<ZoneCoord_t>("X", pMonster->getX());
		MonsterInfo.set<ZoneCoord_t>("Y", pMonster->getY());
		
		MonsterInfo.set<HP_t>("MaxHP", pMonster->getHP(ATTR_MAX));
		MonsterInfo.set<HP_t>("CurHP", pMonster->getHP(ATTR_CURRENT));
	}
	else
	{
		MonsterInfo.set<const char *>("Name", "");
		MonsterInfo.set<ObjectID_t>("ObjectID", 0);
		MonsterInfo.set<MonsterType_t>("MType", 0);
		MonsterInfo.set<SpriteType_t>("SType", 0);
		MonsterInfo.set<ZoneCoord_t>("X", 0);
		MonsterInfo.set<ZoneCoord_t>("Y", 0);
		MonsterInfo.set<HP_t>("MaxHP", 0);
		MonsterInfo.set<HP_t>("CurHP", 0);
	}
	
	MonsterInfo.set<Creature *>("_pCreature", (Creature *)pMonster);
	MonsterInfo.set<Monster *>("_pMonster", pMonster);
}

void DEScript::MakeZoneInfo(lua_tinker::table& ZoneInfo, Zone *pZone)
{
	if ( pZone != NULL )
	{
		ZoneInfo.set<ZoneID_t>("ZoneID", pZone->getZoneID());
	}
	else
	{
		ZoneInfo.set<ZoneID_t>("ZoneID", 0);
	}
	
	ZoneInfo.set<Zone *>("_pZone", pZone);
}

void DEScript::MakeEffectInfo(lua_tinker::table& EffectInfo, Effect *pEffect)
{
	if ( pEffect != NULL )
	{
		EffectInfo.set<ObjectID_t>("ObjectID", pEffect->getObjectID());
	}
	else
	{
		EffectInfo.set<ObjectID_t>("ObjectID", 0);
	}
	
	EffectInfo.set<Effect *>("_pEffect", pEffect);
	
}

bool DEScript::IsGod(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
		
	if (pCreature != NULL && pCreature->isGOD())
	{
		return true;
	}
		
	return false;
}

bool DEScript::IsDM(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
		
	if (pCreature != NULL && pCreature->isDM())
	{
		return true;
	}
		
	return false;	
}

bool DEScript::IsHELPER(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
		
	if (pCreature != NULL && pCreature->isHELPER())
	{
		return true;
	}
		
	return false;	
}

bool DEScript::IsPLAYER(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
			
	if (pCreature != NULL && pCreature->isPLAYER())
	{
		return true;
	}
		
	return false;
}

bool DEScript::IsDead(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
			
	if (pCreature != NULL && pCreature->isDead())
	{
		return true;
	}
		
	return false;	
}

bool DEScript::IsAlive(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
				
	if (pCreature != NULL && pCreature->isAlive())
	{
		return true;
	}
		
	return false;
}
	
bool DEScript::IsPC(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
	
	if (pCreature != NULL && pCreature->isPC())
	{
		return true;
	}
		
	return false;
}

bool DEScript::IsMonster(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
	
	if (pCreature != NULL && pCreature->isMonster())
	{
		return true;
	}
		
	return false;
}

bool DEScript::IsSlayer(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
	
	if (pCreature != NULL && pCreature->isSlayer())
	{
		return true;
	}
		
	return false;
}

bool DEScript::IsVampire(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
	
	if (pCreature != NULL && pCreature->isVampire())
	{
		return true;
	}
		
	return false;
}

bool DEScript::IsOusters(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
	
	if (pCreature != NULL && pCreature->isOusters())
	{
		return true;
	}
		
	return false;
}

Level_t DEScript::GetLevel(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
	
	if ( pCreature == NULL )
	{
		return 0;
	}
	
	PlayerCreature *pPC = dynamic_cast<PlayerCreature *>(pCreature);
	
	return pPC->getLevel();
	
}

Level_t DEScript::GetAdvancementClassLevel(lua_tinker::table CreatureInfo)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
	
	if ( pCreature == NULL )
	{
		return 0;
	}
	
	PlayerCreature *pPC = dynamic_cast<PlayerCreature *>(pCreature);
	
	return pPC->getAdvancementClassLevel();
}

void DEScript::RemoveMonsterBrain(lua_tinker::table MonsterInfo)
{
	Creature *pCreature = MonsterInfo.get<Creature *>("_pCreature");
	
	if ( pCreature->isMonster() )
	{
		Monster *pMonster = dynamic_cast<Monster *>(pCreature);
		
		pMonster->setBrain(NULL);
	}
}

lua_tinker::table DEScript::SetHP(lua_tinker::table CreatureInfo, HP_t hp)
{
	Creature *pCreature = CreatureInfo.get<Creature *>("_pCreature");
	
	lua_tinker::table ChangedCreatureInfo(m_pLuaState);
	
	if ( pCreature == NULL )
	{
		return CreatureInfo;
	}
	
	if ( pCreature->isPC())
	{
		PlayerCreature *pPlayerCreature = dynamic_cast<PlayerCreature *>(pCreature);
				
		pPlayerCreature->setHP(hp);
		
		GCModifyInformation gcMI;
		gcMI.addShortData(MODIFY_CURRENT_HP, hp);
		pPlayerCreature->getPlayer()->sendPacket(&gcMI);
		
	}
	else if ( pCreature->isMonster())
	{
		Monster *pMonster = dynamic_cast<Monster *>(pCreature);
		
		pMonster->setHP(hp);	
	}
	else
	{
		MakeCreatureInfo(ChangedCreatureInfo, NULL);
		
		return ChangedCreatureInfo;
	}

	// 변한 HP를 브로드캐스팅해준다.
	GCStatusCurrentHP pkt;
	pkt.setObjectID(pCreature->getObjectID());
	pkt.setCurrentHP(hp);
	
	Zone *pZone;
	pZone = pCreature->getZone();
	if ( pZone != NULL )
	{
		pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &pkt);
	}
	
	MakeCreatureInfo(ChangedCreatureInfo, pCreature);
	
	return ChangedCreatureInfo;
	
}

long DEScript::GetCurrentTime()
{
	Timeval m_currentTime;
	
	getCurrentTime(m_currentTime);
	
	return m_currentTime.tv_sec;
	
}

long DEScript::GetHour()
{
	struct tm *time_struct;
	time_t local;
	
	(void)time(&local);
	
	time_struct = localtime(&local);
	
	return time_struct->tm_hour;
	
}

long DEScript::GetMin()
{
	struct tm *time_struct;
	time_t local;
	
	(void)time(&local);
	
	time_struct = localtime(&local);
	
	return time_struct->tm_min;	
}

long DEScript::AddTime(long lTimeVal, const char *strAddType, long lAddValue)
{
	long lAddTime = 0;
	
	if ( strncmp(strAddType, "H", 1) == 0 )
	{
		lAddTime = 60 * 60 * lAddValue;
		
	}
	else if ( strncmp(strAddType, "M", 1) == 0 )
	{
		lAddTime = 60 * lAddValue;
		
	}
	else if ( strncmp(strAddType, "S", 1) == 0 )
	{
		lAddTime = lAddValue;
	}
	
	return lTimeVal + lAddTime;
}

void DEScript::WriteIntegerOnWhiteBoard(const char *strKey, int iVal)
{
	m_WhiteBoardOfInteger[strKey] = iVal;
}

int DEScript::ReadIntegerOnWhiteBoard(const char *strKey, int iDefaultVal)
{
	if ( m_WhiteBoardOfInteger.find(strKey) != m_WhiteBoardOfInteger.end() )
	{
		return m_WhiteBoardOfInteger[strKey];
	}
	
	return iDefaultVal;
}


void DEScript::WriteFileLog(const char *pLogFileName, const char *pLogMsg)
{
	filelog(pLogFileName, pLogMsg);
}
