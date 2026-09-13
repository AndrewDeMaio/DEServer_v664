//////////////////////////////////////////////////////////////////////////////
// Filename    : BloodBibleBonusManager.h
// Written By  : bezz
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __BLOOD_BIBLE_BONUS_INFO_MANAGER_H__
#define __BLOOD_BIBLE_BONUS_INFO_MANAGER_H__

#include "Exception.h"
#include "Exception.h"
#include "Types.h"
#include <hash_map>
#include "BloodBibleBonus.h"
class GCHolyLandBonusInfo;
class BloodBibleBonus;

// Blood Bible token types run 0-83: twelve base bibles, then six clan tiers
// (Grun / Khan / Gabri / Phantom / Red / Ose) of the same twelve. Only the
// twelve base bonuses exist in BloodBibleBonusInfo, so a tiered token maps
// back onto its base bible with % BLOOD_BIBLE_PER_TIER.
#define BLOOD_BIBLE_PER_TIER	12
#define BLOOD_BIBLE_TIER_COUNT	6
#define BLOOD_BIBLE_TYPE_MAX	(BLOOD_BIBLE_PER_TIER * (BLOOD_BIBLE_TIER_COUNT + 1))

typedef hash_map<BloodBibleBonusType_t, BloodBibleBonus*>	BloodBibleBonusHashMap;
typedef BloodBibleBonusHashMap::iterator 					BloodBibleBonusHashMapItor;
typedef BloodBibleBonusHashMap::const_iterator 				BloodBibleBonusHashMapConstItor;

//////////////////////////////////////////////////////////////////////////////
// Class BloodBibleBonusManager
//////////////////////////////////////////////////////////////////////////////

class BloodBibleBonusManager 
{
public:
	BloodBibleBonusManager() throw();
	~BloodBibleBonusManager() throw();

public:

	// initialize Manager
	void init() throw(Error);

	// void load() throw();
	void load() throw(Error);
	
	// clear list
	void clear() throw();

	// Save to DB
	void save() throw(Error);

	// get BloodBibleBonus
	BloodBibleBonus* getBloodBibleBonus(BloodBibleBonusType_t bloodBibleBonusType) const throw(NoSuchElementException, Error);
	const BloodBibleBonusHashMap& getBloodBibleBonuses() const { return m_BloodBibleBonuses; }

	// add BloodBibleBonus
	void addBloodBibleBonus(BloodBibleBonus* pBloodBibleBonus) throw(DuplicatedException, Error);

	// toString for Debug
	string toString() const throw();

public:
	void setBloodBibleBonusRace( BloodBibleBonusType_t bloodBibleBonusType, Race_t race ) throw( Error );

	void makeHolyLandBonusInfo( GCHolyLandBonusInfo& gcHolyLandBonusInfo ) throw( Error );

#ifdef __CONTRIBUTION_SYSTEM__ 
	template <typename ITR> void getBloodBibleByRace(Race_t race, ITR oItr, int ContributeRank) const
	{
		BloodBibleBonusHashMapConstItor itr = m_BloodBibleBonuses.begin();

		// The client accepts token types 0-83: the twelve base bibles plus six
		// clan tiers of twelve. Rank picks the tier, 7 being the lowest (base
		// bible, no tier bonus) and 1 the highest (Ose). ContributeInfo is
		// empty in this database, so getRank() returns 0 for every player,
		// which used to produce (7-0)*12 = +84 and push every token past the
		// end of the client's range - the rent dialog could not render any of
		// them. Treat unranked, and anything else out of range, as the lowest
		// rank. Populating ContributeInfo lights up the tiers on its own.
		int rank = ContributeRank;
		if ( rank < 1 || rank > 7 )
			rank = 7;

		for ( ; itr != m_BloodBibleBonuses.end() ; ++itr )
		{
			if ( itr->second->getRace() == race )
			{
				// Only the twelve base bibles are tiered. This is a hash_map,
				// so iteration order is unspecified - skip the entry rather
				// than breaking out and truncating the rest of the list.
				if( itr->first > 11 )
					continue;

				(*oItr) = itr->first + ((7 - rank) * 12);
				++oItr;
			}
		}
	}
#else
	template <typename ITR> void getBloodBibleByRace(Race_t race, ITR oItr) const
	{
		BloodBibleBonusHashMapConstItor itr = m_BloodBibleBonuses.begin();

		for ( ; itr != m_BloodBibleBonuses.end() ; ++itr )
		{
			if ( itr->second->getRace() == race )
			{
				(*oItr) = itr->first;
				++oItr;
			}
		}
	}
#endif

private:
	uint					m_Count;
	BloodBibleBonusHashMap	m_BloodBibleBonuses;

};

// Global Variable Definition
extern BloodBibleBonusManager* g_pBloodBibleBonusManager;

#endif	// __SKILL_INFO_MANAGER_H__
