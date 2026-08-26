//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionGambleSystem.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_GAMBLE_SYSTEM_H__
#define __ACTION_GAMBLE_SYSTEM_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionGambleSystem
//////////////////////////////////////////////////////////////////////////////

class ActionGambleSystem : public Action 
{
public:
	ActionGambleSystem();
	~ActionGambleSystem() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_GAMBLE_SYSTEM; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private :
	int							m_SelectID;
	ScriptID_t					m_NextGambleScriptID;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionGambleSystemFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionGambleSystemFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_GAMBLE_SYSTEM; }
	virtual string getActionName() const throw() { return "GambleSystem"; }
	virtual Action* createAction() const throw() { return new ActionGambleSystem(); }
};

#endif
