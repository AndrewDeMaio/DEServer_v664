-- =====================================================================
-- EventStarInfo: import the types the drop code actually asks for.
--
--   UNHANDLED EXCEPTION : const char*: EventStar::EventStar() :
--                         Invalid item type or optionType
--
-- MonsterManager builds ITEM_CLASS_EVENT_STAR items of type 47, 54, 55, 56,
-- 69 and 78 on a monster kill (MonsterManager.cpp:1705-1713, 2173, 2984,
-- 3044). Our EventStarInfo only held types 0-22, so the constructor threw --
-- as a bare const char*, which is why this used to abort with no message.
--
-- It fires on a random drop roll, so it looks like "the server crashed while
-- I wasn't doing anything": the trigger is killing a monster, not any new action.
--
-- This one is import-driven-by-a-crash, not speculation: the server names the
-- exact item class and the code names the exact types.
--
-- Deliberately a SEPARATE file rather than re-running original664_content.sql,
-- because that file still carries the UniqueItemInfo rows which were just
-- reverted -- re-running it would reintroduce the startup assert.
--
-- revert:  DELETE FROM `EventStarInfo` WHERE ItemType > 22;
-- =====================================================================

USE DARKEDEN;

INSERT IGNORE INTO `EventStarInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `ItemLevel`, `FunctionFlag`, `FunctionValue`, `Race`)
VALUES
  (23,'ÆÄÀÌ¾î ¿À³Ê¸ÕÃ÷','Fire Ornaments',10000,1,1,0,0,17,1,7),
  (24,'Æ÷ÀÌÁð ¿À³Ê¸ÕÃ÷','Poison Prnaments',10000,1,1,0,0,17,2,7),
  (25,'¾ÆÀÌ½º ¿À³Ê¸ÕÃ÷','Ice Ornaments',10000,1,1,0,0,17,3,7),
  (26,'¸ö³î¸²ÀÌ Àì½ÎÁö´Â ¼ÛÆí SP','Korean Rice Cake of Defense SP',1000,1,1,0,0,2,43,7),
  (27,'ÇÇºÎ°¡ ´Ü´ÜÇØÁö´Â ¼ÛÆí SP','Korean Rice Cake of Protection',1000,1,1,0,0,2,53,7),
  (28,'¼ÕÁþÀÌ »¡¶óÁö´Â ¼ÛÆí SP','Korean Rice Cake of Attack Spe',1000,1,1,0,0,2,78,7),
  (29,'¸ÂÀ¸¸é ´õ ¾ÆÇÂ SP','Korean Rice Cake of Damage SP',1000,1,1,0,0,2,49,7),
  (30,'¿î¹ßÀÌ ¿À¸£´Â ¼ÛÆí SP','Korean Rice Cake of Luck SP',1000,1,1,0,0,2,176,7),
  (31,'´«ÀÌ ¸¼¾ÆÁö´Â ¼ÛÆí SP','Korean Rice Cake of Sight SP',1000,1,1,0,0,2,77,7),
  (32,'³²»ö º¯¼ºÀÇ µ¹','Indigo Denature Stone',1000000,1,1,0,0,2,198,7),
  (33,'Àû°¥ º¯¼ºÀÇ µ¹','Crimson Denature Stone',1000000,1,1,0,0,2,199,7),
  (34,'ÁÖÈ² º¯¼ºÀÇ µ¹','Coral Denature Stone',1000000,1,1,0,0,2,200,7),
  (35,'ÀÚÈ« º¯¼ºÀÇ µ¹','Fuchsia Denature Stone',1000000,1,1,0,0,2,201,7),
  (36,'³²Ã» º¯¼ºÀÇ µ¹','Navy Denature Stone',1000000,1,1,0,0,2,202,7),
  (37,'Àº»ö º¯¼ºÀÇ µ¹','Silver Denature Stone',1000000,1,1,0,0,2,203,7),
  (38,'°¨ÀÚ ¼ÛÆí','Potato Rice Cake',1000,1,1,0,0,2,44,7),
  (39,'Äá ¼ÛÆí','Soybean Rice Cake',1000,1,1,0,0,2,54,7),
  (40,'µµÅä¸® ¼ÛÆí','Acorn Rice Cake',1000,1,1,0,0,2,79,7),
  (41,'¹ã ¼ÛÆí','Chestnut Rice Cake',1000,1,1,0,0,2,49,7),
  (42,'¾¦ ¼ÛÆí','Crown Daisy Rice Cake',1000,1,1,0,0,2,176,7),
  (43,'È£¹Ú ¼ÛÆí','Pumpkin Rice Cake',1000,1,1,0,0,2,76,7),
  (44,'ÆÏ ¼ÛÆí','Red Bean Rice Cake',1000,1,1,0,0,2,2,7),
  (45,'±ú ¼ÛÆí','Sesame Rice Cake',1000,1,1,0,0,2,7,7),
  (46,'´ëÃß ¼ÛÆí','Date Rice Cake',1000,1,1,0,0,2,12,7),
  (47,'Âý½Ò ¹ÝÁ×','Glutinous Rice Kneading',1000,1,1,0,0,2,0,7),
  (48,'¿»·Î¿ì µå·Ó 2','Yellow Drop 2',1,1,1,0,0,16,1,7),
  (49,'·¹µå ÄÚ¶ö','Red Coral',1,2,1,0,0,32,1,7),
  (50,'±×¸° ÄÚ¶ö','Green Coral',1,2,1,0,0,32,6,7),
  (51,'ºí·ç ÄÚ¶ö','Blue Coral',1,2,1,0,0,32,11,7),
  (52,'ºí·¢ ÄÚ¶ö','Black Coral',1,2,1,0,0,32,48,7),
  (53,'ºí·ç±×¸° ÄÚ¶ö','Bluegreen Coral',1,2,1,0,0,32,183,7),
  (54,'¸±¸®½º Àª','Lilith Will',2000000,1,1,0,0,64,1,7),
  (55,'¸±¸®½º ½ºÇÇ¸´','Lilith Spirit',2000000,1,1,0,0,64,2,7),
  (56,'¸±¸®½º µå·Ó','Lilith Drop',2000000,1,1,0,0,64,3,7),
  (57,'¿¤·Î¿ì µå·Ó 3','Yellow Drop 3',1,1,1,0,0,16,1,7),
  (58,'Å©¸®½ºÅ»','Crystal',1,1,1,0,0,32,0,7),
  (59,'¿Ã¸®ºê±×¸° ÄÚ¶ö','Olivegreen Coral',1,2,1,0,0,32,175,7),
  (60,'¸±¸®½º Àª 2','Lilith Will 2',10000000,1,1,0,0,64,1,7),
  (61,'¸±¸®½º ½ºÇÇ¸´ 2','Lilith Spirit 2',10000000,1,1,0,0,64,2,7),
  (62,'¸±¸®½º µå·Ó 2','Lilith Drop 2',10000000,1,1,0,0,64,3,7),
  (63,'¿Àµð³Ê¸® ·¹µå ÄÚ¶ö','Ordinary Red Coral',1,2,1,0,0,32,1,7),
  (64,'¿Àµð³Ê¸® ±×¸° ÄÚ¶ö','Ordinary Green Coral',1,2,1,0,0,32,6,7),
  (65,'¿Àµð³Ê¸® ºí·ç ÄÚ¶ö','Ordinary Blue Coral',1,2,1,0,0,32,11,7),
  (66,'¿Àµð³Ê¸® ºí·ç±×¸° ÄÚ¶ö','Ordinary Bluegreen Coral',1,2,1,0,0,32,183,7),
  (67,'¿Àµð³Ê¸® ºí·¢ ÄÚ¶ö','Ordinary Black Coral',1,2,1,0,0,32,48,7),
  (68,'¿Àµð³Ê¸® Å©¸®½ºÅ»','Ordinary Crystal',1,1,1,0,0,32,0,7),
  (69,'¿Àµð³Ê¸® ¿¤·Î¿ì µå·Ó','Ordinary Yellow Drop',1,1,1,0,0,16,1,7),
  (70,'¿Àµð³Ê¸® ¸±¸®½º Àª','Ordinary Lilith Will',1,1,1,0,0,64,1,7),
  (71,'¿Àµð³Ê¸® ¸±¸®½º ½ºÇÇ¸´','Ordinary Lilith Spirit',1,1,1,0,0,64,2,7),
  (72,'¿Àµð³Ê¸® ¸±¸®½º µå·Ó','Ordinary Lilith Drop',1,1,1,0,0,64,3,7),
  (73,'¾î¼¾Æ® ¿»·Î¿ì ÄÚ¾î','Ascent Yellow Core',1,1,1,0,0,0,0,7),
  (74,'¸®Å¸µå ¿»·Î¿ì ÄÚ¾î','Retard Yellow Core',1,1,1,0,0,0,0,7),
  (75,'¾î¼¾Æ® ¸±¸®½º ÄÚ¾î','Ascent Lilith Core',1,1,1,0,0,0,0,7),
  (76,'¸®Å¸µå ¸±¸®½º ÄÚ¾î','Retard Lilith Core',1,1,1,0,0,0,0,7),
  (77,'¾î¼¾Æ® ÄÚ¶ö ÄÚ¾î','Ascent Coral Core',1,2,1,0,0,0,0,7),
  (78,'ºí·ç µå·Ó »þÀÎ','Blue Drop Shine',1,1,1,0,0,1,0,7),
  (79,'ºí·ç µå·Ó ¿§Áö','Blue Drop Edge',1,1,1,0,0,1,0,7);

-- Expect 80, and all six needed types present.
SELECT COUNT(*) AS eventstarinfo_rows FROM `EventStarInfo`;
SELECT GROUP_CONCAT(ItemType ORDER BY ItemType) AS needed_types
  FROM `EventStarInfo` WHERE ItemType IN (47,54,55,56,69,78);
