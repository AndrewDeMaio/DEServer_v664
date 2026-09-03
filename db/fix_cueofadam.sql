-- =====================================================================
-- CueOfAdamInfo: fill the table properly instead of one sparse row.
--
--   Assertion Failed : InfoClassManager.cpp : 85
--     InfoClassManager::init()  m_pItemInfos[0] != NULL
--
-- My fix_item_infos.sql imported only the types the SOURCE names literally.
-- For CueOfAdamInfo that was type 4 alone, into a previously EMPTY table --
-- so the info array was sized to 5 with slot 0 NULL, and init() asserts slot 0
-- exists whenever any rows loaded.
--
-- Importing a SPARSE subset into an empty table is the bug. Every other table
-- in that file already had a type 0, which is why only this one broke.
-- Verified across all 13: CueOfAdamInfo was the only offender.
--
-- Fix: take the whole table from the original rather than cherry-picking.
--
-- revert:  DELETE FROM `CueOfAdamInfo` WHERE ItemType <> 4;
-- =====================================================================

USE DARKEDEN;

INSERT IGNORE INTO `CueOfAdamInfo`
  (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `OptionClass`, `SetOption`)
VALUES
  (0,'Å¥ ¿Àºê ¾Æ´ã ·¹µå','Cue Of Adam Red',1,1,1,1,0,'ATTR+2'),
  (1,'Å¥ ¿Àºê ¾Æ´ã ±×¸°','Cue Of Adam Green',1,1,1,1,1,'MP+4'),
  (2,'Å¥ ¿Àºê ¾Æ´ã ºí·ç','Cue Of Adam Blue',1,1,1,1,2,'TOHIT+7'),
  (3,'Å¥ ¿Àºê ¾Æ´ã ºí·¢','Cue Of Adam Black',1,1,1,1,10,'DAM+7'),
  (4,'°í´ëÀÇ ¸Åµì','Ancient Knot',1,1,1,1,10,'DAM+7');

-- Expect a contiguous run starting at 0.
SELECT COUNT(*) AS rows_, MIN(ItemType) AS min_type,
       GROUP_CONCAT(ItemType ORDER BY ItemType) AS types
  FROM `CueOfAdamInfo`;
