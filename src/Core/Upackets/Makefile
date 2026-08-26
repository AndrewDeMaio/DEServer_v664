#--------------------------------------------------------------------------------
#
# Filename    : Makefile
# Written By  : Reiot
#
#--------------------------------------------------------------------------------

#--------------------------------------------------------------------------------
# Directories
#--------------------------------------------------------------------------------
VSHOME  = ../../..
STLDIR  = /usr/include/STL
BINDIR  = $(VSHOME)/bin
LIBDIR  = $(VSHOME)/lib
SRCDIR  = $(VSHOME)/src
COREDIR = ..
SERVDIR = ../../server
USDIR   = $(SERVDIR)/updateserver
CLIDIR  = ../../client
UCDIR   = $(CLIDIR)/updateclient


#--------------------------------------------------------------------------------
# General Rules
#--------------------------------------------------------------------------------
.SUFFIXES : .cpp .us.o .uc.o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__
INCLUDES = -I$(COREDIR)/compat -I$(STLDIR) -I$(COREDIR)
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c

TARGET1 = $(LIBDIR)/libUpdateServerPackets.a
TARGET2 = $(LIBDIR)/libUpdateClientPackets.a

OBJS1	= \
		CUBeginUpdate.us.o CUBeginUpdateHandler.us.o \
		CURequest.us.o CURequestHandler.us.o \
		CUEndUpdate.us.o CUEndUpdateHandler.us.o \
		CURequestLoginMode.us.o CURequestLoginModeHandler.us.o \
		UCUpdate.us.o UCUpdateHandler.us.o \
		UCUpdateList.us.o UCUpdateListHandler.us.o \
		UCRequestLoginMode.us.o UCRequestLoginModeHandler.us.o

OBJS2	= \
		CUBeginUpdate.uc.o CUBeginUpdateHandler.uc.o \
		CURequest.uc.o CURequestHandler.uc.o \
		CUEndUpdate.uc.o CUEndUpdateHandler.uc.o \
		CURequestLoginMode.uc.o CURequestLoginModeHandler.uc.o \
		UCUpdate.uc.o UCUpdateHandler.uc.o \
		UCUpdateList.uc.o UCUpdateListHandler.uc.o \
		UCRequestLoginMode.uc.o UCRequestLoginModeHandler.uc.o

SRCS	= $(OBJS1:.us.o=.cpp)

.cpp.us.o : 
	$(CC) $(CCFLAGS) $(DEFS) -D__UPDATE_SERVER__ $(INCLUDES) -I$(USDIR) -I$(SERVDIR) -o $*.us.o $<

.cpp.uc.o : 
	$(CC) $(CCFLAGS) $(DEFS) -D__UPDATE_CLIENT__ $(INCLUDES) -I$(UCDIR) -o $*.uc.o $<



#--------------------------------------------------------------------------------
# Actions
#--------------------------------------------------------------------------------

all : $(TARGET1) $(TARGET2)
#all : $(TARGET1)

allloginserver : $(TARGET1) $(TARGET2)

allgameserver : $(TARGET1) $(TARGET2)

$(TARGET1) : $(OBJS1)
	ar rc $@ $(OBJS1)

$(TARGET2) : $(OBJS2)
	ar rc $@ $(OBJS2)

clean :
	rm -rf *.o

cleanloginserver :
	rm -rf *.o

cleangameserver :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGET1) $(TARGET2)

depall :
	gccmakedep  $(SRCS) $(INCLUDES) $(DEFS)

dep :
	gccmakedep  $(SRCS) $(INCLUDES) $(DEFS)

# DO NOT DELETE
CUBeginUpdate.o: CUBeginUpdate.cpp CUBeginUpdate.h ../Packet.h ../Types.h \
  ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h ../UpdateManager.h ../Update.h ../UpdateDef.h ../Assert.h \
  ../Resource.h ../ResourceManager.h ../Properties.h \
  \

CUBeginUpdateHandler.o: CUBeginUpdateHandler.cpp CUBeginUpdate.h \
  ../Packet.h ../Types.h ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h ../UpdateManager.h ../Update.h ../UpdateDef.h ../Assert.h \
  ../Resource.h ../ResourceManager.h
CURequest.o: CURequest.cpp CURequest.h ../Packet.h ../Types.h \
  ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h ../Resource.h ../UpdateDef.h
CURequestHandler.o: CURequestHandler.cpp CURequest.h ../Packet.h \
  ../Types.h ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h ../Resource.h ../UpdateDef.h
CUEndUpdate.o: CUEndUpdate.cpp CUEndUpdate.h ../Packet.h ../Types.h \
  ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h
CUEndUpdateHandler.o: CUEndUpdateHandler.cpp CUEndUpdate.h ../Packet.h \
  ../Types.h ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h
CURequestLoginMode.o: CURequestLoginMode.cpp CURequestLoginMode.h \
  ../Packet.h ../Types.h ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h
CURequestLoginModeHandler.o: CURequestLoginModeHandler.cpp \
  CURequestLoginMode.h ../Packet.h ../Types.h ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h
UCUpdate.o: UCUpdate.cpp UCUpdate.h ../Packet.h ../Types.h \
  ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h ../Resource.h ../UpdateDef.h
UCUpdateHandler.o: UCUpdateHandler.cpp UCUpdate.h ../Packet.h ../Types.h \
  ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h ../Resource.h ../UpdateDef.h
UCUpdateList.o: UCUpdateList.cpp UCUpdateList.h ../Packet.h ../Types.h \
  ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h ../UpdateManager.h ../Update.h ../UpdateDef.h ../Assert.h \
  ../Resource.h ../ResourceManager.h
UCUpdateListHandler.o: UCUpdateListHandler.cpp UCUpdateList.h ../Packet.h \
  ../Types.h ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h ../UpdateManager.h ../Update.h ../UpdateDef.h ../Assert.h \
  ../Resource.h ../ResourceManager.h
UCRequestLoginMode.o: UCRequestLoginMode.cpp UCRequestLoginMode.h \
  ../Packet.h ../Types.h ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h
UCRequestLoginModeHandler.o: UCRequestLoginModeHandler.cpp \
  UCRequestLoginMode.h ../Packet.h ../Types.h ../types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../types/PlayerTypes.h ../types/SystemTypes.h ../types/ObjectTypes.h \
  ../types/CreatureTypes.h ../types/ItemTypes.h ../types/ZoneTypes.h \
  ../types/QuestTypes.h ../types/ShopTypes.h ../types/ItemTypes.h \
  ../types/GuildTypes.h ../types/WarTypes.h ../types/ServerType.h \
  ../types/VersionType.h ../Utility.h ../Exception.h ../StringStream.h \
  \
  \
  ../SocketInputStream.h ../Socket.h \
  ../SocketImpl.h ../SocketAPI.h \
  \
  \
  \
  \
  ../SocketOutputStream.h ../PacketFactory.h \
  ../Packet.h
