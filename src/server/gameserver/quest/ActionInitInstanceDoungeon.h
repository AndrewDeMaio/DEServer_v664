//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionInitInstanceDoungeon.h
// Written By  : rappi76
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_INIT_INSTANCEDOUNGEON_H__
#define __ACTION_INIT_INSTANCEDOUNGEON_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionInitInstanceDoungeon;
//////////////////////////////////////////////////////////////////////////////

class ActionInitInstanceDoungeon : public Action 
{
public:
	ActionInitInstanceDoungeon() throw(Error) {}
	virtual ~ActionInitInstanceDoungeon() throw(Error) {}
	
	virtual ActionType_t getActionType() const throw() { return ACTION_INIT_INSTANCEDOUNGEON; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

public:
	string getDoungeonScript() { return m_strDoungeonScript; }
	void setDoungeonScript(string& strScript) { m_strDoungeonScript = strScript; }

private:
	string m_strDoungeonScript;

};

////////////////////////////////////////////////////////////////////////////////
// class ActionInitInstanceDoungeonFactory;
////////////////////////////////////////////////////////////////////////////////

class ActionInitInstanceDoungeonFactory : public ActionFactory 
{
public:
    virtual ActionType_t getActionType() const throw() { return Action::ACTION_INIT_INSTANCEDOUNGEON; }
    virtual string getActionName() const throw() { return "InitInstanceDoungeon"; }
    virtual Action* createAction() const throw() { return new ActionInitInstanceDoungeon(); }
};

#endif
