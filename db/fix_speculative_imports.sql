-- =====================================================================
-- Revert ONLY the UniqueItemInfo import.
--
--   Assertion Failed : UniqueItemManager.cpp : 81
--     UniqueItemManager::init()  pItemInfo != NULL
--
-- init() walks every (ItemClass, ItemType) in UniqueItemInfo and asserts the
-- item actually exists. The 11 rows imported from the original name items that
-- exist in ITS ItemInfo tables but not in ours, so they dangle and abort boot.
--
-- Scope deliberately narrowed to this one table. My first draft of this file
-- also reverted ItemClass, AttrInfo, WayPointInfo, GSStringPool and
-- EventTreeInfo -- and the ItemClass revert would have been DESTRUCTIVE:
-- our snapshot file carries ItemClass as structure-only, so the generator saw
-- "ours = 0 rows" and would have emitted a DELETE for all 104 identities,
-- removing the 91 rows that were ours all along. Live counts confirm the real
-- picture (91 ours + 13 imported = 104).
--
-- The other four are consistent and have broken nothing, so they stay:
--   AttrInfo 143+78=221   WayPointInfo 115+76=191
--   GSStringPool 380+98=478   EventTreeInfo 42+48=90
--
-- Lesson: compute a DELETE from the LIVE database, never from a snapshot file
-- that may not mirror it.
--
-- Re-runnable: deleting rows already gone is a no-op.
-- =====================================================================

USE DARKEDEN;

DELETE FROM `UniqueItemInfo` WHERE
  (`ItemClass`=8 AND `ItemType`=19)
  OR (`ItemClass`=10 AND `ItemType`=18)
  OR (`ItemClass`=30 AND `ItemType`=19)
  OR (`ItemClass`=32 AND `ItemType`=18)
  OR (`ItemClass`=63 AND `ItemType`=19)
  OR (`ItemClass`=62 AND `ItemType`=18)
  OR (`ItemClass`=42 AND `ItemType`=17)
  OR (`ItemClass`=9 AND `ItemType`=17)
  OR (`ItemClass`=64 AND `ItemType`=24)
  OR (`ItemClass`=64 AND `ItemType`=25)
  OR (`ItemClass`=64 AND `ItemType`=26);

-- Expect 38, the pre-import count.
SELECT COUNT(*) AS uniqueiteminfo_rows FROM `UniqueItemInfo`;
