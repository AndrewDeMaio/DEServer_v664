-- =====================================================================
-- CueOfAdamInfo: de-duplicate, then give it the unique key it never had.
--
--   Assertion Failed : InfoClassManager.cpp : 119
--     addItemInfo(ItemInfo*)  m_pItemInfos[getItemType()] == NULL
--     <- CueOfAdamInfoManager::load()
--
-- The table ended up as types 0,1,2,3,4,4 -- six rows, five distinct. My
-- previous fix inserted types 0-4 with INSERT IGNORE, but this table has NO
-- UNIQUE KEY, so "IGNORE" had nothing to ignore on and the existing type 4 was
-- inserted a second time.
--
-- This is the THIRD time the same trap has bitten in this import (after
-- SkillBookInfo / MenegrothDoungeonTrapInfo / NPC, then again here), so the key
-- is being added permanently rather than just cleaning the rows: with it in
-- place, INSERT IGNORE actually means what it says and re-running any of these
-- files is safe.
--
-- Checked against the live DB: of the 13 tables in db/fix_item_infos.sql,
-- CueOfAdamInfo is the ONLY one lacking a unique key, which is precisely why it
-- is the only one that duplicated.
--
-- Safe to re-run.
-- =====================================================================

USE DARKEDEN;

-- Drop the duplicate rows, keeping one per ItemType.
ALTER TABLE `CueOfAdamInfo`
  ADD COLUMN `_dedup_rid` INT NOT NULL AUTO_INCREMENT PRIMARY KEY;

DELETE a FROM `CueOfAdamInfo` a
  JOIN `CueOfAdamInfo` b
    ON a.`ItemType` = b.`ItemType`
   AND a.`_dedup_rid` > b.`_dedup_rid`;

ALTER TABLE `CueOfAdamInfo` DROP COLUMN `_dedup_rid`;

-- Prevent a recurrence.
ALTER TABLE `CueOfAdamInfo` ADD UNIQUE KEY `uk_CueOfAdamInfo` (`ItemType`);

-- Expect 5 rows, types 0,1,2,3,4, distinct == rows.
SELECT COUNT(*) AS rows_, COUNT(DISTINCT `ItemType`) AS distinct_,
       GROUP_CONCAT(`ItemType` ORDER BY `ItemType`) AS types
  FROM `CueOfAdamInfo`;
