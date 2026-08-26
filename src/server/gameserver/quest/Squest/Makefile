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
#VSHOME   = ../../../../..
STLDIR   = /usr/include/STL
BINDIR   = $(VSHOME)/bin
LIBDIR   = $(VSHOME)/lib
LOGDIR   = $(VSHOME)/log
SRCDIR   = ../../../..
COREDIR  = ../../../../Core
SERVDIR  = ../../..
DBDIR    = ../../../database
MYSQLDIR = /usr/lib/x86_64-linux-gnu
GSDIR    = ../..
SKILLDIR = ../../skill
ITEMDIR  = ../../item
QUESTDIR  = ..


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__GAME_SERVER__ 
#-D__QUEST_TEST__
INCLUDES = -I$(COREDIR)/compat -I$(STLDIR) -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(SKILLDIR) -I$(ITEMDIR) -I$(QUESTDIR) -I.
CCFLAGS  = -Wall -c -g  -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c

#LIBS     = -L$(LIBDIR) -lGameServerDatabase -lServerCore -lGameServerPackets -lCore
#SYSLIBS  = -L$(MYSQLDIR) -static -lpthread -lnsl -lmysqlclient -lz


.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

SIMPLE_QUEST_OBJS = MonsterKillQuest.o  \
					QuestFactoryManager.o \
					Quest.o \
					QuestManager.o \
					QuestBoard.o  \
					QuestPrice.o \
					QuestPriceReward.o \
					QuestPricePenalty.o \
					SimpleQuest.o \
					SimpleQuestLoader.o \
					QuestEvent.o \
					MonsterSelector.o

#							\
					main.o \
					FakeMonsterInfo.o
					              
OBJS = $(SIMPLE_QUEST_OBJS)


SRCS = $(OBJS:.o=.cpp)

TARGET   = $(LIBDIR)/libSimpleQuest.a
#TARGET = qt


#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
all : $(TARGET)

$(TARGET) : $(OBJS)
	ar rc $@ $^

#$(TARGET) : $(OBJS) $(LIBDIR)/libGameServerDatabase.a $(LIBDIR)/libCore.a $(LIBDIR)/libServerCore.a $(LIBDIR)/libGameServerPackets.a
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
MonsterKillQuest.o: MonsterKillQuest.cpp ../../MonsterInfo.h \
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
  ../../../../Core/Utility.h ../../../../Core/Exception.h \
  ../../../../Core/StringStream.h \
  ../../../../Core/Assert.h \
  ../../Creature.h ../../Object.h ../../EffectManager.h ../../Effect.h \
  ../../../Timeval.h \
  \
  ../../../../Core/EffectInfo.h \
  ../../../../Core/Packet.h ../../../../Core/SocketInputStream.h \
  ../../../../Core/Socket.h ../../../../Core/SocketImpl.h \
  ../../../../Core/SocketAPI.h ../../../../Core/SocketOutputStream.h \
  ../../VisionInfo.h ../../MonsterSummonInfo.h \
  ../../MonsterInfoTypes.h \
  \
  ../../Treasure.h ../../Item.h \
  \
  MonsterKillQuest.h SimpleQuest.h \
  Quest.h QuestPrice.h QuestFactoryManager.h QuestUtil.h \
  MonsterSelector.h QuestPriceReward.h QuestPricePenalty.h \
  QuestEventMonsterKill.h QuestEvent.h ../../../database/DB.h \
  ../../../database/DatabaseManager.h ../../../database/Connection.h \
  \
  ../../../Mutex.h \
  \
  \
  ../../../database/Statement.h ../../../database/Result.h
QuestFactoryManager.o: QuestFactoryManager.cpp QuestFactoryManager.h \
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
  ../../../../Core/Utility.h ../../../../Core/Exception.h \
  ../../../../Core/StringStream.h \
  Quest.h MonsterKillQuest.h SimpleQuest.h \
  ../../../Timeval.h \
  \
  ../../Creature.h ../../Object.h \
  ../../../../Core/Assert.h ../../EffectManager.h ../../Effect.h \
  ../../../../Core/EffectInfo.h ../../../../Core/Packet.h \
  ../../../../Core/SocketInputStream.h ../../../../Core/Socket.h \
  ../../../../Core/SocketImpl.h ../../../../Core/SocketAPI.h \
  ../../../../Core/SocketOutputStream.h ../../VisionInfo.h \
  QuestPrice.h QuestUtil.h MonsterSelector.h \
  \

Quest.o: Quest.cpp Quest.h ../../../../Core/Types.h \
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
  ../../../../Core/Utility.h ../../../../Core/Exception.h \
  ../../../../Core/StringStream.h \

QuestManager.o: QuestManager.cpp Quest.h ../../../../Core/Types.h \
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
  ../../../../Core/Utility.h ../../../../Core/Exception.h \
  ../../../../Core/StringStream.h \
  QuestManager.h
QuestBoard.o: QuestBoard.cpp Quest.h ../../../../Core/Types.h \
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
  ../../../../Core/Utility.h ../../../../Core/Exception.h \
  ../../../../Core/StringStream.h \
  QuestUtil.h QuestBoard.h \
  \
  \
  QuestFactoryManager.h ../../../../Core/Gpackets/GCNPCAskDynamic.h \
  ../../../../Core/Packet.h ../../../../Core/SocketInputStream.h \
  ../../../../Core/Socket.h ../../../../Core/SocketImpl.h \
  ../../../../Core/SocketAPI.h ../../../../Core/SocketOutputStream.h \
  ../../../../Core/PacketFactory.h ../../Script.h \
  ../../../../Core/Assert.h
QuestPrice.o: QuestPrice.cpp QuestPrice.h ../../../../Core/Types.h \
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
  ../../../../Core/Utility.h ../../../../Core/Exception.h \
  ../../../../Core/StringStream.h \

QuestPriceReward.o: QuestPriceReward.cpp QuestPriceReward.h \
  QuestPrice.h ../../../../Core/Types.h \
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
  ../../../../Core/Utility.h ../../../../Core/Exception.h \
  ../../../../Core/StringStream.h \
  ../../Creature.h ../../Object.h \
  ../../../../Core/Assert.h ../../EffectManager.h ../../Effect.h \
  ../../../Timeval.h \
  \
  ../../../../Core/EffectInfo.h \
  ../../../../Core/Packet.h ../../../../Core/SocketInputStream.h \
  ../../../../Core/Socket.h ../../../../Core/SocketImpl.h \
  ../../../../Core/SocketAPI.h ../../../../Core/SocketOutputStream.h \
  ../../VisionInfo.h
QuestPricePenalty.o: QuestPricePenalty.cpp QuestPricePenalty.h \
  QuestPrice.h ../../../../Core/Types.h \
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
  ../../../../Core/Utility.h ../../../../Core/Exception.h \
  ../../../../Core/StringStream.h \
  ../../Creature.h ../../Object.h \
  ../../../../Core/Assert.h ../../EffectManager.h ../../Effect.h \
  ../../../Timeval.h \
  \
  ../../../../Core/EffectInfo.h \
  ../../../../Core/Packet.h ../../../../Core/SocketInputStream.h \
  ../../../../Core/Socket.h ../../../../Core/SocketImpl.h \
  ../../../../Core/SocketAPI.h ../../../../Core/SocketOutputStream.h \
  ../../VisionInfo.h
SimpleQuest.o: SimpleQuest.cpp SimpleQuest.h ../../../../Core/Types.h \
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
  ../../../../Core/Utility.h ../../../../Core/Exception.h \
  ../../../../Core/StringStream.h \
  Quest.h ../../../Timeval.h \
  \
  \
  ../../Creature.h ../../Object.h \
  ../../../../Core/Assert.h ../../EffectManager.h ../../Effect.h \
  ../../../../Core/EffectInfo.h ../../../../Core/Packet.h \
  ../../../../Core/SocketInputStream.h ../../../../Core/Socket.h \
  ../../../../Core/SocketImpl.h ../../../../Core/SocketAPI.h \
  ../../../../Core/SocketOutputStream.h ../../VisionInfo.h \
  QuestPrice.h QuestPriceReward.h \
  QuestPricePenalty.h ../../../database/DB.h \
  ../../../database/DatabaseManager.h \
  \
  ../../../database/Connection.h \
  \
  ../../../Mutex.h \
  \
  \
  ../../../database/Statement.h ../../../database/Result.h
SimpleQuestLoader.o: SimpleQuestLoader.cpp SimpleQuestLoader.h \
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
  ../../../../Core/Utility.h ../../../../Core/Exception.h \
  ../../../../Core/StringStream.h \
  Quest.h ../../../../Core/Assert.h \
  ../../../database/DB.h ../../../database/DatabaseManager.h \
  \
  \
  ../../../database/Connection.h \
  \
  ../../../Mutex.h \
  \
  \
  ../../../database/Statement.h ../../../database/Result.h \
  ../../Creature.h ../../Object.h \
  ../../EffectManager.h ../../Effect.h ../../../Timeval.h \
  \
  \
  ../../../../Core/EffectInfo.h ../../../../Core/Packet.h \
  ../../../../Core/SocketInputStream.h ../../../../Core/Socket.h \
  ../../../../Core/SocketImpl.h ../../../../Core/SocketAPI.h \
  ../../../../Core/SocketOutputStream.h ../../VisionInfo.h \
  ../../PlayerCreature.h ../../ObjectRegistry.h \
  ../../InventorySlot.h ../../Item.h \
  \
  ../../Garbage.h ../../RankBonus.h ../../TimeLimitItemManager.h \
  ../../../../Core/VSDateTime.h SimpleQuest.h QuestPrice.h \
  QuestFactoryManager.h
QuestEvent.o: QuestEvent.cpp QuestEvent.h ../../../../Core/Types.h \
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
  ../../../../Core/Utility.h ../../../../Core/Exception.h \
  ../../../../Core/StringStream.h \
  Quest.h
MonsterSelector.o: MonsterSelector.cpp MonsterSelector.h \
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
  ../../../../Core/Utility.h ../../../../Core/Exception.h \
  ../../../../Core/StringStream.h \
  ../../../../Core/Assert.h
