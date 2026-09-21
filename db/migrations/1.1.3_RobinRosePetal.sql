-- 1.1.3_RobinRosePetal.sql
--
-- Robin Baxter (NPC 428, accessories / repair / storage in Perona SW) sold
-- "Rose Petal" - ItemClass 72 (MOON_CARD) type 5, a Hell Garden item - in the
-- last slot of his normal rack. ShopTemplate 4606 is removed. It is his
-- highest template ID, so no other slot moves.
--
-- The client builds its normal and gamble shelves from its own npc(.en).inf and
-- ShopTemplate.inf, so re-export those from ShopTemplate after this runs, or the
-- client keeps showing the petal.
--
-- The game server reads shop templates at startup: restart it after this runs.
--
-- Safe to run twice: the WHERE clause only matches the row as it was.

SET NAMES utf8mb4;

DELETE FROM `ShopTemplate`
 WHERE `ID` = 4606
   AND `NPCID` = 428
   AND `ShopType` = 0
   AND `ItemClass` = 72
   AND `MinItemType` = 5
   AND `MaxItemType` = 5;
