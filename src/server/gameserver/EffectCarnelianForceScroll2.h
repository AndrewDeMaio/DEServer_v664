//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectCarnelianForceScroll2.h
// Written by  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_CARNELIAN_FORCE_SCROLL_2__
#define __EFFECT_CARNELIAN_FORCE_SCROLL_2__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectCarnelianForceScroll2
//////////////////////////////////////////////////////////////////////////////

class EffectCarnelianForceScroll2 : public Effect
{
public:
	EffectCarnelianForceScroll2(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_CARNELIAN_FORCE_SCROLL_2; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error); 
	void unaffect(Creature* pCreature) throw(Error);

	virtual void create( const string& ownerID ) throw(Error);
	virtual void destroy( const string& ownerID ) throw(Error);
	virtual void save( const string& ownerID ) throw(Error);

	string toString() const throw();

private:
};

//////////////////////////////////////////////////////////////////////////////
// class EffectCarnelianForceScroll2Loader
//////////////////////////////////////////////////////////////////////////////

class EffectCarnelianForceScroll2Loader : public EffectLoader
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_CARNELIAN_FORCE_SCROLL_2; }
	virtual string getEffectClassName() const throw() { return "EffectCarnelianForceScroll2"; }

public:
	virtual void load( Creature* pCreature ) throw(Error);
};

extern EffectCarnelianForceScroll2Loader* g_pEffectCarnelianForceScroll2Loader;

#endif 

