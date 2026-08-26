//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionResetAttribute.h
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_RESET_ATTRIBUTE_H__
#define __ACTION_RESET_ATTRIBUTE_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionResetAttribute
//////////////////////////////////////////////////////////////////////////////

class ActionResetAttribute : public Action 
{
public:
	virtual ActionType_t getActionType() const throw() { return ACTION_RESET_ATTRIBUTE; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

};


//////////////////////////////////////////////////////////////////////////////
// class ActionResetAttributeFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionResetAttributeFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_RESET_ATTRIBUTE; }
	virtual string getActionName() const throw() { return "ResetAttribute"; }
	virtual Action* createAction() const throw() { return new ActionResetAttribute(); }
};

#endif
