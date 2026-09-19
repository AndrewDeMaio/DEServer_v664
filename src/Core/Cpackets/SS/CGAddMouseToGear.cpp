//////////////////////////////////////////////////////////////////////////////
// Filename    : CGAddMouseToGear.cpp 
// Written By  : elca@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "CGAddMouseToGear.h"

CGAddMouseToGear::CGAddMouseToGear () 
     throw ()
: m_GearSlotID(0), m_ObjectID(0), m_SlotID(0)
{
	__BEGIN_TRY
	__END_CATCH
}

CGAddMouseToGear::~CGAddMouseToGear () 
    throw ()
{
	__BEGIN_TRY
	__END_CATCH
}

void CGAddMouseToGear::read (SocketInputStream & iStream) 
	 throw (ProtocolException , Error)
{
	__BEGIN_TRY
		
	// The client writes the gear set first under __CONTENTS(__GEAR_SWAP_CHANGE),
	// __ON again for the gear swap UI (2026-09-17). The handler compares this
	// with the creature's current gear set, so equipping into set II needs it.
	iStream.read(m_GearSlotID);
	iStream.read(m_ObjectID);
	iStream.read(m_SlotID);

	__END_CATCH
}

void CGAddMouseToGear::write (SocketOutputStream & oStream) const 
     throw (ProtocolException , Error)
{
	__BEGIN_TRY

	// see read() -- the gear set goes first
	oStream.write(m_GearSlotID);
	oStream.write(m_ObjectID);
	oStream.write(m_SlotID);

	__END_CATCH
}

void CGAddMouseToGear::execute (Player* pPlayer) 
	 throw (ProtocolException , Error)
{
	__BEGIN_TRY

	CGAddMouseToGearHandler::execute (this , pPlayer);
		
	__END_CATCH
}

string CGAddMouseToGear::toString () 
	const throw ()
{
	__BEGIN_TRY
		
	StringStream msg;
	msg << "CGAddMouseToGear("
		<< "GearSlotID : " << (int)m_GearSlotID 
		<< "ObjectID : " << (int)m_ObjectID 
		<< ",SlotID" << (int)m_SlotID
		<< ")";
	return msg.toString();

	__END_CATCH
}
