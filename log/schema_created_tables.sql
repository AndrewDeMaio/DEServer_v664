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
