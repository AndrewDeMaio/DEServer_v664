//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionCheckEventLevelUp200604.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_CHECK_EVENT_LEVELUP_200604_H__
#define __ACTION_CHECK_EVENT_LEVELUP_200604_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionCheckEventLevelUp200604
//////////////////////////////////////////////////////////////////////////////

class ActionCheckEventLevelUp200604 : public Action 
{
public:
	ActionCheckEventLevelUp200604();
	~ActionCheckEventLevelUp200604() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_CHECK_EVENT_LEVELUP_200604; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private :
	Level_t		m_Level;
	ScriptID_t	m_SatisfyScriptID;
	ScriptID_t	m_UnsatisfyScriptID;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionCheckEventLevelUp200604Factory;
//////////////////////////////////////////////////////////////////////////////

class ActionCheckEventLevelUp200604Factory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_CHECK_EVENT_LEVELUP_200604; }
	virtual string getActionName() const throw() { return "CheckEventLevelUp200604"; }
	virtual Action* createAction() const throw() { return new ActionCheckEventLevelUp200604(); }
};

#endif
