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
MYSQLDIR = /usr/lib/x86_64-linux-gnu
CPPUNITDIR = /usr/local/include/cppunit


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__GAME_SERVER__
INCLUDES = -I$(COREDIR)/compat -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(SKILLDIR) -I$(CPPUNITDIR) -I.
#CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
CCFLAGS  = -Wall -c -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

OBJS = \
	GameServerTest.o \
	GameServerTester.o \
	GameServerSkillTest.o \
	GameServerExpTest.o \
	GameServerItemTest.o \
	GameServerWarTest.o \
	GameServerSpeedCheckTest.o

SRCS = $(OBJS:.o=.cpp)

TARGET = $(LIBDIR)/libGameServerTest.a


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
GameServerTest.o: GameServerTest.cpp GameServerTest.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  TestDef.h
GameServerTester.o: GameServerTester.cpp $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Properties.h GameServerTest.h TestDef.h \
  GameServerSkillTest.h GameServerExpTest.h GameServerItemTest.h \
  GameServerSpeedCheckTest.h GameServerWarTest.h
GameServerSkillTest.o: GameServerSkillTest.cpp GameServerSkillTest.h \
  GameServerTest.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h TestDef.h \
  $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(SKILLDIR)/Skill.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(SKILLDIR)/SkillHandlerManager.h $(SKILLDIR)/SkillHandler.h \
  $(GSDIR)/SkillInfo.h $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(GSDIR)/Monster.h $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(GSDIR)/Treasure.h \
  $(GSDIR)/PrecedenceTable.h $(SKILLDIR)/HitRoll.h \
  $(SKILLDIR)/SkillUtil.h $(GSDIR)/ZoneUtil.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/gameguard/CSAuth.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h MockSkillInput.h
GameServerExpTest.o: GameServerExpTest.cpp GameServerExpTest.h \
  GameServerTest.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h TestDef.h \
  $(SKILLDIR)/SkillUtil.h $(COREDIR)/ModifyInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(SKILLDIR)/Skill.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/VariableManager.h
GameServerItemTest.o: GameServerItemTest.cpp GameServerItemTest.h \
  GameServerTest.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h TestDef.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/VariableManager.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/Vampire.h $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/InventoryInfo.h \
  $(COREDIR)/InventorySlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(SKILLDIR)/VampireSkillSlot.h \
  $(SKILLDIR)/Skill.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo2.h \
  $(COREDIR)/PCSlayerInfo3.h $(GSDIR)/ItemLoaderManager.h \
  $(GSDIR)/ItemLoader.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(SKILLDIR)/SkillSlot.h $(GSDIR)/ZoneUtil.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/ItemUtil.h
GameServerWarTest.o: GameServerWarTest.cpp GameServerWarTest.h \
  GameServerTest.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h TestDef.h \
  $(COREDIR)/VSDateTime.h
GameServerSpeedCheckTest.o: GameServerSpeedCheckTest.cpp \
  GameServerSpeedCheckTest.h GameServerTest.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  TestDef.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/SocketOutputStream.h \
  $(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/SocketInputStream.h \
  $(SERVDIR)/Mutex.h $(COREDIR)/Packet.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/gameguard/CSAuth.h $(COREDIR)/Cpackets/CGVerifyTime.h
