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
#VSHOME   = ../../../..
STLDIR   = /usr/include/STL
BINDIR   = $(VSHOME)/bin
LIBDIR   = $(VSHOME)/lib
LOGDIR   = $(VSHOME)/log
SRCDIR   = $(VSHOME)/src
COREDIR  = $(SRCDIR)/Core
SERVDIR  = $(SRCDIR)/server
DBDIR    = $(SERVDIR)/database
GSDIR    = ..
SMSDIR  = $(GSDIR)/sms
MYSQLDIR = /usr/lib/x86_64-linux-gnu


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o .gs.o .ls.o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__
INCLUDES = -I$(COREDIR)/compat -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(SMSDIR) -I.
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs

# < for Library >
TARGET_GS  = $(LIBDIR)/libGameServerSMS.a

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

# < for Test >
#TARGET = test/billingTest


#	main.o
GS_OBJS = \
	md5.gs.o \
	CommonSMSPacket.gs.o \
	CommonSMSPacketHandler.gs.o \
	SMSPlayer.gs.o	\
	SMSPlayerManager.gs.o 

SRCS = $(GS_OBJS:.gs.o=.cpp)

#.cpp.o :
#	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

.cpp.gs.o :
	$(CC) $(CCFLAGS) $(DEFS)  -D__GAME_SERVER__ $(INCLUDES) -o $*.gs.o $<

#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
#all : $(TARGET)
all : $(TARGET_GS)

allgameserver : $(TARGET_GS)

# < for Library >
$(TARGET_GS) : $(GS_OBJS)
	ar r $@ $(GS_OBJS)

# < for Test >
#$(TARGET) : $(OBJS) $(LIBDIR)/libGameServerDatabase.a $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a 
#	$(CC) -o $@ $(OBJS) $(LIBS) $(SYSLIBS)

clean :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGET_GS)

cleangameserver :
	rm -rf *.gs.o

depall :
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)

# DO NOT DELETE
md5.o: md5.cpp \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  md5.h \
  /home/darkeden/vs/src/Core/Types.h \
  /home/darkeden/vs/src/Core/types/SystemTypes.h \
  \
  \
  /home/darkeden/vs/src/Core/types/PlayerTypes.h \
  /home/darkeden/vs/src/Core/types/ObjectTypes.h \
  /home/darkeden/vs/src/Core/types/CreatureTypes.h \
  /home/darkeden/vs/src/Core/types/ItemTypes.h \
  /home/darkeden/vs/src/Core/types/ZoneTypes.h \
  /home/darkeden/vs/src/Core/types/QuestTypes.h \
  /home/darkeden/vs/src/Core/types/ShopTypes.h \
  /home/darkeden/vs/src/Core/types/GuildTypes.h \
  /home/darkeden/vs/src/Core/types/WarTypes.h \
  /home/darkeden/vs/src/Core/Utility.h
CommonSMSPacket.o: CommonSMSPacket.cpp CommonSMSPacket.h \
  \
  \
  \
  \
  \
  \
  \
  \
  /home/darkeden/vs/src/Core/Packet.h \
  /home/darkeden/vs/src/Core/Types.h \
  /home/darkeden/vs/src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  /home/darkeden/vs/src/Core/types/PlayerTypes.h \
  /home/darkeden/vs/src/Core/types/ObjectTypes.h \
  /home/darkeden/vs/src/Core/types/CreatureTypes.h \
  /home/darkeden/vs/src/Core/types/ItemTypes.h \
  /home/darkeden/vs/src/Core/types/ZoneTypes.h \
  /home/darkeden/vs/src/Core/types/QuestTypes.h \
  /home/darkeden/vs/src/Core/types/ShopTypes.h \
  /home/darkeden/vs/src/Core/types/GuildTypes.h \
  /home/darkeden/vs/src/Core/types/WarTypes.h \
  /home/darkeden/vs/src/Core/Utility.h \
  /home/darkeden/vs/src/Core/Exception.h \
  /home/darkeden/vs/src/Core/StringStream.h \
  \
  /home/darkeden/vs/src/Core/SocketInputStream.h \
  /home/darkeden/vs/src/Core/Socket.h \
  /home/darkeden/vs/src/Core/SocketImpl.h \
  /home/darkeden/vs/src/Core/SocketAPI.h \
  /home/darkeden/vs/src/Core/SocketOutputStream.h \
  /home/darkeden/vs/src/Core/PacketFactory.h SMSInfo.h \
  /home/darkeden/vs/src/Core/Assert.h \
  /home/darkeden/vs/src/Core/Properties.h \
  \
  \
  \
  \
  \
  \
  /home/darkeden/vs/src/server/database/DB.h \
  /home/darkeden/vs/src/server/database/DatabaseManager.h \
  \
  \
  /home/darkeden/vs/src/server/database/Connection.h \
  \
  \
  /home/darkeden/vs/src/server/Mutex.h \
  \
  \
  /home/darkeden/vs/src/server/database/Statement.h \
  /home/darkeden/vs/src/server/database/Result.h \
  /home/darkeden/vs/src/Core/VSDateTime.h
CommonSMSPacketHandler.o: CommonSMSPacketHandler.cpp CommonSMSPacket.h \
  \
  \
  \
  \
  \
  \
  \
  \
  /home/darkeden/vs/src/Core/Packet.h \
  /home/darkeden/vs/src/Core/Types.h \
  /home/darkeden/vs/src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  /home/darkeden/vs/src/Core/types/PlayerTypes.h \
  /home/darkeden/vs/src/Core/types/ObjectTypes.h \
  /home/darkeden/vs/src/Core/types/CreatureTypes.h \
  /home/darkeden/vs/src/Core/types/ItemTypes.h \
  /home/darkeden/vs/src/Core/types/ZoneTypes.h \
  /home/darkeden/vs/src/Core/types/QuestTypes.h \
  /home/darkeden/vs/src/Core/types/ShopTypes.h \
  /home/darkeden/vs/src/Core/types/GuildTypes.h \
  /home/darkeden/vs/src/Core/types/WarTypes.h \
  /home/darkeden/vs/src/Core/Utility.h \
  /home/darkeden/vs/src/Core/Exception.h \
  /home/darkeden/vs/src/Core/StringStream.h \
  \
  /home/darkeden/vs/src/Core/SocketInputStream.h \
  /home/darkeden/vs/src/Core/Socket.h \
  /home/darkeden/vs/src/Core/SocketImpl.h \
  /home/darkeden/vs/src/Core/SocketAPI.h \
  /home/darkeden/vs/src/Core/SocketOutputStream.h \
  /home/darkeden/vs/src/Core/PacketFactory.h SMSInfo.h SMSPlayer.h \
  /home/darkeden/vs/src/Core/Player.h \
  /home/darkeden/vs/src/Core/Gpackets/GCSystemMessage.h
SMSPlayer.o: SMSPlayer.cpp SMSPlayer.h \
  /home/darkeden/vs/src/Core/Types.h \
  /home/darkeden/vs/src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  /home/darkeden/vs/src/Core/types/PlayerTypes.h \
  /home/darkeden/vs/src/Core/types/ObjectTypes.h \
  /home/darkeden/vs/src/Core/types/CreatureTypes.h \
  /home/darkeden/vs/src/Core/types/ItemTypes.h \
  /home/darkeden/vs/src/Core/types/ZoneTypes.h \
  /home/darkeden/vs/src/Core/types/QuestTypes.h \
  /home/darkeden/vs/src/Core/types/ShopTypes.h \
  /home/darkeden/vs/src/Core/types/GuildTypes.h \
  /home/darkeden/vs/src/Core/types/WarTypes.h \
  /home/darkeden/vs/src/Core/Utility.h \
  /home/darkeden/vs/src/Core/Exception.h \
  /home/darkeden/vs/src/Core/StringStream.h \
  /home/darkeden/vs/src/Core/Player.h \
  SMSInfo.h /home/darkeden/vs/src/Core/Socket.h \
  /home/darkeden/vs/src/Core/SocketImpl.h \
  /home/darkeden/vs/src/Core/SocketAPI.h \
  /home/darkeden/vs/src/Core/SocketInputStream.h \
  /home/darkeden/vs/src/Core/SocketOutputStream.h \
  /home/darkeden/vs/src/Core/Assert.h \
  /home/darkeden/vs/src/Core/Packet.h \
  /home/darkeden/vs/src/Core/Properties.h \
  \
  \
  /home/darkeden/vs/src/Core/PacketFactoryManager.h \
  /home/darkeden/vs/src/Core/PacketFactory.h CommonSMSPacket.h \

SMSPlayerManager.o: SMSPlayerManager.cpp SMSPlayerManager.h \
  /home/darkeden/vs/src/Core/Types.h \
  /home/darkeden/vs/src/Core/types/SystemTypes.h \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  /home/darkeden/vs/src/Core/types/PlayerTypes.h \
  /home/darkeden/vs/src/Core/types/ObjectTypes.h \
  /home/darkeden/vs/src/Core/types/CreatureTypes.h \
  /home/darkeden/vs/src/Core/types/ItemTypes.h \
  /home/darkeden/vs/src/Core/types/ZoneTypes.h \
  /home/darkeden/vs/src/Core/types/QuestTypes.h \
  /home/darkeden/vs/src/Core/types/ShopTypes.h \
  /home/darkeden/vs/src/Core/types/GuildTypes.h \
  /home/darkeden/vs/src/Core/types/WarTypes.h \
  /home/darkeden/vs/src/Core/Utility.h \
  /home/darkeden/vs/src/Core/Exception.h \
  /home/darkeden/vs/src/Core/StringStream.h \
  /home/darkeden/vs/src/server/Thread.h \
  /home/darkeden/vs/src/server/pthreadAPI.h \
  \
  \
  /home/darkeden/vs/src/Core/Socket.h \
  /home/darkeden/vs/src/Core/SocketImpl.h \
  /home/darkeden/vs/src/Core/SocketAPI.h \
  /home/darkeden/vs/src/Core/Packet.h \
  /home/darkeden/vs/src/Core/SocketInputStream.h \
  /home/darkeden/vs/src/Core/SocketOutputStream.h \
  /home/darkeden/vs/src/server/Mutex.h SMSInfo.h SMSPlayer.h \
  /home/darkeden/vs/src/Core/Player.h CommonSMSPacket.h \
  \
  /home/darkeden/vs/src/Core/PacketFactory.h \
  /home/darkeden/vs/src/Core/Properties.h \
  \
  \
  /home/darkeden/vs/src/server/LogClient.h \
  /home/darkeden/vs/src/Core/Assert.h \
  \
  /home/darkeden/vs/src/server/Timeval.h \

