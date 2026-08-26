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
MYSQLDIR = /usr/lib/x86_64-linux-gnu


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__GAME_SERVER__
INCLUDES = -I$(COREDIR)/compat -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I.
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

OBJS = \
	Schedule.o \
	Scheduler.o \
	War.o \
	RaceWar.o \
	GuildWar.o \
	SiegeWar.o \
	WarSchedule.o \
	WarScheduler.o \
	WarSystem.o \
	ZoneItemPosition.o \
	InventoryItemPosition.o \
	MouseItemPosition.o \
	CorpseItemPosition.o \
	RaceWarLimiter.o \
	DragonEyeManager.o \
	SubInventoryItemPosition.o

SRCS = $(OBJS:.o=.cpp)

TARGET = $(LIBDIR)/libWar.a


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
Schedule.o: Schedule.cpp $(COREDIR)/Exception.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/StringStream.h Work.h Schedule.h \
  $(COREDIR)/VSDateTime.h
Scheduler.o: Scheduler.cpp Scheduler.h $(COREDIR)/Exception.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/StringStream.h Work.h Schedule.h $(COREDIR)/VSDateTime.h \
  $(COREDIR)/Assert.h
War.o: War.cpp War.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h Work.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/VSDateTime.h $(SERVDIR)/Mutex.h WarSystem.h Scheduler.h \
  Schedule.h $(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
  $(COREDIR)/RaceWarInfo.h $(COREDIR)/Properties.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(COREDIR)/Assert.h $(GSDIR)/ZoneGroupManager.h \
  $(GSDIR)/ZoneGroup.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Object.h \
  $(GSDIR)/Creature.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(GSDIR)/Item.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(GSDIR)/HolyLandRaceBonus.h $(GSDIR)/ZoneUtil.h \
  $(GSDIR)/CastleInfoManager.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  $(GSDIR)/ShrineInfoManager.h $(GSDIR)/ZoneInfoManager.h \
  $(GSDIR)/ZoneInfo.h $(GSDIR)/StringPool.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNoticeEvent.h
RaceWar.o: RaceWar.cpp RaceWar.h War.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h Work.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h $(COREDIR)/VSDateTime.h $(SERVDIR)/Mutex.h \
  WarSystem.h Scheduler.h Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
  $(COREDIR)/RaceWarInfo.h $(COREDIR)/Properties.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(COREDIR)/Assert.h $(GSDIR)/ZoneGroupManager.h \
  $(GSDIR)/ZoneGroup.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Object.h \
  $(GSDIR)/Creature.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(GSDIR)/Item.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(GSDIR)/ZoneUtil.h $(GSDIR)/CastleInfoManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  $(GSDIR)/ShrineInfoManager.h $(GSDIR)/ZoneInfoManager.h \
  $(GSDIR)/ZoneInfo.h $(COREDIR)/Gpackets/GCWarScheduleList.h \
  $(GSDIR)/HolyLandManager.h $(GSDIR)/VariableManager.h RaceWarLimiter.h \
  $(GSDIR)/PCLimiter.h $(GSDIR)/RegenZoneManager.h \
  $(GSDIR)/MonsterCorpse.h $(GSDIR)/ItemFactory.h $(GSDIR)/Inventory.h \
  $(GSDIR)/VolumeInfo.h $(GSDIR)/Corpse.h DragonEyeManager.h \
  $(GSDIR)/item/WarItem.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNoticeEvent.h $(COREDIR)/Cpackets/CGSay.h \
  $(GSDIR)/HeroItemManager.h
GuildWar.o: GuildWar.cpp $(GSDIR)/Guild.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Assert.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h $(SERVDIR)/Mutex.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/GuildManager.h $(SERVDIR)/Timeval.h GuildWar.h War.h Work.h \
  WarSystem.h Scheduler.h Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
  $(COREDIR)/RaceWarInfo.h $(COREDIR)/Properties.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneGroup.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Object.h $(GSDIR)/Creature.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(COREDIR)/EffectInfo.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(GSDIR)/HolyLandRaceBonus.h $(GSDIR)/ZoneUtil.h \
  $(GSDIR)/CastleInfoManager.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  $(GSDIR)/CastleShrineInfoManager.h $(GSDIR)/ShrineInfoManager.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZoneInfo.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNoticeEvent.h \
  $(COREDIR)/Gpackets/GCWarScheduleList.h $(COREDIR)/Cpackets/CGSay.h
SiegeWar.o: SiegeWar.cpp $(GSDIR)/Guild.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Assert.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h $(SERVDIR)/Mutex.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/GuildManager.h $(SERVDIR)/Timeval.h SiegeWar.h War.h Work.h \
  WarSystem.h Scheduler.h Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
  $(COREDIR)/RaceWarInfo.h $(COREDIR)/Properties.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneGroup.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Object.h $(GSDIR)/Creature.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(COREDIR)/EffectInfo.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(GSDIR)/HolyLandRaceBonus.h $(GSDIR)/ZoneUtil.h \
  $(GSDIR)/CastleInfoManager.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZoneInfo.h $(GSDIR)/SiegeManager.h \
  $(SERVDIR)/GameServerInfoManager.h $(SERVDIR)/GameServerInfo.h \
  $(GSDIR)/LoginServerManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(COREDIR)/DatagramSocket.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNoticeEvent.h \
  $(COREDIR)/Gpackets/GCWarScheduleList.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Cpackets/CGSay.h \
  $(COREDIR)/Gpackets/GGCommand.h
WarSchedule.o: WarSchedule.cpp WarSchedule.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h Work.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h Schedule.h $(COREDIR)/VSDateTime.h War.h \
  $(GSDIR)/GuildManager.h $(COREDIR)/Assert.h $(SERVDIR)/Mutex.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/Properties.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Object.h \
  $(GSDIR)/Creature.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/CastleInfoManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h GuildWar.h SiegeWar.h \
  $(COREDIR)/Gpackets/GCWarScheduleList.h \
  $(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/GuildWarInfo.h \
  $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h
WarScheduler.o: WarScheduler.cpp WarSchedule.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h Work.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h Schedule.h $(COREDIR)/VSDateTime.h War.h \
  WarScheduler.h Scheduler.h $(SERVDIR)/Mutex.h $(COREDIR)/Assert.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Object.h $(GSDIR)/Creature.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/Properties.h GuildWar.h \
  SiegeWar.h $(GSDIR)/VariableManager.h \
  $(COREDIR)/Gpackets/GCWarScheduleList.h $(COREDIR)/PacketFactory.h \
  WarSystem.h $(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/GuildWarInfo.h \
  $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h
WarSystem.o: WarSystem.cpp WarSystem.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(SERVDIR)/Mutex.h Scheduler.h Work.h Schedule.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Gpackets/GCWarList.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
  $(COREDIR)/RaceWarInfo.h $(COREDIR)/Assert.h War.h RaceWar.h \
  WarSchedule.h WarScheduler.h $(COREDIR)/Player.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h \
  $(GSDIR)/Event.h $(GSDIR)/skill/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(GSDIR)/Effect.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ZoneGroupManager.h \
  $(GSDIR)/ZoneGroup.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Creature.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(GSDIR)/CastleInfoManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCWarScheduleList.h \
  $(COREDIR)/Gpackets/GCNoticeEvent.h $(GSDIR)/VariableManager.h \
  GuildWar.h SiegeWar.h $(GSDIR)/EventRefreshHolyLandPlayer.h \
  $(GSDIR)/ShrineInfoManager.h $(GSDIR)/ClientManager.h \
  $(GSDIR)/HolyLandManager.h $(GSDIR)/StringPool.h
ZoneItemPosition.o: ZoneItemPosition.cpp $(COREDIR)/Assert.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Corpse.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Creature.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h $(GSDIR)/ZoneUtil.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Gpackets/GCDeleteObject.h \
  $(COREDIR)/Gpackets/GCAddEffectToTile.h ZoneItemPosition.h \
  GlobalItemPosition.h
InventoryItemPosition.o: InventoryItemPosition.cpp $(COREDIR)/Assert.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h $(GSDIR)/PCFinder.h \
  $(GSDIR)/NPC.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/ZoneGroup.h \
  $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
  $(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/RelicUtil.h InventoryItemPosition.h \
  GlobalItemPosition.h $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(COREDIR)/Gpackets/GCAddEffect.h
MouseItemPosition.o: MouseItemPosition.cpp $(COREDIR)/Assert.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h $(GSDIR)/PCFinder.h \
  $(GSDIR)/NPC.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/ZoneGroup.h \
  $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
  $(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h $(GSDIR)/ZoneUtil.h \
  $(GSDIR)/RelicUtil.h $(GSDIR)/CreatureUtil.h MouseItemPosition.h \
  GlobalItemPosition.h $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(COREDIR)/Gpackets/GCAddEffect.h
CorpseItemPosition.o: CorpseItemPosition.cpp $(COREDIR)/Assert.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Object.h $(GSDIR)/Creature.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h $(GSDIR)/Corpse.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/MonsterCorpse.h $(GSDIR)/Inventory.h \
  $(GSDIR)/VolumeInfo.h $(GSDIR)/InventorySlot.h $(GSDIR)/ZoneUtil.h \
  $(COREDIR)/VSDateTime.h $(GSDIR)/ItemUtil.h $(GSDIR)/RelicUtil.h \
  $(GSDIR)/ItemFactoryManager.h CorpseItemPosition.h \
  GlobalItemPosition.h $(COREDIR)/Gpackets/GCAddEffectToTile.h \
  $(GSDIR)/ctf/FlagManager.h $(GSDIR)/war/Work.h \
  $(GSDIR)/war/Scheduler.h $(GSDIR)/war/Schedule.h \
  $(COREDIR)/Gpackets/GCFlagWarStatus.h
RaceWarLimiter.o: RaceWarLimiter.cpp RaceWarLimiter.h \
  $(GSDIR)/PCLimiter.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(GSDIR)/skill/Skill.h $(GSDIR)/skill/SlayerSkillSlot.h \
  $(GSDIR)/skill/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(GSDIR)/skill/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(GSDIR)/skill/OustersSkillSlot.h
DragonEyeManager.o: DragonEyeManager.cpp DragonEyeManager.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(GSDIR)/item/WarItem.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ZoneUtil.h $(GSDIR)/Creature.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/GlobalItemPositionLoader.h \
  GlobalItemPosition.h $(GSDIR)/EffectDragonEye.h \
  $(GSDIR)/EffectHasRelic.h
SubInventoryItemPosition.o: SubInventoryItemPosition.cpp \
  $(COREDIR)/Assert.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h $(GSDIR)/PCFinder.h \
  $(GSDIR)/NPC.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/ZoneGroup.h \
  $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
  $(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h \
  $(GSDIR)/item/SubInventory.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/CreatureUtil.h $(GSDIR)/RelicUtil.h \
  SubInventoryItemPosition.h GlobalItemPosition.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(COREDIR)/Gpackets/GCAddEffect.h
