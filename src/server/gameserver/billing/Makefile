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
VSHOME   = ../../../..
BINDIR   = $(VSHOME)/bin
LIBDIR   = $(VSHOME)/lib
LOGDIR   = $(VSHOME)/log
SRCDIR   = $(VSHOME)/src
COREDIR  = $(SRCDIR)/Core
SERVDIR  = $(SRCDIR)/server
DBDIR    = $(SERVDIR)/database
GSDIR    = ..
LSDIR    = ../../loginserver
BILLDIR  = $(GSDIR)/billing
MYSQLDIR = /usr/lib/x86_64-linux-gnu
FREETDSINC = /usr/include


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o .gs.o .ls.o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__
INCLUDES = -I$(COREDIR)/compat -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(LSDIR) -I$(BILLDIR) -I$(FREETDSINC) -I.
INCLUDES_GS = -I$(COREDIR)/compat -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(BILLDIR) -I$(FREETDSINC) -I.
INCLUDES_LS = -I$(COREDIR)/compat -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(LSDIR) -I$(BILLDIR) -I$(FREETDSINC) -I.
#CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#LIBS     = -L$(LIBDIR) -lGameServerDatabase -lServerCore -lCore
#SYSLIBS  = -L$(MYSQLDIR) -static -lpthread -lnsl -lmysqlclient -lz

# < for Library >
TARGET_GS  = $(LIBDIR)/libGameServerBilling.a
TARGET_LS  = $(LIBDIR)/libLoginServerBilling.a

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

# < for Test >
#TARGET = test/billingTest


#	main.o
GS_OBJS = \
	CommonBillingPacket.gs.o \
	CommonBillingPacketHandler.gs.o \
	BillingPlayer.gs.o	\
	BillingPlayerManager.gs.o \
	BillingPlayerInfo.gs.o \
	MSSQLEngine.gs.o \
	common.gs.o

LS_OBJS = \
	CommonBillingPacket.ls.o \
	CommonBillingPacketHandler.ls.o \
	BillingPlayer.ls.o	\
	BillingPlayerManager.ls.o \
	BillingPlayerInfo.ls.o \
	MSSQLEngine.ls.o \
	common.ls.o

SRCS = $(GS_OBJS:.gs.o=.cpp)



#.cpp.o :
#	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

.cpp.gs.o :
	$(CC) $(CCFLAGS) $(DEFS)  -D__GAME_SERVER__ $(INCLUDES_GS) -o $*.gs.o $<

.cpp.ls.o :
	$(CC) $(CCFLAGS) $(DEFS)  -D__LOGIN_SERVER__ $(INCLUDES_LS) -o $*.ls.o $<

#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
#all : $(TARGET)
all : $(TARGET_GS) $(TARGET_LS)

allgameserver : $(TARGET_GS)

allloginserver : $(TARGET_LS)

# < for Library >
$(TARGET_GS) : $(GS_OBJS)
	ar r $@ $(GS_OBJS)

$(TARGET_LS) : $(LS_OBJS)
	ar r $@ $(LS_OBJS)

# < for Test >
#$(TARGET) : $(OBJS) $(LIBDIR)/libGameServerDatabase.a $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a 
#	$(CC) -o $@ $(OBJS) $(LIBS) $(SYSLIBS)


clean :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGET_GS) $(TARGET_LS)

cleanloginserver :
	rm -rf *.ls.o

cleangameserver :
	rm -rf *.gs.o

depall :
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)

# DO NOT DELETE
CommonBillingPacket.o: CommonBillingPacket.cpp CommonBillingPacket.h \
  $(COREDIR)/Packet.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  BillingInfo.h $(COREDIR)/Assert.h $(COREDIR)/Properties.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/VSDateTime.h
CommonBillingPacketHandler.o: CommonBillingPacketHandler.cpp \
  CommonBillingPacket.h $(COREDIR)/Packet.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  BillingInfo.h BillingPlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
BillingPlayer.o: BillingPlayer.cpp BillingPlayer.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Player.h BillingInfo.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/SocketOutputStream.h \
  $(COREDIR)/Assert.h $(COREDIR)/Packet.h $(COREDIR)/Properties.h \
  $(COREDIR)/PacketFactoryManager.h $(COREDIR)/PacketFactory.h \
  CommonBillingPacket.h
BillingPlayerManager.o: BillingPlayerManager.cpp BillingPlayerManager.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h \
  $(COREDIR)/SocketAPI.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/SocketOutputStream.h \
  $(SERVDIR)/Mutex.h BillingInfo.h BillingPlayer.h $(COREDIR)/Player.h \
  CommonBillingPacket.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Properties.h $(SERVDIR)/LogClient.h $(COREDIR)/Assert.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SERVDIR)/Timeval.h
BillingPlayerInfo.o: BillingPlayerInfo.cpp $(COREDIR)/Assert.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Player.h \
  $(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  BillingPlayerInfo.h $(SERVDIR)/Timeval.h
MSSQLEngine.o: MSSQLEngine.cpp MSSQLEngine.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  common.h
common.o: common.cpp common.h
