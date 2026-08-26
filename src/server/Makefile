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
VSHOME  = ../..
BINDIR  = $(VSHOME)/bin
LIBDIR  = $(VSHOME)/lib
LOGDIR  = $(VSHOME)/log
SRCDIR  = ..
COREDIR = ../Core
DBDIR   = database


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__
INCLUDES = -I$(COREDIR)/compat -I$(COREDIR) -I$(DBDIR) -I.
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs

.cpp.o : 
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<


#----------------------------------------------------------------------
# Server Core Library
#----------------------------------------------------------------------
SERVER_CORE_OBJS = CondVar.o LogData.o LogClient.o Mutex.o PlayerManager.o GameWorldInfoManager.o SystemAPI.o Thread.o ThreadAttr.o Timeval.o pthreadAPI.o Profile.o PacketProfile.o GameServerInfoManager.o PaySystem.o DBExecuteManager.o
SERVER_CORE_LIB  = $(LIBDIR)/libServerCore.a

SERVER_CORE_SRCS = $(SERVER_CORE_OBJS:.o=.cpp)

#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
all : $(SERVER_CORE_LIB)
	$(MAKE) -C database
	$(MAKE) -C chinabilling
	$(MAKE) -C gameserver/billing
	$(MAKE) -C loginserver
	$(MAKE) -C gameserver
#	$(MAKE) -C updateserver
	$(MAKE) -C sharedserver

server : $(SERVER_CORE_LIB)

allgameserver : $(SERVER_CORE_LIB)
	$(MAKE) -C database
	$(MAKE) -C chinabilling
	$(MAKE) -C gameserver

allloginserver : $(SERVER_CORE_LIB)
	$(MAKE) -C database
	$(MAKE) -C chinabilling
	$(MAKE) -C gameserver/billing
	$(MAKE) -C loginserver

allsharedserver : $(SERVER_CORE_LIB)
	$(MAKE) -C database
	$(MAKE) -C sharedserver

alltheoneserver : $(SERVER_CORE_LIB)
	$(MAKE) -C theoneserver

$(SERVER_CORE_LIB) : $(SERVER_CORE_OBJS)
	ar rc $@ $^

clean :
	$(MAKE) -C database clean
	$(MAKE) -C chinabilling clean
	$(MAKE) -C loginserver clean
	$(MAKE) -C gameserver clean
	$(MAKE) -C updateserver clean
	$(MAKE) -C sharedserver clean
	rm -rf *.o

cleanloginserver :
	$(MAKE) -C database clean
	$(MAKE) -C chinabilling clean
	$(MAKE) -C loginserver clean
	rm -rf *.o

cleangameserver :
	$(MAKE) -C database clean
	$(MAKE) -C chinabilling clean
	$(MAKE) -C gameserver clean
	rm -rf *.o

cleansharedserver :
	$(MAKE) -C database clean
	$(MAKE) -C sharedserver clean
	rm -rf *.o

cleanall :
	$(MAKE) -C database cleanall
	$(MAKE) -C chinabilling cleanall
	$(MAKE) -C loginserver cleanall
	$(MAKE) -C gameserver cleanall
	$(MAKE) -C updateserver cleanall
	$(MAKE) -C sharedserver cleanall
	rm -rf *.o $(SERVER_CORE_LIB)

depall :
	$(MAKE) -C database depall
	$(MAKE) -C chinabilling depall
	$(MAKE) -C loginserver depall
	$(MAKE) -C gameserver depall
	$(MAKE) -C updateserver depall
	$(MAKE) -C sharedserver depall
	gccmakedep $(SERVER_CORE_SRCS) $(INCLUDES)

dep :
	gccmakedep $(SERVER_CORE_SRCS) $(INCLUDES)
# DO NOT DELETE
CondVar.o: CondVar.cpp CondVar.h CondVarAttr.h pthreadAPI.h \
  $(COREDIR)/Exception.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h $(COREDIR)/StringStream.h \
  Mutex.h Thread.h LogClient.h
LogData.o: LogData.cpp LogData.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h
LogClient.o: LogClient.cpp LogClient.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h LogData.h
Mutex.o: Mutex.cpp Mutex.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h MutexAttr.h pthreadAPI.h Thread.h LogClient.h
PlayerManager.o: PlayerManager.cpp PlayerManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Timeval.h $(COREDIR)/SocketAPI.h Mutex.h $(COREDIR)/Assert.h \
  $(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/Player.h \
  gameserver/Creature.h gameserver/Object.h gameserver/EffectManager.h \
  gameserver/Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/SocketOutputStream.h \
  gameserver/Slayer.h gameserver/PlayerCreature.h \
  gameserver/ObjectRegistry.h gameserver/InventorySlot.h \
  gameserver/Item.h gameserver/Garbage.h gameserver/RankBonus.h \
  gameserver/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  gameserver/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  gameserver/Zone.h gameserver/Tile.h gameserver/Obstacle.h \
  gameserver/Portal.h gameserver/quest/TriggerManager.h \
  gameserver/quest/Trigger.h gameserver/quest/Condition.h \
  gameserver/quest/PropertyBuffer.h gameserver/Sector.h \
  gameserver/Party.h $(COREDIR)/ModifyInfo.h gameserver/PCManager.h \
  gameserver/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h gameserver/Inventory.h \
  gameserver/VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  gameserver/ItemLoaderManager.h gameserver/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h gameserver/CreatureUtil.h \
  gameserver/SlayerAttrExpTable.h gameserver/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h gameserver/skill/Skill.h \
  gameserver/skill/SlayerSkillSlot.h gameserver/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h
GameWorldInfoManager.o: GameWorldInfoManager.cpp GameWorldInfoManager.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  GameWorldInfo.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
SystemAPI.o: SystemAPI.cpp $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h SystemAPI.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h
Thread.o: Thread.cpp Thread.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h pthreadAPI.h ThreadAttr.h
ThreadAttr.o: ThreadAttr.cpp ThreadAttr.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  pthreadAPI.h
Timeval.o: Timeval.cpp Timeval.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h
pthreadAPI.o: pthreadAPI.cpp pthreadAPI.h $(COREDIR)/Exception.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/StringStream.h
Profile.o: Profile.cpp Profile.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Timeval.h Mutex.h $(COREDIR)/Assert.h Thread.h pthreadAPI.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
  $(COREDIR)/DatagramPacket.h $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h \
  $(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h
PacketProfile.o: PacketProfile.cpp PacketProfile.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h Timeval.h $(COREDIR)/VSDateTime.h
GameServerInfoManager.o: GameServerInfoManager.cpp \
  GameServerInfoManager.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h GameServerInfo.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
PaySystem.o: PaySystem.cpp PaySystem.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h Timeval.h $(COREDIR)/VSDateTime.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  Thread.h pthreadAPI.h $(COREDIR)/Properties.h
DBExecuteManager.o: DBExecuteManager.cpp $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h $(DBDIR)/Connection.h Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(COREDIR)/Properties.h \
  CondVar.h CondVarAttr.h pthreadAPI.h DBExecuteManager.h Thread.h
