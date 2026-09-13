#ifndef __PET_EXP_INFO_H__
#define __PET_EXP_INFO_H__

#include "Types.h"
#include "types/PetTypes.h"

#include <vector>

const PetLevel_t PetMaxLevel=60;   // data has levels 0-60 (61 rows)

class PetExpInfo
{
public:
	PetExpInfo( PetLevel_t petLevel, PetExp_t goalExp ) : m_PetLevel(petLevel), m_PetGoalExp(goalExp) { }

	PetLevel_t getPetLevel() const { return m_PetLevel; }
	PetExp_t getPetGoalExp() const { return m_PetGoalExp; }
private:
	PetLevel_t	m_PetLevel;
	PetExp_t	m_PetGoalExp;

/*	static PetExp_t getTargetExp( PetLevel_t level ) { return 250 * level * level + 1000; }
	static bool canLevelUp( PetLevel_t level, PetExp_t exp )
	{
		if ( level >= 50 ) return false;
		return exp >= getTargetExp(level+1);
	}*/
};

class PetExpInfoManager
{
public:
	PetExpInfoManager() { m_PetExpInfos.resize(PetMaxLevel+1, NULL); }
	~PetExpInfoManager() { clear(); }

	void clear();
	void load();

	bool canLevelUp( PetLevel_t level, PetExp_t exp );
	static PetExpInfoManager& Instance() { static PetExpInfoManager theInstance; return theInstance; }

	PetExpInfo* getPetExpInfo( PetLevel_t level ) const { return m_PetExpInfos[level]; }

private:
	vector<PetExpInfo*> m_PetExpInfos;
};

#endif
