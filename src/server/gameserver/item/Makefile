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
	ItemIDRegistry.o \
	AR.o \
	Belt.o \
	Blade.o \
	Bomb.o \
	BombMaterial.o \
	Bracelet.o \
	Coat.o \
	Cross.o \
	Mace.o \
	ETC.o \
	Glove.o \
	Sword.o \
	Helm.o \
	HolyWater.o \
	Key.o \
	LearningItem.o \
	Magazine.o \
	Mine.o \
	Money.o \
	Motorcycle.o \
	Necklace.o \
	Potion.o \
	Ring.o \
	SG.o \
	SMG.o \
	Shield.o \
	Shoes.o \
	SR.o \
	Trouser.o \
	VampireBracelet.o \
	VampireRing.o \
	VampireNecklace.o \
	VampireCoat.o \
	Water.o \
	Skull.o \
	Serum.o \
	VampireETC.o \
	SlayerPortalItem.o \
	VampirePortalItem.o \
	EventGiftBox.o \
	EventStar.o	\
	VampireEarring.o \
	Relic.o \
	VampireWeapon.o \
	VampireAmulet.o \
	QuestItem.o \
	Gun.o \
	EventTree.o \
	EventETC.o \
	BloodBible.o \
	CastleSymbol.o \
	CoupleRing.o \
	VampireCoupleRing.o \
	CoupleRingBase.o \
	EventItem.o \
	DyePotion.o \
	ResurrectItem.o \
	MixingItem.o \
	OustersArmsband.o \
	OustersBoots.o \
	OustersChakram.o \
	OustersCirclet.o \
	OustersCoat.o \
	OustersPendent.o \
	OustersRing.o \
	OustersStone.o \
	OustersWristlet.o \
	Larva.o \
	Pupa.o \
	ComposMei.o \
	OustersSummonItem.o \
	EffectItem.o \
	CodeSheet.o \
	MoonCard.o \
	Sweeper.o \
	PetItem.o \
	PetFood.o \
	PetEnchantItem.o \
	LuckyBag.o \
	SMSItem.o \
	CoreZap.o \
	TrapItem.o \
	WarItem.o \
	CarryingReceiver.o \
	ShoulderArmor.o \
	Dermis.o \
	Persona.o \
	Fascia.o \
	Mitten.o \
	SubInventory.o \
	CommonQuestItem.o \
	EtherealChain.o \
	OustersCoupleRing.o \
	CheckMoney.o \
	CueOfAdam.o \
	ContractOfBlood.o \
	SkillBook.o \
	VampireWingItem.o \
	OustersWingItem.o \
	SlayerTunningItem.o \
	VampireTunningItem.o \
	OustersTunningItem.o \
	CallNPCCard.o

SRCS = $(OBJS:.o=.cpp)

TARGET = $(LIBDIR)/libItems.a


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
ItemIDRegistry.o: ItemIDRegistry.cpp $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemInfoManager.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h Motorcycle.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h Potion.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemPolicies.h Water.h HolyWater.h Magazine.h BombMaterial.h \
  ETC.h Key.h Ring.h Bracelet.h Necklace.h Coat.h Trouser.h Shoes.h \
  Sword.h Blade.h Shield.h Cross.h Mace.h Glove.h Helm.h SG.h SMG.h AR.h \
  SR.h Bomb.h Mine.h Belt.h LearningItem.h Money.h VampireRing.h \
  VampireBracelet.h VampireNecklace.h VampireCoat.h Skull.h Serum.h \
  VampireETC.h SlayerPortalItem.h VampirePortalItem.h EventGiftBox.h \
  EventStar.h VampireEarring.h Relic.h VampireWeapon.h VampireAmulet.h \
  QuestItem.h EventTree.h EventETC.h BloodBible.h CastleSymbol.h \
  CoupleRing.h CoupleRingBase.h VampireCoupleRing.h EventItem.h \
  DyePotion.h ResurrectItem.h MixingItem.h OustersArmsband.h \
  OustersBoots.h OustersChakram.h OustersCirclet.h OustersCoat.h \
  OustersPendent.h OustersRing.h OustersStone.h OustersWristlet.h \
  Larva.h Pupa.h ComposMei.h OustersSummonItem.h OustersCoupleRing.h \
  EffectItem.h CodeSheet.h MoonCard.h Sweeper.h PetItem.h \
  $(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h \
  $(COREDIR)/VSDateTime.h PetFood.h PetEnchantItem.h LuckyBag.h \
  SMSItem.h CoreZap.h $(GSDIR)/OptionInfo.h TrapItem.h WarItem.h \
  CarryingReceiver.h ShoulderArmor.h Dermis.h Persona.h Fascia.h \
  Mitten.h SubInventory.h CommonQuestItem.h EtherealChain.h CheckMoney.h \
  CueOfAdam.h ContractOfBlood.h SkillBook.h VampireWingItem.h \
  OustersWingItem.h SlayerTunningItem.h VampireTunningItem.h \
  OustersTunningItem.h CallNPCCard.h
AR.o: AR.cpp AR.h $(GSDIR)/ConcreteItem.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Belt.o: Belt.cpp Belt.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Blade.o: Blade.cpp Blade.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Bomb.o: Bomb.cpp Bomb.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
BombMaterial.o: BombMaterial.cpp BombMaterial.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Bracelet.o: Bracelet.cpp Bracelet.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Coat.o: Coat.cpp Coat.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Cross.o: Cross.cpp Cross.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Mace.o: Mace.cpp Mace.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
ETC.o: ETC.cpp ETC.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Glove.o: Glove.cpp Glove.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Sword.o: Sword.cpp Sword.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Helm.o: Helm.cpp Helm.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
HolyWater.o: HolyWater.cpp HolyWater.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Key.o: Key.cpp Key.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/ParkingCenter.h \
  $(GSDIR)/item/Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
LearningItem.o: LearningItem.cpp LearningItem.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Magazine.o: Magazine.cpp Magazine.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Mine.o: Mine.cpp Mine.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Money.o: Money.cpp Money.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Motorcycle.o: Motorcycle.cpp Motorcycle.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(GSDIR)/ParkingCenter.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Creature.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/item/Motorcycle.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Necklace.o: Necklace.cpp Necklace.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Potion.o: Potion.cpp Potion.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Ring.o: Ring.cpp Ring.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
SG.o: SG.cpp SG.h $(GSDIR)/ConcreteItem.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
SMG.o: SMG.cpp SMG.h $(GSDIR)/ConcreteItem.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Shield.o: Shield.cpp Shield.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Shoes.o: Shoes.cpp Shoes.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
SR.o: SR.cpp SR.h $(GSDIR)/ConcreteItem.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Trouser.o: Trouser.cpp Trouser.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
VampireBracelet.o: VampireBracelet.cpp VampireBracelet.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
VampireRing.o: VampireRing.cpp VampireRing.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
VampireNecklace.o: VampireNecklace.cpp VampireNecklace.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
VampireCoat.o: VampireCoat.cpp VampireCoat.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Water.o: Water.cpp Water.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Skull.o: Skull.cpp Skull.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Serum.o: Serum.cpp Serum.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
VampireETC.o: VampireETC.cpp VampireETC.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
SlayerPortalItem.o: SlayerPortalItem.cpp SlayerPortalItem.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
VampirePortalItem.o: VampirePortalItem.cpp VampirePortalItem.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h $(GSDIR)/skill/EffectVampirePortal.h \
  $(GSDIR)/EffectLoader.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
EventGiftBox.o: EventGiftBox.cpp EventGiftBox.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
EventStar.o: EventStar.cpp EventStar.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
VampireEarring.o: VampireEarring.cpp VampireEarring.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Relic.o: Relic.cpp Relic.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
VampireWeapon.o: VampireWeapon.cpp VampireWeapon.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
VampireAmulet.o: VampireAmulet.cpp VampireAmulet.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
QuestItem.o: QuestItem.cpp QuestItem.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Gun.o: Gun.cpp Gun.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemUtil.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
EventTree.o: EventTree.cpp EventTree.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
EventETC.o: EventETC.cpp EventETC.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h OustersArmsband.h \
  Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
BloodBible.o: BloodBible.cpp BloodBible.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
CastleSymbol.o: CastleSymbol.cpp CastleSymbol.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
CoupleRing.o: CoupleRing.cpp CoupleRing.h CoupleRingBase.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h $(GSDIR)/FlagSet.h $(GSDIR)/couple/CoupleManager.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
VampireCoupleRing.o: VampireCoupleRing.cpp VampireCoupleRing.h \
  CoupleRingBase.h $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h $(GSDIR)/FlagSet.h $(GSDIR)/couple/CoupleManager.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
CoupleRingBase.o: CoupleRingBase.cpp CoupleRingBase.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h CoupleRing.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h VampireCoupleRing.h \
  OustersCoupleRing.h $(GSDIR)/ItemUtil.h
EventItem.o: EventItem.cpp EventItem.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(GSDIR)/BalloonHeadbandUtil.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
DyePotion.o: DyePotion.cpp DyePotion.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
ResurrectItem.o: ResurrectItem.cpp ResurrectItem.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
MixingItem.o: MixingItem.cpp MixingItem.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
OustersArmsband.o: OustersArmsband.cpp OustersArmsband.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
OustersBoots.o: OustersBoots.cpp OustersBoots.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
OustersChakram.o: OustersChakram.cpp OustersChakram.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
OustersCirclet.o: OustersCirclet.cpp OustersCirclet.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
OustersCoat.o: OustersCoat.cpp OustersCoat.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
OustersPendent.o: OustersPendent.cpp OustersPendent.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
OustersRing.o: OustersRing.cpp OustersRing.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
OustersStone.o: OustersStone.cpp OustersStone.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
OustersWristlet.o: OustersWristlet.cpp OustersWristlet.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Larva.o: Larva.cpp Larva.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h $(GSDIR)/ZoneGroupManager.h \
  $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Pupa.o: Pupa.cpp Pupa.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h OustersArmsband.h \
  Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
ComposMei.o: ComposMei.cpp ComposMei.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h OustersArmsband.h \
  Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
OustersSummonItem.o: OustersSummonItem.cpp OustersSummonItem.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
EffectItem.o: EffectItem.cpp EffectItem.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
CodeSheet.o: CodeSheet.cpp CodeSheet.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
MoonCard.o: MoonCard.cpp MoonCard.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Sweeper.o: Sweeper.cpp Sweeper.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
PetItem.o: PetItem.cpp PetItem.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(COREDIR)/PetInfo.h \
  $(COREDIR)/types/PetTypes.h $(COREDIR)/VSDateTime.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h $(GSDIR)/PetUtil.h \
  $(GSDIR)/EffectHasPet.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PetTypeInfo.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
PetFood.o: PetFood.cpp PetFood.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(COREDIR)/types/PetTypes.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
PetEnchantItem.o: PetEnchantItem.cpp PetEnchantItem.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(COREDIR)/types/PetTypes.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
LuckyBag.o: LuckyBag.cpp LuckyBag.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
SMSItem.o: SMSItem.cpp SMSItem.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
CoreZap.o: CoreZap.cpp CoreZap.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/OptionInfo.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
TrapItem.o: TrapItem.cpp TrapItem.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
WarItem.o: WarItem.cpp WarItem.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(GSDIR)/ItemInfoManager.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
CarryingReceiver.o: CarryingReceiver.cpp CarryingReceiver.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
ShoulderArmor.o: ShoulderArmor.cpp ShoulderArmor.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Dermis.o: Dermis.cpp Dermis.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Persona.o: Persona.cpp Persona.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h Motorcycle.h $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
Fascia.o: Fascia.cpp Fascia.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Mitten.o: Mitten.cpp Mitten.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
SubInventory.o: SubInventory.cpp SubInventory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
CommonQuestItem.o: CommonQuestItem.cpp CommonQuestItem.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
EtherealChain.o: EtherealChain.cpp EtherealChain.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/OptionInfo.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
OustersCoupleRing.o: OustersCoupleRing.cpp OustersCoupleRing.h \
  CoupleRingBase.h $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(GSDIR)/skill/OustersSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h $(GSDIR)/FlagSet.h $(GSDIR)/couple/CoupleManager.h \
  SubInventory.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
CheckMoney.o: CheckMoney.cpp CheckMoney.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
CueOfAdam.o: CueOfAdam.cpp CueOfAdam.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/OptionInfo.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
ContractOfBlood.o: ContractOfBlood.cpp ContractOfBlood.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(GSDIR)/OptionInfo.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
SkillBook.o: SkillBook.cpp SkillBook.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
VampireWingItem.o: VampireWingItem.cpp VampireWingItem.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  Belt.h $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h Motorcycle.h $(GSDIR)/Stash.h \
  $(GSDIR)/ItemUtil.h SubInventory.h $(SERVDIR)/DBExecuteManager.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
OustersWingItem.o: OustersWingItem.cpp OustersWingItem.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
SlayerTunningItem.o: SlayerTunningItem.cpp SlayerTunningItem.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
VampireTunningItem.o: VampireTunningItem.cpp VampireTunningItem.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
OustersTunningItem.o: OustersTunningItem.cpp OustersTunningItem.h \
  $(GSDIR)/Item.h $(GSDIR)/Object.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
CallNPCCard.o: CallNPCCard.cpp CallNPCCard.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/InventorySlot.h \
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
  $(GSDIR)/ItemLoaderManager.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(GSDIR)/skill/Skill.h \
  $(GSDIR)/skill/SlayerSkillSlot.h $(GSDIR)/skill/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(GSDIR)/skill/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(GSDIR)/skill/OustersSkillSlot.h Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h Motorcycle.h \
  $(GSDIR)/Stash.h $(GSDIR)/ItemUtil.h SubInventory.h \
  $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
