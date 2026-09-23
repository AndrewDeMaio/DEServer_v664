-- 1.1.11_NoNewbieEventItems.sql
--
-- New characters no longer get the 30-day event items. Variable 236
-- (EVENT_NEWBIE_ITEMS_GIVE) goes to 0, and addNewbieEventItemToInventory() then
-- stops after the pet. What it used to hand out, all with a 30-day expiry:
--
--   every race  Contract of Blood, hourglasses (Slayer 60 of type 5, the others
--               9 of type 6), 40 each of quest items 6-11 (seals), skill books
--   Vampire     coat, 2 earrings, 4 rings, weapon 18, all ATTR+3/HPS+3
--   Ousters     coat, boots, circlet, 2 rings, 2 pendants, 6 stones, same options
--
-- Still granted, permanently: the Slayer weapon set, magazine and potions, the
-- Ousters pupa/larva and Tou Chakram + three wristlets, 500 gold, and the
-- mini-dog pet (NEWBIE_ITEM_EVENT, variable 169, which stays 1).
--
-- Ships with gameserver code. addNewbieItemToGear(Ousters*) was also gated on
-- 236, so without the matching ItemUtil.cpp change a new Ousters starts with no
-- weapon. Ousters::loadItem() now clears FLAGSET_RECEIVE_NEWBIE_ITEM_AUTO
-- outside the event branch, as Slayer::loadItem() does.
--
-- Characters that already received the items keep them until they expire.
--
-- The game server reads AttrInfo at startup: restart it after this runs.
--
-- Safe to run twice: it sets a value.

SET NAMES utf8mb4;

UPDATE `AttrInfo`
   SET `attr1` = 0,
       `comm`  = 'EVENT_NEWBIE_ITEMS_GIVE - 1 adds the 30-day event items to a new character'
 WHERE `attrID` = 236;
