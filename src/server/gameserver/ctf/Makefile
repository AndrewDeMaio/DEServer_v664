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
SRCDIR   = ../../..
COREDIR  = ../../../Core
SERVDIR  = ../..
DBDIR    = ../../database
GSDIR    = ..
WARDIR   = ../war
MYSQLDIR = /usr/lib/x86_64-linux-gnu


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__GAME_SERVER__
INCLUDES = -I$(COREDIR)/compat -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(WARDIR) -I.
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

OBJS = \
	FlagManager.o \
	FlagWar.o \
	NewbieFlagWar.o

SRCS = $(OBJS:.o=.cpp)

TARGET = $(LIBDIR)/libCTF.a


#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
all : $(TARGET)

$(TARGET) : $(OBJS)
	ar rc $@ $^

clean :
	rm -rf *.o

cleanall :
	rm -rf *.o $(TARGET)

depall :
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)
# DO NOT DELETE
FlagManager.o: FlagManager.cpp FlagManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(WARDIR)/Work.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h \
  $(COREDIR)/VSDateTime.h $(SERVDIR)/Mutex.h $(COREDIR)/Assert.h \
  $(COREDIR)/Gpackets/GCFlagWarStatus.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h FlagWar.h \
  NewbieFlagWar.h $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(GSDIR)/ObjectRegistry.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  $(GSDIR)/MonsterCorpse.h $(GSDIR)/ItemFactory.h $(GSDIR)/Inventory.h \
  $(GSDIR)/VolumeInfo.h $(GSDIR)/Corpse.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneUtil.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(COREDIR)/Properties.h $(COREDIR)/Player.h \
  $(GSDIR)/EffectFlagInsert.h $(COREDIR)/NPCInfo.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(COREDIR)/Gpackets/GCAddEffect.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
FlagWar.o: FlagWar.cpp FlagWar.h $(WARDIR)/Work.h $(COREDIR)/Exception.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/StringStream.h $(COREDIR)/VSDateTime.h FlagManager.h \
  $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/Assert.h $(COREDIR)/Gpackets/GCFlagWarStatus.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(GSDIR)/ItemFactory.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Creature.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneUtil.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/GlobalItemPositionLoader.h $(WARDIR)/GlobalItemPosition.h \
  $(GSDIR)/MonsterSummonInfo.h $(GSDIR)/MonsterInfoTypes.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/Gpackets/GCNoticeEvent.h
NewbieFlagWar.o: NewbieFlagWar.cpp NewbieFlagWar.h FlagWar.h \
  $(WARDIR)/Work.h $(COREDIR)/Exception.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/StringStream.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/ZoneUtil.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneInfoManager.h \
  $(GSDIR)/ZoneInfo.h FlagManager.h $(WARDIR)/Scheduler.h \
  $(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCFlagWarStatus.h \
  $(COREDIR)/PacketFactory.h
