#----------------------------------------------------------------------
#
# Filename    : Makefile
# Written By  : Reiot
#
#----------------------------------------------------------------------

#----------------------------------------------------------------------
# Directories Setting
#----------------------------------------------------------------------
VSHOME   = ../../..
STLDIR   = /usr/include/STL
BINDIR   = $(VSHOME)/bin
LIBDIR   = $(VSHOME)/lib
LOGDIR   = $(VSHOME)/log
SRCDIR   = ../..
COREDIR  = ../../Core
SERVDIR  = ..
DBDIR    = ../database


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__UPDATE_SERVER__ -D__DEBUG__
INCLUDES = -I$(COREDIR)/compat -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I.
CCFLAGS  = -Wall -c -g  -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c
LIBS     = -L$(LIBDIR) -lUpdateServerPackets -lServerCore -lCore -lstlport
SYSLIBS  = -lpthread -lnsl

.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<


#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------
OBJS   = main.o UpdateServer.o UpdateServerPlayer.o
SRCS   = $(OBJS:.o=.cpp)
TARGET = $(BINDIR)/updateserver
UPDATE = $(BINDIR)/update

#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
all : $(TARGET) $(UPDATE)

$(TARGET) : $(OBJS) $(LIBDIR)/libUpdateServerPackets.a $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a
	$(CC) -o $@ $(OBJS) $(LIBS) $(SYSLIBS)

$(UPDATE) : update.o $(LIBDIR)/libCore.a
	$(CC) -o $@ update.o -L$(LIBDIR) -lCore -lstlport

clean :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGET) $(UPDATE)

depall :
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)

# DO NOT DELETE
main.o: main.cpp ../../Core/Types.h ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/types/VersionType.h ../../Core/Utility.h ../../Core/Types.h \
  ../../Core/Exception.h ../../Core/StringStream.h \
  \
  \
  UpdateServer.h ../../Core/Properties.h ../../Core/Exception.h \
  \
  \
  ../../Core/ServerSocket.h ../../Core/SocketImpl.h \
  ../../Core/SocketAPI.h ../../Core/Socket.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../Core/UpdateManager.h ../../Core/Update.h ../../Core/UpdateDef.h \
  ../../Core/Assert.h ../../Core/SocketInputStream.h \
  ../../Core/SocketOutputStream.h ../../Core/Resource.h \
  ../../Core/ResourceManager.h ../../Core/Update.h \
  ../../Core/StringStream.h
UpdateServer.o: UpdateServer.cpp \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  UpdateServer.h \
  ../../Core/Types.h ../../Core/types/SystemTypes.h \
  \
  \
  ../../Core/types/PlayerTypes.h \
  ../../Core/types/SystemTypes.h ../../Core/types/ObjectTypes.h \
  ../../Core/types/CreatureTypes.h ../../Core/types/ItemTypes.h \
  ../../Core/types/ZoneTypes.h ../../Core/types/QuestTypes.h \
  ../../Core/types/ShopTypes.h ../../Core/types/ItemTypes.h \
  ../../Core/types/GuildTypes.h ../../Core/types/WarTypes.h \
  ../../Core/types/ServerType.h ../../Core/types/VersionType.h \
  ../../Core/Utility.h ../../Core/Types.h ../../Core/Exception.h \
  ../../Core/StringStream.h \
  \
  ../../Core/Properties.h ../../Core/Exception.h \
  \
  ../../Core/ServerSocket.h \
  ../../Core/SocketImpl.h ../../Core/SocketAPI.h ../../Core/Socket.h \
  ../../Core/Assert.h ../SystemAPI.h ../../Core/Types.h \
  ../../Core/Exception.h UpdateServerPlayer.h ../../Core/Player.h \
  ../../Core/PlayerStatus.h \
  \
  ../../Core/Packet.h ../../Core/SocketInputStream.h \
  ../../Core/SocketOutputStream.h ../Timeval.h \

UpdateServerPlayer.o: UpdateServerPlayer.cpp UpdateServerPlayer.h \
  ../../Core/Player.h ../../Core/Types.h ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../Core/types/PlayerTypes.h ../../Core/types/SystemTypes.h \
  ../../Core/types/ObjectTypes.h ../../Core/types/CreatureTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/ZoneTypes.h \
  ../../Core/types/QuestTypes.h ../../Core/types/ShopTypes.h \
  ../../Core/types/ItemTypes.h ../../Core/types/GuildTypes.h \
  ../../Core/types/WarTypes.h ../../Core/types/ServerType.h \
  ../../Core/types/VersionType.h ../../Core/Utility.h \
  ../../Core/Exception.h ../../Core/StringStream.h \
  \
  \
  ../../Core/PlayerStatus.h \
  \
  ../../Core/Packet.h ../../Core/SocketInputStream.h ../../Core/Socket.h \
  ../../Core/SocketImpl.h ../../Core/SocketAPI.h \
  ../../Core/SocketOutputStream.h ../Timeval.h \
  \
  \
  \
  ../../Core/Assert.h \
  ../../Core/Upackets/CUBeginUpdate.h ../../Core/Packet.h \
  ../../Core/PacketFactory.h ../../Core/Packet.h \
  ../../Core/UpdateManager.h ../../Core/Update.h ../../Core/UpdateDef.h \
  ../../Core/Assert.h ../../Core/Resource.h ../../Core/ResourceManager.h \
  ../../Core/Upackets/CURequest.h ../../Core/Resource.h \
  ../../Core/Upackets/CUEndUpdate.h \
  ../../Core/Upackets/CURequestLoginMode.h
