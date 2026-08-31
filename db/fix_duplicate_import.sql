-- =====================================================================
-- Repair: the content import was run twice, and three of the target tables
-- had NO unique key -- so INSERT IGNORE had nothing to ignore ON and simply
-- inserted every row a second time.
--
--     SkillBookInfo               82 rows /  41 distinct ItemType
--     MenegrothDoungeonTrapInfo  432 rows / 213 distinct positions
--     NPC                        391 rows / 251 distinct (Name, ZoneID)
--
-- The gameserver caught it at startup rather than running corrupt:
--     Assertion Failed : InfoClassManager.cpp : 119
--       addItemInfo(ItemInfo*)  m_pItemInfos[getItemType()] == NULL
--       <- SkillBookInfoManager::load()
-- i.e. two skill books claimed the same ItemType slot.
--
-- This script de-duplicates in place and then adds the unique keys that
-- should have been there, which makes the content import genuinely
-- idempotent from now on.
--
-- In place, NOT drop-and-recreate: SkillBookInfo carries the CharID sync
-- triggers (trg_SkillBookInfo_cid_ins/upd) and dropping the table would
-- silently take them with it. NPC also holds 111 rows that predate the
-- import and must survive.
--
-- Safe to re-run: every step is conditional or naturally idempotent.
-- =====================================================================

USE DARKEDEN;

-- ---------------------------------------------------------------------
-- 1. SkillBookInfo  -- identity is ItemType (the server asserts this)
-- ---------------------------------------------------------------------
ALTER TABLE `SkillBookInfo`
  ADD COLUMN `_dedup_rid` INT NOT NULL AUTO_INCREMENT PRIMARY KEY;

DELETE a FROM `SkillBookInfo` a
  JOIN `SkillBookInfo` b
    ON a.`ItemType` = b.`ItemType`
   AND a.`_dedup_rid` > b.`_dedup_rid`;

ALTER TABLE `SkillBookInfo` DROP COLUMN `_dedup_rid`;
ALTER TABLE `SkillBookInfo` ADD UNIQUE KEY `uk_SkillBookInfo` (`ItemType`);

-- ---------------------------------------------------------------------
-- 2. MenegrothDoungeonTrapInfo -- identity is the trap's position+type+zone.
--    Note: the ORIGINAL dump itself contains 3 exact repeats -- trap type 1
--    at (16,66) in zones 1705 / 1711 / 1717, i.e. floor 5 of each race wing.
--    Two identical traps on one tile do nothing a single trap does not, so
--    collapsing 216 source rows to 213 loses no behaviour.
-- ---------------------------------------------------------------------
ALTER TABLE `MenegrothDoungeonTrapInfo`
  ADD COLUMN `_dedup_rid` INT NOT NULL AUTO_INCREMENT PRIMARY KEY;

DELETE a FROM `MenegrothDoungeonTrapInfo` a
  JOIN `MenegrothDoungeonTrapInfo` b
    ON a.`TrapX` = b.`TrapX` AND a.`TrapY` = b.`TrapY`
   AND a.`TrapType` = b.`TrapType` AND a.`ZoneID` = b.`ZoneID`
   AND a.`_dedup_rid` > b.`_dedup_rid`;

ALTER TABLE `MenegrothDoungeonTrapInfo` DROP COLUMN `_dedup_rid`;
ALTER TABLE `MenegrothDoungeonTrapInfo`
  ADD UNIQUE KEY `uk_MenegrothTrap` (`TrapX`, `TrapY`, `TrapType`, `ZoneID`);

-- ---------------------------------------------------------------------
-- 3. NPC -- identity is (Name, ZoneID). Verified unique in the original
--    (207 rows, 207 distinct pairs), so the key cannot lose a real NPC.
-- ---------------------------------------------------------------------
ALTER TABLE `NPC`
  ADD COLUMN `_dedup_rid` INT NOT NULL AUTO_INCREMENT PRIMARY KEY;

DELETE a FROM `NPC` a
  JOIN `NPC` b
    ON a.`Name` = b.`Name` AND a.`ZoneID` = b.`ZoneID`
   AND a.`_dedup_rid` > b.`_dedup_rid`;

ALTER TABLE `NPC` DROP COLUMN `_dedup_rid`;
ALTER TABLE `NPC` ADD UNIQUE KEY `uk_NPC` (`Name`, `ZoneID`);

-- ---------------------------------------------------------------------
-- Verify: expect 41 / 213 / 251, each with distinct == rows.
-- ---------------------------------------------------------------------
SELECT 'SkillBookInfo'  AS tbl, COUNT(*) AS rows_, COUNT(DISTINCT `ItemType`) AS distinct_
  FROM `SkillBookInfo`
UNION ALL
SELECT 'MenegrothTrap', COUNT(*), COUNT(DISTINCT CONCAT(`TrapX`,'_',`TrapY`,'_',`TrapType`,'_',`ZoneID`))
  FROM `MenegrothDoungeonTrapInfo`
UNION ALL
SELECT 'NPC', COUNT(*), COUNT(DISTINCT CONCAT(`Name`,'_',`ZoneID`))
  FROM `NPC`;
