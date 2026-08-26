//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectTituosForceScroll2.h
// Written by  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_TITUOS_FORCE_SCROLL_2__
#define __EFFECT_TITUOS_FORCE_SCROLL_2__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectTituosForceScroll2
//////////////////////////////////////////////////////////////////////////////

class EffectTituosForceScroll2 : public Effect
{
public:
	EffectTituosForceScroll2(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_TITUOS_FORCE_SCROLL_2; }

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
// class EffectTituosForceScroll2Loader
//////////////////////////////////////////////////////////////////////////////

class EffectTituosForceScroll2Loader : public EffectLoader
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_TITUOS_FORCE_SCROLL_2; }
	virtual string getEffectClassName() const throw() { return "EffectTituosForceScroll2"; }

public:
	virtual void load( Creature* pCreature ) throw(Error);
};

extern EffectTituosForceScroll2Loader* g_pEffectTituosForceScroll2Loader;

#endif 

