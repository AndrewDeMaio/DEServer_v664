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
BINDIR   = $(VSHOME)/bin
LIBDIR   = $(VSHOME)/lib
LOGDIR   = $(VSHOME)/log
SRCDIR   = ../../..
COREDIR  = ../../../Core
SERVDIR  = ../..
DBDIR    = ../../database
SKILLDIR = ../skill
GSDIR    = ..
WARDIR	 = ../war
MYSQLDIR = /usr/lib/x86_64-linux-gnu
CPPUNITDIR = /usr/local/include/cppunit


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__GAME_SERVER__
INCLUDES = -I$(COREDIR)/compat -I. -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(SKILLDIR) -I$(CPPUNITDIR) -I$(WARDIR)
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
LIBS	 = #-L$(LIBDIR) -lWar
SYSLIBS  = -lcppunit

.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

OBJS = \
	main.o \
#	Scheduler.o \
#	Schedule.o \
#	VSDateTime.o \
#	StringStream.o \
#	ScheduleTest.o

SRCS = $(OBJS:.o=.cpp)

TARGET = testAlone


#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
all : 
	$(MAKE) $(TARGET)

$(TARGET) : $(OBJS) #$(LIBDIR)/libWar.a
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
main.o: main.cpp $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h ScheduleTest.h \
  TestDef.h
Scheduler.o: Scheduler.cpp Scheduler.h $(COREDIR)/Exception.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/Utility.h \
  $(COREDIR)/StringStream.h Work.h Schedule.h VSDateTime.h \
  $(COREDIR)/Assert.h
Schedule.o: Schedule.cpp $(COREDIR)/Exception.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/Utility.h $(COREDIR)/StringStream.h Work.h Schedule.h \
  VSDateTime.h
VSDateTime.o: VSDateTime.cpp VSDateTime.h
ScheduleTest.o: ScheduleTest.cpp ScheduleTest.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  TestDef.h Work.h Schedule.h VSDateTime.h Scheduler.h
