-- =====================================================================
-- Item info rows for types the server ALREADY constructs.
--
-- Same failure mode as EventStar, but found by scanning instead of crashing:
--   createItem(Item::ITEM_CLASS_X, <literal type>, ...)
-- throws a bare const char* ("Invalid item type or optionType") when that type
-- has no info row. Our info tables are subsets of the original's, so every
-- literal above our ceiling is a latent crash waiting on a drop roll.
--
-- The one that was about to fire: MonsterManager.cpp:1701 creates EFFECT_ITEM
-- type 47 in the same drop block as the EventStar types that just crashed the
-- server -- and we had none of the 12 EffectItemInfo types the code uses.
--
-- Scope: only types the SOURCE demonstrably constructs, and only rows the
-- original actually has. Crash-driven, not a bulk diff -- the speculative
-- imports (OptionInfo, UniqueItemInfo) are what broke startup earlier.
--
-- All targets keyed on ItemType, so INSERT IGNORE genuinely dedupes and this
-- file is safe to re-run.
--
-- revert: see log/schema_migration_applied.sql for the per-table type lists.
-- =====================================================================

USE DARKEDEN;

-- CommonQuestItemInfo : 14 row(s) for types [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 30, 52]
INSERT IGNORE INTO `CommonQuestItemInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `ItemLevel`, `BonusRatio`, `Race`)
VALUES
  (0,'À¯½ÇµÈ º¸±ÞÇ°','Lost Ordnance',1,5,1,0,0,0,1),
  (1,'¹ìÇÇ¿À¸¯ ÄÚ¾î','Vampiric Core',1,5,1,0,0,0,2),
  (2,'°í´ëÀÇ ±â¾ï','Ancient Remain',1,5,1,0,0,0,4),
  (3,'¹«µÎÁú¿ë Ä®','Tanning Knife',10000,5,1,0,0,0,7),
  (4,'±ú²ýÇÑ °¡Á×','Neat Leather',32000,5,1,0,0,0,7),
  (5,'¼Õ»óµÈ °¡Á×','Injury Leather',3000,5,1,0,0,0,7),
  (6,'ÄÉ¸£º£·Î½º ÀÎÀå','Cerberus¡¯s seal',50,1,1,0,0,0,7),
  (7,'¸ÇÆ¼ÄÚ¾ÆÆ® ÀÎÀå','Manticoret¡¯s seal',50,1,1,0,0,0,7),
  (8,'º¸±ÛÆ® H ÀÎÀå','Boglet H¡¯s seal',50,1,1,0,0,0,7),
  (9,'º¸±ÛÆ® B ÀÎÀå','Boglet B¡¯s seal',50,1,1,0,0,0,7),
  (10,'¸Å¼­Ä¿ ÀÎÀå','Massacre¡¯s seal',50,1,1,0,0,0,7),
  (11,'ÇÃ·³ÇÇº¸¾î ÀÎÀå','Plumy Boar¡¯s seal',50,1,1,0,0,0,7),
  (30,'¿µÇèÇÑ ¼­','A miracle epistle',50,5,1,0,0,0,7),
  (52,'´Þºû °áÁ¤','Moon Crystal',1,1,1,0,0,0,7);

-- ContractOfBloodInfo : 1 row(s) for types [0]
INSERT IGNORE INTO `ContractOfBloodInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `OptionClass`, `Race`)
VALUES
  (0,'ÇÇÀÇ °è¾à','Contract Of Adam',1,5,1,1,0,7);

-- CueOfAdamInfo : 1 row(s) for types [4]
INSERT IGNORE INTO `CueOfAdamInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `OptionClass`, `SetOption`)
VALUES
  (4,'°í´ëÀÇ ¸Åµì','Ancient Knot',1,1,1,1,10,'DAM+7');

-- EffectItemInfo : 11 row(s) for types [20, 21, 22, 23, 27, 34, 35, 36, 37, 47, 58]
INSERT IGNORE INTO `EffectItemInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `ItemLevel`, `EffectClass`, `TimeSec`, `Race`)
VALUES
  (20,'±¤ÆøÀÇ Çâ','Furious Incense',1,1,1,0,0,499,1800,7),
  (21,'°­·ÂÀÇ Çâ','Strengthen Incense',1,1,1,0,0,500,1800,7),
  (22,'È°¼ºÀÇ Çâ','Hyperactive Incense',1,1,1,0,0,501,1800,7),
  (23,'Ã¶º®ÀÇ Çâ','Impregnable Incense',1,1,1,0,0,502,1800,7),
  (27,'ÀÇ¹®ÀÇ ¹°¾à','Mystery Potion',1,2,1,0,0,537,7200,7),
  (34,'¾Ë½É ¼ÛÆí','Rice Cake of Strength',1,1,1,0,0,503,300,7),
  (35,'³¯·ÆÇÑ ¼ÛÆí','Rice Cake of Agility',1,1,1,0,0,504,300,7),
  (36,'¾ËÀ½¾ËÀÌ ¼ÛÆí','Rice Cake of Knowledge',1,1,1,0,0,505,300,7),
  (37,'¿Ë°ñÁø ¼ÛÆí','Rice Cake of Acceleration',1,1,1,0,0,467,300,7),
  (47,'°æÇèÀÇ µ¹','Experience Stone',1,1,1,0,0,607,3600,7),
  (58,'ÇÁ¸®¹Ì¾ö Ä«µå A-15','Premium Card A-15',1,1,1,0,0,561,1296000,7);

-- EtherealChainInfo : 1 row(s) for types [0]
INSERT IGNORE INTO `EtherealChainInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `Race`)
VALUES
  (0,'¿¡Å×¸®¾ó Ã¼ÀÎ','Ethereal Chain',1,1,1,1,7);

-- EventGiftBoxInfo : 5 row(s) for types [30, 31, 32, 35, 39]
INSERT IGNORE INTO `EventGiftBoxInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `Race`)
VALUES
  (30,'Çàº¹ÀÇ ¼¼ÀÙ Å¬·Î¹ö','Three-leaf clover',0,1,1,0,7),
  (31,'Çà¿îÀÇ ³×ÀÙ Å¬·Î¹ö','Four-leaf clover',0,1,1,0,7),
  (32,'ÇÍºû ¼±¹° »óÀÚ','Blood Gift Box',0,5,1,0,7),
  (35,'Àè¿À·£ÅÏ','jacko\'lantern',1,5,1,0,7),
  (39,'¾ç¸»¹®¾ç','Socks Pattern',0,5,1,0,7);

-- EventTreeInfo : 3 row(s) for types [54, 67, 80]
INSERT IGNORE INTO `EventTreeInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `ItemLevel`, `Race`)
VALUES
  (54,'ÅÍÇÁÇÑ ´«»ç¶÷','Tough Snowman',0,6,1,0,0,7),
  (67,'ºí¸®Ã÷ ¹®¾ç','Blitz Pattern',0,6,1,0,0,7),
  (80,'³«¿± ¹®¾ç','Fallen Leaves Pattern',0,6,1,0,0,7);

-- MixingItemInfo : 4 row(s) for types [28, 31, 32, 33]
INSERT IGNORE INTO `MixingItemInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Target`, `Type`, `SlayerLevel`, `VampireLevel`, `OustersLevel`, `Race`)
VALUES
  (28,'Ç»¸®Å¸½º','Puritas',1,1,1,'ALL','DETACH',100,100,100,7),
  (31,'¿þÇÂ ¹Í½Ì Æ÷Áö','Weapon Mixing Forge',300000,5,0,'WEAPON','MIX',1,1,1,7),
  (32,'¾Æ¸Ó ¹Í½Ì Æ÷Áö','Armor Mixing Forge',300000,5,0,'ARMOR','MIX',1,1,1,7),
  (33,'¾×¼¼¼­¸® ¹Í½Ì Æ÷Áö','Accessory Mixing Forge',300000,5,0,'ACCESSORY','MIX',1,1,1,7);

-- PetEnchantItemInfo : 5 row(s) for types [22, 24, 25, 26, 36]
INSERT IGNORE INTO `PetEnchantItemInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `ItemLevel`, `Function`, `FunctionGrade`, `Race`)
VALUES
  (22,'Æê ¼Ó¼º ÃÊ±âÈ­ ¹°¾à','Pet Attribute Cleaner Potion',10000,1,1,0,0,22,0,7),
  (24,'¸ÅÁöÄÃ Æê Ã¼ÀÎÁ®','Magical Pet Changer',10000,5,1,0,0,24,0,7),
  (25,'ÀÍ½ºÆÛÆ® Æê Ã¼ÀÎÁ®','Expert Pet Changer',10000,5,1,0,0,25,0,7),
  (26,'·¹µå ¹öµå 2','Red Bird 2',10000,1,1,0,0,14,0,7),
  (36,'ºñÁ¯¾ÚÇÃ','Vision ampul',10000,1,1,0,0,2,18,7);

-- PetItemInfo : 1 row(s) for types [40]
INSERT IGNORE INTO `PetItemInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `ItemLevel`, `Race`, `PetDefaultOption`)
VALUES
  (40,'¹Ì´Ï ¿ïÇÁµ¶ ¸ñÁÙ','Mini Wolfdog Leash',1,1,1,0,0,7,'');

-- QuestItemInfo : 1 row(s) for types [10]
INSERT IGNORE INTO `QuestItemInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `ItemLevel`, `BonusRatio`, `Race`)
VALUES
  (10,'ºÀÀÎ¼®','Sealing Stone',10000000,5,1,0,0,0,7);

-- SubInventoryInfo : 1 row(s) for types [1]
INSERT IGNORE INTO `SubInventoryInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `Width`, `Height`, `Race`)
VALUES
  (1,'4x6 ÆÑ','4x6 Pack',10000,1,0,0,4,6,7);

-- WarItemInfo : 6 row(s) for types [1, 2, 3, 4, 5, 6]
INSERT IGNORE INTO `WarItemInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `Race`)
VALUES
  (1,'¼¼ÀÌ¹ö ½¯µå','Saver Shield',0,1,1,0,1),
  (2,'¹ÙÀÌ¾î·±Æ® ½ºÄÃ','Violent Skull',0,1,1,0,2),
  (3,'ÀÎÇÇ´ÏÆ¼ ½©','Infinity Shell',0,1,1,0,4),
  (4,'Ä®¸®°í ¼¼ÀÌ¹ö ½¯µå','Caligo Saver Shield',0,1,1,0,1),
  (5,'Ä®¸®°í ¹ÙÀÌ¾î·±Æ® ½ºÄÃ','Caligo Violent Skull',0,1,1,0,2),
  (6,'Ä®¸®°í ÀÎÇÇ´ÏÆ¼ ½©','Caligo Infinity Shell',0,1,1,0,4);
