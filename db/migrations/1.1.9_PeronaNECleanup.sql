-- 1.1.9_PeronaNECleanup.sql
--
-- Two things in Perona NE (zone 61) that do not belong there.
--
-- The Cabracam altar by Griffith's hut at (112,199) is the NPC VampShop. The
-- client picks an NPC's sprite and name from creature.en.inf by NPCID, and 996
-- is "Altar of Cabracam" (the same id as one of the Menegroth altars in 1712).
-- It was never usable: its greeting, script 19001, is not in the client, and the
-- client binds a script to an NPC only when the script's owner matches that
-- name, which "Shop" does not. Its menu, shop, skill teaching, hunting-ground
-- portals and lair trades could not be reached. The NPC, its triggers and its
-- shop stock (ShopTemplate NPCID 996, used by no other NPC) go. The altar of the
-- same NPCID in zone 1712 is keyed by its own name and is not touched.
--
-- Griffith (NPCID 427) sold Seed of Hell Garden (MoonCard 6). Seeds are a
-- Hell Garden tower drop, traded 20 at a time to the crystal orb for a reward,
-- so selling them bypasses the tower. His other stock stays.
--
-- The game server loads NPCs and shop stock at startup: restart it after this
-- runs.
--
-- Safe to run twice: the second run finds no rows.

SET NAMES utf8mb4;

-- ---------------------------------------------------------------------------
-- VampShop (NPCID 996, zone 61): the altar-looking NPC.
-- Scripts 19001-19003, 20005/20006 and 20101-20108 are owned by "Shop" and are
-- left alone.
-- ---------------------------------------------------------------------------

DELETE FROM `Triggers`
 WHERE `NPC` = 'VampShop';

DELETE FROM `NPC`
 WHERE `Name` = 'VampShop'
   AND `NPCID` = 996
   AND `ZoneID` = 61;

DELETE FROM `ShopTemplate`
 WHERE `NPCID` = 996;

-- ---------------------------------------------------------------------------
-- Griffith (NPCID 427, zone 61): Seed of Hell Garden off the shelf.
-- ---------------------------------------------------------------------------

DELETE FROM `ShopTemplate`
 WHERE `NPCID` = 427
   AND `ItemClass` = 72
   AND `MinItemType` = 6
   AND `MaxItemType` = 6;
