//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionGiveEventLevelUp200604.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_GIVE_EVENT_LEVELUP_200604_H__
#define __ACTION_GIVE_EVENT_LEVELUP_200604_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionGiveEventLevelUp200604
//////////////////////////////////////////////////////////////////////////////

class ActionGiveEventLevelUp200604 : public Action 
{
public:
	ActionGiveEventLevelUp200604();
	~ActionGiveEventLevelUp200604() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_GIVE_EVENT_LEVELUP_200604; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private :
	Level_t		m_Level;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionGiveEventLevelUp200604Factory;
//////////////////////////////////////////////////////////////////////////////

class ActionGiveEventLevelUp200604Factory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_GIVE_EVENT_LEVELUP_200604; }
	virtual string getActionName() const throw() { return "GiveEventLevelUp200604"; }
	virtual Action* createAction() const throw() { return new ActionGiveEventLevelUp200604(); }
};

#endif
