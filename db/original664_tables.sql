-- =====================================================================
-- Tables present in the original 664 dump but absent from our database.
--
-- Filtered to those the v664 SOURCE actually references -- the rest of the
-- 59 are the previous operator's residue (per-month donation tables, temp
-- copies, logs) and are deliberately not imported.
--
-- Converted from MyISAM/utf8 to InnoDB/utf8mb4 to match the rest of our
-- database rather than leaving it half one engine and half the other.
--
-- revert:  DROP TABLE for each table created below.
-- =====================================================================

USE DARKEDEN;

-- ----------------------------------------------------------------------
DROP TABLE IF EXISTS `EventNewbie`;
CREATE TABLE `EventNewbie` (
  `Name` varchar(10) NOT NULL default '',
  PRIMARY KEY  (`Name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

INSERT INTO `EventNewbie` VALUES ('dfdff33'),('dfsdffff'),('dsdsad'),('sadddd'),('sadsadsa'),('sdadasdsa'),('sdsdasad'),('sssss');

-- ----------------------------------------------------------------------
DROP TABLE IF EXISTS `GuildMasterChangeLog`;
CREATE TABLE `GuildMasterChangeLog` (
  `ID` int(10) unsigned NOT NULL auto_increment,
  `GuildID` int(10) unsigned NOT NULL default '0',
  `WorldID` tinyint(3) unsigned NOT NULL default '0',
  `PrevMaster` varchar(10) NOT NULL default '',
  `NewMaster` varchar(10) NOT NULL default '',
  PRIMARY KEY  (`ID`),
  KEY `GuildMasterChangeLog_u1` (`GuildID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- (no rows in the original)

-- ----------------------------------------------------------------------
DROP TABLE IF EXISTS `HarmonicInfo`;
CREATE TABLE `HarmonicInfo` (
  `ID` smallint(5) unsigned NOT NULL auto_increment,
  `Ousters1` char(10) NOT NULL default '',
  `Ousters2` char(10) NOT NULL default '',
  `Race` tinyint(4) NOT NULL default '0',
  `CoupleDate` date NULL DEFAULT NULL,
  PRIMARY KEY  (`ID`),
  KEY `HarmonicInfo_m1` (`Ousters1`),
  KEY `HarmonicInfo_m2` (`Ousters2`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- (no rows in the original)

-- ----------------------------------------------------------------------
DROP TABLE IF EXISTS `ItemUseLog`;
CREATE TABLE `ItemUseLog` (
  `SeqNum` bigint(20) unsigned NOT NULL auto_increment,
  `ItemID` bigint(20) unsigned NOT NULL default '0',
  `ItemClass` varchar(25) NOT NULL default '',
  `ItemType` tinyint(3) unsigned NOT NULL default '0',
  `OwnerID` varchar(10) NOT NULL default '',
  `BeforeCount` tinyint(3) unsigned NOT NULL default '0',
  `RemainCount` tinyint(3) unsigned NOT NULL default '0',
  `UseTime` datetime NULL DEFAULT NULL,
  PRIMARY KEY  (`SeqNum`),
  KEY `IDX_ItemUseLog` (`ItemClass`,`ItemType`),
  KEY `IDX_OwnerID` (`OwnerID`)
) ENGINE=InnoDB AUTO_INCREMENT=108 DEFAULT CHARSET=utf8mb4;

INSERT INTO `ItemUseLog` VALUES (49,3,'EFFECT_ITEM',47,'Moldovia',1,0,'2020-11-27 01:52:10'),(50,2,'EFFECT_ITEM',5,'Moldovia',1,0,'2020-11-27 13:23:04'),(51,10,'EFFECT_ITEM',5,'Moldovia',1,0,'2020-11-29 13:49:24'),(52,16,'EFFECT_ITEM',47,'Oustras',1,0,'2020-11-29 15:10:05'),(53,19,'EFFECT_ITEM',5,'Vampiras',1,0,'2020-12-02 15:08:23'),(54,22,'EFFECT_ITEM',47,'Slangs2',1,0,'2020-12-02 15:50:06'),(55,20,'EFFECT_ITEM',47,'Vampiras',1,0,'2020-12-02 15:51:34'),(56,15,'EFFECT_ITEM',5,'Oustras',1,0,'2020-12-03 10:58:11'),(57,30,'EFFECT_ITEM',47,'Sasaee',1,0,'2020-12-04 06:24:25'),(58,21,'EFFECT_ITEM',5,'Slangs2',1,0,'2020-12-07 11:42:42'),(59,39,'EFFECT_ITEM',40,'GM-netshow',1,0,'2020-12-07 11:47:01'),(60,26,'EFFECT_ITEM',47,'Slangs2',1,0,'2020-12-09 13:22:24'),(61,38,'EFFECT_ITEM',5,'Slangs2',1,0,'2020-12-09 13:22:43'),(62,40,'EFFECT_ITEM',5,'Slangs2',1,0,'2020-12-09 13:59:01'),(63,41,'EFFECT_ITEM',5,'Slangs2',1,0,'2020-12-10 14:25:35'),(64,43,'EFFECT_ITEM',5,'Slangs2',1,0,'2020-12-10 15:47:29'),(65,44,'EFFECT_ITEM',5,'Slangs2',1,0,'2020-12-12 15:32:02'),(66,46,'EFFECT_ITEM',5,'Slangs2',1,0,'2020-12-16 12:51:39'),(67,51,'EFFECT_ITEM',47,'GM-netshow',1,0,'2020-12-26 02:11:59'),(68,2,'CALLNPC_CARD',1,'GM-vamp',1,0,'2020-12-26 15:09:48'),(69,2,'CALLNPC_CARD',1,'GM-vamp',1,0,'2020-12-29 01:37:50'),(70,32,'EFFECT_ITEM',47,'Slangs2',1,0,'2021-01-04 23:22:57'),(71,48,'EFFECT_ITEM',5,'Slangs2',1,0,'2021-01-04 23:24:16'),(72,50,'EFFECT_ITEM',5,'GM-netshow',1,0,'2021-01-14 21:32:03'),(73,53,'EFFECT_ITEM',47,'GM-netshow',1,0,'2021-01-17 12:37:45'),(74,62,'EFFECT_ITEM',5,'GM-netshow',1,0,'2021-01-18 09:27:55'),(75,69,'EFFECT_ITEM',5,'½½·¹ÀÌ',1,0,'2021-01-20 12:25:22'),(76,64,'EFFECT_ITEM',47,'GM-netshow',1,0,'2021-01-23 00:42:38'),(77,90,'EFFECT_ITEM',77,'¹ìÆÄ½ºÅ³2',1,0,'2021-02-28 15:29:25'),(78,102,'EFFECT_ITEM',87,'¹ìÆÄ½ºÅ³2',1,0,'2021-02-28 15:30:15'),(79,104,'EFFECT_ITEM',89,'¹ìÆÄ½ºÅ³2',1,0,'2021-02-28 15:30:21'),(80,105,'EFFECT_ITEM',90,'¹ìÆÄ½ºÅ³2',1,0,'2021-02-28 15:30:26'),(81,4,'EFFECT_ITEM',69,'¹ìÆÄ½ºÅ³2',1,0,'2021-02-28 15:37:55'),(82,20,'EFFECT_ITEM',88,'¹ìÆÄ½ºÅ³2',1,0,'2021-02-28 15:39:36'),(83,5,'EFFECT_ITEM',74,'¹ìÆÄ½ºÅ³2',1,0,'2021-02-28 15:39:39'),(84,17,'EFFECT_ITEM',85,'¹ìÆÄ½ºÅ³2',1,0,'2021-02-28 15:43:36'),(85,38,'EFFECT_ITEM',105,'¹ìÆÄ½ºÅ³2',1,0,'2021-03-01 13:19:54'),(86,39,'EFFECT_ITEM',106,'¹ìÆÄ½ºÅ³2',1,0,'2021-03-01 13:19:56'),(87,33,'EFFECT_ITEM',100,'¹ìÆÄ½ºÅ³2',1,0,'2021-03-01 13:19:58'),(88,32,'EFFECT_ITEM',99,'¹ìÆÄ½ºÅ³2',1,0,'2021-03-01 13:19:59'),(89,16,'EFFECT_ITEM',84,'¹ìÆÄ½ºÅ³2',1,0,'2021-03-01 13:20:01'),(90,7,'EFFECT_ITEM',76,'¹ìÆÄ½ºÅ³2',1,0,'2021-03-03 11:38:16'),(91,19,'EFFECT_ITEM',87,'¹ìÆÄ½ºÅ³2',1,0,'2021-03-18 19:55:34'),(92,62,'EFFECT_ITEM',5,'½½·¹ÀÌ½ºÅ³',1,0,'2021-04-20 04:41:55'),(93,72,'EFFECT_ITEM',51,'GM-netshow',1,0,'2021-04-23 02:56:58'),(94,73,'EFFECT_ITEM',10,'Slangs2',1,0,'2021-04-23 02:57:31'),(95,74,'EFFECT_ITEM',47,'Slangs2',1,0,'2021-04-23 02:57:40'),(96,80,'EFFECT_ITEM',5,'sdddd',1,0,'2021-04-30 16:47:35'),(97,82,'EFFECT_ITEM',68,'141414',1,0,'2021-04-30 17:59:56'),(98,97,'EFFECT_ITEM',100,'141414',1,0,'2021-04-30 18:01:57'),(99,93,'EFFECT_ITEM',51,'141414',1,0,'2021-04-30 18:02:07'),(100,86,'EFFECT_ITEM',45,'141414',1,0,'2021-04-30 18:02:11'),(101,87,'EFFECT_ITEM',38,'141414',1,0,'2021-04-30 18:02:16'),(102,89,'EFFECT_ITEM',4,'141414',1,0,'2021-04-30 18:02:19'),(103,85,'EFFECT_ITEM',48,'141414',1,0,'2021-04-30 18:02:24'),(104,90,'EFFECT_ITEM',17,'141414',1,0,'2021-04-30 18:02:26'),(105,80,'EFFECT_ITEM',76,'141414',1,0,'2021-04-30 18:02:30'),(106,2,'PET_FOOD',24,'dfdff33',1,0,'2021-05-31 17:06:19'),(107,2,'MIXING_ITEM',31,'dfdff33',1,0,'2021-05-31 18:54:12');

-- ----------------------------------------------------------------------
DROP TABLE IF EXISTS `LilithSeriesLog`;
CREATE TABLE `LilithSeriesLog` (
  `LogID` int(10) unsigned NOT NULL auto_increment,
  `PlayerID` varchar(20) NOT NULL default '',
  `Name` varchar(10) NOT NULL default '',
  `ReportTime` datetime NOT NULL default '2003-01-01 00:00:00',
  `ItemType` smallint(3) unsigned NOT NULL default '0',
  `ItemID` int(10) unsigned NOT NULL default '0',
  `BeforeLevel` int(10) unsigned NOT NULL default '0',
  `AfterLevel` int(10) unsigned NOT NULL default '0',
  `BeforeGrade` int(10) unsigned NOT NULL default '0',
  `AfterGrade` int(10) unsigned NOT NULL default '0',
  `TargetItemClass` varchar(25) NOT NULL default '',
  `TargetItemType` int(10) unsigned NOT NULL default '0',
  `TargetItemID` int(10) unsigned NOT NULL default '0',
  `Success` smallint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`LogID`)
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=utf8mb4;

INSERT INTO `LilithSeriesLog` VALUES (1,'kim2','dfdff33','2021-05-31 18:57:34',60,3,0,1,5,5,'VAMPIRE_WEAPON',1,4,1),(2,'kim2','dfdff33','2021-05-31 18:57:48',60,8,1,2,5,5,'VAMPIRE_WEAPON',1,4,1),(3,'kim2','dfdff33','2021-05-31 18:57:53',60,11,2,3,5,5,'VAMPIRE_WEAPON',1,4,1),(4,'kim2','dfdff33','2021-05-31 18:57:54',60,10,3,4,5,5,'VAMPIRE_WEAPON',1,4,1),(5,'kim2','dfdff33','2021-05-31 18:58:05',54,15,4,0,5,5,'VAMPIRE_WEAPON',1,4,0),(6,'kim2','dfdff33','2021-05-31 18:59:19',70,25,0,1,5,5,'VAMPIRE_WEAPON',1,4,1),(7,'kim2','dfdff33','2021-05-31 18:59:22',70,26,1,2,5,5,'VAMPIRE_WEAPON',1,4,1),(8,'kim2','dfdff33','2021-05-31 18:59:24',70,27,2,0,5,5,'VAMPIRE_WEAPON',1,4,0),(9,'kim2','dfdff33','2021-05-31 18:59:26',70,28,0,0,5,4,'VAMPIRE_WEAPON',1,4,0),(10,'kim2','dfdff33','2021-05-31 18:59:30',70,29,0,1,4,4,'VAMPIRE_WEAPON',1,4,1),(11,'kim2','dfdff33','2021-05-31 18:59:31',70,31,1,0,4,4,'VAMPIRE_WEAPON',1,4,0),(12,'kim2','dfdff33','2021-05-31 18:59:34',70,30,0,1,4,4,'VAMPIRE_WEAPON',1,4,1),(13,'kim2','dfdff33','2021-05-31 18:59:38',70,32,1,0,4,4,'VAMPIRE_WEAPON',1,4,0),(14,'kim2','dfdff33','2021-05-31 18:59:39',70,33,0,1,4,4,'VAMPIRE_WEAPON',1,4,1),(15,'kim2','dfdff33','2021-05-31 18:59:40',70,36,1,2,4,4,'VAMPIRE_WEAPON',1,4,1),(16,'kim2','dfdff33','2021-05-31 18:59:41',70,34,2,3,4,4,'VAMPIRE_WEAPON',1,4,1),(17,'kim2','dfdff33','2021-05-31 18:59:42',70,35,3,0,4,4,'VAMPIRE_WEAPON',1,4,0),(18,'kim2','dfdff33','2021-05-31 18:59:45',70,38,0,0,4,3,'VAMPIRE_WEAPON',1,4,0),(19,'kim2','dfdff33','2021-05-31 18:59:47',70,37,0,1,3,3,'VAMPIRE_WEAPON',1,4,1),(20,'kim2','dfdff33','2021-05-31 18:59:48',70,39,1,2,3,3,'VAMPIRE_WEAPON',1,4,1),(21,'kim2','dfdff33','2021-05-31 18:59:49',70,40,2,0,3,3,'VAMPIRE_WEAPON',1,4,0),(22,'kim2','dfdff33','2021-05-31 18:59:51',70,42,0,1,3,3,'VAMPIRE_WEAPON',1,4,1),(23,'kim2','dfdff33','2021-05-31 18:59:53',70,43,1,0,3,3,'VAMPIRE_WEAPON',1,4,0),(24,'kim2','dfdff33','2021-05-31 18:59:54',70,41,0,1,3,3,'VAMPIRE_WEAPON',1,4,1),(25,'kim2','dfdff33','2021-05-31 19:04:14',71,44,0,1,4,4,'VAMPIRE_WEAPON',1,10,1);

-- ----------------------------------------------------------------------
DROP TABLE IF EXISTS `PetMixingLog`;
CREATE TABLE `PetMixingLog` (
  `LogID` int(10) unsigned NOT NULL auto_increment,
  `ReportTime` datetime NOT NULL default '2009-05-01 00:00:00',
  `OwnerID` varchar(10) NOT NULL default '',
  `TargetItemID` bigint(20) NOT NULL default '0',
  `TargetItemType` tinyint(3) unsigned NOT NULL default '0',
  `TargetMixOptionType` varchar(10) NOT NULL default '',
  `materialItemID` bigint(20) NOT NULL default '0',
  `materialItemType` tinyint(3) unsigned NOT NULL default '0',
  `PetLevel` tinyint(3) unsigned NOT NULL default '0',
  `PetAttr` tinyint(3) unsigned NOT NULL default '0',
  `PetAttrLevel` tinyint(3) unsigned NOT NULL default '0',
  `PetOption` tinyint(3) unsigned NOT NULL default '0',
  `PetOption2` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`LogID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- (no rows in the original)

-- ----------------------------------------------------------------------
DROP TABLE IF EXISTS `SpeedHackLog`;
CREATE TABLE `SpeedHackLog` (
  `LogID` bigint(20) NOT NULL auto_increment,
  `PlayerID` varchar(12) NOT NULL default '',
  `Name` varchar(12) NOT NULL default '',
  `ServerGroupID` tinyint(4) NOT NULL default '0',
  `ZoneID` smallint(6) NOT NULL default '0',
  `XCoord` tinyint(4) NOT NULL default '0',
  `YCoord` tinyint(4) NOT NULL default '0',
  `IP` varchar(15) NOT NULL default '',
  `AbuseAction` text NOT NULL,
  `IssueDate` datetime NULL DEFAULT NULL,
  PRIMARY KEY  (`LogID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- (no rows in the original)

-- ----------------------------------------------------------------------
DROP TABLE IF EXISTS `WebMarketKey`;
CREATE TABLE `WebMarketKey` (
  `PlayerID` varchar(20) NOT NULL default '',
  `Key` int(10) unsigned NOT NULL default '0',
  `Refresh` smallint(5) unsigned NOT NULL default '0',
  PRIMARY KEY  (`PlayerID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- (no rows in the original)

-- ----------------------------------------------------------------------
DROP TABLE IF EXISTS `WeekItemGive`;
CREATE TABLE `WeekItemGive` (
  `PlayerID` varchar(10) NOT NULL default '',
  `GiveDate` datetime default NULL,
  PRIMARY KEY  (`PlayerID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

INSERT INTO `WeekItemGive` VALUES ('teste1','2020-12-21 13:18:50'),('teste2','2020-12-07 11:40:42'),('kim','2021-05-31 23:23:53'),('kim2','2021-06-02 14:21:25'),('kim3','2021-01-26 07:54:20'),('test1','2021-03-26 03:12:40'),('test2','2021-03-17 16:51:04'),('test3','2021-03-19 02:01:17'),('1','2021-04-21 05:31:38'),('5','2021-04-30 19:48:54');

-- ----------------------------------------------------------------------
DROP TABLE IF EXISTS `WeekItemInfo`;
CREATE TABLE `WeekItemInfo` (
  `ID` int(11) NOT NULL auto_increment,
  `Week` tinyint(3) unsigned NOT NULL default '0',
  `ItemClass` smallint(5) unsigned NOT NULL default '0',
  `ItemType` tinyint(3) unsigned NOT NULL default '0',
  `Num` tinyint(3) unsigned NOT NULL default '1',
  `OptionType` varchar(10) NOT NULL default '',
  `Grade` tinyint(3) unsigned NOT NULL default '1',
  `LimitTime` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`ID`),
  KEY `Week` (`Week`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4;

INSERT INTO `WeekItemInfo` VALUES (1,1,40,40,1,'',1,518400),(2,2,70,7,3,'',1,518400),(3,3,55,1,3,'',1,518400),(4,4,40,37,1,'',1,518400),(5,4,40,37,1,'',1,518400),(6,4,40,37,1,'',1,518400),(7,5,70,38,3,'',1,518400),(8,6,40,38,1,'',1,518400),(9,6,40,38,1,'',1,518400),(10,6,40,38,1,'',1,518400),(11,7,40,36,1,'',1,518400);

-- ----------------------------------------------------------------------
DROP TABLE IF EXISTS `uds_msg`;
CREATE TABLE `uds_msg` (
  `mid` varchar(30) NOT NULL default '',
  `recvdate` datetime default NULL,
  `target` varchar(50) default NULL,
  `toname` varchar(50) default NULL,
  `callback` varchar(50) default NULL,
  `body` text,
  PRIMARY KEY  (`mid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- (no rows in the original)
