-- 1.2.2_DraculaBoxLootTable.sql
--
-- The Dracula Box's loot moves out of the C++ handler and into EventGiftBoxRewardItemInfo, group 57, the same
-- way Morgoth's reliquary (box 33) reads group 4. Editing a row and restarting now changes the loot; no rebuild.
--
-- The odds are unchanged. Four of the five outcomes are fixed items and live here; the fifth, a
-- level-appropriate weapon/armor/accessory, is a roll against the opener's own attributes
-- (getRandomMysteriousItem) that no table can express, so it stays in the handler as a 1-in-5 coin flip taken
-- before this table is consulted. These rows therefore share the remaining 4/5, and each of the four outcomes
-- is 1/4 of that - still 20% each overall:
--
--     Elixir Fragment      1 row  x 105  = 105     1/4 of 420
--     Ethereal Chain       1 row  x 105  = 105
--     a Contract           7 rows x  15  = 105     one row per contract, so 1/7 of the slot each
--     a Combining Forge    3 rows x  35  = 105     weapon / armor / accessory
--                                          ----
--                                           420 per race
--
-- Ratio is a weight within (group, race), not a percentage: getEventGiftBoxReward() rolls
-- rand() % sum(Ratio) + 1 and walks the rows. All three races get the same table.
--
-- Every (ItemClass, ItemType) here must exist in its *Info table - the manager asserts on a missing one.
-- 91/63 Elixir Fragment (added in 1.1.12), 92/0 Ethereal Chain, 96/0-6 the Contracts of Blood,
-- 56/31-33 the weapon/armor/accessory Mixing Forges.
--
-- Ships with gameserver code: the handler branch for box type 57 now calls
-- getEventGiftBoxReward(pCreature, 57, LimitTime) instead of building the four items itself.
--
-- The game server loads this table at startup: restart it after this runs.
--
-- Safe to run twice: the group is deleted and rewritten.

SET NAMES utf8mb4;

DELETE FROM `EventGiftBoxRewardItemInfo` WHERE `Groups` = 57;

INSERT INTO `EventGiftBoxRewardItemInfo`
    (`Groups`, `Orders`, `ItemClass`, `ItemType`, `OptionType`, `LimitTime`, `Ratio`, `Race`)
VALUES
    -- Slayer
    (57,  0, 91, 63, '', 0, 105, 0),
    (57,  1, 92,  0, '', 0, 105, 0),
    (57,  2, 96,  0, '', 0,  15, 0),
    (57,  3, 96,  1, '', 0,  15, 0),
    (57,  4, 96,  2, '', 0,  15, 0),
    (57,  5, 96,  3, '', 0,  15, 0),
    (57,  6, 96,  4, '', 0,  15, 0),
    (57,  7, 96,  5, '', 0,  15, 0),
    (57,  8, 96,  6, '', 0,  15, 0),
    (57,  9, 56, 31, '', 0,  35, 0),
    (57, 10, 56, 32, '', 0,  35, 0),
    (57, 11, 56, 33, '', 0,  35, 0),
    -- Vampire
    (57,  0, 91, 63, '', 0, 105, 1),
    (57,  1, 92,  0, '', 0, 105, 1),
    (57,  2, 96,  0, '', 0,  15, 1),
    (57,  3, 96,  1, '', 0,  15, 1),
    (57,  4, 96,  2, '', 0,  15, 1),
    (57,  5, 96,  3, '', 0,  15, 1),
    (57,  6, 96,  4, '', 0,  15, 1),
    (57,  7, 96,  5, '', 0,  15, 1),
    (57,  8, 96,  6, '', 0,  15, 1),
    (57,  9, 56, 31, '', 0,  35, 1),
    (57, 10, 56, 32, '', 0,  35, 1),
    (57, 11, 56, 33, '', 0,  35, 1),
    -- Ousters
    (57,  0, 91, 63, '', 0, 105, 2),
    (57,  1, 92,  0, '', 0, 105, 2),
    (57,  2, 96,  0, '', 0,  15, 2),
    (57,  3, 96,  1, '', 0,  15, 2),
    (57,  4, 96,  2, '', 0,  15, 2),
    (57,  5, 96,  3, '', 0,  15, 2),
    (57,  6, 96,  4, '', 0,  15, 2),
    (57,  7, 96,  5, '', 0,  15, 2),
    (57,  8, 96,  6, '', 0,  15, 2),
    (57,  9, 56, 31, '', 0,  35, 2),
    (57, 10, 56, 32, '', 0,  35, 2),
    (57, 11, 56, 33, '', 0,  35, 2);
