//////////////////////////////////////////////////////////////////////////////
// Filename    : CGAddMouseToGear.h 
// Written By  : reiot@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __CG_ADD_MOUSE_TO_GEAR_H__
#define __CG_ADD_MOUSE_TO_GEAR_H__

#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class CGAddMouseToGear;
//////////////////////////////////////////////////////////////////////////////

class CGAddMouseToGear : public Packet 
{
public:
	CGAddMouseToGear() throw();
	~CGAddMouseToGear() throw();

public:
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);
	void execute(Player* pPlayer) throw(ProtocolException, Error);
	PacketID_t getPacketID() const throw() { return PACKET_CG_ADD_MOUSE_TO_GEAR; }
	PacketSize_t getPacketSize() const throw() { return szObjectID + szSlotID; } /* m_GearSlotID is NOT on the wire: the client guards it with __CONTENTS(__GEAR_SWAP_CHANGE), which is __OFF for this build, so it sends only these two fields (5 bytes). Counting it here made the server read 7 and swallow 2 bytes of the next packet. */
	string getPacketName() const throw() { return "CGAddMouseToGear"; }
	string toString() const throw();
	
public:
	GearSlotID_t getGearSlotID() throw() { return m_GearSlotID; }
	void setGearSlotID(GearSlotID_t GearSlotID) throw() { m_GearSlotID = GearSlotID; }

	ObjectID_t getObjectID() throw() { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID) throw() { m_ObjectID = ObjectID; }

	SlotID_t getSlotID() const throw() { return m_SlotID; }
	void setSlotID(SlotID_t SlotID) throw() { m_SlotID = SlotID; }

private:
	GearSlotID_t m_GearSlotID;
	ObjectID_t m_ObjectID;
	SlotID_t   m_SlotID;

};

//////////////////////////////////////////////////////////////////////////////
// class CGAddMouseToGearFactory;
//////////////////////////////////////////////////////////////////////////////

class CGAddMouseToGearFactory : public PacketFactory 
{
public:
	Packet* createPacket() throw() { return new CGAddMouseToGear(); }
	string getPacketName() const throw() { return "CGAddMouseToGear"; }
	PacketID_t getPacketID() const throw() { return Packet::PACKET_CG_ADD_MOUSE_TO_GEAR; }
	PacketSize_t getPacketMaxSize() const throw() { return szObjectID + szSlotID; } /* m_GearSlotID is NOT on the wire: the client guards it with __CONTENTS(__GEAR_SWAP_CHANGE), which is __OFF for this build, so it sends only these two fields (5 bytes). Counting it here made the server read 7 and swallow 2 bytes of the next packet. */
};

//////////////////////////////////////////////////////////////////////////////
// class CGAddMouseToGearHandler;
//////////////////////////////////////////////////////////////////////////////

class CGAddMouseToGearHandler 
{
public:
	static void execute(CGAddMouseToGear* pPacket, Player* player) throw(ProtocolException, Error);
};

#endif
