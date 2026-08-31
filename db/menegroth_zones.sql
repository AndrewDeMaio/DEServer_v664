-- =====================================================================
-- Menegroth dungeon: the 18 ZoneInfo rows (1701-1718).
--
-- The dungeon system itself is already written and compiled in
-- (__MENEGROTH_DOUNGEON_SYSTEM__, VersionType.h:30) and all 18 server maps
-- are present in data/. The only thing missing was the zone rows, so the
-- zones could never be instantiated.
--
-- Layout, fixed by MenegrothDoungeonManager::getDoungeonZoneToMove() and
-- confirmed against the zone id inside each .smp header:
--
--     1701-1706  Slayer   floors 1-6
--     1707-1712  Vampire  floors 1-6
--     1713-1718  Ousters  floors 1-6
--
-- Floor is chosen by player level (getFloorByLevel), 20 levels per floor
-- starting at 21; below 21 the dungeon refuses entry.
--
-- Resurrect points are getAltarPosToMove()'s towns -- the same place the
-- server already sends a player who logs in while inside Menegroth.
--
-- Monster lists are EMPTY on purpose. This pass adds zones only; monsters,
-- traps, items and the entrance statues come later.
--
-- Portal items are already blocked in these zones by code
-- (CGUseItemFromInventoryHandler), so NoPortalZone stays 0.
--
-- Re-runnable: ON DUPLICATE KEY UPDATE refreshes the columns this script
-- owns and leaves any hand-tuning of other columns alone.
-- =====================================================================

USE DARKEDEN;

INSERT INTO `ZoneInfo`
  (`ZoneID`, `ZoneGroupID`, `Type`, `Level`, `AccessMode`, `OwnerId`, `MonsterList`, `EventMonsterList`, `SResurrectZoneID`, `SResurrectX`, `SResurrectY`, `VResurrectZoneID`, `VResurrectX`, `VResurrectY`, `OResurrectZoneID`, `OResurrectX`, `OResurrectY`, `SmpFileName`, `SsiFileName`, `FullName`, `ShortName`, `PayPlayZone`, `PremiumZone`, `PKZone`, `NoPortalZone`, `HolyLand`, `Available`, `OpenLevel`, `PromotionMonsterList`)
VALUES
  -- Slayer 1F  levels 21-40   entry (62,19)
  (1701,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_1f_slayer.smp','menegroth_1f_slayer.ssi','Menegroth 1F (Slayer)','MenegrothS1F',0,0,0,0,0,0,1,NULL),
  -- Slayer 2F  levels 41-60   entry (23,58)
  (1702,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_2f_slayer.smp','menegroth_2f_slayer.ssi','Menegroth 2F (Slayer)','MenegrothS2F',0,0,0,0,0,0,1,NULL),
  -- Slayer 3F  levels 61-80   entry (36,36)
  (1703,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_3f_slayer.smp','menegroth_3f_slayer.ssi','Menegroth 3F (Slayer)','MenegrothS3F',0,0,0,0,0,0,1,NULL),
  -- Slayer 4F  levels 81-100  entry (58,22)
  (1704,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_4f_slayer.smp','menegroth_4f_slayer.ssi','Menegroth 4F (Slayer)','MenegrothS4F',0,0,0,0,0,0,1,NULL),
  -- Slayer 5F  levels 101-120 entry (36,36)
  (1705,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_5f_slayer.smp','menegroth_5f_slayer.ssi','Menegroth 5F (Slayer)','MenegrothS5F',0,0,0,0,0,0,1,NULL),
  -- Slayer 6F  levels 121+    entry (59,21)
  (1706,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_6f_slayer.smp','menegroth_6f_slayer.ssi','Menegroth 6F (Slayer)','MenegrothS6F',0,0,0,0,0,0,1,NULL),
  -- Vampire 1F  levels 21-40   entry (62,19)
  (1707,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_1f_vampire.smp','menegroth_1f_vampire.ssi','Menegroth 1F (Vampire)','MenegrothV1F',0,0,0,0,0,0,1,NULL),
  -- Vampire 2F  levels 41-60   entry (23,58)
  (1708,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_2f_vampire.smp','menegroth_2f_vampire.ssi','Menegroth 2F (Vampire)','MenegrothV2F',0,0,0,0,0,0,1,NULL),
  -- Vampire 3F  levels 61-80   entry (36,36)
  (1709,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_3f_vampire.smp','menegroth_3f_vampire.ssi','Menegroth 3F (Vampire)','MenegrothV3F',0,0,0,0,0,0,1,NULL),
  -- Vampire 4F  levels 81-100  entry (58,22)
  (1710,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_4f_vampire.smp','menegroth_4f_vampire.ssi','Menegroth 4F (Vampire)','MenegrothV4F',0,0,0,0,0,0,1,NULL),
  -- Vampire 5F  levels 101-120 entry (36,36)
  (1711,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_5f_vampire.smp','menegroth_5f_vampire.ssi','Menegroth 5F (Vampire)','MenegrothV5F',0,0,0,0,0,0,1,NULL),
  -- Vampire 6F  levels 121+    entry (59,21)
  (1712,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_6f_vampire.smp','menegroth_6f_vampire.ssi','Menegroth 6F (Vampire)','MenegrothV6F',0,0,0,0,0,0,1,NULL),
  -- Ousters 1F  levels 21-40   entry (62,19)
  (1713,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_1f_ousters.smp','menegroth_1f_ousters.ssi','Menegroth 1F (Ousters)','MenegrothO1F',0,0,0,0,0,0,1,NULL),
  -- Ousters 2F  levels 41-60   entry (23,58)
  (1714,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_2f_ousters.smp','menegroth_2f_ousters.ssi','Menegroth 2F (Ousters)','MenegrothO2F',0,0,0,0,0,0,1,NULL),
  -- Ousters 3F  levels 61-80   entry (36,36)
  (1715,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_3f_ousters.smp','menegroth_3f_ousters.ssi','Menegroth 3F (Ousters)','MenegrothO3F',0,0,0,0,0,0,1,NULL),
  -- Ousters 4F  levels 81-100  entry (58,22)
  (1716,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_4f_ousters.smp','menegroth_4f_ousters.ssi','Menegroth 4F (Ousters)','MenegrothO4F',0,0,0,0,0,0,1,NULL),
  -- Ousters 5F  levels 101-120 entry (36,36)
  (1717,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_5f_ousters.smp','menegroth_5f_ousters.ssi','Menegroth 5F (Ousters)','MenegrothO5F',0,0,0,0,0,0,1,NULL),
  -- Ousters 6F  levels 121+    entry (59,21)
  (1718,1,'NORMAL_DUNGEON',0,'PUBLIC',NULL,'','',12,47,182,22,217,230,81,191,111,'menegroth_6f_ousters.smp','menegroth_6f_ousters.ssi','Menegroth 6F (Ousters)','MenegrothO6F',0,0,0,0,0,0,1,NULL)
ON DUPLICATE KEY UPDATE
  `ZoneGroupID`      = VALUES(`ZoneGroupID`),
  `Type`             = VALUES(`Type`),
  `AccessMode`       = VALUES(`AccessMode`),
  `SResurrectZoneID` = VALUES(`SResurrectZoneID`),
  `SResurrectX`      = VALUES(`SResurrectX`),
  `SResurrectY`      = VALUES(`SResurrectY`),
  `VResurrectZoneID` = VALUES(`VResurrectZoneID`),
  `VResurrectX`      = VALUES(`VResurrectX`),
  `VResurrectY`      = VALUES(`VResurrectY`),
  `OResurrectZoneID` = VALUES(`OResurrectZoneID`),
  `OResurrectX`      = VALUES(`OResurrectX`),
  `OResurrectY`      = VALUES(`OResurrectY`),
  `SmpFileName`      = VALUES(`SmpFileName`),
  `SsiFileName`      = VALUES(`SsiFileName`),
  `FullName`         = VALUES(`FullName`),
  `ShortName`        = VALUES(`ShortName`),
  `OpenLevel`        = VALUES(`OpenLevel`);

-- Verification: expect 18 rows, and every SmpFileName must exist in data/.
SELECT COUNT(*) AS menegroth_zones FROM `ZoneInfo` WHERE ZoneID BETWEEN 1701 AND 1718;
SELECT ZoneID, SmpFileName, FullName FROM `ZoneInfo` WHERE ZoneID BETWEEN 1701 AND 1718 ORDER BY ZoneID;
