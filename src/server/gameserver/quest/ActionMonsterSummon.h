//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionMonsterSummon.h
// Description : Summon a monster from an NPC dialogue (Ruper Island's Altar of
//               Heroes wakes Sius). Ported from the v9 gameserver, which has the
//               same action name and fields; the item offering is new.
//
//   ActionType : MonsterSummon          (every field required, in this order -
//     Monster          : monster type     PropertyBuffer is sequential)
//     X / Y            : where to summon it
//     Num              : how many
//     DeleteMonster    : 0, or a monster type that must be alive in the zone and
//                        dies when the summon happens
//     RequireItemClass : 0 for none, or the class/type of one item taken from
//     RequireItemType    the player's inventory as the offering
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_MONSTER_SUMMON_H__
#define __ACTION_MONSTER_SUMMON_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionMonsterSummon;
//////////////////////////////////////////////////////////////////////////////

class ActionMonsterSummon : public Action
{
public:
	ActionMonsterSummon() throw(Error);
	virtual ~ActionMonsterSummon() throw(Error) {}

	virtual ActionType_t getActionType() const throw() { return ACTION_MONSTER_SUMMON; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private:
	MonsterType_t m_MonsterType;
	MonsterType_t m_DeleteMonsterType;
	ZoneCoord_t   m_X;
	ZoneCoord_t   m_Y;
	int           m_Num;
	int           m_RequireItemClass;	// -1 = no offering
	ItemType_t    m_RequireItemType;
};

////////////////////////////////////////////////////////////////////////////////
// class ActionMonsterSummonFactory;
////////////////////////////////////////////////////////////////////////////////

class ActionMonsterSummonFactory : public ActionFactory
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_MONSTER_SUMMON; }
	virtual string getActionName() const throw() { return "MonsterSummon"; }
	virtual Action* createAction() const throw() { return new ActionMonsterSummon(); }
};

#endif
