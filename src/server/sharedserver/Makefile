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
VSHOME  = ../../..
STLDIR  = /usr/include/STL
BINDIR  = $(VSHOME)/bin
LIBDIR  = $(VSHOME)/lib
LOGDIR  = $(VSHOME)/log
DBINCDIR = /usr/include/mysql
SRCDIR  = ../..
COREDIR = ../../Core
SERVDIR = ..
DBDIR   = ../database
MYSQLDIR = /usr/lib/x86_64-linux-gnu
PYTHONDIR = /usr/local/include/python2.2

#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__SHARED_SERVER__ -D__DEBUG__
INCLUDES = -I$(COREDIR)/compat -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(DBINCDIR) -I$(PYTHONDIR) -I.
CCFLAGS  = -Wall -c -g  -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c
# -lstlport dropped: STLport is no longer used and the archive is 32-bit only.
LIBS     = -L$(LIBDIR) -lDatabase -lSharedServerPackets -lGameServerPackets -lServerCore -lCore
SYSLIBS  = -L$(MYSQLDIR) -lxerces-c -lmysqlclient -lpthread -lnsl -lutil -ldl -lz -lssl -lcrypto -lresolv -lrt -lm
#SYSLIBS  = -L$(MYSQLDIR) -lmysqlclient -lpthread -lnsl -lz -ldl -lutil -lpython2.2 -rdynamic

.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<


#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------
OBJS = \
	Guild.o GuildManager.o ResurrectLocationManager.o GameServerPlayer.o \
	HeartbeatManager.o GameServerInfoManager.o \
	GameServerGroupInfoManager.o GameServerManager.o \
	SharedServer.o main.o StringPool.o \
	FriendManager.o

SRCS = $(OBJS:.o=.cpp)

TARGET = $(BINDIR)/sharedserver


#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
$(TARGET) : $(OBJS) $(LIBDIR)/libDatabase.a $(LIBDIR)/libGameServerPackets.a $(LIBDIR)/libSharedServerPackets.a $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a
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
Guild.o: Guild.cpp \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  Guild.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
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
  ../../Core/Assert.h ../../Core/Exception.h ../../Core/StringStream.h \
  \
  \
  ../../Core/Exception.h ../Mutex.h \
  \
  \
  \
  ../../Core/Types.h ../../Core/Exception.h \
  \
  \
  \
  \
  \
  \
  ../../Core/VSDateTime.h \
  ../../Core/StringStream.h ../database/DB.h \
  ../database/DatabaseManager.h ../../Core/Types.h ../../Core/Exception.h \
  ../database/Connection.h \
  \
  \
  \
  \
  \
  ../Mutex.h \
  ../database/Statement.h ../database/Result.h ../../Core/GuildInfo.h \
  ../../Core/Packet.h ../../Core/SocketInputStream.h ../../Core/Socket.h \
  ../../Core/SocketImpl.h ../../Core/SocketAPI.h \
  ../../Core/SocketOutputStream.h ../../Core/Gpackets/GCGuildMemberList.h \
  ../../Core/Packet.h ../../Core/PacketFactory.h \
  ../../Core/GuildMemberInfo.h ../../Core/GuildMemberInfo.h \
  ../../Core/Properties.h \
  \

GuildManager.o: GuildManager.cpp Guild.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
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
  ../../Core/Assert.h ../../Core/Exception.h ../../Core/StringStream.h \
  \
  \
  ../../Core/Exception.h ../Mutex.h \
  \
  \
  \
  ../../Core/Types.h ../../Core/Exception.h \
  \
  \
  \
  \
  \
  \
  ../../Core/VSDateTime.h \
  GuildManager.h ../Timeval.h \
  \
  \
  ../../Core/StringStream.h ../database/DB.h \
  ../database/DatabaseManager.h ../../Core/Types.h ../../Core/Exception.h \
  ../database/Connection.h \
  \
  \
  \
  \
  \
  ../Mutex.h \
  ../database/Statement.h ../database/Result.h ../../Core/Properties.h \
  \
  \
  ../../Core/Gpackets/GCWaitGuildList.h \
  ../../Core/Packet.h ../../Core/SocketInputStream.h ../../Core/Socket.h \
  ../../Core/SocketImpl.h ../../Core/SocketAPI.h \
  ../../Core/SocketOutputStream.h ../../Core/PacketFactory.h \
  ../../Core/Packet.h ../../Core/GuildInfo.h \
  ../../Core/Gpackets/GCActiveGuildList.h
ResurrectLocationManager.o: ResurrectLocationManager.cpp \
  ResurrectLocationManager.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
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
  \
  \
  \
  \
  \
  \
  ../database/DB.h \
  ../database/DatabaseManager.h ../../Core/Types.h ../../Core/Exception.h \
  ../database/Connection.h \
  \
  \
  \
  \
  \
  ../Mutex.h \
  \
  \
  \
  ../../Core/Types.h ../../Core/Exception.h \
  ../database/Statement.h ../database/Result.h
GameServerPlayer.o: GameServerPlayer.cpp GameServerPlayer.h \
  ../../Core/Types.h ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
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
  ../../Core/Player.h ../../Core/Exception.h ../../Core/Socket.h \
  ../../Core/SocketImpl.h ../../Core/SocketAPI.h \
  ../../Core/SocketInputStream.h ../../Core/Socket.h \
  ../../Core/SocketOutputStream.h ../../Core/Assert.h ../../Core/Packet.h \
  ../../Core/SocketInputStream.h ../../Core/SocketOutputStream.h \
  ../../Core/PacketFactoryManager.h ../../Core/Packet.h \
  ../../Core/PacketFactory.h \
  \

HeartbeatManager.o: HeartbeatManager.cpp HeartbeatManager.h \
  ../../Core/Types.h ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
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
  ../../Core/Assert.h ../../Core/Exception.h \
  \

GameServerInfoManager.o: GameServerInfoManager.cpp \
  GameServerInfoManager.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
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
  GameServerInfo.h ../../Core/StringStream.h \
  \
  \
  \
  \
  \
  ../database/DB.h \
  ../database/DatabaseManager.h ../../Core/Types.h ../../Core/Exception.h \
  ../database/Connection.h \
  \
  \
  \
  \
  \
  ../Mutex.h \
  \
  \
  \
  ../../Core/Types.h ../../Core/Exception.h \
  ../database/Statement.h ../database/Result.h ../../Core/Properties.h \
  ../../Core/Exception.h \

GameServerGroupInfoManager.o: GameServerGroupInfoManager.cpp \
  GameServerGroupInfoManager.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
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
  GameServerGroupInfo.h ../../Core/StringStream.h \
  \
  \
  \
  \
  \
  \
  ../database/DatabaseManager.h \
  ../../Core/Types.h ../../Core/Exception.h ../database/Connection.h \
  \
  \
  \
  \
  \
  \
  ../Mutex.h \
  \
  \
  \
  ../../Core/Types.h ../../Core/Exception.h \
  ../database/Connection.h ../database/Statement.h ../database/Result.h \
  ../database/DB.h ../database/DatabaseManager.h ../database/Statement.h \
  ../database/Result.h
GameServerManager.o: GameServerManager.cpp \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  GameServerManager.h \
  ../Thread.h ../../Core/Types.h ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
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
  ../pthreadAPI.h \
  \
  \
  \
  ../../Core/Types.h ../Timeval.h \
  \
  \
  ../../Core/Exception.h GameServerPlayer.h ../../Core/Player.h \
  ../../Core/Exception.h ../../Core/ServerSocket.h \
  ../../Core/SocketImpl.h ../../Core/SocketAPI.h ../../Core/Socket.h \
  ../Mutex.h \
  \
  ../../Core/Assert.h ../../Core/SocketAPI.h ../../Core/Socket.h \
  \
  \
  \
  \
  \
  ../../Core/Properties.h Guild.h \
  \
  \
  \
  \
  \
  ../../Core/VSDateTime.h \
  GuildManager.h ../../Core/Packet.h ../../Core/SocketInputStream.h \
  ../../Core/SocketOutputStream.h ../database/DB.h \
  ../database/DatabaseManager.h ../../Core/Types.h ../../Core/Exception.h \
  ../database/Connection.h \
  \
  \
  \
  \
  \
  ../Mutex.h \
  ../database/Statement.h ../database/Result.h
SharedServer.o: SharedServer.cpp SharedServer.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
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
  ../../Core/Assert.h ../../Core/Exception.h GameServerInfoManager.h \
  GameServerInfo.h ../../Core/StringStream.h \
  \
  \
  \
  \
  \
  GameServerGroupInfoManager.h \
  GameServerGroupInfo.h GameServerManager.h ../Thread.h \
  ../../Core/Types.h ../../Core/Exception.h ../pthreadAPI.h \
  \
  \
  \
  ../Timeval.h \
  \
  GameServerPlayer.h \
  ../../Core/Player.h ../../Core/ServerSocket.h ../../Core/SocketImpl.h \
  ../../Core/SocketAPI.h ../../Core/Socket.h ../Mutex.h \
  \
  \
  HeartbeatManager.h ../database/DatabaseManager.h ../../Core/Types.h \
  ../../Core/Exception.h ../database/Connection.h \
  \
  \
  \
  \
  \
  \
  ../Mutex.h \
  ../../Core/PacketFactoryManager.h ../../Core/Packet.h \
  ../../Core/SocketInputStream.h ../../Core/SocketOutputStream.h \
  ../../Core/PacketFactory.h ../../Core/PacketValidator.h \
  ../../Core/PacketIDSet.h ../../Core/PlayerStatus.h \
  ../GameWorldInfoManager.h ../GameWorldInfo.h \
  ../../Core/StringStream.h GuildManager.h ResurrectLocationManager.h \
  StringPool.h ../../Core/Properties.h ../DBExecuteManager.h \
  \
  \
  \
  ../Thread.h ../CondVar.h ../CondVarAttr.h ../Mutex.h ../database/DB.h \
  ../database/DatabaseManager.h ../database/Statement.h \
  ../database/Result.h FriendManager.h ../../Core/types/FriendType.h \
  ../LogClient.h ../../Core/types/ServerType.h
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
  SharedServer.h ../LogClient.h ../../Core/Types.h \
  ../../Core/Properties.h ../../Core/Exception.h \
  \
  ../../Core/StringStream.h \
  \

StringPool.o: StringPool.cpp StringPool.h ../../Core/Exception.h \
  ../../Core/Types.h ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
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
  ../../Core/StringStream.h \
  \
  \
  \
  \
  \
  \
  \
  \
  ../database/DB.h \
  ../database/DatabaseManager.h ../../Core/Types.h ../../Core/Exception.h \
  ../database/Connection.h \
  \
  \
  \
  \
  \
  ../Mutex.h \
  \
  \
  \
  ../../Core/Types.h ../../Core/Exception.h \
  ../database/Statement.h ../database/Result.h
FriendManager.o: FriendManager.cpp FriendManager.h ../../Core/Types.h \
  ../../Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
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
  ../../Core/types/FriendType.h \
  \
  \
  ../DBExecuteManager.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../Thread.h ../../Core/Types.h ../../Core/Exception.h \
  ../../Core/StringStream.h \
  \
  ../pthreadAPI.h \
  \
  \
  \
  ../CondVar.h ../CondVarAttr.h ../Mutex.h ../database/DB.h \
  ../database/DatabaseManager.h ../../Core/Types.h ../../Core/Exception.h \
  ../database/Connection.h \
  \
  \
  \
  \
  \
  ../Mutex.h \
  ../database/Statement.h ../database/Result.h
