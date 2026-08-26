//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectChannelMicroPhone.h
// Written by  : ksym555
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_CHANNEL_MICROPHONE__
#define __EFFECT_CHANNEL_MICROPHONE__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectChannelMicroPhone
//////////////////////////////////////////////////////////////////////////////

class EffectChannelMicroPhone : public Effect
{
public:
	EffectChannelMicroPhone(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_CHANNEL_MICROPHONE; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error); 
	void unaffect(Creature* pCreature) throw(Error);

	virtual void create( const string& ownerID ) throw(Error);
	virtual void destroy( const string& ownerID ) throw(Error);
	virtual void save( const string& ownerID ) throw(Error);
	
	void SetBonusRate(float fRate) { m_fBonusRate = fRate; }
	float GetBonusRate() { return m_fBonusRate; }

	bool isPossibleAffect () throw(Error); 
	string toString() const throw();

protected :
	float m_fBonusRate;
};

//////////////////////////////////////////////////////////////////////////////
// class EffectChannelMicroPhoneLoader
//////////////////////////////////////////////////////////////////////////////

class EffectChannelMicroPhoneLoader : public EffectLoader
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_CHANNEL_MICROPHONE; }
	virtual string getEffectClassName() const throw() { return "EffectChannelMicroPhone"; }

public:
	virtual void load( Creature* pCreature ) throw(Error);
};

extern EffectChannelMicroPhoneLoader* g_pEffectChannelMicroPhoneLoader;

#endif 
