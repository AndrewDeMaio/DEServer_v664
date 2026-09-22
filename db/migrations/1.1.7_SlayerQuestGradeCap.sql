-- 1.1.7_SlayerQuestGradeCap.sql
--
-- Chris's top monster hunting quests (19-21: Mum Rimmon, Dun Wolfarch, Dark
-- Berith) stopped at quest grade 885. A Slayer's quest grade is STR + DEX + INT
-- - 1.5 x (Heal + Enchant domain levels); normal stat caps keep it under 475, but
-- late-game Slayers will pass 1000 in a single stat, and above 885 no quest fit,
-- so Chris offered nothing. The top tier is now open-ended until higher quests
-- are added (narrow 19-21 again when they are).
--
-- Why 65535 and not the type's maximum: the grade is an unsigned DWORD, and a
-- healer whose domain penalty outweighs their stats has a negative grade that
-- wraps to about 4 billion. The cap has to stay below that, or those healers
-- would be offered the top tier.
--
-- The game server loads quests at startup: restart it after this runs.
--
-- Safe to run twice: the second run finds no rows still capped at 885.

SET NAMES utf8mb4;

UPDATE `MonsterKillQuestInfo`
   SET `MaxGrade` = 65535
 WHERE `QuestID` IN (19, 20, 21)
   AND `Race` = 0
   AND `MaxGrade` = 885;
