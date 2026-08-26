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

#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT
INCLUDES = -I$(COREDIR)/compat -I/usr/include/lua5.1 -I$(COREDIR) -I$(SERVDIR) -I$(GSDIR) -I$(DBDIR)
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#LIBS     = -L$(LIBDIR) -lItems -lQuest -lGameServerDatabase -lServerCore -lGameServerPackets -lSkill -lCore -lGameServerBilling -lSimpleQuest
#SYSLIBS  = -llua5.1 -llualib

.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

#main.o 
OBJS = lua_tinker.o \
		DEScript.o \
		DEScriptZone.o \
		DEScriptEffect.o \
		DEScriptSkill.o

SRCS = $(OBJS:.o=.cpp)

#TARGET = lt
TARGET = $(LIBDIR)/libDEScript.a

all : $(TARGET)
	$(MAKE)	$(TARGET)

$(TARGET) : $(OBJS)
#	$(CC) -o $@ $(OBJS) $(SYSLIBS)
	ar r $@ $(OBJS)

clean :
	rm -f *.o

cleanall :
	rm -f *.o $(TARGET)

depall :
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)


# DO NOT DELETE
lua_tinker.o: lua_tinker.cpp lua_tinker.h $(COREDIR)/Exception.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/StringStream.h
DEScript.o: DEScript.cpp DEScript.h lua_tinker.h $(COREDIR)/Exception.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/StringStream.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Monster.h \
  $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(GSDIR)/Treasure.h $(GSDIR)/Item.h \
  $(GSDIR)/PrecedenceTable.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Player.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/PCFinder.h $(GSDIR)/NPC.h \
  $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/ZoneGroupManager.h \
  $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h
DEScriptZone.o: DEScriptZone.cpp $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/Creature.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneUtil.h \
  $(COREDIR)/VSDateTime.h $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h $(GSDIR)/Monster.h \
  $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(GSDIR)/Treasure.h \
  $(GSDIR)/PrecedenceTable.h $(GSDIR)/MonsterManager.h \
  $(GSDIR)/MonsterCounter.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(GSDIR)/skill/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h \
  $(GSDIR)/VolumeInfo.h $(GSDIR)/ItemUtil.h $(GSDIR)/Directive.h \
  $(GSDIR)/MonsterAI.h $(COREDIR)/Properties.h DEScriptZone.h DEScript.h \
  lua_tinker.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(GSDIR)/EffectScript.h $(GSDIR)/script/DEScriptEffect.h \
  $(GSDIR)/script/DEScript.h $(GSDIR)/EventTransport.h \
  $(GSDIR)/InstanceDoungeonManager.h $(GSDIR)/DynamicZoneManager.h \
  $(GSDIR)/DynamicZoneInfo.h $(GSDIR)/DynamicZoneScriptGroup.h \
  $(GSDIR)/DynamicZoneGroup.h $(GSDIR)/DynamicZoneScript.h \
  $(GSDIR)/DynamicZone.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCAddEffectToScreen.h $(COREDIR)/Gpackets/GCSay.h \
  $(COREDIR)/Gpackets/GCGlobalChat.h $(GSDIR)/EventSystemMessage.h \
  $(GSDIR)/StringPool.h
DEScriptEffect.o: DEScriptEffect.cpp DEScriptEffect.h DEScript.h \
  lua_tinker.h $(COREDIR)/Exception.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/StringStream.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Monster.h \
  $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(GSDIR)/Treasure.h $(GSDIR)/Item.h \
  $(GSDIR)/PrecedenceTable.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/PacketFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/EffectScript.h \
  $(GSDIR)/script/DEScriptEffect.h $(COREDIR)/Player.h \
  $(GSDIR)/PacketUtil.h
DEScriptSkill.o: DEScriptSkill.cpp DEScriptSkill.h DEScript.h \
  lua_tinker.h $(COREDIR)/Exception.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/StringStream.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Monster.h \
  $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(GSDIR)/Treasure.h $(GSDIR)/Item.h \
  $(GSDIR)/PrecedenceTable.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/PacketFactory.h $(GSDIR)/skill/SkillHandler.h \
  $(GSDIR)/skill/Skill.h $(GSDIR)/SkillInfo.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
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
  $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h $(GSDIR)/skill/HitRoll.h \
  $(GSDIR)/skill/SkillUtil.h $(GSDIR)/ZoneUtil.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(GSDIR)/skill/SimpleSkill.h
