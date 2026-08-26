//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionCheckComebackEventItem200604.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_CHECK_COMEBACK_EVENT_ITEM_200604_H__
#define __ACTION_CHECK_COMEBACK_EVENT_ITEM_200604_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionCheckEventItemDialog
//////////////////////////////////////////////////////////////////////////////

class ActionCheckComebackEventItem200604 : public Action 
{
public:
	ActionCheckComebackEventItem200604();
	~ActionCheckComebackEventItem200604() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_CHECK_COMEBACK_EVENT_ITEM_200604; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private :
	string					m_EventCheckType;
	ScriptID_t				m_EventScriptID;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionCheckEventItemDialogFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionCheckComebackEventItem200604Factory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_CHECK_COMEBACK_EVENT_ITEM_200604; }
	virtual string getActionName() const throw() { return "CheckComebackEventItem200604"; }
	virtual Action* createAction() const throw() { return new ActionCheckComebackEventItem200604(); }
};

#endif
