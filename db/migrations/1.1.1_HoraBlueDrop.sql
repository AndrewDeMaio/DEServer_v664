-- 1.1.1_HoraBlueDrop.sql
--
-- Hora (NPC 658, the Ousters potion seller in Perona NW) sold "Seed Of
-- Foresight" - ItemClass 72 (MOON_CARD) type 7, a Hell Garden item - in the last
-- slot of her normal rack. It is meant to be the ordinary enchant star the other
-- shops sell: "Blue Drop", ItemClass 41 (EVENT_STAR) type 7 (templates 170,
-- 2235, 5031, 6917). ShopTemplate 7007 had the wrong class; the type was right.
--
-- Found 2026-09-18, after the client's shop files were rebuilt from this table.
-- The client builds its normal and gamble shelves from its own npc(.en).inf and
-- ShopTemplate.inf, so re-export those from ShopTemplate after this runs, or the
-- client keeps showing the seed.
--
-- The game server reads shop templates at startup: restart it after this runs.
--
-- Safe to run twice: the WHERE clause only matches the row as it was.

SET NAMES utf8mb4;

UPDATE `ShopTemplate`
   SET `ItemClass` = 41
 WHERE `ID` = 7007
   AND `NPCID` = 658
   AND `ItemClass` = 72
   AND `MinItemType` = 7
   AND `MaxItemType` = 7;
