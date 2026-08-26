//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionEnterDraculaCastle.h //MENEGROTH
// Written By  : rappi76
// Description : 
// 	Enter PVPSystem Doungeon.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_ENTER_PVP_SYSTEM_H__
#define __ACTION_ENTER_PVP_SYSTEM_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionEnterPVPSystem
//////////////////////////////////////////////////////////////////////////////

class ActionEnterPVPSystem : public Action 
{
public:
	virtual ActionType_t getActionType() const throw() { return ACTION_ENTER_PVP_SYSTEM; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

public:

private:

};


//////////////////////////////////////////////////////////////////////////////
// class ActionEnterPVPSystemFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionEnterPVPSystemFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_ENTER_PVP_SYSTEM; }
	virtual string getActionName() const throw() { return "EnterPVPSystem"; }
	virtual Action* createAction() const throw() { return new ActionEnterPVPSystem(); }
};

#endif
