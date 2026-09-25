-- 1.1.13_DraculaBoxType57.sql
--
-- The Dracula Box moves from EventGiftBox type 54 to 57, because 54 was not free.
--
-- 1.1.12 picked 54 from the data alone: EventGiftBoxInfo ended at 53 and the client's item.en.inf class 40 had
-- 54 rows. But CGUseItemFromInventoryHandler::executeEventGiftBox() already had branches for types up to 56,
-- and its type-54 branch pulls a reward from EventGiftBoxRewardItemInfo group 54 and then writes the result
-- to UseGiftBoxLog. That table is empty on this server, so the reward came back NULL, the log dereferenced it,
-- and right-clicking the box killed the game server. The Dracula branch, which was appended after it in the
-- chain, never ran at all. 57 is the first type no branch uses.
--
-- The one box already in the world (Waterana's) is converted rather than deleted.
--
-- Ships with gameserver code: the handler branch and MonsterManager::killCreature() now both say 57, and the
-- four UseGiftBoxLog blocks (box types 52, 54, 55, 56) no longer dereference a NULL reward - box 52 exists in
-- EventGiftBoxInfo, so that crash was reachable by any player holding one, with or without Dracula.
--
-- The client's item.en.inf class 40 gets fillers at 54-56 and the box at 57; it ships separately.
--
-- The game server reads the item info tables at startup: restart it after this runs.
--
-- Safe to run twice: the insert converges with ON DUPLICATE KEY UPDATE, and the delete and the update only
-- match the old type while it is still the Dracula Box.

SET NAMES utf8mb4;

INSERT INTO `EventGiftBoxInfo`
    (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `Race`)
VALUES
    (57, _latin1 X'B5E5B6F3C5A7B6F320BBF3C0DA', 'Dracula Box', 0, 5, 1, 0, 7)
ON DUPLICATE KEY UPDATE
    `Name`   = VALUES(`Name`),
    `EName`  = VALUES(`EName`),
    `Price`  = VALUES(`Price`),
    `Volume` = VALUES(`Volume`),
    `Weight` = VALUES(`Weight`),
    `Ratio`  = VALUES(`Ratio`),
    `Race`   = VALUES(`Race`);

UPDATE `EventGiftBoxObject` SET `ItemType` = 57 WHERE `ItemType` = 54;

DELETE FROM `EventGiftBoxInfo` WHERE `ItemType` = 54 AND `EName` = 'Dracula Box';
