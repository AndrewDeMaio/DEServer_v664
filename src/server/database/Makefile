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
DBINCDIR = /usr/include/mysql
BINDIR  = $(VSHOME)/bin
LIBDIR  = $(VSHOME)/lib
LOGDIR  = $(VSHOME)/log
SRCDIR  = $(VSHOME)/src
COREDIR = $(SRCDIR)/Core
SERVDIR = $(SRCDIR)/server


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o .gs.o .ls.o .us.o .ss.o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__
INCLUDES = -I$(COREDIR)/compat -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I.
CCFLAGS  = -Wall -c -g  -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c

.cpp.o : 
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

.cpp.gs.o :
	$(CC) $(CCFLAGS) $(DEFS) -D__GAME_SERVER__ $(INCLUDES) -o $*.gs.o $<

.cpp.ls.o :
	$(CC) $(CCFLAGS) $(DEFS) -D__LOGIN_SERVER__ $(INCLUDES) -o $*.ls.o $<

.cpp.us.o :
	$(CC) $(CCFLAGS) $(DEFS) -D__UPDATE_SERVER__ $(INCLUDES) -o $*.us.o $<

.cpp.ss.o :
	$(CC) $(CCFLAGS) $(DEFS) -D__SHARED_SERVER__ $(INCLUDES) -o $*.ss.o $<

#----------------------------------------------------------------------
# Server Core Library
#----------------------------------------------------------------------
DB_OBJS = Connection.o Statement.o Result.o DatabaseManager.o
DB_SRC  = $(DB_OBJS:.o=.cpp)
DB_LIB  = $(LIBDIR)/libDatabase.a

#----------------------------------------------------------------------
# Packet Library for GameServer
#----------------------------------------------------------------------
GS_DB_OBJS = Connection.gs.o Statement.gs.o Result.gs.o DatabaseManager.gs.o
GS_DB_SRCS = $(GS_DB_OBJS:.gs.o=.cpp)
GS_DB_LIB  = $(LIBDIR)/libGameServerDatabase.a

#----------------------------------------------------------------------
# Packet Library for LoginServer
#----------------------------------------------------------------------
LS_DB_OBJS = Connection.ls.o Statement.ls.o Result.ls.o DatabaseManager.ls.o
LS_DB_SRCS = $(LS_DB_OBJS:.ls.o=.cpp)
LS_DB_LIB  = $(LIBDIR)/libLoginServerDatabase.a

#----------------------------------------------------------------------
# Packet Library for Updateserver 
#----------------------------------------------------------------------
US_DB_OBJS = Connection.us.o Statement.us.o Result.gs.o DatabaseManager.us.o
US_DB_SRCS = $(US_DB_OBJS:.us.o=.cpp)
US_DB_LIB  = $(LIBDIR)/libUpdateServerDatabase.a

#----------------------------------------------------------------------
# Database Library for Updateserver 
#----------------------------------------------------------------------
SS_DB_OBJS = Connection.ss.o Statement.ss.o Result.ss.o DatabaseManager.ss.o
SS_DB_SRCS = $(SS_DB_OBJS:.ss.o=.cpp)
SS_DB_LIB  = $(LIBDIR)/libSharedServerDatabase.a

#----------------------------------------------------------------------
# All Targets
#----------------------------------------------------------------------
#TARGETS = $(CORE_LIB) $(LS_DB_LIB) $(GS_DB_LIB)
SRCS = $(LS_DB_SRCS) $(GS_DB_SRCS) $(US_DB_SRCS) $(SS_DB_SRCS)
TARGETS = $(DB_LIB) $(LS_DB_LIB) $(GS_DB_LIB) $(US_DB_LIB) $(SS_DB_LIB)

#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
all : $(TARGETS)

$(DB_LIB) : $(DB_OBJS)
	ar rc $@ $^

$(LS_DB_LIB) : $(LS_DB_OBJS)
	ar rc $@ $^

$(GS_DB_LIB) : $(GS_DB_OBJS)
	ar rc $@ $^

$(US_DB_LIB) : $(US_DB_OBJS)
	ar rc $@ $^

$(SS_DB_LIB) : $(SS_DB_OBJS)
	ar rc $@ $^

clean :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGETS)

depall : 
	gccmakedep $(SRCS) $(INCLUDES)

dep : 
	gccmakedep $(SRCS) $(INCLUDES)

# DO NOT DELETE
Connection.o: Connection.cpp Connection.h ../../../src/Core/Types.h \
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
  \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  ../../../src/Core/Types.h \
  ../../../src/Core/Exception.h Statement.h
Statement.o: Statement.cpp Statement.h ../../../src/Core/Types.h \
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
  Connection.h \
  \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  \
  Result.h ../../../src/Core/Assert.h \
  ../../../src/Core/Exception.h ../../../src/server/Profile.h \
  ../../../src/server/Timeval.h \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  \
  \

Result.o: Result.cpp Result.h ../../../src/Core/Types.h \
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
  \
  \
  \
  ../../../src/Core/Assert.h \
  ../../../src/Core/Exception.h ../../../src/Core/StringStream.h
DatabaseManager.o: DatabaseManager.cpp \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  DatabaseManager.h \
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
  \
  \
  \
  \
  \
  \
  Connection.h \
  \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  ../../../src/Core/Types.h \
  ../../../src/Core/Exception.h ../../../src/Core/Properties.h \
  ../../../src/Core/Exception.h \
  \
  ../../../src/Core/Utility.h \
  ../../../src/server/Thread.h ../../../src/server/pthreadAPI.h \
  ../../../src/server/Timeval.h \
  \
  Result.h Statement.h \
  ../../../src/Core/Assert.h DB.h
Connection.o: Connection.cpp Connection.h ../../../src/Core/Types.h \
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
  \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  ../../../src/Core/Types.h \
  ../../../src/Core/Exception.h Statement.h
Statement.o: Statement.cpp Statement.h ../../../src/Core/Types.h \
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
  Connection.h \
  \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  \
  Result.h ../../../src/Core/Assert.h \
  ../../../src/Core/Exception.h ../../../src/server/Profile.h \
  ../../../src/server/Timeval.h \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  \
  \

Result.o: Result.cpp Result.h ../../../src/Core/Types.h \
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
  \
  \
  \
  ../../../src/Core/Assert.h \
  ../../../src/Core/Exception.h ../../../src/Core/StringStream.h
DatabaseManager.o: DatabaseManager.cpp \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  DatabaseManager.h \
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
  \
  \
  \
  \
  \
  \
  Connection.h \
  \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  ../../../src/Core/Types.h \
  ../../../src/Core/Exception.h ../../../src/Core/Properties.h \
  ../../../src/Core/Exception.h \
  \
  ../../../src/Core/Utility.h \
  ../../../src/server/Thread.h ../../../src/server/pthreadAPI.h \
  ../../../src/server/Timeval.h \
  \
  Result.h Statement.h \
  ../../../src/Core/Assert.h DB.h
Connection.o: Connection.cpp Connection.h ../../../src/Core/Types.h \
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
  \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  ../../../src/Core/Types.h \
  ../../../src/Core/Exception.h Statement.h
Statement.o: Statement.cpp Statement.h ../../../src/Core/Types.h \
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
  Connection.h \
  \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  \
  Result.h ../../../src/Core/Assert.h \
  ../../../src/Core/Exception.h ../../../src/server/Profile.h \
  ../../../src/server/Timeval.h \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  \
  \

DatabaseManager.o: DatabaseManager.cpp \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  DatabaseManager.h \
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
  \
  \
  \
  \
  \
  \
  Connection.h \
  \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  ../../../src/Core/Types.h \
  ../../../src/Core/Exception.h ../../../src/Core/Properties.h \
  ../../../src/Core/Exception.h \
  \
  ../../../src/Core/Utility.h \
  ../../../src/server/Thread.h ../../../src/server/pthreadAPI.h \
  ../../../src/server/Timeval.h \
  \
  Result.h Statement.h \
  ../../../src/Core/Assert.h DB.h
Connection.o: Connection.cpp Connection.h ../../../src/Core/Types.h \
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
  \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  ../../../src/Core/Types.h \
  ../../../src/Core/Exception.h Statement.h
Statement.o: Statement.cpp Statement.h ../../../src/Core/Types.h \
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
  Connection.h \
  \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  ../../../src/Core/Types.h ../../../src/Core/Exception.h \
  \
  Result.h ../../../src/Core/Assert.h \
  ../../../src/Core/Exception.h ../../../src/server/Profile.h \
  ../../../src/server/Timeval.h \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  \
  \

Result.o: Result.cpp Result.h ../../../src/Core/Types.h \
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
  \
  \
  \
  ../../../src/Core/Assert.h \
  ../../../src/Core/Exception.h ../../../src/Core/StringStream.h
DatabaseManager.o: DatabaseManager.cpp \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  \
  DatabaseManager.h \
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
  \
  \
  \
  \
  \
  \
  Connection.h \
  \
  \
  \
  ../../../src/server/Mutex.h \
  \
  \
  \
  ../../../src/Core/Types.h \
  ../../../src/Core/Exception.h ../../../src/Core/Properties.h \
  ../../../src/Core/Exception.h \
  \
  ../../../src/Core/Utility.h \
  ../../../src/server/Thread.h ../../../src/server/pthreadAPI.h \
  ../../../src/server/Timeval.h \
  \
  Result.h Statement.h \
  ../../../src/Core/Assert.h DB.h
