//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectMIRForceScroll2.h
// Written by  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_MIR_FORCE_SCROLL_2__
#define __EFFECT_MIR_FORCE_SCROLL_2__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectMIRForceScroll2
//////////////////////////////////////////////////////////////////////////////

class EffectMirForceScroll2 : public Effect
{
public:
	EffectMirForceScroll2(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_MIR_FORCE_SCROLL_2; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error); 
	void unaffect(Creature* pCreature) throw(Error);

	virtual void create( const string& ownerID ) throw(Error);
	virtual void destroy( const string& ownerID ) throw(Error);
	virtual void save( const string& ownerID ) throw(Error);

	bool isPossibleAffect () throw(Error); // 20081029 wlzzi - Extreme Force Scroll   	
	string toString() const throw();

private:
};

//////////////////////////////////////////////////////////////////////////////
// class EffectMIRForceScroll2Loader
//////////////////////////////////////////////////////////////////////////////

class EffectMirForceScroll2Loader : public EffectLoader
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_MIR_FORCE_SCROLL_2; }
	virtual string getEffectClassName() const throw() { return "EffectMirForceScroll2"; }

public:
	virtual void load( Creature* pCreature ) throw(Error);
};

extern EffectMirForceScroll2Loader* g_pEffectMirForceScroll2Loader;

#endif 
