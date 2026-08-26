//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionGiveHellGardenSeedItem.h
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_GIVE_HELLGARDEN_SEED_ITEM_H__
#define __ACTION_GIVE_HELLGARDEN_SEED_ITEM_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionGiveHellGardenSeedItem
//////////////////////////////////////////////////////////////////////////////

class ActionGiveHellGardenSeedItem : public Action 
{
public:
	virtual ActionType_t getActionType() const throw() { return ACTION_GIVE_HELLGARDEN_SEED_ITEM; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();
public:
	int getType(void) const { return m_Type; }
	void setType(int type) { m_Type = type; }

private:
	ItemType_t m_Type; 
}
;


//////////////////////////////////////////////////////////////////////////////
// class ActionGiveHellGardenSeedItemFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionGiveHellGardenSeedItemFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_GIVE_HELLGARDEN_SEED_ITEM; }
	virtual string getActionName() const throw() { return "GiveHellGardenSeedItem"; }
	virtual Action* createAction() const throw() { return new ActionGiveHellGardenSeedItem(); }
};

#endif
