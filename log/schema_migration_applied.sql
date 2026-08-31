ALTER TABLE `ARObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `BeltObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `BladeObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `BraceletInfo` ADD COLUMN `MagicProtection` tinyint unsigned NOT NULL DEFAULT 0;  -- cloned from Protection
ALTER TABLE `BraceletObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
-- NO SIBLING RULE: CanEnterGDRLair.EnemyName
ALTER TABLE `CarryingReceiverObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `CoatObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
-- NO SIBLING RULE: CodeSheetObject.Durability
-- NO SIBLING RULE: CodeSheetObject.EnchantLevel
-- NO SIBLING RULE: CodeSheetObject.ItemFlag
-- NO SIBLING RULE: CoreZapObject.EnchantLevel
ALTER TABLE `CrossObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `DermisObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
-- NO SIBLING RULE: EventQuestRewardInfo.QuestLevel
-- NO SIBLING RULE: EventQuestRewardInfo.RewardClass
ALTER TABLE `FasciaObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `GloveObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
-- NO SIBLING RULE: GoldMedalCount.GoldMedalCount
ALTER TABLE `HelmObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
-- NO SIBLING RULE: ItemClass.EnchantClass1
-- NO SIBLING RULE: ItemClass.EnchantClass2
-- NO SIBLING RULE: ItemRewardInfo.TimeLimit
-- NO SIBLING RULE: KeyObject.BikeBodyColor
-- NO SIBLING RULE: KeyObject.BikeEffectColor
ALTER TABLE `MaceObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `MittenObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '0';  -- cloned from OptionType
-- NO SIBLING RULE: MotorcycleObject.BodyColor
-- NO SIBLING RULE: MotorcycleObject.EffectColor
-- NO SIBLING RULE: NPC.NpcFace
ALTER TABLE `NecklaceInfo` ADD COLUMN `MagicProtection` tinyint unsigned NOT NULL DEFAULT 0;  -- cloned from Protection
ALTER TABLE `NecklaceObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
-- NO SIBLING RULE: OptionClassInfo.IndexName
ALTER TABLE `OptionInfo` ADD COLUMN `UpgradeThirdRatio` int NOT NULL DEFAULT 0;  -- cloned from UpgradeSecondRatio
ALTER TABLE `OustersArmsbandObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `OustersBootsObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `OustersChakramObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `OustersCircletObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `OustersCoatObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `OustersPendentInfo` ADD COLUMN `MagicProtection` tinyint unsigned NOT NULL DEFAULT 0;  -- cloned from Protection
ALTER TABLE `OustersPendentObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `OustersRingInfo` ADD COLUMN `MagicProtection` tinyint unsigned NOT NULL DEFAULT 0;  -- cloned from Protection
ALTER TABLE `OustersRingObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `OustersStoneInfo` ADD COLUMN `MagicProtection` tinyint unsigned NOT NULL DEFAULT 0;  -- cloned from Protection
ALTER TABLE `OustersStoneObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `OustersWristletObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `PersonaObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '0';  -- cloned from OptionType
-- NO SIBLING RULE: PetItemInfo.PetDefaultOption
-- NO SIBLING RULE: Player.Birthday
-- NO SIBLING RULE: Player.ID
-- NO SIBLING RULE: Player.MacAddress
-- NO SIBLING RULE: Player.PID
-- NO SIBLING RULE: Player.Passwd
ALTER TABLE `RingInfo` ADD COLUMN `MagicProtection` tinyint unsigned NOT NULL DEFAULT 0;  -- cloned from Protection
ALTER TABLE `RingObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `SGObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `SMGObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `SRObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `ShieldObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `ShoesObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `ShoulderArmorObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '0';  -- cloned from OptionType
-- NO SIBLING RULE: Slayer.Level
ALTER TABLE `SwordObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `TrouserObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `VampireAmuletInfo` ADD COLUMN `MagicProtection` tinyint unsigned NOT NULL DEFAULT 0;  -- cloned from Protection
ALTER TABLE `VampireAmuletObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `VampireBraceletInfo` ADD COLUMN `MagicProtection` tinyint unsigned NOT NULL DEFAULT 0;  -- cloned from Protection
ALTER TABLE `VampireBraceletObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `VampireCoatObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `VampireCoupleRingObject` ADD COLUMN `ThirdOptionType` varchar(30) DEFAULT '';  -- cloned from OptionType
ALTER TABLE `VampireEarringInfo` ADD COLUMN `MagicProtection` tinyint unsigned NOT NULL DEFAULT 0;  -- cloned from Protection
ALTER TABLE `VampireEarringObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `VampireNecklaceInfo` ADD COLUMN `MagicProtection` tinyint unsigned NOT NULL DEFAULT 0;  -- cloned from Protection
ALTER TABLE `VampireNecklaceObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `VampireRingInfo` ADD COLUMN `MagicProtection` tinyint unsigned NOT NULL DEFAULT 0;  -- cloned from Protection
ALTER TABLE `VampireRingObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
ALTER TABLE `VampireWeaponObject` ADD COLUMN `ThirdOptionType` varchar(10) NOT NULL DEFAULT '';  -- cloned from OptionType
-- NO SIBLING RULE: Vampire.AdvBatColor
-- NO SIBLING RULE: ZoneInfo.PromotionMonsterList
-- Round 2: columns with no direct same-table sibling. Types taken from the
-- equivalent column on a sibling table (donor noted per line), not guessed.
-- Player.{ID,PID,Passwd,MacAddress,Birthday} are deliberately omitted: this
-- schema uses Password/PlayerID, so those queries belong to #ifdef'd publisher
-- variants that are not compiled in this build.

ALTER TABLE `CanEnterGDRLair`      ADD COLUMN `EnemyName`            varchar(30)      NOT NULL DEFAULT '';   -- name-style column
ALTER TABLE `CodeSheetObject`      ADD COLUMN `Durability`           bigint unsigned  NOT NULL DEFAULT 0;    -- donor BladeObject.Durability
ALTER TABLE `CodeSheetObject`      ADD COLUMN `EnchantLevel`         bigint           NOT NULL DEFAULT 0;    -- donor BladeObject.EnchantLevel
ALTER TABLE `CodeSheetObject`      ADD COLUMN `ItemFlag`             tinyint          NOT NULL DEFAULT 0;    -- donor BladeObject.ItemFlag
ALTER TABLE `CoreZapObject`        ADD COLUMN `EnchantLevel`         bigint           NOT NULL DEFAULT 0;    -- donor BladeObject.EnchantLevel
ALTER TABLE `EventQuestRewardInfo` ADD COLUMN `QuestLevel`           int              NOT NULL DEFAULT 0;
ALTER TABLE `EventQuestRewardInfo` ADD COLUMN `RewardClass`          int              NOT NULL DEFAULT 0;
ALTER TABLE `GoldMedalCount`       ADD COLUMN `GoldMedalCount`       int              NOT NULL DEFAULT 0;
ALTER TABLE `ItemClass`            ADD COLUMN `EnchantClass1`        int              NOT NULL DEFAULT 0;    -- donor ItemClass.ItemClass
ALTER TABLE `ItemClass`            ADD COLUMN `EnchantClass2`        int              NOT NULL DEFAULT 0;    -- donor ItemClass.ItemClass
ALTER TABLE `ItemRewardInfo`       ADD COLUMN `TimeLimit`            int              NOT NULL DEFAULT 0;
ALTER TABLE `KeyObject`            ADD COLUMN `BikeBodyColor`        smallint unsigned NOT NULL DEFAULT 0;   -- donor Vampire.BatColor (colour)
ALTER TABLE `KeyObject`            ADD COLUMN `BikeEffectColor`      smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `MotorcycleObject`     ADD COLUMN `BodyColor`            smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `MotorcycleObject`     ADD COLUMN `EffectColor`          smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `NPC`                  ADD COLUMN `NpcFace`              smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `OptionClassInfo`      ADD COLUMN `IndexName`            varchar(50)      NOT NULL DEFAULT '';   -- donor OptionClassInfo.Name
ALTER TABLE `PetItemInfo`          ADD COLUMN `PetDefaultOption`     varchar(50)      NOT NULL DEFAULT '';
ALTER TABLE `Slayer`               ADD COLUMN `Level`                tinyint unsigned NOT NULL DEFAULT 1;    -- donor Vampire.Level
ALTER TABLE `Vampire`              ADD COLUMN `AdvBatColor`          smallint unsigned NOT NULL DEFAULT 0;   -- donor Vampire.BatColor
ALTER TABLE `ZoneInfo`             ADD COLUMN `PromotionMonsterList` text             NULL;                  -- donor ZoneInfo.MonsterList
CREATE TABLE `PetEnchantOptionRatioInfo2` LIKE `PetEnchantOptionRatioInfo`;  -- structural clone, empty
CREATE TABLE `EffectBehemothForceScroll2` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectCarnelianForceScroll2` LIKE `EffectCarnelianForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectSafeForceScroll2` LIKE `EffectSafeForceScroll`;  -- structural clone, empty
CREATE TABLE `CallNPCCardObject` LIKE `BombMaterialObject`;  -- structural clone, empty
CREATE TABLE `CheckMoneyInfo` LIKE `BombMaterialInfo`;  -- structural clone, empty
CREATE TABLE `CheckMoneyObject` LIKE `MoneyObject`;  -- structural clone, empty
CREATE TABLE `CommonQuestItemInfo` LIKE `QuestItemInfo`;  -- structural clone, empty
CREATE TABLE `CommonQuestItemObject` LIKE `BombMaterialObject`;  -- structural clone, empty
CREATE TABLE `ContractOfBloodInfo` LIKE `CoreZapInfo`;  -- structural clone, empty
CREATE TABLE `ContractOfBloodObject` LIKE `BeltObject`;  -- structural clone, empty
CREATE TABLE `CrystalEnchantInfo` LIKE `PetEnchantOptionRatioInfo`;  -- structural clone, empty
CREATE TABLE `CueOfAdamObject` LIKE `BeltObject`;  -- structural clone, empty
CREATE TABLE `DonationWedding200505` LIKE `LogUserInfo`;  -- structural clone, empty
CREATE TABLE `EffectAccuraForceScroll` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectAccuraForceScroll2` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectBehemothForceScroll2` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectCarnelianForceScroll2` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectExtremeForceScroll` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectExtremeForceScroll2` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectFuriousIncense` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectGentisDungeon` LIKE `EffectAcidTouch`;  -- structural clone, empty
CREATE TABLE `EffectGreyfellForceScroll` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectGreyfellForceScroll2` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectHoodlumStigma` LIKE `EffectCarnelianForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectHyperactiveIncense` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectImpregnableIncense` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectLifeForceScroll` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectLifeForceScroll2` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectMirForceScroll` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectMirForceScroll2` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectMysteryPotion` LIKE `EffectAcidTouch`;  -- structural clone, empty
CREATE TABLE `EffectOdinForceScroll` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectOdinForceScroll2` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectPremiumService` LIKE `EffectAcidTouch`;  -- structural clone, empty
CREATE TABLE `EffectPromotionAngelFlutter` LIKE `EffectAcidTouch`;  -- structural clone, empty
CREATE TABLE `EffectPromotionBatWing` LIKE `EffectAcidTouch`;  -- structural clone, empty
CREATE TABLE `EffectPromotionButterflyWing` LIKE `EffectAcidTouch`;  -- structural clone, empty
CREATE TABLE `EffectRankBonusExpBlue` LIKE `EffectAcidTouch`;  -- structural clone, empty
CREATE TABLE `EffectRankBonusExpRed` LIKE `EffectAcidTouch`;  -- structural clone, empty
CREATE TABLE `EffectSafeForceScroll2` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectSoviusForceScroll` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectSoviusForceScroll2` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectStrengthenIncense` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectTituosForceScroll` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EffectTituosForceScroll2` LIKE `EffectBehemothForceScroll`;  -- structural clone, empty
CREATE TABLE `EnchantArmorInfo` LIKE `OptionInfo_copy1`;  -- structural clone, empty
CREATE TABLE `EnchantMagicInfo` LIKE `OptionInfo_copy1`;  -- structural clone, empty
CREATE TABLE `EnchantMeleeInfo` LIKE `OptionInfo_copy1`;  -- structural clone, empty
CREATE TABLE `EtherealChainInfo` LIKE `BombMaterialInfo`;  -- structural clone, empty
CREATE TABLE `EtherealChainObject` LIKE `BeltObject`;  -- structural clone, empty
CREATE TABLE `Event200507Main` LIKE `Event200501Main`;  -- structural clone, empty
CREATE TABLE `Event200507Recommend` LIKE `Event200501Recommend`;  -- structural clone, empty
CREATE TABLE `Event200604` LIKE `Event200501Main`;  -- structural clone, empty
CREATE TABLE `EventBallInfo` LIKE `BombMaterialInfo`;  -- structural clone, empty
CREATE TABLE `EventBallObject` LIKE `ComposMeiObject`;  -- structural clone, empty
CREATE TABLE `IPAllowInfo` LIKE `IPBlockInfo`;  -- structural clone, empty
CREATE TABLE `LoginPayType` LIKE `PCRoomInfo`;  -- structural clone, empty
CREATE TABLE `MakePCLog` LIKE `AbnormalList`;  -- structural clone, empty
CREATE TABLE `OustersHarmonicPendentInfo` LIKE `BombMaterialInfo`;  -- structural clone, empty
CREATE TABLE `OustersHarmonicPendentObject` LIKE `VampireCoupleRingObject`;  -- structural clone, empty
CREATE TABLE `OustersTunningItemObject` LIKE `BombMaterialObject`;  -- structural clone, empty
CREATE TABLE `OustersWingItemObject` LIKE `MotorcycleObject`;  -- structural clone, empty
CREATE TABLE `PVPSystemPartyObject` LIKE `LogUserInfo`;  -- structural clone, empty
CREATE TABLE `PetEnchantOptionRatioInfo2` LIKE `PetEnchantOptionRatioInfo`;  -- structural clone, empty
CREATE TABLE `PrivateAgreementRemain` LIKE `AbnormalList`;  -- structural clone, empty
CREATE TABLE `SkillBookObject` LIKE `ComposMeiObject`;  -- structural clone, empty
CREATE TABLE `SlayerTunningItemObject` LIKE `BombMaterialObject`;  -- structural clone, empty
CREATE TABLE `VampireTunningItemObject` LIKE `BombMaterialObject`;  -- structural clone, empty
CREATE TABLE `VampireWingItemObject` LIKE `MotorcycleObject`;  -- structural clone, empty
CREATE TABLE IF NOT EXISTS `AttendCheck` (
  `CheckDate` varchar(255) NOT NULL DEFAULT '',
  `CheckCount` int NOT NULL DEFAULT 0,
  `PlayerID` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `BlitzEvent` (
  `BlitzCount` int NOT NULL DEFAULT 0,
  `BlitzRemainCount` int NOT NULL DEFAULT 0,
  `OwnerID` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `CallNPCCardInfo` (
  `ItemType` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `EName` varchar(255) NOT NULL DEFAULT '',
  `Price` int NOT NULL DEFAULT 0,
  `Volume` int NOT NULL DEFAULT 0,
  `Weight` int NOT NULL DEFAULT 0,
  `Ratio` int NOT NULL DEFAULT 0,
  `NPCID` int NOT NULL DEFAULT 0,
  `ScriptType` int NOT NULL DEFAULT 0,
  `OwnerID` varchar(255) NOT NULL DEFAULT '',
  `Storage` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `ChangeWorld` (
  `NewName` varchar(255) NULL,
  `Level` int NOT NULL DEFAULT 0,
  `RankType` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `ContributeDegree` (
  `ContributePoint` int NOT NULL DEFAULT 0,
  `HolyWarCheckPoint` int NOT NULL DEFAULT 0,
  `HolyWarCheckDate` varchar(255) NOT NULL DEFAULT '',
  `LevelWarCheckPoint` int NOT NULL DEFAULT 0,
  `LevelWarCheckDate` varchar(255) NOT NULL DEFAULT '',
  `UserName` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `ContributeInfo` (
  `Rank` int NOT NULL DEFAULT 0,
  `RankPoint` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `ContributeRewardCount` (
  `RewardCount` int NOT NULL DEFAULT 0,
  `OwnerID` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `CreatureSprite` (
  `FrameID` int NOT NULL DEFAULT 0,
  `SpriteFilePosition` int NOT NULL DEFAULT 0,
  `SpriteShadowFilePosition` int NOT NULL DEFAULT 0,
  `FirstSpriteID` int NOT NULL DEFAULT 0,
  `LastSpriteID` int NOT NULL DEFAULT 0,
  `FirstShadowSpriteID` int NOT NULL DEFAULT 0,
  `LastShadowSpriteID` int NOT NULL DEFAULT 0,
  `CreatureType` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `CueOfAdamInfo` (
  `ItemType` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `EName` varchar(255) NOT NULL DEFAULT '',
  `Price` int NOT NULL DEFAULT 0,
  `Volume` int NOT NULL DEFAULT 0,
  `Weight` int NOT NULL DEFAULT 0,
  `Ratio` int NOT NULL DEFAULT 0,
  `OptionClass` int NOT NULL DEFAULT 0,
  `SetOption` varchar(255) NOT NULL DEFAULT '',
  `OwnerID` varchar(255) NOT NULL DEFAULT '',
  `Storage` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `DSGMemberList` (
  `DsgStat` varchar(255) NOT NULL DEFAULT '',
  `Access` varchar(255) NOT NULL DEFAULT '',
  `Name` varchar(255) NOT NULL DEFAULT '',
  `PlayerID` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `EffectBonusExp` (
  `BonusRate` varchar(255) NULL,
  `DayTime` varchar(255) NULL,
  `LogOn` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `OwnerID` varchar(255) NOT NULL DEFAULT '',
  `Race` varchar(255) NOT NULL DEFAULT '',
  `YearTime` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `EffectBonusExpAdvance` (
  `BonusRate` varchar(255) NULL,
  `DayTime` varchar(255) NULL,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `YearTime` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `EffectBonusExpSecond` (
  `BonusRate` varchar(255) NULL,
  `DayTime` varchar(255) NULL,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `YearTime` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `EffectChannelMicroPhone` (
  `BonusRate` varchar(255) NULL,
  `RemainTime` varchar(255) NULL,
  `OwnerID` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `EffectChaoticExp` (
  `BonusRate` varchar(255) NULL,
  `RemainTime` varchar(255) NULL,
  `OwnerID` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `EffectPetBonusExp` (
  `BonusRate` varchar(255) NULL,
  `DayTime` varchar(255) NULL,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `YearTime` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `EventBlitzRewardItemInfo` (
  `Orders` int NOT NULL DEFAULT 0,
  `ItemClass` int NOT NULL DEFAULT 0,
  `ItemType` int NOT NULL DEFAULT 0,
  `OptionType` varchar(255) NOT NULL DEFAULT '',
  `LimitTime` int NOT NULL DEFAULT 0,
  `ItemCount` int NOT NULL DEFAULT 0,
  `Ratio` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `EventGiftBoxRewardItemInfo` (
  `Groups` int NOT NULL DEFAULT 0,
  `Orders` int NOT NULL DEFAULT 0,
  `ItemClass` int NOT NULL DEFAULT 0,
  `ItemType` int NOT NULL DEFAULT 0,
  `OptionType` varchar(255) NOT NULL DEFAULT '',
  `LimitTime` int NOT NULL DEFAULT 0,
  `Ratio` int NOT NULL DEFAULT 0,
  `Race` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `EventLevelUp` (
  `Level50` int NOT NULL DEFAULT 0,
  `Level80` int NOT NULL DEFAULT 0,
  `Level100` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `OwnerID` varchar(255) NOT NULL DEFAULT '',
  `PayPremiumDate` int NOT NULL DEFAULT 0,
  `PlayerID` varchar(255) NOT NULL DEFAULT '',
  `RecvItemDate` varchar(255) NOT NULL DEFAULT '',
  `RecvPremiumItemDate` varchar(255) NOT NULL DEFAULT '',
  `s` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `EventPresentItemSchedule` (
  `EventTitle` varchar(255) NOT NULL DEFAULT '',
  `GoodsID` int NOT NULL DEFAULT 0,
  `GoodsCount` int NOT NULL DEFAULT 0,
  `Period` int NOT NULL DEFAULT 0,
  `PlayerID` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `FameLimitInfo` (
  `DomainType` int NOT NULL DEFAULT 0,
  `Level` int NOT NULL DEFAULT 0,
  `Fame` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `FriendGlobalOption` (
  `AllowToRequestAddition` int NOT NULL DEFAULT 0,
  `FriendName` varchar(255) NOT NULL DEFAULT '',
  `Memo` varchar(255) NOT NULL DEFAULT '',
  `Name` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `FriendList` (
  `FriendName` varchar(255) NOT NULL DEFAULT '',
  `Memo` varchar(255) NOT NULL DEFAULT '',
  `AllowToRequestAddition` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `FriendWaitList` (
  `Name` varchar(255) NOT NULL DEFAULT '',
  `AllowToRequestAddition` int NOT NULL DEFAULT 0,
  `FriendName` varchar(255) NOT NULL DEFAULT '',
  `Memo` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `HellGardenTowerMonsterList` (
  `TowerState` int NOT NULL DEFAULT 0,
  `MonsterType` int NOT NULL DEFAULT 0,
  `MonsterCount` int NOT NULL DEFAULT 0,
  `ZoneID` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `IPAllowFunc` (
  `Enabled` int NOT NULL DEFAULT 0,
  `IP` varchar(255) NOT NULL DEFAULT '',
  `PlayerID` varchar(255) NOT NULL DEFAULT '',
  `class` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `InstanceDoungeonInfo` (
  `DoungeonID` varchar(255) NOT NULL DEFAULT '',
  `DoungeonTitle` varchar(255) NOT NULL DEFAULT '',
  `DoungeonDesc` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `InstanceDoungeonList` (
  `DoungeonID` varchar(255) NOT NULL DEFAULT '',
  `DoungeonIndex` int NOT NULL DEFAULT 0,
  `DoungeonName` varchar(255) NOT NULL DEFAULT '',
  `DoungeonScript` varchar(255) NOT NULL DEFAULT '',
  `CreateOnStart` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `ItemList` (
  `IndexID` int NOT NULL DEFAULT 0,
  `ClassNum` int NOT NULL DEFAULT 0,
  `ItemType` int NOT NULL DEFAULT 0,
  `OptionType` varchar(255) NOT NULL DEFAULT '',
  `GiveFlag` int NOT NULL DEFAULT 0,
  `OwnerID` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `LevelWarRewardItemInfo` (
  `Orders` int NOT NULL DEFAULT 0,
  `ItemClass` int NOT NULL DEFAULT 0,
  `ItemType` int NOT NULL DEFAULT 0,
  `OptionType` varchar(255) NOT NULL DEFAULT '',
  `Ratio` int NOT NULL DEFAULT 0,
  `Race` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `MapleEvent` (
  `MapleCount` int NOT NULL DEFAULT 0,
  `MapleRemainCount` int NOT NULL DEFAULT 0,
  `OwnerID` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `MenegrothDoungeonTrapInfo` (
  `TrapX` int NOT NULL DEFAULT 0,
  `TrapY` int NOT NULL DEFAULT 0,
  `TrapType` varchar(255) NOT NULL DEFAULT '',
  `ZoneID` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `NameChange` (
  `FixName` varchar(255) NULL,
  `Level` int NOT NULL DEFAULT 0,
  `NewName` varchar(255) NOT NULL DEFAULT '',
  `RankType` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `OustersTunningItemInfo` (
  `ItemType` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `EName` varchar(255) NOT NULL DEFAULT '',
  `Price` int NOT NULL DEFAULT 0,
  `Volume` int NOT NULL DEFAULT 0,
  `TunningItemClass` int NOT NULL DEFAULT 0,
  `TunningItemType` int NOT NULL DEFAULT 0,
  `Ratio` int NOT NULL DEFAULT 0,
  `ReqAbility` varchar(255) NOT NULL DEFAULT '',
  `OwnerID` varchar(255) NOT NULL DEFAULT '',
  `Storage` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `OustersWingItemInfo` (
  `ItemType` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `EName` varchar(255) NOT NULL DEFAULT '',
  `Price` int NOT NULL DEFAULT 0,
  `Volume` int NOT NULL DEFAULT 0,
  `Weight` int NOT NULL DEFAULT 0,
  `DefaultBodyColor` int NOT NULL DEFAULT 0,
  `DefaultEffectColor` int NOT NULL DEFAULT 0,
  `OwnerID` varchar(255) NOT NULL DEFAULT '',
  `Storage` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `PCRoomDBInfo` (
  `ID` int NOT NULL DEFAULT 0,
  `Host` varchar(255) NOT NULL DEFAULT '',
  `DB` varchar(255) NOT NULL DEFAULT '',
  `User` varchar(255) NOT NULL DEFAULT '',
  `Password` varchar(255) NOT NULL DEFAULT '',
  `CurrentServerGroupID` int NOT NULL DEFAULT 0,
  `CurrentWorldID` int NOT NULL DEFAULT 0,
  `LogOn` varchar(255) NOT NULL DEFAULT '',
  `PlayerID` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `PVPSystemObject` (
  `PartyID` int NOT NULL DEFAULT 0,
  `LevelRange` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `Status` int NOT NULL DEFAULT 0,
  `isAttend` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `RedistributeAttr50Count` (
  `RemainCount` int NOT NULL DEFAULT 0,
  `Bonus` int NOT NULL DEFAULT 0,
  `DEX` int NOT NULL DEFAULT 0,
  `INTE` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `PayPremiumDate` int NOT NULL DEFAULT 0,
  `PlayerID` varchar(255) NOT NULL DEFAULT '',
  `RecvItemDate` varchar(255) NOT NULL DEFAULT '',
  `RecvPremiumItemDate` varchar(255) NOT NULL DEFAULT '',
  `STR` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `ResetAttributeCount` (
  `RemainCount` int NOT NULL DEFAULT 0,
  `Bonus` int NOT NULL DEFAULT 0,
  `DEX` int NOT NULL DEFAULT 0,
  `INTE` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `STR` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `SimpleQuest` (
  `QuestType` int NOT NULL DEFAULT 0,
  `Objective` varchar(255) NOT NULL DEFAULT '',
  `Reward` varchar(255) NOT NULL DEFAULT '',
  `Penalty` varchar(255) NOT NULL DEFAULT '',
  `DayTime` varchar(255) NULL,
  `OwnerID` varchar(255) NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `SkillBookInfo` (
  `ItemType` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `EName` varchar(255) NOT NULL DEFAULT '',
  `Price` int NOT NULL DEFAULT 0,
  `Volume` int NOT NULL DEFAULT 0,
  `Weight` int NOT NULL DEFAULT 0,
  `SkillType` int NOT NULL DEFAULT 0,
  `SkillDomainType` int NOT NULL DEFAULT 0,
  `Race` int NOT NULL DEFAULT 0,
  `NeedAttribute` varchar(255) NOT NULL DEFAULT '',
  `OwnerID` varchar(255) NOT NULL DEFAULT '',
  `Storage` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `SlayerTunningItemInfo` (
  `ItemType` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `EName` varchar(255) NOT NULL DEFAULT '',
  `Price` int NOT NULL DEFAULT 0,
  `Volume` int NOT NULL DEFAULT 0,
  `TunningItemClass` int NOT NULL DEFAULT 0,
  `TunningItemType` int NOT NULL DEFAULT 0,
  `Ratio` int NOT NULL DEFAULT 0,
  `ReqAbility` varchar(255) NOT NULL DEFAULT '',
  `OwnerID` varchar(255) NOT NULL DEFAULT '',
  `Storage` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `TimePeriodSchdule` (
  `TimePeriodType` int NOT NULL DEFAULT 0,
  `StartTimeH` int NOT NULL DEFAULT 0,
  `StartTimeM` int NOT NULL DEFAULT 0,
  `EndTimeH` int NOT NULL DEFAULT 0,
  `EndTimeM` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `VampireTunningItemInfo` (
  `ItemType` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `EName` varchar(255) NOT NULL DEFAULT '',
  `Price` int NOT NULL DEFAULT 0,
  `Volume` int NOT NULL DEFAULT 0,
  `TunningItemClass` int NOT NULL DEFAULT 0,
  `TunningItemType` int NOT NULL DEFAULT 0,
  `Ratio` int NOT NULL DEFAULT 0,
  `ReqAbility` varchar(255) NOT NULL DEFAULT '',
  `OwnerID` varchar(255) NOT NULL DEFAULT '',
  `Storage` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `VampireWingItemInfo` (
  `ItemType` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `EName` varchar(255) NOT NULL DEFAULT '',
  `Price` int NOT NULL DEFAULT 0,
  `Volume` int NOT NULL DEFAULT 0,
  `Weight` int NOT NULL DEFAULT 0,
  `Ratio` int NOT NULL DEFAULT 0,
  `DefaultBodyColor` int NOT NULL DEFAULT 0,
  `DefaultEffectColor` int NOT NULL DEFAULT 0,
  `ReqAbility` varchar(255) NOT NULL DEFAULT '',
  `OwnerID` varchar(255) NOT NULL DEFAULT '',
  `Storage` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `WebTemp` (
  `NewName` varchar(255) NULL,
  `Level` int NOT NULL DEFAULT 0,
  `RankType` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
CREATE TABLE IF NOT EXISTS `WeekItemListObject` (
  `ID` int NOT NULL DEFAULT 0,
  `ItemClass` int NOT NULL DEFAULT 0,
  `ItemType` int NOT NULL DEFAULT 0,
  `Num` int NOT NULL DEFAULT 0,
  `OptionType` varchar(255) NOT NULL DEFAULT '',
  `Grade` int NOT NULL DEFAULT 0,
  `LimitTime` int NOT NULL DEFAULT 0,
  `Name` varchar(255) NOT NULL DEFAULT '',
  `OwnerID` varchar(255) NOT NULL DEFAULT '',
  `PlayerID` varchar(255) NOT NULL DEFAULT '',
  `RecvDate` int NOT NULL DEFAULT 0,
  `Week` int NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
ALTER TABLE `EventBlitzRewardItemInfo` ADD COLUMN `Groups` int NOT NULL DEFAULT 0;
ALTER TABLE `KeyInfo` ADD COLUMN `DefaultBikeBodyColor` int NOT NULL DEFAULT 0;
ALTER TABLE `KeyInfo` ADD COLUMN `DefaultBikeEffectColor` int NOT NULL DEFAULT 0;
ALTER TABLE `Ousters` ADD COLUMN `AttackBloodBurstPoint` int NOT NULL DEFAULT 0;
ALTER TABLE `Ousters` ADD COLUMN `Born` varchar(255) NOT NULL DEFAULT '';
ALTER TABLE `Ousters` ADD COLUMN `DefenseBloodBurstPoint` int NOT NULL DEFAULT 0;
ALTER TABLE `Ousters` ADD COLUMN `GambleAccumulation` int NOT NULL DEFAULT 0;
ALTER TABLE `Ousters` ADD COLUMN `GambleTryCount` int NOT NULL DEFAULT 0;
ALTER TABLE `Ousters` ADD COLUMN `ShopColor` int NOT NULL DEFAULT 0;
ALTER TABLE `PetItemObject` ADD COLUMN `EnchantSkill` int NOT NULL DEFAULT 0;
ALTER TABLE `PetItemObject` ADD COLUMN `ExpertExpireTime` int NOT NULL DEFAULT 0;
ALTER TABLE `PetItemObject` ADD COLUMN `MagicExpireTime` varchar(255) NOT NULL DEFAULT '';
ALTER TABLE `PetItemObject` ADD COLUMN `MixOptionType` int NOT NULL DEFAULT 0;
ALTER TABLE `PetItemObject` ADD COLUMN `OptionType` varchar(10) NOT NULL DEFAULT '0';
ALTER TABLE `PetItemObject` ADD COLUMN `PetOption2` int NOT NULL DEFAULT 0;
-- skipped Player.* (inactive publisher code paths)
ALTER TABLE `RaceWarPCList` ADD COLUMN `ID` int unsigned NOT NULL DEFAULT 0;
ALTER TABLE `RaceWarPCList` ADD COLUMN `LimitNum` smallint NOT NULL DEFAULT 0;
ALTER TABLE `RaceWarPCList` ADD COLUMN `MaxLevel` smallint NOT NULL DEFAULT 0;
ALTER TABLE `RaceWarPCList` ADD COLUMN `MinLevel` smallint NOT NULL DEFAULT 0;
ALTER TABLE `SkillBalance` ADD COLUMN `AvoidAttribute` int NOT NULL DEFAULT 0;
ALTER TABLE `SkillBalance` ADD COLUMN `CastingTime` int NOT NULL DEFAULT 0;
ALTER TABLE `SkillBalance` ADD COLUMN `Conditions` int NOT NULL DEFAULT 0;
ALTER TABLE `SkillBalance` ADD COLUMN `DefaultCastingTime` int NOT NULL DEFAULT 0;
ALTER TABLE `SkillBalance` ADD COLUMN `SingleTarget` varchar(255) NOT NULL DEFAULT '';
ALTER TABLE `SkillBalance` ADD COLUMN `WideTarget` varchar(255) NOT NULL DEFAULT '';
ALTER TABLE `Slayer` ADD COLUMN `AttackBloodBurstPoint` int NOT NULL DEFAULT 0;
ALTER TABLE `Slayer` ADD COLUMN `Born` varchar(255) NOT NULL DEFAULT '';
ALTER TABLE `Slayer` ADD COLUMN `DefenseBloodBurstPoint` int NOT NULL DEFAULT 0;
ALTER TABLE `Slayer` ADD COLUMN `GambleAccumulation` int NOT NULL DEFAULT 0;
ALTER TABLE `Slayer` ADD COLUMN `GambleTryCount` int NOT NULL DEFAULT 0;
ALTER TABLE `Slayer` ADD COLUMN `ShopColor` int NOT NULL DEFAULT 0;
ALTER TABLE `Vampire` ADD COLUMN `AttackBloodBurstPoint` int NOT NULL DEFAULT 0;
ALTER TABLE `Vampire` ADD COLUMN `Born` varchar(255) NOT NULL DEFAULT '';
ALTER TABLE `Vampire` ADD COLUMN `DefenseBloodBurstPoint` int NOT NULL DEFAULT 0;
ALTER TABLE `Vampire` ADD COLUMN `GambleAccumulation` int NOT NULL DEFAULT 0;
ALTER TABLE `Vampire` ADD COLUMN `GambleTryCount` int NOT NULL DEFAULT 0;
ALTER TABLE `Vampire` ADD COLUMN `ShopColor` int NOT NULL DEFAULT 0;

-- 2026-07-30: CLLoginHandler SELECTs Player.MacAddress (13 columns, all 13 read
-- back by index in the normal-login branch), but the column did not exist.
-- Value written by the server is sprintf("%02X-%02X-%02X-%02X-%02X-%02X") = 17 chars.
ALTER TABLE Player ADD COLUMN MacAddress varchar(17) DEFAULT "00-00-00-00-00-00" AFTER LoginIP;

-- 2026-07-30: MySQL 8 removed PASSWORD() and OLD_PASSWORD(). v664 source calls
-- PASSWORD() on both login SELECT and registration INSERT, so the column was
-- always meant to hold a 41-char hash; varchar(10) was a v2-era leftover that
-- could only ever have held plaintext. Source now uses the documented MySQL 4.1
-- equivalent: CONCAT("*", UPPER(SHA1(UNHEX(SHA1(pw))))).
ALTER TABLE Player MODIFY Password varchar(41) NOT NULL;
UPDATE Player SET Password = CONCAT("*", UPPER(SHA1(UNHEX(SHA1("test"))))) WHERE PlayerID = "devolo";

-- 2026-07-30: CLSelectWorld -> LoginPayTypeManager::IsAllow runs
--   SELECT PayType FROM LoginPayType WHERE WorldID=%d
-- but DARKEDEN.LoginPayType was an unrelated web-registration table (Account,
-- Password, Ssno, Email, addresses) with no WorldID column, so the query errored.
-- It held 0 rows, so renaming it is lossless. LOGIN_PAYTYPE_ALL_ALLLOW = 0 and
-- the no-row branch also yields 0, so an empty table of the right shape allows
-- login -- no seed data required.
RENAME TABLE LoginPayType TO LoginPayType_webreg_unused;
CREATE TABLE LoginPayType ( WorldID tinyint unsigned NOT NULL, PayType int NOT NULL DEFAULT 0, PRIMARY KEY (WorldID) );
-- 2026-08-09: CGConnect now succeeds, but character load calls
-- PlayerCreature::loadEventNewStartSupplyItemList() and
-- loadEventComebackSupplyItemList() (CGConnectHandler.cpp:452/453, 541/542,
-- 618/619 -- all three races), which query six tables that do not exist.
-- The missing table threw out to "UNHANDLED EXCEPTION" and killed the gameserver.
--
-- Columns are derived from the queries in PlayerCreature.cpp:
--   2744  SELECT E1.EventID, ifnull(E1.EventDesc,'') FROM EventNewStartSchedule E1
--         LEFT OUTER JOIN EventNewStart E2 ON E1.EventID=E2.EventID
--         AND E2.PlayerID=.. AND E2.Name=..
--         WHERE now() BETWEEN EventSDate AND EventEDate
--           AND (.. EventType=1 ..) OR (.. EventType=2 ..) AND E2.RecvDate is null
--   2782  INSERT IGNORE INTO EventNewStart VALUES(EventID, PlayerID, Name, now(), IP)
--   2791  SELECT .. GoodsID, GoodsCount FROM EventNewStartSupplyItem
--         WHERE EventID=.. AND (Race=7 OR Race=..)
--   2855  .. FROM EventComebackSchedule E1 LEFT OUTER JOIN EventComeback E2
--         .. WHERE now() BETWEEN EventSDate AND EventEDate
--            AND (.. <= EventBaseDate) AND E2.RecvDate is null
--   2890  INSERT IGNORE INTO EventComeback VALUES(EventID, PlayerID, now(), IP)
--   2898  SELECT .. GoodsID, GoodsCount FROM EventComebackSupplyItem
--         WHERE EventID=.. AND (Race=7 OR Race=..)
--
-- Left EMPTY on purpose: the schedule SELECTs then return zero rows, which is
-- the correct "no event running" outcome. RecvDate must stay NULLable because
-- the LEFT JOIN tests "E2.RecvDate is null".

CREATE TABLE IF NOT EXISTS EventNewStartSchedule (
  EventID    varchar(32)  NOT NULL,
  EventDesc  varchar(255) DEFAULT NULL,
  EventSDate datetime     NOT NULL DEFAULT '2000-01-01 00:00:00',
  EventEDate datetime     NOT NULL DEFAULT '2000-01-01 00:00:00',
  EventType  tinyint      NOT NULL DEFAULT 1,
  PRIMARY KEY (EventID)
);

CREATE TABLE IF NOT EXISTS EventNewStart (
  EventID  varchar(32) NOT NULL,
  PlayerID varchar(13) NOT NULL,
  Name     varchar(20) NOT NULL,
  RecvDate datetime    DEFAULT NULL,
  IP       varchar(15) DEFAULT NULL,
  PRIMARY KEY (EventID, PlayerID, Name)
);

CREATE TABLE IF NOT EXISTS EventNewStartSupplyItem (
  EventID    varchar(32)  NOT NULL,
  Race       int          NOT NULL DEFAULT 7,
  GoodsID    int          NOT NULL DEFAULT 0,
  GoodsCount int          NOT NULL DEFAULT 0,
  KEY IDX_EventID (EventID)
);

CREATE TABLE IF NOT EXISTS EventComebackSchedule (
  EventID       varchar(32)  NOT NULL,
  EventDesc     varchar(255) DEFAULT NULL,
  EventSDate    datetime     NOT NULL DEFAULT '2000-01-01 00:00:00',
  EventEDate    datetime     NOT NULL DEFAULT '2000-01-01 00:00:00',
  EventBaseDate datetime     NOT NULL DEFAULT '2000-01-01 00:00:00',
  PRIMARY KEY (EventID)
);

CREATE TABLE IF NOT EXISTS EventComeback (
  EventID  varchar(32) NOT NULL,
  PlayerID varchar(13) NOT NULL,
  RecvDate datetime    DEFAULT NULL,
  IP       varchar(15) DEFAULT NULL,
  PRIMARY KEY (EventID, PlayerID)
);

CREATE TABLE IF NOT EXISTS EventComebackSupplyItem (
  EventID    varchar(32) NOT NULL,
  Race       int         NOT NULL DEFAULT 7,
  GoodsID    int         NOT NULL DEFAULT 0,
  GoodsCount int         NOT NULL DEFAULT 0,
  KEY IDX_EventID (EventID)
);
-- 2026-08-09: PlayerCreature::loadEventPresentItemList() (called from
-- CGConnectHandler during character load) needs two things this schema lacks.
--
-- 1. EventPresentItemSchedule exists but has no date range:
--      PlayerCreature.cpp:2577
--      SELECT EventTitle, GoodsID, GoodsCount, Period FROM EventPresentItemSchedule
--       WHERE now() between StartDate and EndDate
--    -> "Unknown column 'StartDate' in 'where clause'", which reached
--       UNHANDLED EXCEPTION and killed the gameserver.
--
-- 2. EventPresentItemLog does not exist at all, and the SELECT names an index
--    explicitly, so the index must exist or USE INDEX() itself errors:
--      PlayerCreature.cpp:2605
--      SELECT count(*), to_days(now()) - to_days(ifnull(max(GiftRecvDate), ...))
--        FROM EventPresentItemLog USE INDEX(IDX_EventTitleAndPlayerID)
--       WHERE PlayerID=.. AND EventTitle=..
--      PlayerCreature.cpp:2642
--      INSERT IGNORE INTO EventPresentItemLog
--        (EventTitle, PlayerID, CharName, GiftRecvDate, GoodsID, GoodsCount, IP)
--
-- The schedule table stays empty, so the outer SELECT returns no rows and the
-- whole gift path is skipped -- the correct "no present event running" outcome.

ALTER TABLE EventPresentItemSchedule
  ADD COLUMN StartDate datetime NOT NULL DEFAULT '2000-01-01 00:00:00',
  ADD COLUMN EndDate   datetime NOT NULL DEFAULT '2000-01-01 00:00:00';

CREATE TABLE IF NOT EXISTS EventPresentItemLog (
  EventTitle   varchar(255) NOT NULL,
  PlayerID     varchar(13)  NOT NULL,
  CharName     varchar(20)  DEFAULT NULL,
  GiftRecvDate datetime     DEFAULT NULL,
  GoodsID      int          NOT NULL DEFAULT 0,
  GoodsCount   int          NOT NULL DEFAULT 0,
  IP           varchar(15)  DEFAULT NULL,
  KEY IDX_EventTitleAndPlayerID (EventTitle, PlayerID)
);
-- Pending schema fixes, generated from the source-vs-DB diff.
-- Effect* columns are varchar(10) NOT NULL in every table that
-- already has them, so the type here is copied, not guessed.
-- Blocker: EffectLoaderManager::load() during Ousters::load().

ALTER TABLE EffectAccuraForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectAccuraForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectBehemothForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectBehemothForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectExtremeForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectExtremeForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectGentisDungeon ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectGreyfellForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectGreyfellForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectLifeForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectLifeForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectMirForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectMirForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectMysteryPotion ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectOdinForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectOdinForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectPromotionAngelFlutter ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectPromotionBatWing ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectPromotionButterflyWing ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectRankBonusExpBlue ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectRankBonusExpRed ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectSoviusForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectSoviusForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectTituosForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectTituosForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';

-- NEEDS TYPE REVIEW (not emitted as SQL):
--   ContributeRewardCount.Race
--   MakePCLog.EndDate
--   PVPSystemObject.SignDate
--   PVPSystemObject.SignName
--   PVPSystemPartyObject.PartyID
--   SimpleQuest.YearTime
ALTER TABLE DSGMemberList ADD COLUMN DsgEndTime datetime DEFAULT NULL;  -- CGConnectHandler.cpp:1191

-- 2026-08-10: disable premium-zone gating (user request).
-- 124 of 150 zones had PremiumZone=1, including the starter areas (Eslania),
-- so nearly every door refused entry with "You can not access premium zone".
-- The client refuses locally: PacketUtil.cpp:648 sets the GCUpdateInfo premium
-- flag from Zone::isPremiumZone(), which reads this column, and the client then
-- blocks the door without ever contacting the server (the click never appears
-- in the packet log). Clearing the column is enough; no code change needed.
-- Zone data is cached at startup, so the gameserver must be restarted.
DROP TABLE IF EXISTS ZoneInfo_PremiumZone_backup;
CREATE TABLE ZoneInfo_PremiumZone_backup AS SELECT ZoneID, PremiumZone FROM ZoneInfo;
UPDATE ZoneInfo SET PremiumZone = 0;
-- To revert:
--   UPDATE ZoneInfo z JOIN ZoneInfo_PremiumZone_backup b USING (ZoneID)
--     SET z.PremiumZone = b.PremiumZone;

-- 2026-08-10: disable pay-play zone gating (user request).
-- The refusal is CGSelectTileEffectHandler.cpp:159-161 (stepping on a portal
-- tile), which tests pZoneInfo->isPayPlay() -- the PayPlayZone column -- and
-- then sends GSStringPool ID 24 (STRID_CANNOT_ENTER_PAY_ZONE), whose text is
-- You

-- 2026-08-10: disable pay-play zone gating (user request).
-- The refusal is CGSelectTileEffectHandler.cpp:159-161 (stepping on a portal
-- tile): it tests pZoneInfo->isPayPlay() -- the PayPlayZone column -- and sends
-- GSStringPool ID 24 (STRID_CANNOT_ENTER_PAY_ZONE), whose text reads
-- You can not access premium zone. The wording says premium but the gate is
-- PayPlayZone; the earlier PremiumZone change was aimed at the wrong column.
-- 8 zones were gated: 1204/1205/1206 (castles) and 1211/1212/1221/1222/1231
-- (castle dungeons). Zone data is cached at startup, so restart the gameserver.
DROP TABLE IF EXISTS ZoneInfo_PayPlayZone_backup;
CREATE TABLE ZoneInfo_PayPlayZone_backup AS SELECT ZoneID, PayPlayZone FROM ZoneInfo;
UPDATE ZoneInfo SET PayPlayZone = 0;
-- To revert:
--   UPDATE ZoneInfo z JOIN ZoneInfo_PayPlayZone_backup b USING (ZoneID)
--     SET z.PayPlayZone = b.PayPlayZone;

-- 2026-08-10: open pay/premium portals via the OPEN_PAYZONE server variable.
-- THIS is the real gate, not the ZoneInfo columns. Zone.cpp:1594 reads:
--     else if (pTargetZoneInfo->isPayPlay() && !pZoneInfo->isPayPlay()
--              || !g_pVariableManager->getVariable(OPEN_PAYZONE) )
-- Precedence makes that (A && B) || !OPEN_PAYZONE, so with OPEN_PAYZONE = 0
-- EVERY portal gets the refusal trigger whose counter-action sends GSStringPool
-- ID 24 -- regardless of PayPlayZone/PremiumZone. That is why clearing those two
-- columns changed nothing.
-- VariableManager loads from AttrInfo (attrID = variable id, attr1 = value) and
-- OPEN_PAYZONE is 193; the row did not exist (AttrInfo topped out at 137), so
-- the hardcoded default at VariableManager.cpp:277 (false) applied.
-- Same three-condition sites also gate Mikllizz Lair, Castle Dungeon and Master
-- Lair entry (ConditionEnter*.cpp), which this fixes too.
INSERT INTO AttrInfo (attrID, attr1, attr2, comm)
  VALUES (193, 1, 0, 'OPEN_PAYZONE - 1 opens pay/premium portals')
  ON DUPLICATE KEY UPDATE attr1 = 1;
-- To revert:  DELETE FROM AttrInfo WHERE attrID = 193;

-- 2026-08-20: second test account (user request): devola / test
-- Password is the MySQL 4.1 PASSWORD() equivalent that CLLoginHandler.cpp
-- computes: CONCAT('*', UPPER(SHA1(UNHEX(SHA1(pw))))). Derived in SQL rather
-- than pasted so it stays correct if the hashing scheme changes.
-- Only the NOT NULL columns without defaults are set explicitly; everything
-- else takes the column default, matching how devolo looks.
INSERT INTO Player
    (PlayerID, Password, Name, SSN, Event, Passwordwebsite, LogOn, Access, CurrentWorldID)
VALUES
    ('devola', CONCAT('*', UPPER(SHA1(UNHEX(SHA1('test'))))), '', '', '', '', 'LOGOFF', 'ALLOW', 1);
-- To revert:  DELETE FROM Player WHERE PlayerID = 'devola';

-- 2026-08-20: enable starter gear at first login (user request).
-- ItemUtil.cpp addNewbieItemToGear() -- for BOTH Slayer and Ousters -- opens with
--     if (g_pVariableManager->getVariable(EVENT_NEWBIE_ITEMS_GIVE) == 0) return true;
-- so with the variable unset no race received a starting weapon at all. Same
-- AttrInfo mechanism as OPEN_PAYZONE: attrID = VariableType id, attr1 = value.
-- EVENT_NEWBIE_ITEMS_GIVE is 236 (VariableManager.h:342) and had no row.
INSERT INTO AttrInfo (attrID, attr1, attr2, comm)
  VALUES (236, 1, 0, 'EVENT_NEWBIE_ITEMS_GIVE - 1 grants starter gear at first login')
  ON DUPLICATE KEY UPDATE attr1 = 1;
-- To revert:  DELETE FROM AttrInfo WHERE attrID = 236;

-- 2026-08-21: give the active Waterana effectively unlimited money (user request).
-- Two characters are named Waterana on account 'devola': a never-played Level 1
-- Slayer (zone 12, 0 gold) and the Level 9 Ousters in zone 1311 that had just
-- logged out. Only the Ousters was touched.
-- 2,000,000,000 rather than the 4,294,967,295 the unsigned column allows,
-- because several code paths cast gold to signed int (see PlayerCreature.cpp
-- ~1060, the StashGold writes), where anything over 2,147,483,647 goes negative.
UPDATE Ousters SET Gold = 2000000000 WHERE Name='Waterana' AND PlayerID='devola';
-- revert: UPDATE Ousters SET Gold = 500 WHERE Name='Waterana' AND PlayerID='devola';

-- =====================================================================
-- 2026-08-21: allow reusing a character name held only by INACTIVE
-- characters. This build soft-deletes (CLDeletePCHandler #else branch:
-- Active='INACTIVE', data kept), so the name must be freed by RENAMING the
-- dead character and everything keyed to its name, not by purging.
--
-- Renamed form is [D_<hex>]<OriginalName>, e.g. [D_001]Caravice, so a name
-- can be reused up to 0xFFF times before needing a 4th hex digit. Brackets
-- and '_' are unreachable for players: isAvailableCharName() whitelists only
-- a-z A-Z 0-9 and Korean, 4-10 chars. Player name length is still enforced
-- in C++, NOT by the column width -- widening these columns does not let
-- anyone create a longer name.
--
-- 173 columns widened varchar(10)->varchar(32): Slayer/Vampire/Ousters.Name
-- plus every OwnerID column under 32 chars. Widening cannot lose data.
-- Reverts are listed after the applied statements.
-- =====================================================================
ALTER TABLE `ARObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `BeltObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `BladeObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `BloodBibleObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `BloodBibleSignObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `BombMaterialObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `BombObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `BraceletObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `CallNPCCardObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `CanEnterGDRLair` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `CarryingReceiverObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `CastleSymbolObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `CheckMoneyObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `CoatObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `CodeSheetObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `CommonQuestItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `ComposMeiObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `ContractOfBloodObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `CoreZapObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `CoupleRingObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `CrossObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `CueOfAdamObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `DermisObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `DyePotionObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `ETCObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectAccuraForceScroll` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectAccuraForceScroll2` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectAcidTouch` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectAftermath` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectBehemothForceScroll` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectBehemothForceScroll2` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectBloodDrain` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectCarnelianForceScroll` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectCarnelianForceScroll2` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectDetectHidden` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectEXP` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectExtremeForceScroll` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectExtremeForceScroll2` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectFlare` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectGentisDungeon` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectGreyfellForceScroll` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectGreyfellForceScroll2` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectHoodlumStigma` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectKillAftermath` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectLifeForceScroll` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectLifeForceScroll2` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectLight` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectMirForceScroll` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectMirForceScroll2` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectMute` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectMysteryPotion` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectOdinForceScroll` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectOdinForceScroll2` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectParalysis` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectPoison` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectPoisonousHands` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectPremiumService` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectPromotionAngelFlutter` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectPromotionBatWing` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectPromotionButterflyWing` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectProtectionFromParalysis` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectProtectionFromPoison` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectRankBonusExpBlue` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectRankBonusExpRed` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectRestore` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectSafeForceScroll` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectSafeForceScroll2` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectSoviusForceScroll` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectSoviusForceScroll2` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectTituosForceScroll` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectTituosForceScroll2` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EffectYellowPoisonToCreature` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EnemyErase` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EtherealChainObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EventBallObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EventETCObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EventGiftBoxObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EventItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EventQuestAdvance` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EventStarObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `EventTreeObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `FasciaObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `FlagSet` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `GQuestItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `GQuestSave` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `GloveObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `HelmObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `HolyWaterObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `KeyObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `LarvaObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `LearningItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `LuckyBagObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `MaceObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `MagazineObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `MineObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `MittenObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `MixingItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `MofusLog` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `MofusPowerPoint` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `MoneyObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `MoonCardObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `MotorcycleObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `NecklaceObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `NicknameBook` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OlympicStat` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `Ousters` MODIFY `Name` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersArmsbandObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersBootsObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersChakramObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersCircletObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersCoatObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersHarmonicPendentObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersPendentObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersRingObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersSkillSave` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersStoneObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersSummonItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersTunningItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersWingItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `OustersWristletObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `PersonaObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `PetEnchantItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `PetFoodObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `PetItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `PetItemObject1` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `PotionObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `PupaObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `QuestItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `RankBonusData` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `RelicObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `ResurrectItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `RingObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SGObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SMGObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SMSAddressBook` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SMSItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SRObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `Script` MODIFY `OwnerID` varchar(32) ;
ALTER TABLE `SerumObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `ShieldObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `ShoesObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `ShoulderArmorObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SkillBookObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SkillSave` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SkullObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `Slayer` MODIFY `Name` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SlayerPortalItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SlayerTunningItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SubInventoryObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SweeperObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `SwordObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `TimeLimitItems` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `TrapItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `TrouserObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `Vampire` MODIFY `Name` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampireAmuletObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampireBraceletObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampireCoatObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampireCoupleRingObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampireETCObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampireEarringObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampireNecklaceObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampirePortalItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampireRingObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampireSkillSave` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampireTunningItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampireWeaponObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `VampireWingItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `WarItemObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `WaterObject` MODIFY `OwnerID` varchar(32) NOT NULL DEFAULT '';
ALTER TABLE `ZoneInfo` MODIFY `OwnerId` varchar(32) ;
ALTER TABLE `ZoneInfo_bak` MODIFY `OwnerId` varchar(32) ;

-- ---- reverts for the block above ----
-- revert: ALTER TABLE `ARObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `BeltObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `BladeObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `BloodBibleObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `BloodBibleSignObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `BombMaterialObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `BombObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `BraceletObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `CallNPCCardObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `CanEnterGDRLair` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `CarryingReceiverObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `CastleSymbolObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `CheckMoneyObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `CoatObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `CodeSheetObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `CommonQuestItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `ComposMeiObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `ContractOfBloodObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `CoreZapObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `CoupleRingObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `CrossObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `CueOfAdamObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `DermisObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `DyePotionObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `ETCObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectAccuraForceScroll` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectAccuraForceScroll2` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectAcidTouch` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectAftermath` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectBehemothForceScroll` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectBehemothForceScroll2` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectBloodDrain` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectCarnelianForceScroll` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectCarnelianForceScroll2` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectDetectHidden` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectEXP` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectExtremeForceScroll` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectExtremeForceScroll2` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectFlare` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectGentisDungeon` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectGreyfellForceScroll` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectGreyfellForceScroll2` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectHoodlumStigma` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectKillAftermath` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectLifeForceScroll` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectLifeForceScroll2` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectLight` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectMirForceScroll` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectMirForceScroll2` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectMute` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectMysteryPotion` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectOdinForceScroll` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectOdinForceScroll2` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectParalysis` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectPoison` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectPoisonousHands` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectPremiumService` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectPromotionAngelFlutter` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectPromotionBatWing` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectPromotionButterflyWing` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectProtectionFromParalysis` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectProtectionFromPoison` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectRankBonusExpBlue` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectRankBonusExpRed` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectRestore` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectSafeForceScroll` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectSafeForceScroll2` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectSoviusForceScroll` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectSoviusForceScroll2` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectTituosForceScroll` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectTituosForceScroll2` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EffectYellowPoisonToCreature` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EnemyErase` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EtherealChainObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EventBallObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EventETCObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EventGiftBoxObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EventItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EventQuestAdvance` MODIFY `OwnerID` varchar(20) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EventStarObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `EventTreeObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `FasciaObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `FlagSet` MODIFY `OwnerID` varchar(30) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `GQuestItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `GQuestSave` MODIFY `OwnerID` varchar(20) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `GloveObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `HelmObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `HolyWaterObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `KeyObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `LarvaObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `LearningItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `LuckyBagObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `MaceObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `MagazineObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `MineObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `MittenObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `MixingItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `MofusLog` MODIFY `OwnerID` varchar(20) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `MofusPowerPoint` MODIFY `OwnerID` varchar(30) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `MoneyObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `MoonCardObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `MotorcycleObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `NecklaceObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `NicknameBook` MODIFY `OwnerID` varchar(20) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OlympicStat` MODIFY `OwnerID` varchar(20) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `Ousters` MODIFY `Name` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersArmsbandObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersBootsObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersChakramObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersCircletObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersCoatObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersHarmonicPendentObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersPendentObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersRingObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersSkillSave` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersStoneObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersSummonItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersTunningItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersWingItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `OustersWristletObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `PersonaObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `PetEnchantItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `PetFoodObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `PetItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `PetItemObject1` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `PotionObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `PupaObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `QuestItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `RankBonusData` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `RelicObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `ResurrectItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `RingObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SGObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SMGObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SMSAddressBook` MODIFY `OwnerID` varchar(20) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SMSItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SRObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `Script` MODIFY `OwnerID` varchar(30) ;
-- revert: ALTER TABLE `SerumObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `ShieldObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `ShoesObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `ShoulderArmorObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SkillBookObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SkillSave` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SkullObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `Slayer` MODIFY `Name` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SlayerPortalItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SlayerTunningItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SubInventoryObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SweeperObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `SwordObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `TimeLimitItems` MODIFY `OwnerID` char(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `TrapItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `TrouserObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `Vampire` MODIFY `Name` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampireAmuletObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampireBraceletObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampireCoatObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampireCoupleRingObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampireETCObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampireEarringObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampireNecklaceObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampirePortalItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampireRingObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampireSkillSave` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampireTunningItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampireWeaponObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `VampireWingItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `WarItemObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `WaterObject` MODIFY `OwnerID` varchar(10) NOT NULL DEFAULT '';
-- revert: ALTER TABLE `ZoneInfo` MODIFY `OwnerId` varchar(20) ;
-- revert: ALTER TABLE `ZoneInfo_bak` MODIFY `OwnerId` varchar(20) ;

-- =====================================================================
-- 2026-08-26: applied to DARKEDEN2 (the database the servers now use,
-- via DB_DB in the .conf files; DARKEDEN is kept untouched as the old copy).
-- =====================================================================

-- Decouple WorldDBInfo from the database name and credentials.
--
-- Every server reads this table to build the connection that
-- getConnection(WorldID) returns. Because the columns were mandatory, the
-- database name was pinned in two places: DB_DB in the .conf AND a row here.
-- Repointing the config therefore split the server in half -- accounts went to
-- the new DB (getConnection("DARKEDEN") -> default connection) while character
-- create/delete still went to the old one. Blank now means "use the config".
--
-- REQUIRES the matching DatabaseManager.cpp change; with an older binary a
-- blank row yields Connection("","","","",0) and the world connection fails.
UPDATE WorldDBInfo SET Host = '', DB = '', User = '', Password = '', Port = 0;
-- revert: restore the original WorldDBInfo row. Values are the DB_HOST /
--         DB_DB / DB_USER / DB_PASSWORD already in conf/*.local.conf --
--         deliberately not repeated here so this file carries no credential.

-- Account devolo / test (user request). Same PASSWORD() equivalent as devola.
INSERT INTO Player
    (PlayerID, Password, Name, SSN, Event, Passwordwebsite, LogOn, Access, CurrentWorldID)
VALUES
    ('devolo', CONCAT('*', UPPER(SHA1(UNHEX(SHA1('test'))))), '', '', '', '', 'LOGOFF', 'ALLOW', 1);
-- revert: DELETE FROM Player WHERE PlayerID = 'devolo';

-- =====================================================================
-- NOTE on the 2026-08-26 DARKEDEN2 block above: DARKEDEN2 and DARKEDEN3 were
-- throwaway databases used to prove the schema script spins up a working
-- server. Both have been dropped; DARKEDEN is the live database again.
--   * the WorldDBInfo blanking HAS been applied to DARKEDEN (see below)
--   * the devolo account INSERT does NOT apply -- DARKEDEN already had it
-- =====================================================================

-- 2026-08-26: WorldDBInfo decoupled in the live DARKEDEN database.
-- Blank = "use the config" (DatabaseManager.cpp). Puts the database name in one
-- place (DB_DB) and removes the plaintext DB password from the table.
UPDATE DARKEDEN.WorldDBInfo SET Host='', DB='', User='', Password='', Port=0;
-- revert: restore the original WorldDBInfo row. Values are the DB_HOST /
--         DB_DB / DB_USER / DB_PASSWORD already in conf/*.local.conf --
--         deliberately not repeated here so this file carries no credential.

-- 2026-08-26: deleteNum, for reusing the name of a soft-deleted character.
-- When a name is reused, the dead holder is renamed to [D_<hex>]<Name> and this
-- column stores the sequence number. It exists so the counter lives in a column
-- rather than being parsed back out of the marker name with sscanf, which broke
-- once the counter passed 0xFFF and the hex strings stopped being equal width.
-- Safe to add: nothing does SELECT * on these tables, and every INSERT lists
-- its columns explicitly.
ALTER TABLE DARKEDEN.Slayer  ADD COLUMN deleteNum INT UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE DARKEDEN.Vampire ADD COLUMN deleteNum INT UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE DARKEDEN.Ousters ADD COLUMN deleteNum INT UNSIGNED NOT NULL DEFAULT 0;
-- revert: ALTER TABLE DARKEDEN.Slayer  DROP COLUMN deleteNum;
-- revert: ALTER TABLE DARKEDEN.Vampire DROP COLUMN deleteNum;
-- revert: ALTER TABLE DARKEDEN.Ousters DROP COLUMN deleteNum;

-- =====================================================================
-- 2026-08-26  CharID migration, Phase 1: surrogate character identity.
--
-- Full backup taken first: ~/backups/darkeden_full_20260826.sql
--   (4.6 MB, 522 CREATE TABLE, 257 INSERT, 4 triggers, "Dump completed")
--
-- Slayer is the universal registry: CLCreatePCHandler always writes a row
-- there regardless of race, and it carries the Race column. Verified zero
-- Vampire/Ousters rows exist without a matching Slayer row (14 registry rows
-- = 6 SLAYER + 7 OUSTERS + 1 VAMPIRE).
--
-- So identity is issued ONCE by Slayer.CharID and COPIED to the race tables.
-- Giving all three their own AUTO_INCREMENT would create three independent
-- sequences, and OwnerCharID in the 190 item tables could not tell you which
-- table's numbering it referred to.
--
-- Additive only: nothing reads CharID yet.
-- =====================================================================
ALTER TABLE DARKEDEN.Slayer  ADD COLUMN CharID INT UNSIGNED NOT NULL AUTO_INCREMENT UNIQUE;
ALTER TABLE DARKEDEN.Vampire ADD COLUMN CharID INT UNSIGNED NOT NULL DEFAULT 0;
ALTER TABLE DARKEDEN.Ousters ADD COLUMN CharID INT UNSIGNED NOT NULL DEFAULT 0;
UPDATE DARKEDEN.Vampire v JOIN DARKEDEN.Slayer s ON s.Name = v.Name SET v.CharID = s.CharID;
UPDATE DARKEDEN.Ousters o JOIN DARKEDEN.Slayer s ON s.Name = o.Name SET o.CharID = s.CharID;
-- revert: ALTER TABLE DARKEDEN.Slayer  DROP COLUMN CharID;
-- revert: ALTER TABLE DARKEDEN.Vampire DROP COLUMN CharID;
-- revert: ALTER TABLE DARKEDEN.Ousters DROP COLUMN CharID;

-- =====================================================================
-- 2026-08-26  CharID migration, Phase 2: OwnerCharID alongside OwnerID.
--
-- Additive only. OwnerID remains authoritative and nothing reads the new
-- column yet, so this is reversible by dropping the columns.
--
-- Applied to 184 of the 190 OwnerID tables. Excluded because their OwnerID is
-- NOT a character name:
--   Script          NPC names (verified: 그루버, 요한, 크리스)
--   ZoneInfo/_bak   zone data (column is spelled OwnerId)
--   ItemTraceLog    audit -- a name is the right thing to record
--   MoneyTraceLog   audit
--   MofusLog        audit
--
-- The target list came from ItemLoaderManager, not from data shape: its three
-- race overloads name 101 item classes loaded per character, and every one has
-- a matching <Class>Object table.
--
-- Result: 113 of 11,545 rows carry a CharID. The rest legitimately do not --
-- 11,155 are dropped instances in STORAGE_ZONE(5)/STORAGE_CORPSE(8) with no
-- character owner, and the remainder are orphans of characters deleted before
-- this port. Verified zero rows whose OwnerID matches a live character were
-- left unlinked.
-- =====================================================================
-- for each of the 184 tables:
--   ALTER TABLE <tbl> ADD COLUMN OwnerCharID INT UNSIGNED NOT NULL DEFAULT 0;
--   UPDATE <tbl> t JOIN Slayer s ON s.Name = t.OwnerID SET t.OwnerCharID = s.CharID;
--
-- revert (generates the DROPs for every table that has the column):
--   SELECT CONCAT('ALTER TABLE `',TABLE_NAME,'` DROP COLUMN OwnerCharID;')
--     FROM information_schema.COLUMNS
--    WHERE TABLE_SCHEMA='DARKEDEN' AND COLUMN_NAME='OwnerCharID';

-- =====================================================================
-- 2026-08-26  CharID migration, Phase 3 prerequisite: OwnerCharID sync
--             triggers (368 = 184 tables x BEFORE INSERT + BEFORE UPDATE).
--
-- Why triggers rather than editing the writers: there are ~300 places that
-- write an owner -- 102 per-class create() INSERTs plus 199 sites building an
-- "OwnerID='<name>'" field string for tinysave(). Missing one detaches an item
-- from its owner SILENTLY: no compile error, no runtime error, the item just
-- stops loading. A trigger makes that class of mistake structurally impossible
-- -- whichever code path writes OwnerID, the derived column follows.
--
-- Verified through the real write paths: INSERT (create) -> CharID set;
-- UPDATE OwnerID (trade) -> follows; OwnerID='' (drop to zone) -> 0;
-- pickup -> restored; unrelated UPDATE -> unchanged.
--
-- TRANSITIONAL. Drop them once writers set OwnerCharID directly.
-- =====================================================================
-- for each of the 184 tables, for ev in (INSERT, UPDATE):
--   CREATE TRIGGER `trg_<tbl>_cid_<ins|upd>` BEFORE <ev> ON `<tbl>`
--     FOR EACH ROW SET NEW.OwnerCharID =
--       IFNULL((SELECT CharID FROM Slayer WHERE Name = NEW.OwnerID), 0);
--
-- revert (generates the DROPs):
--   SELECT CONCAT('DROP TRIGGER IF EXISTS `',TRIGGER_NAME,'`;')
--     FROM information_schema.TRIGGERS
--    WHERE TRIGGER_SCHEMA='DARKEDEN' AND TRIGGER_NAME LIKE 'trg\_%\_cid\_%';

-- =====================================================================
-- 2026-08-31  Menegroth dungeon, phase 1: the 18 ZoneInfo rows.
--
-- The dungeon system was already written, compiled in
-- (__MENEGROTH_DOUNGEON_SYSTEM__, VersionType.h:30) and backed by all 18
-- server maps in data/ -- but ZoneInfo had no rows for 1701-1718, so the
-- zones were never instantiated and nothing could reach them.
--
-- Layout is fixed by MenegrothDoungeonManager::getDoungeonZoneToMove() and
-- was confirmed independently against the zone id stored in each .smp
-- header (they agree exactly):
--     1701-1706 Slayer / 1707-1712 Vampire / 1713-1718 Ousters, floors 1-6.
--
-- Resurrect points reuse getAltarPosToMove()'s towns, which is where the
-- server already sends a player who logs in while inside the dungeon:
--     Slayer -> 12 (47,182)   Vampire -> 22 (217,230)   Ousters -> 81 (191,111)
--
-- MonsterList/EventMonsterList are intentionally EMPTY. Zones only in this
-- pass; monsters, traps, items and the entrance statues are still to come.
--
-- Applied from: db/menegroth_zones.sql  (re-runnable, ON DUPLICATE KEY UPDATE)
--
-- revert:
--   DELETE FROM `ZoneInfo` WHERE ZoneID BETWEEN 1701 AND 1718;
-- =====================================================================
--
-- 2026-08-31  CORRECTION to the above. The first version gave all three race
-- wings the same ShortName ('Menegroth 1F' x3), and the gameserver refused to
-- boot: ZoneInfoManager::addZoneInfo keys BOTH FullName and ShortName into
-- lookup maps for the *warp command and throws on a collision --
--     "Duplicated Zone Short Name"  ->  UNHANDLED EXCEPTION, exit during
--     ObjectManager::init(), before ZoneGroupManager ever ran.
-- ShortName is now 'Menegroth<S|V|O><N>F' (space-free, since *warp takes it).
-- Checked against all 150 pre-existing zones: no FullName or ShortName clash.
-- Re-running db/menegroth_zones.sql fixes rows in place.

-- =====================================================================
-- 2026-08-31  Content imported from the ORIGINAL 664 dump (db/DARKEDEN.sql),
-- which the user located. Our database is kept as-is (characters, CharID
-- migration, 368 OwnerCharID triggers, InnoDB/utf8mb4); only missing rows and
-- missing tables are added.
--
-- Why not adopt the original wholesale: it has no CharID/OwnerCharID column
-- anywhere, no triggers, is MyISAM/utf8, carries another operator's test
-- characters, AND is missing 6 columns plus 17 tables the v664 source needs
-- (SystemAvailabilities alone is referenced in 72 files, and ZoneInfoManager
-- calls getZoneOpenDegree() during startup). It is a content donor, not a base.
--
-- Mapped by COLUMN NAME, never position -- the original's SkillBalance begins
-- with AvoidAttribute while ours holds it at index 29, so a positional copy
-- would have shifted every column silently.
--
-- Applied from: db/original664_content.sql   (rows)
--               db/original664_tables.sql    (11 tables)
--
--   SkillBalance               +107  (includes all 20 rare skills 419-438)
--   SkillBookInfo              + 41  (the rare skill books)
--   ZoneInfo                   + 18  REPLACE: the real Menegroth 1701-1718
--                                    rows supersede the ones hand-authored
--                                    earlier today; these carry MonsterList
--   MonsterInfo                +144  (includes Cabracam bosses 1021-1026)
--   CommonQuestItemInfo        + 53  (includes Menegroth seals, types 6-11)
--   MenegrothDoungeonTrapInfo  +216  (trap positions per zone)
--   NPC                        +140  (72 of them inside Menegroth 1701-1718)
--   Script                     +260  (NPC dialogue)
--   11 tables created: EventNewbie, GuildMasterChangeLog, HarmonicInfo,
--     ItemUseLog, LilithSeriesLog, PetMixingLog, SpeedHackLog, WebMarketKey,
--     WeekItemGive, WeekItemInfo, uds_msg  (MyISAM/utf8 -> InnoDB/utf8mb4)
--
-- 46 further tables in the original are the previous operator's residue
-- (per-month donation tables, temp copies, Chinese-shop logs) and the v664
-- source never names them, so they are deliberately NOT imported. Two more
-- were excluded as verified grep false positives: `member` (the English word;
-- 0 rows) and `NPC_1` (matched STRID_EVENT_NPC_1; an operator backup of NPC).
--
-- OwnerCharID on the imported rows is filled by the existing triggers.
--
-- revert:
--   DELETE FROM `SkillBalance`   WHERE Type   BETWEEN 397 AND 505;
--   DELETE FROM `SkillBookInfo`;
--   DELETE FROM `ZoneInfo`       WHERE ZoneID BETWEEN 1701 AND 1718;
--   DELETE FROM `MonsterInfo`    WHERE MType  > 850;
--   DELETE FROM `CommonQuestItemInfo`;
--   DELETE FROM `MenegrothDoungeonTrapInfo`;
--   -- NPC/Script: no clean range; restore from the pre-import backup instead.
--   DROP TABLE `EventNewbie`,`GuildMasterChangeLog`,`HarmonicInfo`,`ItemUseLog`,
--     `LilithSeriesLog`,`PetMixingLog`,`SpeedHackLog`,`WebMarketKey`,
--     `WeekItemGive`,`WeekItemInfo`,`uds_msg`;
-- =====================================================================
--
-- 2026-08-31  Fix while importing: MySQL 5.0 allowed '0000-00-00' defaults,
-- MySQL 8 rejects them under NO_ZERO_DATE --
--     ERROR 1067 (42000) at line 41: Invalid default value for 'CoupleDate'
-- Three columns affected (HarmonicInfo.CoupleDate, ItemUseLog.UseTime,
-- WebMarketKey.IssueDate), all rewritten to NULL DEFAULT NULL rather than
-- relaxing sql_mode: our schema contains no zero dates anywhere, and nothing
-- reads these defaults (the server writes CoupleDate with now(), the log
-- timestamps are always supplied, and HarmonicInfo is referenced only from
-- commented-out code).
--
-- Also verified before importing: the incoming Menegroth ZoneInfo rows have no
-- FullName/ShortName collision with our existing 150 zones. They are unique
-- within the original dump's 196 zones, which does not imply uniqueness within
-- ours -- and a collision aborts the gameserver at startup.
--
-- 2026-08-31  Follow-up: warping into Menegroth 1701 SEGFAULTED the gameserver.
--     dmesg: "gameserver[...]: segfault at 50"
--     addr2line -> DirectiveSet::canAttackAir() const, Directive.h:259
--
-- Cause: MonsterInfo.AIType points at DirectiveSet. The 144 imported monsters
-- use AITypes 166-205, of which our DirectiveSet had only part -- 37 were
-- missing. getDirectiveSet() returned NULL and the caller dereferences it with
-- no NULL check, so the first Menegroth monster spawned killed the server.
-- I imported MonsterInfo without the lookup table it depends on.
--
-- Fix: DirectiveSet added to db/original664_content.sql (+37 rows, ids 166-205,
-- the existing 169 untouched). Re-running that file is safe and idempotent.
--
-- Audited the rest of the imported content for the same class of dangling
-- reference rather than fixing one and hitting the next. Only other unresolved
-- id is AIType 65535, which is a "no AI" sentinel on props (Auto Turret, Drum,
-- Tripods); those monsters predate this import and have always been fine.
-- All six Cabracam bosses (1021-1026) use AIType 181, which exists.
--
-- revert:  DELETE FROM `DirectiveSet` WHERE ID BETWEEN 166 AND 205;
--
-- 2026-08-31  Repair: the content file was run twice and three target tables
-- had NO unique key, so INSERT IGNORE had nothing to ignore on and inserted
-- every row again. My error -- I described the file as safe to re-run without
-- checking that each table could actually enforce that.
--
--   SkillBookInfo               82 rows /  41 distinct ItemType
--   MenegrothDoungeonTrapInfo  432 rows / 213 distinct positions
--   NPC                        391 rows / 251 distinct (Name, ZoneID)
--
-- Caught at startup by an assertion rather than running corrupt:
--   InfoClassManager.cpp:119  m_pItemInfos[getItemType()] == NULL
--   <- SkillBookInfoManager::load()   (two books claiming one ItemType)
--
-- The six tables that DO have a unique key were unaffected and verified clean:
-- SkillBalance 481/481, MonsterInfo 796/796, ZoneInfo 168/168, Script
-- 1436/1436, DirectiveSet 206/206, CommonQuestItemInfo 53/53.
--
-- Applied from: db/fix_duplicate_import.sql -- de-duplicates in place (NOT
-- drop/recreate: SkillBookInfo carries trg_SkillBookInfo_cid_ins/upd, and NPC
-- holds 111 rows predating the import) and then adds the missing unique keys,
-- which makes the content import idempotent from here on.
--
-- Note: the original dump itself holds 3 exact repeats in the trap table --
-- type 1 at (16,66) in zones 1705/1711/1717, floor 5 of each wing -- so the
-- deduped count is 213, not 216. Two identical traps on one tile are redundant.
--
-- revert:
--   ALTER TABLE `SkillBookInfo`             DROP KEY `uk_SkillBookInfo`;
--   ALTER TABLE `MenegrothDoungeonTrapInfo` DROP KEY `uk_MenegrothTrap`;
--   ALTER TABLE `NPC`                       DROP KEY `uk_NPC`;
--   (the removed duplicate rows were exact copies; nothing unique was lost)
--
-- 2026-08-31  Third crash, same shape: killing a Menegroth monster aborted the
-- server with no message. Fixed main.cpp's terminate/unexpected handlers to
-- rethrow-and-catch so the exception NAMES itself, and it named itself at once:
--     UNHANDLED EXCEPTION OCCURED : const char*: Skull::Skull() : Invalid
--     item type or optionType
-- A bare const char* throw, which no catch(Error&) in the codebase can see --
-- which is exactly why every earlier log showed only the banner.
--
-- Cause: MonsterInfo.SkullType indexes SkullInfo. Ours held 0-75; the imported
-- monsters use up to 87 (BogletB in zone 1704 uses 79). Third missing lookup
-- table after DirectiveSet.
--
-- So rather than wait for a fourth, swept EVERY table present in both dumps
-- for "original has rows we lack": 58 of them. Our snapshot is substantially
-- thinner than the real 664 database. Added the ones the imported content
-- indexes into: SkullInfo +12, EventTreeInfo +48, AttrInfo +78, OptionInfo +41,
-- ItemClass +104, UniqueItemInfo +11, WayPointInfo +76, GSStringPool +98.
--
-- CreatureSprite deliberately EXCLUDED although the original has 491 rows:
-- our table is missing the original's `SpriteType` column entirely (8 cols vs
-- 9), so a name-mapped copy would insert 491 rows stripped of the column that
-- identifies them, into a table with no unique key. It is empty here and the
-- client carries its own creaturesprite.inf.
--
-- Verified before emitting: 8 of the 9 new targets have a PRIMARY KEY, so
-- INSERT IGNORE genuinely dedupes on re-run (the lesson from the duplicate
-- import above). CreatureSprite was the only keyless one and is excluded.
--
-- revert:
--   DELETE FROM `SkullInfo`      WHERE SkullType > 75;
--   DELETE FROM `EventTreeInfo`  WHERE ItemType NOT IN (SELECT ...) -- see backup
--   (simplest: restore db/pre_import_backup.sql)
