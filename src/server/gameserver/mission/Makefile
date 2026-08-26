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
	QuestInfo.o \
	MonsterKillQuestInfo.o \
	GatherItemQuestInfo.o \
	MeetNPCQuestInfo.o \
	RewardClass.o \
	RandomRewardClass.o \
	SlayerWeaponRewardClass.o \
	AnotherQuestRewardClass.o \
	RewardInfo.o \
	ItemRewardInfo.o \
	QuestAdvanceRewardInfo.o \
	AnotherQuestRewardInfo.o \
	MiniGameQuestInfo.o \
	QuestInfoManager.o \
	SimpleQuestInfoManager.o \
	EventQuestInfoManager.o \
	RewardClassInfoManager.o \
	SimpleQuestRewardManager.o \
	QuestManager.o \
	QuestStatus.o \
	MonsterKillQuestStatus.o \
	GatherItemQuestStatus.o \
	DummyQuestStatus.o \
	MeetNPCQuestStatus.o \
	MiniGameQuestStatus.o \
	EventQuestAdvance.o \
	EventQuestLootingManager.o

SRCS = $(OBJS:.o=.cpp)

TARGET = $(LIBDIR)/libMission.a

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
QuestInfo.o: QuestInfo.cpp QuestInfo.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h RewardClass.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  QuestManager.h QuestStatus.h $(COREDIR)/VSDateTime.h \
  EventQuestAdvance.h $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(GSDIR)/Slayer.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
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
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h
MonsterKillQuestInfo.o: MonsterKillQuestInfo.cpp MonsterKillQuestInfo.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h QuestInfo.h \
  $(COREDIR)/Assert.h RewardClass.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  MonsterKillQuestStatus.h QuestStatus.h $(COREDIR)/VSDateTime.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
GatherItemQuestInfo.o: GatherItemQuestInfo.cpp GatherItemQuestStatus.h \
  QuestStatus.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Assert.h QuestInfo.h RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h GatherItemQuestInfo.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
MeetNPCQuestInfo.o: MeetNPCQuestInfo.cpp MeetNPCQuestInfo.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h QuestInfo.h \
  $(COREDIR)/Assert.h RewardClass.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  MeetNPCQuestStatus.h QuestStatus.h $(COREDIR)/VSDateTime.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
RewardClass.o: RewardClass.cpp RewardClass.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  RewardInfo.h $(COREDIR)/Assert.h
RandomRewardClass.o: RandomRewardClass.cpp RandomRewardClass.h \
  RewardClass.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  RewardInfo.h $(COREDIR)/Assert.h
SlayerWeaponRewardClass.o: SlayerWeaponRewardClass.cpp \
  SlayerWeaponRewardClass.h RewardClass.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Slayer.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
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
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(GSDIR)/skill/OustersSkillSlot.h \
  ItemRewardInfo.h RewardInfo.h $(GSDIR)/ItemUtil.h
AnotherQuestRewardClass.o: AnotherQuestRewardClass.cpp \
  AnotherQuestRewardClass.h RewardClass.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  RewardInfo.h $(COREDIR)/Assert.h
RewardInfo.o: RewardInfo.cpp RewardInfo.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h
ItemRewardInfo.o: ItemRewardInfo.cpp ItemRewardInfo.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h RewardInfo.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/PacketFactory.h \
  RewardClass.h $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(COREDIR)/Player.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(GSDIR)/ItemUtil.h $(GSDIR)/PacketUtil.h $(COREDIR)/PetInfo.h \
  $(COREDIR)/types/PetTypes.h $(GSDIR)/item/PetItem.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/PetTypeInfo.h \
  $(COREDIR)/Gpackets/GCCreateItem.h
QuestAdvanceRewardInfo.o: QuestAdvanceRewardInfo.cpp \
  QuestAdvanceRewardInfo.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h RewardInfo.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/PacketFactory.h \
  QuestManager.h QuestInfo.h RewardClass.h QuestStatus.h \
  $(COREDIR)/VSDateTime.h EventQuestAdvance.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
AnotherQuestRewardInfo.o: AnotherQuestRewardInfo.cpp \
  AnotherQuestRewardInfo.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h RewardInfo.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/PacketFactory.h \
  QuestManager.h QuestInfo.h RewardClass.h QuestStatus.h \
  $(COREDIR)/VSDateTime.h $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
MiniGameQuestInfo.o: MiniGameQuestInfo.cpp MiniGameQuestInfo.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h QuestInfo.h \
  $(COREDIR)/Assert.h RewardClass.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  MiniGameQuestStatus.h QuestStatus.h $(COREDIR)/VSDateTime.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h
QuestInfoManager.o: QuestInfoManager.cpp QuestInfoManager.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h QuestInfo.h \
  $(COREDIR)/Assert.h RewardClass.h ItemRewardInfo.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h RewardInfo.h \
  MonsterKillQuestInfo.h MonsterKillQuestStatus.h QuestStatus.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Gpackets/GCQuestStatus.h \
  GatherItemQuestInfo.h GatherItemQuestStatus.h QuestManager.h \
  EventQuestAdvance.h $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(GSDIR)/NPC.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/VariableManager.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
SimpleQuestInfoManager.o: SimpleQuestInfoManager.cpp \
  SimpleQuestInfoManager.h QuestInfoManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h QuestInfo.h \
  $(COREDIR)/Assert.h RewardClass.h RewardClassInfoManager.h \
  MonsterKillQuestInfo.h MonsterKillQuestStatus.h QuestStatus.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Gpackets/GCQuestStatus.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EventQuestInfoManager.o: EventQuestInfoManager.cpp \
  EventQuestInfoManager.h QuestInfoManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h QuestInfo.h \
  $(COREDIR)/Assert.h RewardClass.h RewardClassInfoManager.h \
  MonsterKillQuestInfo.h MonsterKillQuestStatus.h QuestStatus.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Gpackets/GCQuestStatus.h \
  GatherItemQuestInfo.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h GatherItemQuestStatus.h MeetNPCQuestInfo.h \
  MeetNPCQuestStatus.h MiniGameQuestInfo.h MiniGameQuestStatus.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
RewardClassInfoManager.o: RewardClassInfoManager.cpp \
  RewardClassInfoManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  RandomRewardClass.h RewardClass.h SlayerWeaponRewardClass.h \
  ItemRewardInfo.h $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h RewardInfo.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
SimpleQuestRewardManager.o: SimpleQuestRewardManager.cpp \
  SimpleQuestRewardManager.h RewardClassInfoManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h RandomRewardClass.h RewardClass.h \
  SlayerWeaponRewardClass.h ItemRewardInfo.h RewardInfo.h
QuestManager.o: QuestManager.cpp QuestManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  QuestInfo.h $(COREDIR)/Assert.h RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  QuestStatus.h $(COREDIR)/VSDateTime.h MonsterKillQuestStatus.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h GatherItemQuestStatus.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  MeetNPCQuestStatus.h MiniGameQuestStatus.h QuestInfoManager.h \
  EventQuestAdvance.h $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
  $(GSDIR)/Monster.h $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(GSDIR)/Treasure.h \
  $(GSDIR)/PrecedenceTable.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/VariableManager.h
QuestStatus.o: QuestStatus.cpp QuestStatus.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Assert.h QuestInfo.h RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  QuestManager.h
MonsterKillQuestStatus.o: MonsterKillQuestStatus.cpp \
  MonsterKillQuestStatus.h QuestStatus.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Assert.h QuestInfo.h RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h
GatherItemQuestStatus.o: GatherItemQuestStatus.cpp \
  GatherItemQuestStatus.h QuestStatus.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Assert.h QuestInfo.h RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h QuestInfoManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h \
  $(GSDIR)/VolumeInfo.h
DummyQuestStatus.o: DummyQuestStatus.cpp DummyQuestStatus.h \
  QuestStatus.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Assert.h QuestInfo.h RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h
MeetNPCQuestStatus.o: MeetNPCQuestStatus.cpp MeetNPCQuestStatus.h \
  QuestStatus.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Assert.h QuestInfo.h RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h
MiniGameQuestStatus.o: MiniGameQuestStatus.cpp MiniGameQuestStatus.h \
  QuestStatus.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Assert.h QuestInfo.h RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(GSDIR)/Slayer.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
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
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h $(COREDIR)/Player.h \
  $(GSDIR)/PacketUtil.h $(COREDIR)/Gpackets/GCMiniGameScores.h
EventQuestAdvance.o: EventQuestAdvance.cpp EventQuestAdvance.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h
EventQuestLootingManager.o: EventQuestLootingManager.cpp \
  EventQuestLootingManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Monster.h $(GSDIR)/Creature.h \
  $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(GSDIR)/Treasure.h \
  $(GSDIR)/PrecedenceTable.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Slayer.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
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
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h EventQuestAdvance.h QuestManager.h \
  QuestInfo.h RewardClass.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  QuestStatus.h
