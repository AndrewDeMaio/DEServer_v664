//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionBlitzRegister.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_BLITZ_REGISTER_H__
#define __ACTION_BLITZ_REGISTER_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionBlitzRegister
//////////////////////////////////////////////////////////////////////////////

class ActionBlitzRegister : public Action 
{
public:
	ActionBlitzRegister();
	~ActionBlitzRegister() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_BLITZ_REGISTER; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

};


//////////////////////////////////////////////////////////////////////////////
// class ActionBlitzRegisterFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionBlitzRegisterFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_BLITZ_REGISTER; }
	virtual string getActionName() const throw() { return "BlitzRegister"; }
	virtual Action* createAction() const throw() { return new ActionBlitzRegister(); }
};

#endif
