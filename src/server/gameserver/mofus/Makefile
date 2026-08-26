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
GSDIR    = $(SERVDIR)/gameserver
LSDIR    = $(SERVDIR)/loginserver
BILLDIR  = $(GSDIR)/billing
MYSQLDIR = /usr/lib/x86_64-linux-gnu


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o .gs.o .ls.o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__GAME_SERVER
INCLUDES = -I$(COREDIR)/compat -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I.
#CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#LIBS     = -L$(LIBDIR) -lServerCore -lCore
#SYSLIBS  = -static -lpthread -ldl -lnsl -lz

# < for Library >
TARGET     = $(LIBDIR)/libMofus.a

#BINTARGET	= $(BINDIR)/mofus

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

#	main.o
OBJS = \
	Mofus.o \
	MPacketManager.o \
	MPlayer.o \
	MPlayerManager.o \
	PKTConnectAccept.o \
	PKTConnectAcceptHandler.o \
	PKTConnectAsk.o \
	PKTError.o \
	PKTErrorHandler.o \
	PKTLogout.o \
	PKTPowerPoint.o \
	PKTPowerPointHandler.o \
	PKTReceiveOK.o \
	PKTResult.o \
	PKTUserInfo.o \
	PKTSError.o

#BINOBJS = main.o StringParser.o

SRCS = $(OBJS:.o=.cpp)



.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

#.cpp.o :
#	$(CC) $(CCFLAGS) $(DEFS)  $(INCLUDES) -o $*.o $<

#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
all : $(TARGET)

#bin : $(BINTARGET)

# < for Library >
$(TARGET) : $(OBJS)
	ar r $@ $(OBJS)

#$(BINTARGET) : $(BINOBJS) $(OBJS) $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a
#	$(CC) -o $@ $(BINOBJS) $(OBJS) $(LIBS) $(SYSLIBS) -rdynamic

# < for Test >
#$(TARGET) : $(OBJS) $(LIBDIR)/libGameServerDatabase.a $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a 
#	$(CC) -o $@ $(OBJS) $(LIBS) $(SYSLIBS)


clean :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGET)

depall :
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)

# DO NOT DELETE
Mofus.o: Mofus.cpp Mofus.h
MPacketManager.o: MPacketManager.cpp Mofus.h MPacketManager.h MPacket.h \
  MPacketID.h MPacketHandler.h PKTConnectAsk.h PKTLogout.h PKTUserInfo.h \
  PKTReceiveOK.h PKTResult.h PKTSError.h PKTConnectAccept.h \
  PKTConnectAcceptHandler.h PKTPowerPoint.h PKTPowerPointHandler.h \
  PKTError.h PKTErrorHandler.h
MPlayer.o: MPlayer.cpp Mofus.h MPlayer.h MPacket.h MPacketManager.h \
  MJob.h PKTConnectAsk.h PKTLogout.h PKTUserInfo.h PKTReceiveOK.h \
  PKTResult.h PKTSError.h
MPlayerManager.o: MPlayerManager.cpp Mofus.h MPlayerManager.h MJob.h \
  MPlayer.h PKTError.h MPacket.h
PKTConnectAccept.o: PKTConnectAccept.cpp PKTConnectAccept.h MPacket.h
PKTConnectAcceptHandler.o: PKTConnectAcceptHandler.cpp Mofus.h \
  PKTConnectAcceptHandler.h MPacketHandler.h MPacket.h MPlayer.h MJob.h
PKTConnectAsk.o: PKTConnectAsk.cpp PKTConnectAsk.h MPacket.h
PKTError.o: PKTError.cpp PKTError.h MPacket.h MPacketID.h
PKTErrorHandler.o: PKTErrorHandler.cpp Mofus.h PKTErrorHandler.h \
  MPacketHandler.h MPacket.h PKTError.h MPlayer.h MJob.h
PKTLogout.o: PKTLogout.cpp PKTLogout.h MPacket.h MPacketID.h
PKTPowerPoint.o: PKTPowerPoint.cpp PKTPowerPoint.h MPacket.h MPacketID.h
PKTPowerPointHandler.o: PKTPowerPointHandler.cpp Mofus.h \
  PKTPowerPointHandler.h MPacketHandler.h MPacket.h PKTPowerPoint.h \
  PKTError.h PKTSError.h MPlayer.h MJob.h
PKTReceiveOK.o: PKTReceiveOK.cpp PKTReceiveOK.h MPacket.h MPacketID.h
PKTResult.o: PKTResult.cpp PKTResult.h MPacket.h MPacketID.h
PKTUserInfo.o: PKTUserInfo.cpp PKTUserInfo.h MPacket.h MPacketID.h
PKTSError.o: PKTSError.cpp PKTSError.h MPacket.h MPacketID.h
