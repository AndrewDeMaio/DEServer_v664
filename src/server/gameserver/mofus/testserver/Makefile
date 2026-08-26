#----------------------------------------------------------------------
#
# Filename    : Makefile
# Written By  : Reiot
# Description :
#
#----------------------------------------------------------------------

#----------------------------------------------------------------------
# Directories Setting
#----------------------------------------------------------------------
#VSHOME  = ../../..
STLDIR  = /usr/include/STL
BINDIR  = $(VSHOME)/bin
LIBDIR  = $(VSHOME)/lib
LOGDIR  = $(VSHOME)/log
DBINCDIR = /usr/include/mysql
SRCDIR  = ../../../..
COREDIR = ../../../../Core
SERVDIR = ../../..
DBDIR   = ../../../database
MYSQLDIR = /usr/lib/x86_64-linux-gnu

#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__
INCLUDES = -I$(COREDIR)/compat -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I. -I../
CCFLAGS  = -Wall -c -g  -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c
LIBS     = -L$(LIBDIR) -lServerCore -lCore -lMofus
SYSLIBS  = -L$(MYSQLDIR) -static -lpthread -lnsl -lz

.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<


#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------
OBJS = \
	main.o GameServerManager.o GameServerPlayer.o MPacketManager.o \
	PKTConnectAskHandler.o PKTLogoutHandler.o PKTReceiveOKHandler.o \
	PKTResultHandler.o PKTUserInfoHandler.o

SRCS = $(OBJS:.o=.cpp)

TARGET = $(BINDIR)/mofusserver


#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
$(TARGET) : $(OBJS) $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a $(LIBDIR)/libMofus.a
	$(CC) -o $@ $(OBJS) $(LIBS) $(SYSLIBS)

clean :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGET)

depall :
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)

# DO NOT DELETE
main.o: main.cpp \
  \
  \
  \
  \
  \
  \
  \
  \
  GameServerManager.h ../../../Thread.h ../../../../Core/Types.h \
  ../../../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../Core/types/PlayerTypes.h \
  ../../../../Core/types/ObjectTypes.h \
  ../../../../Core/types/CreatureTypes.h \
  ../../../../Core/types/ItemTypes.h ../../../../Core/types/ZoneTypes.h \
  ../../../../Core/types/QuestTypes.h \
  ../../../../Core/types/ShopTypes.h \
  ../../../../Core/types/GuildTypes.h ../../../../Core/types/WarTypes.h \
  ../../../../Core/types/ServerType.h ../../../../Core/Utility.h \
  ../../../../Core/Exception.h ../../../../Core/StringStream.h \
  \
  ../../../pthreadAPI.h \
  \
  ../../../Timeval.h \
  \
  \
  GameServerPlayer.h ../../../../Core/Player.h \
  ../../../../Core/ServerSocket.h ../../../../Core/SocketImpl.h \
  ../../../../Core/SocketAPI.h ../../../../Core/Socket.h \
  ../../../Mutex.h ../../../../Core/Properties.h \
  \

GameServerManager.o: GameServerManager.cpp \
  \
  \
  \
  \
  \
  \
  \
  \
  GameServerManager.h ../../../Thread.h \
  ../../../../Core/Types.h ../../../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../Core/types/PlayerTypes.h \
  ../../../../Core/types/ObjectTypes.h \
  ../../../../Core/types/CreatureTypes.h \
  ../../../../Core/types/ItemTypes.h ../../../../Core/types/ZoneTypes.h \
  ../../../../Core/types/QuestTypes.h \
  ../../../../Core/types/ShopTypes.h \
  ../../../../Core/types/GuildTypes.h ../../../../Core/types/WarTypes.h \
  ../../../../Core/types/ServerType.h ../../../../Core/Utility.h \
  ../../../../Core/Exception.h ../../../../Core/StringStream.h \
  \
  ../../../pthreadAPI.h \
  \
  ../../../Timeval.h \
  \
  \
  GameServerPlayer.h ../../../../Core/Player.h \
  ../../../../Core/ServerSocket.h ../../../../Core/SocketImpl.h \
  ../../../../Core/SocketAPI.h ../../../../Core/Socket.h \
  ../../../Mutex.h ../../../../Core/Assert.h \
  ../../../../Core/Properties.h \
  \
  ../../../../Core/Packet.h \
  ../../../../Core/SocketInputStream.h \
  ../../../../Core/SocketOutputStream.h
GameServerPlayer.o: GameServerPlayer.cpp GameServerPlayer.h \
  ../../../../Core/Types.h ../../../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../Core/types/PlayerTypes.h \
  ../../../../Core/types/ObjectTypes.h \
  ../../../../Core/types/CreatureTypes.h \
  ../../../../Core/types/ItemTypes.h ../../../../Core/types/ZoneTypes.h \
  ../../../../Core/types/QuestTypes.h \
  ../../../../Core/types/ShopTypes.h \
  ../../../../Core/types/GuildTypes.h ../../../../Core/types/WarTypes.h \
  ../../../../Core/types/ServerType.h ../../../../Core/Utility.h \
  ../../../../Core/Exception.h ../../../../Core/StringStream.h \
  \
  ../../../../Core/Player.h ../../../../Core/Socket.h \
  ../../../../Core/SocketImpl.h ../../../../Core/SocketAPI.h \
  ../../../../Core/SocketInputStream.h \
  ../../../../Core/SocketOutputStream.h ../../../../Core/Assert.h \
  ../PKTConnectAsk.h ../MPacket.h ../PKTLogout.h ../PKTUserInfo.h \
  ../PKTReceiveOK.h ../PKTResult.h ../PKTConnectAccept.h \
  ../PKTPowerPoint.h ../PKTError.h
MPacketManager.o: MPacketManager.cpp ../Mofus.h MPacketManager.h \
  ../MPacket.h ../../../../Core/Types.h \
  ../../../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../Core/types/PlayerTypes.h \
  ../../../../Core/types/ObjectTypes.h \
  ../../../../Core/types/CreatureTypes.h \
  ../../../../Core/types/ItemTypes.h ../../../../Core/types/ZoneTypes.h \
  ../../../../Core/types/QuestTypes.h \
  ../../../../Core/types/ShopTypes.h \
  ../../../../Core/types/GuildTypes.h ../../../../Core/types/WarTypes.h \
  ../../../../Core/types/ServerType.h ../../../../Core/Utility.h \
  ../../../../Core/Exception.h ../../../../Core/StringStream.h \
  \
  ../../../../Core/SocketInputStream.h ../../../../Core/Socket.h \
  ../../../../Core/SocketImpl.h ../../../../Core/SocketAPI.h \
  ../../../../Core/SocketOutputStream.h ../MPacketID.h MPacketHandler.h \
  ../../../../Core/Assert.h ../PKTConnectAsk.h PKTConnectAskHandler.h \
  ../PKTLogout.h PKTLogoutHandler.h ../PKTUserInfo.h \
  PKTUserInfoHandler.h ../PKTReceiveOK.h PKTReceiveOKHandler.h \
  ../PKTResult.h PKTResultHandler.h ../PKTConnectAccept.h \
  ../PKTPowerPoint.h ../PKTError.h
PKTConnectAskHandler.o: PKTConnectAskHandler.cpp ../Mofus.h \
  PKTConnectAskHandler.h MPacketHandler.h ../MPacket.h \
  ../../../../Core/Types.h ../../../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../Core/types/PlayerTypes.h \
  ../../../../Core/types/ObjectTypes.h \
  ../../../../Core/types/CreatureTypes.h \
  ../../../../Core/types/ItemTypes.h ../../../../Core/types/ZoneTypes.h \
  ../../../../Core/types/QuestTypes.h \
  ../../../../Core/types/ShopTypes.h \
  ../../../../Core/types/GuildTypes.h ../../../../Core/types/WarTypes.h \
  ../../../../Core/types/ServerType.h ../../../../Core/Utility.h \
  ../../../../Core/Exception.h ../../../../Core/StringStream.h \
  \
  ../../../../Core/SocketInputStream.h ../../../../Core/Socket.h \
  ../../../../Core/SocketImpl.h ../../../../Core/SocketAPI.h \
  ../../../../Core/SocketOutputStream.h
PKTLogoutHandler.o: PKTLogoutHandler.cpp ../Mofus.h PKTLogoutHandler.h \
  MPacketHandler.h ../MPacket.h ../../../../Core/Types.h \
  ../../../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../Core/types/PlayerTypes.h \
  ../../../../Core/types/ObjectTypes.h \
  ../../../../Core/types/CreatureTypes.h \
  ../../../../Core/types/ItemTypes.h ../../../../Core/types/ZoneTypes.h \
  ../../../../Core/types/QuestTypes.h \
  ../../../../Core/types/ShopTypes.h \
  ../../../../Core/types/GuildTypes.h ../../../../Core/types/WarTypes.h \
  ../../../../Core/types/ServerType.h ../../../../Core/Utility.h \
  ../../../../Core/Exception.h ../../../../Core/StringStream.h \
  \
  ../../../../Core/SocketInputStream.h ../../../../Core/Socket.h \
  ../../../../Core/SocketImpl.h ../../../../Core/SocketAPI.h \
  ../../../../Core/SocketOutputStream.h
PKTReceiveOKHandler.o: PKTReceiveOKHandler.cpp ../Mofus.h \
  PKTReceiveOKHandler.h MPacketHandler.h ../MPacket.h \
  ../../../../Core/Types.h ../../../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../Core/types/PlayerTypes.h \
  ../../../../Core/types/ObjectTypes.h \
  ../../../../Core/types/CreatureTypes.h \
  ../../../../Core/types/ItemTypes.h ../../../../Core/types/ZoneTypes.h \
  ../../../../Core/types/QuestTypes.h \
  ../../../../Core/types/ShopTypes.h \
  ../../../../Core/types/GuildTypes.h ../../../../Core/types/WarTypes.h \
  ../../../../Core/types/ServerType.h ../../../../Core/Utility.h \
  ../../../../Core/Exception.h ../../../../Core/StringStream.h \
  \
  ../../../../Core/SocketInputStream.h ../../../../Core/Socket.h \
  ../../../../Core/SocketImpl.h ../../../../Core/SocketAPI.h \
  ../../../../Core/SocketOutputStream.h
PKTResultHandler.o: PKTResultHandler.cpp ../Mofus.h PKTResultHandler.h \
  MPacketHandler.h ../MPacket.h ../../../../Core/Types.h \
  ../../../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../Core/types/PlayerTypes.h \
  ../../../../Core/types/ObjectTypes.h \
  ../../../../Core/types/CreatureTypes.h \
  ../../../../Core/types/ItemTypes.h ../../../../Core/types/ZoneTypes.h \
  ../../../../Core/types/QuestTypes.h \
  ../../../../Core/types/ShopTypes.h \
  ../../../../Core/types/GuildTypes.h ../../../../Core/types/WarTypes.h \
  ../../../../Core/types/ServerType.h ../../../../Core/Utility.h \
  ../../../../Core/Exception.h ../../../../Core/StringStream.h \
  \
  ../../../../Core/SocketInputStream.h ../../../../Core/Socket.h \
  ../../../../Core/SocketImpl.h ../../../../Core/SocketAPI.h \
  ../../../../Core/SocketOutputStream.h
PKTUserInfoHandler.o: PKTUserInfoHandler.cpp ../Mofus.h \
  PKTUserInfoHandler.h MPacketHandler.h ../MPacket.h \
  ../../../../Core/Types.h ../../../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../../Core/types/PlayerTypes.h \
  ../../../../Core/types/ObjectTypes.h \
  ../../../../Core/types/CreatureTypes.h \
  ../../../../Core/types/ItemTypes.h ../../../../Core/types/ZoneTypes.h \
  ../../../../Core/types/QuestTypes.h \
  ../../../../Core/types/ShopTypes.h \
  ../../../../Core/types/GuildTypes.h ../../../../Core/types/WarTypes.h \
  ../../../../Core/types/ServerType.h ../../../../Core/Utility.h \
  ../../../../Core/Exception.h ../../../../Core/StringStream.h \
  \
  ../../../../Core/SocketInputStream.h ../../../../Core/Socket.h \
  ../../../../Core/SocketImpl.h ../../../../Core/SocketAPI.h \
  ../../../../Core/SocketOutputStream.h
