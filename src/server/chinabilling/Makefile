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
VSHOME   = ../../..
STLDIR   = /usr/include/STL
BINDIR   = $(VSHOME)/bin
LIBDIR   = $(VSHOME)/lib
LOGDIR   = $(VSHOME)/log
SRCDIR   = $(VSHOME)/src
COREDIR  = $(SRCDIR)/Core
SERVDIR  = $(SRCDIR)/server
DBDIR    = $(SERVDIR)/database
GSDIR    = $(SERVDIR)/gameserver
LSDIR    = $(SERVDIR)/loginserver
BILLDIR  = $(GSDIR)/billing
MYSQLDIR = /usr/lib/x86_64-linux-gnu


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o .gs.o .ls.o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__
INCLUDES = -I$(COREDIR)/compat -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(LSDIR) -I$(BILLDIR) -I.
INCLUDES_GS = -I$(COREDIR)/compat -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(BILLDIR) -I.
INCLUDES_LS = -I$(COREDIR)/compat -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(LSDIR) -I$(BILLDIR) -I.
#CCFLAGS  = -Wall -c -g 
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#LIBS     = -L$(LIBDIR) -lGameServerDatabase -lServerCore -lCore
#SYSLIBS  = -L$(MYSQLDIR) -static -lpthread -lnsl -lmysqlclient -lz

# < for Library >
TARGET     = $(LIBDIR)/libCBilling.a
TARGET_GS  = $(LIBDIR)/libGameServerCBilling.a
TARGET_LS  = $(LIBDIR)/libLoginServerCBilling.a

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

# < for Test >
#TARGET = test/billingTest


#	main.o
OBJS = \
	CBillingPacketErrorBody.o \
	CBillingPacketResponseLoginBody.o \
	CBillingPacketHeader.o \
	CBillingPacketResponseLogoutBody.o \
	CBillingPacketRequestIntervalValidationBody.o \
	CBillingPacketResponseMinusMinuteBody.o \
	CBillingPacketRequestLoginBody.o \
	CBillingPacketResponseMinusPointBody.o \
	CBillingPacketRequestLogoutBody.o \
	CBillingPlayer.o \
	CBillingPacketRequestMinusMinuteBody.o \
	CBillingPlayerInfo.o \
	CBillingPacketRequestMinusPointBody.o \
	CBillingPlayerManager.o \
	CBillingPacketResponseIntervalValidationBody.o \

GS_OBJS = \
	CBillingPacketErrorBody.gs.o \
	CBillingPacketResponseLoginBody.gs.o \
	CBillingPacketHeader.gs.o \
	CBillingPacketResponseLogoutBody.gs.o \
	CBillingPacketRequestIntervalValidationBody.gs.o \
	CBillingPacketResponseMinusMinuteBody.gs.o \
	CBillingPacketRequestLoginBody.gs.o \
	CBillingPacketResponseMinusPointBody.gs.o \
	CBillingPacketRequestLogoutBody.gs.o \
	CBillingPlayer.gs.o \
	CBillingPacketRequestMinusMinuteBody.gs.o \
	CBillingPlayerInfo.gs.o \
	CBillingPacketRequestMinusPointBody.gs.o \
	CBillingPlayerManager.gs.o \
	CBillingPacketResponseIntervalValidationBody.gs.o \

LS_OBJS = \
	CBillingPacketErrorBody.ls.o \
	CBillingPacketResponseLoginBody.ls.o \
	CBillingPacketHeader.ls.o \
	CBillingPacketResponseLogoutBody.ls.o \
	CBillingPacketRequestIntervalValidationBody.ls.o \
	CBillingPacketResponseMinusMinuteBody.ls.o \
	CBillingPacketRequestLoginBody.ls.o \
	CBillingPacketResponseMinusPointBody.ls.o \
	CBillingPacketRequestLogoutBody.ls.o \
	CBillingPlayer.ls.o \
	CBillingPacketRequestMinusMinuteBody.ls.o \
	CBillingPlayerInfo.ls.o \
	CBillingPacketRequestMinusPointBody.ls.o \
	CBillingPlayerManager.ls.o \
	CBillingPacketResponseIntervalValidationBody.ls.o \

SRCS = $(GS_OBJS:.gs.o=.cpp)



#.cpp.o :
#	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS)  $(INCLUDES) -o $*.o $<

.cpp.gs.o :
	$(CC) $(CCFLAGS) $(DEFS)  -D__GAME_SERVER__ $(INCLUDES_GS) -o $*.gs.o $<

.cpp.ls.o :
	$(CC) $(CCFLAGS) $(DEFS)  -D__LOGIN_SERVER__ $(INCLUDES_LS) -o $*.ls.o $<

#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
#all : $(TARGET)
all : $(TARGET_GS) $(TARGET_LS) $(TARGET)

allgameserver : $(TARGET_GS)

allloginserver : $(TARGET_LS)

# < for Library >
$(TARGET_GS) : $(GS_OBJS)
	ar r $@ $(GS_OBJS)

$(TARGET_LS) : $(LS_OBJS)
	ar r $@ $(LS_OBJS)

$(TARGET) : $(OBJS)
	ar r $@ $(OBJS)

# < for Test >
#$(TARGET) : $(OBJS) $(LIBDIR)/libGameServerDatabase.a $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a 
#	$(CC) -o $@ $(OBJS) $(LIBS) $(SYSLIBS)


clean :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGET_GS) $(TARGET_LS) $(TARGET)

cleanloginserver :
	rm -rf *.ls.o

cleangameserver :
	rm -rf *.gs.o

depall :
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)

# DO NOT DELETE
CBillingPacketErrorBody.o: CBillingPacketErrorBody.cpp \
  CBillingPacketErrorBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  \
  \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPacketResponseLoginBody.o: CBillingPacketResponseLoginBody.cpp \
  CBillingPacketResponseLoginBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  \
  \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPacketHeader.o: CBillingPacketHeader.cpp CBillingPacketHeader.h \
  CBillingInfo.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/Exception.h ../../../src/Core/Types.h \
  ../../../src/Core/types/SystemTypes.h \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  \
  \
  ../../../src/Core/SocketInputStream.h ../../../src/Core/Exception.h \
  ../../../src/Core/Socket.h ../../../src/Core/SocketImpl.h \
  ../../../src/Core/SocketAPI.h ../../../src/Core/SocketOutputStream.h \
  ../../../src/Core/Properties.h \
  \

CBillingPacketResponseLogoutBody.o: CBillingPacketResponseLogoutBody.cpp \
  CBillingPacketResponseLogoutBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  \
  \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPacketRequestIntervalValidationBody.o: \
  CBillingPacketRequestIntervalValidationBody.cpp \
  CBillingPacketRequestIntervalValidationBody.h \
  ../../../src/Core/Exception.h ../../../src/Core/Types.h \
  ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  \
  \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h CBillingPlayerManager.h \
  ../../../src/Core/Types.h ../../../src/server/Thread.h \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  ../../../src/server/pthreadAPI.h \
  \
  \
  \
  ../../../src/Core/Socket.h ../../../src/server/Mutex.h
CBillingPacketResponseMinusMinuteBody.o: \
  CBillingPacketResponseMinusMinuteBody.cpp \
  CBillingPacketResponseMinusMinuteBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  \
  \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPacketRequestLoginBody.o: CBillingPacketRequestLoginBody.cpp \
  CBillingPacketRequestLoginBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  \
  \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPacketResponseMinusPointBody.o: \
  CBillingPacketResponseMinusPointBody.cpp \
  CBillingPacketResponseMinusPointBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  \
  \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPacketRequestLogoutBody.o: CBillingPacketRequestLogoutBody.cpp \
  CBillingPacketRequestLogoutBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  \
  \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPlayer.o: CBillingPlayer.cpp CBillingPlayer.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  ../../../src/Core/StringStream.h \
  \
  \
  ../../../src/Core/Player.h ../../../src/Core/Exception.h \
  ../../../src/Core/Socket.h ../../../src/Core/SocketImpl.h \
  ../../../src/Core/SocketAPI.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Socket.h ../../../src/Core/SocketOutputStream.h \
  ../../../src/Core/Assert.h ../../../src/Core/Packet.h \
  ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/SocketOutputStream.h CBillingPlayerManager.h \
  ../../../src/server/Thread.h ../../../src/Core/Types.h \
  ../../../src/Core/Exception.h ../../../src/server/pthreadAPI.h \
  \
  \
  \
  ../../../src/server/Mutex.h CBillingInfo.h \
  CBillingPacketHeader.h CBillingPacketErrorBody.h \
  \
  \
  \
  \
  \

CBillingPacketRequestMinusMinuteBody.o: \
  CBillingPacketRequestMinusMinuteBody.cpp \
  CBillingPacketRequestMinusMinuteBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  \
  \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPlayerInfo.o: CBillingPlayerInfo.cpp CBillingPlayerInfo.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  ../../../src/Core/StringStream.h \
  \
  \
  ../../../src/server/Timeval.h \
  \
  CBillingInfo.h \
  ../../../src/Core/VSDateTime.h ../../../src/Core/StringStream.h
CBillingPacketRequestMinusPointBody.o: \
  CBillingPacketRequestMinusPointBody.cpp \
  CBillingPacketRequestMinusPointBody.h ../../../src/Core/Exception.h \
  ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  \
  \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
CBillingPlayerManager.o: CBillingPlayerManager.cpp \
  CBillingPlayerManager.h ../../../src/Core/Types.h \
  ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  ../../../src/Core/StringStream.h \
  \
  \
  ../../../src/server/Thread.h ../../../src/Core/Types.h \
  ../../../src/Core/Exception.h ../../../src/server/pthreadAPI.h \
  \
  \
  \
  ../../../src/Core/Socket.h \
  ../../../src/Core/Exception.h ../../../src/Core/SocketImpl.h \
  ../../../src/Core/SocketAPI.h ../../../src/server/Mutex.h \
  CBillingInfo.h CBillingPlayer.h ../../../src/Core/Player.h \
  ../../../src/Core/Assert.h ../../../src/Core/Properties.h \
  \
  \
  \
  \
  ../../../src/server/database/DB.h \
  ../../../src/server/database/DatabaseManager.h \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/server/database/Connection.h \
  \
  \
  \
  ../../../src/server/Mutex.h ../../../src/server/database/Statement.h \
  ../../../src/server/database/Result.h ../../../src/server/Timeval.h
CBillingPacketResponseIntervalValidationBody.o: \
  CBillingPacketResponseIntervalValidationBody.cpp \
  CBillingPacketResponseIntervalValidationBody.h \
  ../../../src/Core/Exception.h ../../../src/Core/Types.h \
  ../../../src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  ../../../src/Core/types/PlayerTypes.h \
  ../../../src/Core/types/SystemTypes.h \
  ../../../src/Core/types/ObjectTypes.h \
  ../../../src/Core/types/CreatureTypes.h \
  ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
  ../../../src/Core/types/QuestTypes.h \
  ../../../src/Core/types/ShopTypes.h ../../../src/Core/types/ItemTypes.h \
  ../../../src/Core/types/GuildTypes.h ../../../src/Core/types/WarTypes.h \
  ../../../src/Core/types/ServerType.h \
  ../../../src/Core/types/VersionType.h ../../../src/Core/Utility.h \
  ../../../src/Core/StringStream.h \
  \
  \
  CBillingInfo.h ../../../src/Core/SocketInputStream.h \
  ../../../src/Core/Exception.h ../../../src/Core/Socket.h \
  ../../../src/Core/SocketImpl.h ../../../src/Core/SocketAPI.h \
  ../../../src/Core/SocketOutputStream.h
