//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionSoccerEvent200606.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_SOCCER_EVENT_200606_H__
#define __ACTION_SOCCER_EVENT_200606_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionSoccerEvent200606
//////////////////////////////////////////////////////////////////////////////

class ActionSoccerEvent200606 : public Action 
{
public:
	ActionSoccerEvent200606();
	~ActionSoccerEvent200606() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_SOCCER_EVENT_200606; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private :
	int							m_EventBallNum;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionSoccerEvent200606Factory;
//////////////////////////////////////////////////////////////////////////////

class ActionSoccerEvent200606Factory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_SOCCER_EVENT_200606; }
	virtual string getActionName() const throw() { return "SoccerEvent200606"; }
	virtual Action* createAction() const throw() { return new ActionSoccerEvent200606(); }
};

#endif
