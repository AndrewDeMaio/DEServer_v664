//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionEnterMenegroth.h
// Written By  : rappi76
// Description : 
// 	Enter Menegroth Doungeon.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_ENTER_MENEGROTH_H__
#define __ACTION_ENTER_MENEGROTH_H__

#ifdef __MENEGROTH_DOUNGEON_SYSTEM__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionEnterMenegroth
//////////////////////////////////////////////////////////////////////////////

class ActionEnterMenegroth : public Action 
{
public:
	virtual ActionType_t getActionType() const throw() { return ACTION_ENTER_MENEGROTH; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

public:

private:

};


//////////////////////////////////////////////////////////////////////////////
// class ActionEnterMenegrothFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionEnterMenegrothFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_ENTER_MENEGROTH; }
	virtual string getActionName() const throw() { return "EnterMenegroth"; }
	virtual Action* createAction() const throw() { return new ActionEnterMenegroth(); }
};

#endif /* __MENEGROTH_DOUNGEON_SYSTEM__ */

#endif
