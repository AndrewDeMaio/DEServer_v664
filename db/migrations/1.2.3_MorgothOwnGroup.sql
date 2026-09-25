-- 1.2.3_MorgothOwnGroup.sql
--
-- Morgoth's reliquary (EventGiftBox type 33) gets its own reward group instead of sharing group 4.
--
-- Its handler branch read group 4, which is the generic gift-box pool (76 slayer / 53 vampire / 52 ousters
-- rows). Nothing else pointed at group 4, so those rows were effectively Morgoth's loot table, but the number
-- said otherwise and any future box sharing group 4 would have silently changed Morgoth too. The branch now
-- reads group 33, seeded here from v9's own group 33.
--
-- WHAT THIS CHANGES IN GAME: Morgoth's loot stops being the 76-row generic pool and becomes four Lilith
-- enchant items. v9's rows are imported verbatim, including their gaps, so the three races differ:
--
--   slayer    Lilith Will 2 100 / Lilith Spirit 2 100 / Lilith Drop 2 100 / Lilith Spirit 1750  -> Spirit ~85%
--   vampire   Lilith Will 2 100 / Lilith Spirit 2 100                                           -> 50 / 50
--   ousters   Lilith Will 2 100 / Lilith Spirit 2 100 / Lilith Drop 2 100                       -> a third each
--
-- That asymmetry is v9's data, not a transcription slip: its group 33 has no Lilith Drop 2 row for vampires
-- and gives Lilith Spirit to slayers only. Adding the three missing rows evens it out if you want that.
--
-- I could not confirm from the dump that v9's box 33 pointed at v9's group 33 - that mapping lives in the v9
-- binary - so treat this as "v9's group 33 content", not a proven reconstruction of Morgoth's original table.
-- To keep exactly what Morgoth drops today instead, replace the rows below with a copy of group 4:
--     INSERT INTO EventGiftBoxRewardItemInfo (`Groups`, `Orders`, `ItemClass`, `ItemType`, `OptionType`,
--            `LimitTime`, `Ratio`, `Race`)
--     SELECT 33, `Orders`, `ItemClass`, `ItemType`, `OptionType`, `LimitTime`, `Ratio`, `Race`
--       FROM EventGiftBoxRewardItemInfo WHERE `Groups` = 4;
--
-- Num is 2 on most of these rows because v9 handed out pairs, but EventGiftBoxRewardManager on this server
-- never reads that column - one item comes out regardless. Ratio is a weight within (Groups, Race).
--
-- The group 4 rows are left alone. Nothing reads them now; they are the fallback if this is reverted.
--
-- Ships with gameserver code: the box 33 branch in CGUseItemFromInventoryHandler::executeEventGiftBox() now
-- asks for group 33. Without that build this table is never consulted.
--
-- The game server loads this table at startup: restart it after this runs.
--
-- Safe to run twice: the group is deleted and rewritten.

SET NAMES utf8mb4;

DELETE FROM `EventGiftBoxRewardItemInfo` WHERE `Groups` = 33;

INSERT INTO `EventGiftBoxRewardItemInfo`
    (`Groups`, `Orders`, `ItemClass`, `ItemType`, `OptionType`, `LimitTime`, `Ratio`, `Race`)
VALUES
    (33,   0, 41, 60, '', 0,  100, 0),   -- Lilith Will 2
    (33,   0, 41, 60, '', 0,  100, 1),
    (33,   0, 41, 60, '', 0,  100, 2),
    (33,   1, 41, 61, '', 0,  100, 0),   -- Lilith Spirit 2
    (33,   1, 41, 61, '', 0,  100, 1),
    (33,   1, 41, 61, '', 0,  100, 2),
    (33,   2, 41, 62, '', 0,  100, 0),   -- Lilith Drop 2 (no vampire row in v9)
    (33,   2, 41, 62, '', 0,  100, 2),
    (33, 127, 41, 55, '', 0, 1750, 0);   -- Lilith Spirit, slayers only in v9, and ~85% of their table
