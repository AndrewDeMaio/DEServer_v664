//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionRedistributeAttr50.h
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_REDISTRIBUTE_50_H__
#define __ACTION_REDISTRIBUTE_50_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionRedistributeAttr50
//////////////////////////////////////////////////////////////////////////////

class ActionRedistributeAttr50 : public Action 
{
public:
	virtual ActionType_t getActionType() const throw() { return ACTION_REDISTRIBUTE_ATTR_50; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private:
	int m_AttrType;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionRedistributeAttr50Factory;
//////////////////////////////////////////////////////////////////////////////

class ActionRedistributeAttr50Factory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_REDISTRIBUTE_ATTR_50; }
	virtual string getActionName() const throw() { return "RedistributeAttr50"; }
	virtual Action* createAction() const throw() { return new ActionRedistributeAttr50(); }
};

#endif
