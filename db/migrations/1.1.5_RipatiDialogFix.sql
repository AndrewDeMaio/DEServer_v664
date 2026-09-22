-- 1.1.5_RipatiDialogFix.sql
--
-- Ripati (NPC 리파티, NPCID 654, zone 1311 - the Ousters healer), script 12301.
-- The Ousters twin of David's menu fixed in 1.1.2.
--
-- The server had heal / buy / sell / Temerie / Caligo, then goodbye on answer 6.
-- The client row goes on: exchange battlefield tokens / something I can help
-- with / combine / claim an item reward / goodbye, so "exchange battlefield
-- tokens" closed the dialog and the last four answers had no trigger at all,
-- which froze the dialog. The menus they lead to - the Lir Token exchange
-- (12316), the Ancient Remain quest (12308-12315), combining (12320) and the
-- Sealing Stone confirm (12321) - had no triggers either.
--
-- "Claim an item reward" is gone from the client row: it ran GiveCrashingReward,
-- which pays out rows a GM put in `ItemList` (crash compensation), and that table
-- is empty. Client row 12301 has the nine answers below.
--
-- Goodbye moves 6 -> 9, then the missing answers are added, as v9 had them
-- except 12321 answer 1, which v9 left as a dead QuitDialogue: TradeSealingStone
-- takes the 7 Bathory Bijous, 2 pendants, 10 Blue Drops and 600000 the script
-- asks for and gives a Sealing Stone.
--
-- The game server reads Triggers at startup: restart it after this runs.
--
-- Safe to run twice: every statement only matches the rows as they were.

SET NAMES utf8mb4;

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 6', 'AnswerID : 9')
 WHERE `TriggerID` = 1413
   AND `NPC` = X'C0FBCCD8'
   AND `Conditions` REGEXP 'ScriptID : 12301[^0-9]+AnswerID : 6([^0-9]|$)'
   AND `Actions` REGEXP 'ActionType : QuitDialogue[[:space:]]*$';

INSERT INTO `Triggers` (`TriggerType`, `NPC`, `QuestID`, `Conditions`, `Actions`)
SELECT 'NPC', X'C0FBCCD8', 0,
       CONCAT('ConditionType : AnsweredBy\n\t\tScriptID : ', m.s, '\n\t\tAnswerID : ', m.n, '\n\t'),
       m.a
  FROM (          SELECT 12301 AS s, 6 AS n, '\n\tActionType : Ask\n\t\tScriptID : 12316\n\t' AS a
        UNION ALL SELECT 12301, 7, '\n\tActionType : Ask\n\t\tScriptID : 12308\n\t'
        UNION ALL SELECT 12301, 8, '\n\tActionType : Ask\n\t\tScriptID : 12320\n\t'
        UNION ALL SELECT 12308, 1, '\n\tActionType : Ask\n\t\tScriptID : 12309\n\t'
        UNION ALL SELECT 12308, 2, '\n\tActionType : QuitDialogue\n\t'
        UNION ALL SELECT 12309, 1, '\n\tActionType : CheckCommonQuestItem\n\t\tQuestItem : 10\n\t\tEnoughGetItemScriptID : 12310\n\t\tNotEnoughGetItemScriptID : 12311\n\t'
        UNION ALL SELECT 12309, 2, '\n\tActionType : CheckCommonQuestItem\n\t\tQuestItem : 30\n\t\tEnoughGetItemScriptID : 12312\n\t\tNotEnoughGetItemScriptID : 12311\n\t'
        UNION ALL SELECT 12309, 3, '\n\tActionType : CheckCommonQuestItem\n\t\tQuestItem : 50\n\t\tEnoughGetItemScriptID : 12313\n\t\tNotEnoughGetItemScriptID : 12311\n\t'
        UNION ALL SELECT 12309, 4, '\n\tActionType : CheckCommonQuestItem\n\t\tQuestItem : 100\n\t\tEnoughGetItemScriptID : 12314\n\t\tNotEnoughGetItemScriptID : 12311\n\t'
        UNION ALL SELECT 12309, 5, '\n\tActionType : CheckCommonQuestItem\n\t\tQuestItem : 1000\n\t\tEnoughGetItemScriptID : 12315\n\t\tNotEnoughGetItemScriptID : 12311\n\t'
        UNION ALL SELECT 12309, 6, '\n\tActionType : QuitDialogue\n\t'
        UNION ALL SELECT 12310, 1, '\n\tActionType : GiveCommonQuestItem\n\t\tItemID : 1\n\t\tQuestItem : 10\n\t'
        UNION ALL SELECT 12311, 1, '\n\tActionType : QuitDialogue\n\t'
        UNION ALL SELECT 12312, 1, '\n\tActionType : GiveCommonQuestItem\n\t\tItemID : 2\n\t\tQuestItem : 30\n\t'
        UNION ALL SELECT 12313, 1, '\n\tActionType : GiveCommonQuestItem\n\t\tItemID : 3\n\t\tQuestItem : 50\n\t'
        UNION ALL SELECT 12314, 1, '\n\tActionType : GiveCommonQuestItem\n\t\tItemID : 4\n\t\tQuestItem : 100\n\t'
        UNION ALL SELECT 12315, 1, '\n\tActionType : GiveCommonQuestItem\n\t\tItemID : 5\n\t\tQuestItem : 1000\n\t'
        UNION ALL SELECT 12316, 1, '\n\tActionType : CheckLevelWarReward\n\t\tType : Level1\n\t'
        UNION ALL SELECT 12316, 2, '\n\tActionType : CheckLevelWarReward\n\t\tType : Level2\n\t'
        UNION ALL SELECT 12316, 3, '\n\tActionType : CheckLevelWarReward\n\t\tType : Level3\n\t'
        UNION ALL SELECT 12316, 4, '\n\tActionType : CheckLevelWarReward\n\t\tType : Level4\n\t'
        UNION ALL SELECT 12316, 5, '\n\tActionType : QuitDialogue\n\t'
        UNION ALL SELECT 12320, 1, '\n\tActionType : Ask\n\t\tScriptID : 12321\n\t'
        UNION ALL SELECT 12320, 2, '\n\tActionType : QuitDialogue\n\t'
        UNION ALL SELECT 12321, 1, '\n\tActionType : TradeSealingStone\n\t'
        UNION ALL SELECT 12321, 2, '\n\tActionType : QuitDialogue\n\t') AS m
 WHERE NOT EXISTS (SELECT 1 FROM `Triggers` t
                    WHERE t.`NPC` = X'C0FBCCD8'
                      AND t.`Conditions` REGEXP CONCAT('ScriptID : ', m.s, '[^0-9]+AnswerID : ', m.n, '([^0-9]|$)'));
