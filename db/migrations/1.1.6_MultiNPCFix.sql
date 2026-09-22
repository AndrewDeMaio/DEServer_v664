-- 1.1.6_MultiNPCFix.sql
--
-- Monster hunting quest givers whose quests were filed under the wrong name.
--
-- These NPCs are in the NPC table twice, once under a Korean name and once under
-- a GBK one. Only the name that has triggers spawns; the other row loads with no
-- position and is never seen. InitSimpleQuest loads an NPC's quests and rewards
-- by the spawned NPC's name, but they were keyed by the other one, so the NPC had
-- none: SelectQuest sent an empty list and the client showed nothing. Each block
-- moves the quests and rewards to the name the NPC spawns under. The client's
-- questinfo.inf already has every quest below with the same targets, goals and
-- time limits.
--
-- The game server loads these at startup: restart it after this runs.
--
-- Safe to run twice: the second run finds no rows under the old names.

SET NAMES utf8mb4;

-- ---------------------------------------------------------------------------
-- Amata (NPCID 657, zone 1311 - the Ousters storage keeper): quests 88-108.
-- Spawns as 阿玛塔 (GBK); the quests were under 아마타 (Korean).
-- ---------------------------------------------------------------------------

UPDATE `MonsterKillQuestInfo`
   SET `NPC` = X'B0A2C2EDCBFE'
 WHERE `NPC` = X'BEC6B8B6C5B8';

UPDATE `ItemRewardInfo`
   SET `NPC` = X'B0A2C2EDCBFE'
 WHERE `NPC` = X'BEC6B8B6C5B8';

UPDATE `SlayerWeaponRewardInfo`
   SET `NPC` = X'B0A2C2EDCBFE'
 WHERE `NPC` = X'BEC6B8B6C5B8';

-- ---------------------------------------------------------------------------
-- Chris (NPCID 21, zone 2021 - Warrior Guild 1F, the Slayer storage keeper):
-- quests 1-21. Spawns as 克里斯 (GBK); the quests were under 크리스 (Korean).
-- Christine (크리스틴) is a different NPC and is not touched: these match the
-- whole name only.
-- ---------------------------------------------------------------------------

UPDATE `MonsterKillQuestInfo`
   SET `NPC` = X'BFCBC0EFCBB9'
 WHERE `NPC` = X'C5A9B8AEBDBA';

UPDATE `ItemRewardInfo`
   SET `NPC` = X'BFCBC0EFCBB9'
 WHERE `NPC` = X'C5A9B8AEBDBA';

UPDATE `SlayerWeaponRewardInfo`
   SET `NPC` = X'BFCBC0EFCBB9'
 WHERE `NPC` = X'C5A9B8AEBDBA';
