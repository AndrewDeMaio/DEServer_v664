//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionInsertCabracamHeart.h
// Written By  : rappi76
// Description : 
// 	Enter Menegroth Doungeon.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_INSERT_CABRACAM_HEART_H__
#define __ACTION_INSERT_CABRACAM_HEART_H__

#ifdef __MENEGROTH_DOUNGEON_SYSTEM__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionInsertCabracamHeart
//////////////////////////////////////////////////////////////////////////////

class ActionInsertCabracamHeart : public Action 
{
public:
	virtual ActionType_t getActionType() const throw() { return ACTION_INSERT_CABRACAM_HEART; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

public:

private:
	int m_iIncompleteScriptID;

};


//////////////////////////////////////////////////////////////////////////////
// class ActionInsertCabracamHeartFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionInsertCabracamHeartFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_INSERT_CABRACAM_HEART; }
	virtual string getActionName() const throw() { return "InsertCabracamHeart"; }
	virtual Action* createAction() const throw() { return new ActionInsertCabracamHeart(); }
};

#endif /* __MENEGROTH_DOUNGEON_SYSTEM__ */

#endif /*  __ACTION_INSERT_CABRACAM_HEART_H__ */
