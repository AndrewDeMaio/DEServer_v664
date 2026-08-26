#--------------------------------------------------------------------------------
#
# Filename    : Makefile
# Written By  : Reiot
#
#--------------------------------------------------------------------------------

#--------------------------------------------------------------------------------
# Directories
#--------------------------------------------------------------------------------
VSHOME  = ../../../..
STLDIR  = /usr/include/STL
BINDIR  = $(VSHOME)/bin
LIBDIR  = $(VSHOME)/lib
SRCDIR  = $(VSHOME)/src
COREDIR = $(VSHOME)/src/Core
SERVDIR = $(VSHOME)/src/server
DBDIR   = $(SERVDIR)/database
GSDIR   = $(SERVDIR)/gameserver
LSDIR   = $(SERVDIR)/loginserver
SSDIR   = $(SERVDIR)/sharedserver
SKILLDIR= $(GSDIR)/skill
ITEMDIR = $(GSDIR)/item
BILLINGDIR = $(GSDIR)/billing


#--------------------------------------------------------------------------------
# General Rules
#--------------------------------------------------------------------------------
.SUFFIXES : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__ -D__GAME_SERVER__ 
INCLUDES = -I$(COREDIR)/compat -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(SKILLDIR) -I$(ITEMDIR) -I$(BILLINGDIR)

CCFLAGS  = -Wall -c -g  -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c

TARGET_GS  = $(LIBDIR)/libGameServerPackets.a
TARGET_LS  = $(LIBDIR)/libLoginServerPackets.a
TARGET_SS  = $(LIBDIR)/libSharedServerPackets.a

TARGET = $(TARGET_GS)

include ../OBJS

.cpp.o : 
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<


#--------------------------------------------------------------------------------
# Actions
#--------------------------------------------------------------------------------

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar r $@ $(OBJS)

clean :
	rm -rf *.o

cleanall :
	rm -rf *.o

depall :
	gccmakedep	$(SRCS) $(INCLUDES) $(DEFS)

dep :
	gccmakedep	$(SRCS) $(INCLUDES) $(DEFS)


# DO NOT DELETE
LCCreatePCError.o: LCCreatePCError.cpp LCCreatePCError.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCCreatePCErrorHandler.o: LCCreatePCErrorHandler.cpp LCCreatePCError.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCCreatePCOK.o: LCCreatePCOK.cpp LCCreatePCOK.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCCreatePCOKHandler.o: LCCreatePCOKHandler.cpp LCCreatePCOK.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCDeletePCError.o: LCDeletePCError.cpp LCDeletePCError.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCDeletePCErrorHandler.o: LCDeletePCErrorHandler.cpp LCDeletePCError.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCDeletePCOK.o: LCDeletePCOK.cpp LCDeletePCOK.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCDeletePCOKHandler.o: LCDeletePCOKHandler.cpp LCDeletePCOK.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCLoginError.o: LCLoginError.cpp LCLoginError.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCLoginErrorHandler.o: LCLoginErrorHandler.cpp LCLoginError.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCLoginOK.o: LCLoginOK.cpp LCLoginOK.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCLoginOKHandler.o: LCLoginOKHandler.cpp LCLoginOK.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCPCList.o: LCPCList.cpp LCPCList.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/PCInfo.h ../../../../src/Core/PCSlayerInfo.h \
  ../../../../src/Core/PCInfo.h \
  \
  ../../../../src/Core/PCVampireInfo.h \
  ../../../../src/Core/PCOustersInfo.h
LCPCListHandler.o: LCPCListHandler.cpp LCPCList.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/PCInfo.h ../../../../src/Core/PCSlayerInfo.h \
  ../../../../src/Core/PCInfo.h \
  \
  ../../../../src/Core/PCVampireInfo.h \
  ../../../../src/Core/PCOustersInfo.h
LCQueryResultPlayerID.o: LCQueryResultPlayerID.cpp \
  LCQueryResultPlayerID.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCQueryResultPlayerIDHandler.o: LCQueryResultPlayerIDHandler.cpp \
  LCQueryResultPlayerID.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCQueryResultCharacterName.o: LCQueryResultCharacterName.cpp \
  LCQueryResultCharacterName.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCQueryResultCharacterNameHandler.o: \
  LCQueryResultCharacterNameHandler.cpp LCQueryResultCharacterName.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCReconnect.o: LCReconnect.cpp LCReconnect.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCReconnectHandler.o: LCReconnectHandler.cpp LCReconnect.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCRegisterPlayerError.o: LCRegisterPlayerError.cpp \
  LCRegisterPlayerError.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCRegisterPlayerErrorHandler.o: LCRegisterPlayerErrorHandler.cpp \
  LCRegisterPlayerError.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCRegisterPlayerOK.o: LCRegisterPlayerOK.cpp LCRegisterPlayerOK.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCRegisterPlayerOKHandler.o: LCRegisterPlayerOKHandler.cpp \
  LCRegisterPlayerOK.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCSelectPCError.o: LCSelectPCError.cpp LCSelectPCError.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCSelectPCErrorHandler.o: LCSelectPCErrorHandler.cpp LCSelectPCError.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCServerList.o: LCServerList.cpp LCServerList.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/ServerGroupInfo.h \
  ../../../../src/Core/PCSlayerInfo.h ../../../../src/Core/PCInfo.h \
  \
  ../../../../src/Core/PCVampireInfo.h
LCServerListHandler.o: LCServerListHandler.cpp LCServerList.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/ServerGroupInfo.h
LCWorldList.o: LCWorldList.cpp LCWorldList.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/WorldInfo.h ../../../../src/Core/PCSlayerInfo.h \
  ../../../../src/Core/PCInfo.h \
  \
  ../../../../src/Core/PCVampireInfo.h
LCWorldListHandler.o: LCWorldListHandler.cpp LCWorldList.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/WorldInfo.h
LCVersionCheckOK.o: LCVersionCheckOK.cpp LCVersionCheckOK.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCVersionCheckOKHandler.o: LCVersionCheckOKHandler.cpp LCVersionCheckOK.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCVersionCheckError.o: LCVersionCheckError.cpp LCVersionCheckError.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCVersionCheckErrorHandler.o: LCVersionCheckErrorHandler.cpp \
  LCVersionCheckError.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LGIncomingConnection.o: LGIncomingConnection.cpp LGIncomingConnection.h \
  ../../../../src/Core/DatagramPacket.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/Datagram.h \
  ../../../../src/Core/PacketFactory.h
LGIncomingConnectionHandler.o: LGIncomingConnectionHandler.cpp \
  LGIncomingConnection.h ../../../../src/Core/DatagramPacket.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/Datagram.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Properties.h \
  \
  \
  ../../../../src/server/gameserver/ConnectionInfo.h \
  ../../../../src/Core/Types.h ../../../../src/Core/Exception.h \
  ../../../../src/server/Timeval.h \
  \
  \
  ../../../../src/server/gameserver/ConnectionInfoManager.h \
  ../../../../src/server/Mutex.h ../../../../src/Core/Types.h \
  ../../../../src/Core/Exception.h \
  \
  \
  \
  \
  \
  \
  ../../../../src/server/gameserver/ConnectionInfo.h \
  ../../../../src/server/gameserver/LoginServerManager.h \
  ../../../../src/server/Thread.h ../../../../src/server/pthreadAPI.h \
  ../../../../src/Core/DatagramSocket.h \
  ../../../../src/server/gameserver/LogDef.h \
  ../../../../src/server/gameserver/VariableManager.h \
  \
  ../../../../src/Core/Gpackets/GLIncomingConnectionError.h \
  ../../../../src/Core/DatagramPacket.h \
  ../../../../src/Core/PacketFactory.h \
  ../../../../src/Core/Gpackets/GLIncomingConnectionOK.h
LGIncomingConnectionOK.o: LGIncomingConnectionOK.cpp \
  LGIncomingConnectionOK.h ../../../../src/Core/DatagramPacket.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/Datagram.h \
  ../../../../src/Core/PacketFactory.h
LGIncomingConnectionOKHandler.o: LGIncomingConnectionOKHandler.cpp \
  LGIncomingConnectionOK.h ../../../../src/Core/DatagramPacket.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/Datagram.h \
  ../../../../src/Core/PacketFactory.h \
  ../../../../src/server/gameserver/GamePlayer.h \
  ../../../../src/Core/Types.h ../../../../src/Core/Exception.h \
  ../../../../src/Core/Player.h \
  ../../../../src/Core/SocketEncryptOutputStream.h \
  ../../../../src/Core/Encrypter.h ../../../../src/Core/EncryptUtility.h \
  ../../../../src/Core/SocketEncryptInputStream.h \
  ../../../../src/server/Mutex.h ../../../../src/Core/Types.h \
  ../../../../src/Core/Exception.h \
  \
  ../../../../src/Core/Packet.h ../../../../src/server/Timeval.h \
  \
  \
  ../../../../src/Core/PlayerStatus.h \
  ../../../../src/server/gameserver/EventManager.h \
  ../../../../src/server/gameserver/Event.h \
  ../../../../src/server/gameserver/skill/Skill.h \
  ../../../../src/Core/Types.h ../../../../src/server/PaySystem.h \
  ../../../../src/server/Timeval.h ../../../../src/Core/VSDateTime.h \
  ../../../../src/server/gameserver/Item.h \
  ../../../../src/server/gameserver/Object.h \
  ../../../../src/Core/Assert.h \
  ../../../../src/server/gameserver/Effect.h \
  ../../../../src/server/gameserver/EffectManager.h \
  ../../../../src/Core/EffectInfo.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/server/gameserver/billing/BillingPlayerInfo.h \
  ../../../../src/Core/Types.h ../../../../src/Core/Exception.h \
  ../../../../src/server/Timeval.h \
  ../../../../src/server/chinabilling/CBillingPlayerInfo.h \
  ../../../../src/Core/Types.h ../../../../src/Core/Exception.h \
  ../../../../src/server/Timeval.h \
  ../../../../src/server/chinabilling/CBillingInfo.h \
  ../../../../src/Core/VSDateTime.h \
  ../../../../src/Core/Gpackets/GCReconnectLogin.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/PacketFactory.h \
  \
  \
  \
  \
  \
  ../../../../src/server/gameserver/IncomingPlayerManager.h \
  ../../../../src/server/PlayerManager.h ../../../../src/Core/SocketAPI.h \
  ../../../../src/server/Mutex.h \
  ../../../../src/server/gameserver/GamePlayer.h \
  ../../../../src/Core/ServerSocket.h \
  ../../../../src/Core/DatagramSocket.h \
  ../../../../src/server/gameserver/ConnectionInfoManager.h \
  ../../../../src/server/gameserver/ConnectionInfo.h \
  ../../../../src/Core/Assert.h \
  ../../../../src/server/database/Statement.h \
  ../../../../src/Core/Types.h ../../../../src/Core/Exception.h \
  ../../../../src/server/database/Connection.h \
  \
  \
  \
  ../../../../src/server/Mutex.h \
  ../../../../src/server/database/DatabaseManager.h \
  ../../../../src/server/gameserver/LogDef.h \
  ../../../../src/server/gameserver/VariableManager.h \
  ../../../../src/Core/Gpackets/GCReconnectLogin.h
LGIncomingConnectionError.o: LGIncomingConnectionError.cpp \
  LGIncomingConnectionError.h ../../../../src/Core/DatagramPacket.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/Datagram.h \
  ../../../../src/Core/PacketFactory.h
LGIncomingConnectionErrorHandler.o: LGIncomingConnectionErrorHandler.cpp \
  LGIncomingConnectionError.h ../../../../src/Core/DatagramPacket.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/Datagram.h \
  ../../../../src/Core/PacketFactory.h \
  ../../../../src/server/gameserver/GamePlayer.h \
  ../../../../src/Core/Types.h ../../../../src/Core/Exception.h \
  ../../../../src/Core/Player.h \
  ../../../../src/Core/SocketEncryptOutputStream.h \
  ../../../../src/Core/Encrypter.h ../../../../src/Core/EncryptUtility.h \
  ../../../../src/Core/SocketEncryptInputStream.h \
  ../../../../src/server/Mutex.h ../../../../src/Core/Types.h \
  ../../../../src/Core/Exception.h \
  \
  ../../../../src/Core/Packet.h ../../../../src/server/Timeval.h \
  \
  \
  ../../../../src/Core/PlayerStatus.h \
  ../../../../src/server/gameserver/EventManager.h \
  ../../../../src/server/gameserver/Event.h \
  ../../../../src/server/gameserver/skill/Skill.h \
  ../../../../src/Core/Types.h ../../../../src/server/PaySystem.h \
  ../../../../src/server/Timeval.h ../../../../src/Core/VSDateTime.h \
  ../../../../src/server/gameserver/Item.h \
  ../../../../src/server/gameserver/Object.h \
  ../../../../src/Core/Assert.h \
  ../../../../src/server/gameserver/Effect.h \
  ../../../../src/server/gameserver/EffectManager.h \
  ../../../../src/Core/EffectInfo.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/server/gameserver/billing/BillingPlayerInfo.h \
  ../../../../src/Core/Types.h ../../../../src/Core/Exception.h \
  ../../../../src/server/Timeval.h \
  ../../../../src/server/chinabilling/CBillingPlayerInfo.h \
  ../../../../src/Core/Types.h ../../../../src/Core/Exception.h \
  ../../../../src/server/Timeval.h \
  ../../../../src/server/chinabilling/CBillingInfo.h \
  ../../../../src/Core/VSDateTime.h \
  ../../../../src/Core/Gpackets/GCReconnectLogin.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/PacketFactory.h \
  \
  \
  \
  \
  \
  ../../../../src/server/gameserver/IncomingPlayerManager.h \
  ../../../../src/server/PlayerManager.h ../../../../src/Core/SocketAPI.h \
  ../../../../src/server/Mutex.h \
  ../../../../src/server/gameserver/GamePlayer.h \
  ../../../../src/Core/ServerSocket.h \
  ../../../../src/Core/DatagramSocket.h \
  ../../../../src/server/gameserver/ConnectionInfoManager.h \
  ../../../../src/server/gameserver/ConnectionInfo.h \
  ../../../../src/Core/Assert.h \
  ../../../../src/server/gameserver/LogDef.h \
  ../../../../src/server/gameserver/VariableManager.h
LGKickCharacter.o: LGKickCharacter.cpp LGKickCharacter.h \
  ../../../../src/Core/DatagramPacket.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/Datagram.h \
  ../../../../src/Core/PacketFactory.h
LGKickCharacterHandler.o: LGKickCharacterHandler.cpp LGKickCharacter.h \
  ../../../../src/Core/DatagramPacket.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/Datagram.h \
  ../../../../src/Core/PacketFactory.h \
  ../../../../src/server/gameserver/GamePlayer.h \
  ../../../../src/Core/Types.h ../../../../src/Core/Exception.h \
  ../../../../src/Core/Player.h \
  ../../../../src/Core/SocketEncryptOutputStream.h \
  ../../../../src/Core/Encrypter.h ../../../../src/Core/EncryptUtility.h \
  ../../../../src/Core/SocketEncryptInputStream.h \
  ../../../../src/server/Mutex.h ../../../../src/Core/Types.h \
  ../../../../src/Core/Exception.h \
  \
  ../../../../src/Core/Packet.h ../../../../src/server/Timeval.h \
  \
  \
  ../../../../src/Core/PlayerStatus.h \
  ../../../../src/server/gameserver/EventManager.h \
  ../../../../src/server/gameserver/Event.h \
  ../../../../src/server/gameserver/skill/Skill.h \
  ../../../../src/Core/Types.h ../../../../src/server/PaySystem.h \
  ../../../../src/server/Timeval.h ../../../../src/Core/VSDateTime.h \
  ../../../../src/server/gameserver/Item.h \
  ../../../../src/server/gameserver/Object.h \
  ../../../../src/Core/Assert.h \
  ../../../../src/server/gameserver/Effect.h \
  ../../../../src/server/gameserver/EffectManager.h \
  ../../../../src/Core/EffectInfo.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/server/gameserver/billing/BillingPlayerInfo.h \
  ../../../../src/Core/Types.h ../../../../src/Core/Exception.h \
  ../../../../src/server/Timeval.h \
  ../../../../src/server/chinabilling/CBillingPlayerInfo.h \
  ../../../../src/Core/Types.h ../../../../src/Core/Exception.h \
  ../../../../src/server/Timeval.h \
  ../../../../src/server/chinabilling/CBillingInfo.h \
  ../../../../src/Core/VSDateTime.h \
  ../../../../src/Core/Gpackets/GCReconnectLogin.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/PacketFactory.h \
  \
  \
  \
  \
  \
  ../../../../src/server/gameserver/LoginServerManager.h \
  ../../../../src/server/Thread.h ../../../../src/server/pthreadAPI.h \
  ../../../../src/Core/DatagramSocket.h \
  ../../../../src/server/gameserver/Creature.h \
  ../../../../src/server/gameserver/PCFinder.h \
  ../../../../src/server/gameserver/Creature.h \
  ../../../../src/server/gameserver/NPC.h \
  ../../../../src/server/gameserver/Zone.h \
  ../../../../src/server/gameserver/Tile.h \
  ../../../../src/server/gameserver/Obstacle.h \
  ../../../../src/server/gameserver/Portal.h \
  ../../../../src/server/gameserver/quest/TriggerManager.h \
  ../../../../src/Core/Types.h ../../../../src/Core/Exception.h \
  ../../../../src/server/gameserver/quest/Trigger.h \
  ../../../../src/server/gameserver/quest/Condition.h \
  ../../../../src/server/gameserver/quest/PropertyBuffer.h \
  ../../../../src/server/gameserver/Sector.h \
  ../../../../src/server/gameserver/ObjectRegistry.h \
  ../../../../src/server/gameserver/Party.h \
  ../../../../src/Core/ModifyInfo.h \
  ../../../../src/server/gameserver/PCManager.h \
  ../../../../src/server/gameserver/CreatureManager.h \
  ../../../../src/Core/Encrypter.h \
  \
  \
  \
  ../../../../src/server/gameserver/Inventory.h \
  ../../../../src/server/gameserver/VolumeInfo.h \
  ../../../../src/server/gameserver/InventorySlot.h \
  ../../../../src/server/gameserver/couple/PartnerWaitingManager.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/Types.h \
  ../../../../src/server/Timeval.h \
  ../../../../src/server/gameserver/PlayerCreature.h \
  ../../../../src/server/gameserver/Garbage.h \
  ../../../../src/server/gameserver/RankBonus.h \
  ../../../../src/server/gameserver/ExpFwd.h \
  ../../../../src/Core/Gpackets/GCMonsterKillQuestInfo.h \
  ../../../../src/Core/Gpackets/GCSelectQuestID.h \
  ../../../../src/server/gameserver/OptionInfo.h \
  ../../../../src/Core/VSDateTime.h ../../../../src/Core/GearInfo.h \
  ../../../../src/Core/GearSlotInfo.h ../../../../src/Core/PCItemInfo.h \
  ../../../../src/Core/SubItemInfo.h ../../../../src/Core/Assert.h \
  \
  \
  ../../../../src/server/gameserver/LogDef.h \
  ../../../../src/server/gameserver/VariableManager.h \
  ../../../../src/Core/Gpackets/GLKickVerify.h \
  ../../../../src/Core/DatagramPacket.h
LCShowWebPage.o: LCShowWebPage.cpp LCShowWebPage.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCShowWebPageHandler.o: LCShowWebPageHandler.cpp LCShowWebPage.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCSelectWorldError.o: LCSelectWorldError.cpp LCSelectWorldError.h \
  ../../../../src/Core/Packet.h ../../../../src/Core/Types.h \
  ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
LCSelectWorldErrorHandler.o: LCSelectWorldErrorHandler.cpp \
  LCSelectWorldError.h ../../../../src/Core/Packet.h \
  ../../../../src/Core/Types.h ../../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../src/Core/types/PlayerTypes.h \
  ../../../../src/Core/types/SystemTypes.h \
  ../../../../src/Core/types/ObjectTypes.h \
  ../../../../src/Core/types/CreatureTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/ZoneTypes.h \
  ../../../../src/Core/types/QuestTypes.h \
  ../../../../src/Core/types/ShopTypes.h \
  ../../../../src/Core/types/ItemTypes.h \
  ../../../../src/Core/types/GuildTypes.h \
  ../../../../src/Core/types/WarTypes.h \
  ../../../../src/Core/types/ServerType.h \
  ../../../../src/Core/types/VersionType.h ../../../../src/Core/Utility.h \
  ../../../../src/Core/Exception.h ../../../../src/Core/StringStream.h \
  \
  \
  \
  ../../../../src/Core/SocketInputStream.h ../../../../src/Core/Socket.h \
  ../../../../src/Core/SocketImpl.h ../../../../src/Core/SocketAPI.h \
  \
  \
  \
  \
  \
  ../../../../src/Core/SocketOutputStream.h \
  ../../../../src/Core/PacketFactory.h ../../../../src/Core/Packet.h
