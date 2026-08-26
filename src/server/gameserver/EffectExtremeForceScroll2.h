//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectExtremeForceScroll2.h
// Written by  : wlzzi - 2008.10.28
// Description :     
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_EXTREME_FORCE_SCROLL_2__
#define __EFFECT_EXTREME_FORCE_SCROLL_2__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectExtremeForceScroll2
//////////////////////////////////////////////////////////////////////////////

class EffectExtremeForceScroll2 : public Effect
{
public:
	EffectExtremeForceScroll2(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_EXTREME_FORCE_SCROLL_2; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error); 
	void unaffect(Creature* pCreature) throw(Error);

	virtual void create( const string& ownerID ) throw(Error);
	virtual void destroy( const string& ownerID ) throw(Error);
	virtual void save( const string& ownerID ) throw(Error);

	bool isPossibleAffect () throw(Error);
	string toString() const throw();

private:
};

//////////////////////////////////////////////////////////////////////////////
// class EffectExtremeForceScroll2Loader
//////////////////////////////////////////////////////////////////////////////

class EffectExtremeForceScroll2Loader : public EffectLoader
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_EXTREME_FORCE_SCROLL_2; }
	virtual string getEffectClassName() const throw() { return "EffectExtremeForceScroll2"; }

public:
	virtual void load( Creature* pCreature ) throw(Error);
};

extern EffectExtremeForceScroll2Loader* g_pEffectExtremeForceScroll2Loader;

#endif 
