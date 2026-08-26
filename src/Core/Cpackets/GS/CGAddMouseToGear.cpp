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
		
	// m_GearSlotID is deliberately not on the wire. The client compiles it out
	// of both write() and getPacketSize() under __CONTENTS(__GEAR_SWAP_CHANGE),
	// which is __OFF for this build, so it sends ObjectID + SlotID only.
	// Reading it here over-ran the packet by 2 bytes, desynced the input stream,
	// and got the player logged out on every equip. The constructor leaves it 0,
	// which matches PlayerCreature::m_CurrentGearSlotID's default.
	iStream.read(m_ObjectID);
	iStream.read(m_SlotID);

	__END_CATCH
}

void CGAddMouseToGear::write (SocketOutputStream & oStream) const 
     throw (ProtocolException , Error)
{
	__BEGIN_TRY

	// see read() -- m_GearSlotID is not on the wire for this build.
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
