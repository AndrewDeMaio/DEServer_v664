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
BINDIR  = $(VSHOME)/bin
LIBDIR  = $(VSHOME)/lib
LOGDIR  = $(VSHOME)/log
DBINCDIR = /usr/include/mysql
SRCDIR  = ../..
COREDIR = ../../Core
SERVDIR = ..
DBDIR   = ../database
MYSQLDIR = /usr/lib/x86_64-linux-gnu
BILLINGDIR = ../gameserver/billing

#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__LOGIN_SERVER__ -D__DEBUG__
INCLUDES = -I$(COREDIR)/compat -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(DBINCDIR) -I$(BILLINGDIR) -I.
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
# -lcpsso dropped: its only entry point, GetCPCookieValue, is called solely from
# inside #ifdef __NETMARBLE_SERVER__ (Core/Cpackets/CLLogin.cpp), which is not
# defined here -- and the archive is 32-bit only with no source available.
LIBS     = -L$(LIBDIR) -lLoginServerDatabase -lLoginServerPackets -lServerCore -lCore -lLoginServerBilling -lLoginServerCBilling
#LIBS     = -L$(LIBDIR) -lLoginServerDatabase -lLoginServerPackets -lServerCore -lCore -lLoginServerBilling -lLoginServerCBilling
SYSLIBS  = -L$(MYSQLDIR) -lxerces-c -lmysqlclient -lsybdb -lpthread -lnsl -lutil -ldl -lz -lssl -lcrypto -lresolv -lrt -lm

.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<


#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------
OBJS = \
	ClientManager.o UserInfoManager.o \
	GameServerGroupInfoManager.o GameServerManager.o \
	LoginPlayer.o LoginPlayerManager.o LoginServer.o \
	ZoneGroupInfoManager.o ZoneInfoManager.o main.o \
	ItemDestroyer.o ReconnectLoginInfoManager.o \
	LoginPayTypeManager.o

SRCS = $(OBJS:.o=.cpp)

TARGET = $(BINDIR)/loginserver


#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
$(TARGET) : $(OBJS) $(LIBDIR)/libLoginServerDatabase.a $(LIBDIR)/libLoginServerPackets.a $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a $(LIBDIR)/libLoginServerCBilling.a
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
ClientManager.o: ClientManager.cpp $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h ClientManager.h $(COREDIR)/Assert.h \
  LoginPlayerManager.h $(SERVDIR)/PlayerManager.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/SocketAPI.h $(COREDIR)/ServerSocket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/Socket.h \
  ReconnectLoginInfoManager.h ReconnectLoginInfo.h $(SERVDIR)/Profile.h \
  $(SERVDIR)/PacketProfile.h $(COREDIR)/Properties.h \
  $(SERVDIR)/GameWorldInfoManager.h $(SERVDIR)/GameWorldInfo.h \
  GameServerGroupInfoManager.h GameServerGroupInfo.h
UserInfoManager.o: UserInfoManager.cpp UserInfoManager.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h UserInfo.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(DBDIR)/DB.h
GameServerGroupInfoManager.o: GameServerGroupInfoManager.cpp \
  GameServerGroupInfoManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  GameServerGroupInfo.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(DBDIR)/DB.h
GameServerManager.o: GameServerManager.cpp GameServerManager.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(COREDIR)/DatagramSocket.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/Datagram.h $(COREDIR)/Properties.h \
  $(COREDIR)/DatagramPacket.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketOutputStream.h \
  $(SERVDIR)/LogClient.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(COREDIR)/Lpackets/LGKickCharacter.h \
  $(COREDIR)/PacketFactory.h
LoginPlayer.o: LoginPlayer.cpp LoginPlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(SERVDIR)/Timeval.h $(SERVDIR)/PaySystem.h \
  $(COREDIR)/VSDateTime.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Assert.h $(COREDIR)/PacketFactoryManager.h \
  $(COREDIR)/PacketValidator.h $(COREDIR)/PacketIDSet.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(SERVDIR)/LogClient.h $(SERVDIR)/Profile.h \
  $(SERVDIR)/PacketProfile.h $(SERVDIR)/GameServerInfoManager.h $(SERVDIR)/GameServerInfo.h \
  GameServerManager.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
  $(COREDIR)/DatagramSocket.h $(COREDIR)/Datagram.h \
  $(BILLINGDIR)/BillingPlayerManager.h \
  $(BILLINGDIR)/BillingInfo.h \
  $(COREDIR)/Lpackets/LCLoginOK.h $(COREDIR)/Lpackets/LCLoginError.h \
  $(COREDIR)/Lpackets/LGKickCharacter.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Lpackets/LCPCList.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/Shape.h
LoginPlayerManager.o: LoginPlayerManager.cpp LoginPlayerManager.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/PlayerManager.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/SocketAPI.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/ServerSocket.h $(COREDIR)/SocketImpl.h $(COREDIR)/Socket.h \
  $(COREDIR)/Assert.h LoginPlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/PlayerStatus.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/SocketOutputStream.h \
  $(COREDIR)/PacketFactory.h $(SERVDIR)/LogClient.h $(COREDIR)/Properties.h \
  ReconnectLoginInfoManager.h ReconnectLoginInfo.h \
  $(BILLINGDIR)/BillingInfo.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
LoginServer.o: LoginServer.cpp LoginServer.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h $(SERVDIR)/GameServerInfoManager.h $(SERVDIR)/GameServerInfo.h \
  GameServerGroupInfoManager.h GameServerGroupInfo.h \
  GameServerManager.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
  $(COREDIR)/DatagramSocket.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/Datagram.h ClientManager.h ZoneInfoManager.h ZoneInfo.h \
  ZoneGroupInfoManager.h ZoneGroupInfo.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PacketFactoryManager.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketOutputStream.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/PacketValidator.h \
  $(COREDIR)/PacketIDSet.h $(COREDIR)/PlayerStatus.h ItemDestroyer.h \
  $(DBDIR)/DB.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  UserInfoManager.h UserInfo.h $(SERVDIR)/GameWorldInfoManager.h \
  $(SERVDIR)/GameWorldInfo.h $(SERVDIR)/chinabilling/CBillingPlayerManager.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h LoginPlayer.h $(COREDIR)/Player.h \
  $(SERVDIR)/Timeval.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/LogClient.h \
  LoginPayTypeManager.h
ZoneGroupInfoManager.o: ZoneGroupInfoManager.cpp ZoneGroupInfoManager.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h ZoneGroupInfo.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
ZoneInfoManager.o: ZoneInfoManager.cpp ZoneInfoManager.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h ZoneInfo.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
main.o: main.cpp $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h LoginServer.h \
  $(SERVDIR)/LogClient.h $(COREDIR)/Properties.h
ItemDestroyer.o: ItemDestroyer.cpp ItemDestroyer.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
ReconnectLoginInfoManager.o: ReconnectLoginInfoManager.cpp \
  ReconnectLoginInfoManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  ReconnectLoginInfo.h $(SERVDIR)/Timeval.h $(COREDIR)/Assert.h
LoginPayTypeManager.o: LoginPayTypeManager.cpp LoginPayTypeManager.h \
  LoginPlayer.h $(COREDIR)/Player.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(SERVDIR)/Mutex.h $(COREDIR)/PlayerStatus.h $(SERVDIR)/Timeval.h $(SERVDIR)/PaySystem.h \
  $(COREDIR)/VSDateTime.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
