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
	PartnerWaitingManager.o \
	CoupleManager.o \
	WaitForMeet.o \
	WaitForApart.o

SRCS = $(OBJS:.o=.cpp)

TARGET = $(LIBDIR)/libCouple.a


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
PartnerWaitingManager.o: PartnerWaitingManager.cpp \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
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
  $(COREDIR)/SubItemInfo.h $(GSDIR)/PCFinder.h $(GSDIR)/NPC.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h WaitForMeet.h \
  PartnerWaitingManager.h WaitForApart.h $(GSDIR)/VariableManager.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
CoupleManager.o: CoupleManager.cpp $(DBDIR)/DatabaseManager.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(DBDIR)/Connection.h \
  $(SERVDIR)/Mutex.h $(DBDIR)/DB.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h CoupleManager.h
WaitForMeet.o: WaitForMeet.cpp $(COREDIR)/Assert.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Player.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/SocketOutputStream.h \
  $(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/SocketInputStream.h \
  $(SERVDIR)/Mutex.h $(COREDIR)/Packet.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(GSDIR)/skill/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(GSDIR)/Effect.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(GSDIR)/Inventory.h \
  $(GSDIR)/VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/ItemNameInfo.h $(GSDIR)/FlagSet.h $(GSDIR)/StringPool.h \
  WaitForMeet.h PartnerWaitingManager.h CoupleManager.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/item/CoupleRing.h \
  $(GSDIR)/item/CoupleRingBase.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/item/VampireCoupleRing.h $(GSDIR)/ItemFactoryManager.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
WaitForApart.o: WaitForApart.cpp $(COREDIR)/Assert.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Player.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
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
  $(GSDIR)/skill/OustersSkillSlot.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/ItemNameInfo.h $(GSDIR)/FlagSet.h $(GSDIR)/StringPool.h \
  WaitForApart.h PartnerWaitingManager.h CoupleManager.h \
  $(GSDIR)/item/CoupleRing.h $(GSDIR)/item/CoupleRingBase.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/item/VampireCoupleRing.h $(GSDIR)/ItemFactoryManager.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(COREDIR)/Gpackets/GCRemoveFromGear.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
