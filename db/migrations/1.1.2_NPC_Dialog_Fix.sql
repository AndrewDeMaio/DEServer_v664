-- 1.1.2_NPC_Dialog_Fix.sql
--
-- NPC dialog fixes. The server runs an NPC menu answer by its POSITION
-- (Triggers: ConditionType AnsweredBy, ScriptID, AnswerID), and the client shows
-- the labels from its own npcscript(.en).inf row for that ScriptID. Where the two
-- were made for different server versions, a label runs its neighbour's action.
-- Each block below lines one menu up with the client row that ships with it.
--
-- The game server reads Triggers at startup: restart it after this runs.
--
-- Safe to run twice: every statement only matches the rows as they were.

SET NAMES utf8mb4;

-- ---------------------------------------------------------------------------
-- Christine (NPC 크리스틴, NPCID 22, zone 2011 - the storage keeper), script 2300.
--
-- Server answers were: buy a storage slot / open storage / Darden Market basket
-- (Ask 2310) / pet storage / goodbye. The client row read "... / pet storage /
-- exchange currency / goodbye", so "pet storage" opened the basket and "exchange
-- currency" opened pet storage; there is no currency exchange action.
--
-- The basket is on the game menu, so it goes: answer 3 (Ask 2310) and script
-- 2310's two answers are deleted, pet storage becomes answer 3 and goodbye 4.
-- Client row 2300 (npcscript.en.inf) has the same four options.
-- ---------------------------------------------------------------------------

DELETE FROM `Triggers`
 WHERE `TriggerID` IN (167, 170, 171)
   AND `NPC` = X'C5A9B8AEBDBAC6BE'
   AND (`Conditions` LIKE '%ScriptID : 2300%AnswerID : 3%'
     OR `Conditions` LIKE '%ScriptID : 2310%');

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 4', 'AnswerID : 3')
 WHERE `TriggerID` = 168
   AND `NPC` = X'C5A9B8AEBDBAC6BE'
   AND `Conditions` LIKE '%ScriptID : 2300%AnswerID : 4%'
   AND `Actions` LIKE '%PetDeposit%';

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 5', 'AnswerID : 4')
 WHERE `TriggerID` = 169
   AND `NPC` = X'C5A9B8AEBDBAC6BE'
   AND `Conditions` LIKE '%ScriptID : 2300%AnswerID : 5%'
   AND `Actions` LIKE '%QuitDialogue%';

-- ---------------------------------------------------------------------------
-- David (NPC 大卫, NPCID 27, zone 2001 - the repairman), scripts 1200/1207/1210/1211.
--
-- Client row 1200: repair / combine items / Caligo Dungeon / exchange
-- battlefield tokens / carry on. The server only had repair, then Caligo on
-- answer 2 and goodbye on answer 3, so "combine" warped to Caligo, "Caligo"
-- closed the dialog and answers 4 and 5 did nothing. The token exchange
-- (1207), combining (1210) and the Sealing Stone confirm (1211) had no
-- triggers at all.
--
-- Goodbye moves 3 -> 5 and Caligo 2 -> 3 (in that order), then the missing
-- answers are added. 1211 answer 1 runs TradeSealingStone: it takes the 7
-- Bathory Bijous, 2 pendants, 10 Blue Drops and 600000 Rey the script asks
-- for and gives a Sealing Stone.
-- ---------------------------------------------------------------------------

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 3', 'AnswerID : 5')
 WHERE `TriggerID` = 102
   AND `NPC` = X'B4F7CEAC'
   AND `Conditions` REGEXP 'ScriptID : 1200[^0-9]+AnswerID : 3([^0-9]|$)'
   AND `Actions` LIKE '%QuitDialogue%'
   AND `Actions` NOT LIKE '%WarpLevelWarZone%';

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 2', 'AnswerID : 3')
 WHERE `TriggerID` = 101
   AND `NPC` = X'B4F7CEAC'
   AND `Conditions` REGEXP 'ScriptID : 1200[^0-9]+AnswerID : 2([^0-9]|$)'
   AND `Actions` LIKE '%WarpLevelWarZone%';

INSERT INTO `Triggers` (`TriggerType`, `NPC`, `QuestID`, `Conditions`, `Actions`)
SELECT 'NPC', X'B4F7CEAC', 0,
       CONCAT('ConditionType : AnsweredBy\n\t\tScriptID : ', m.s, '\n\t\tAnswerID : ', m.n, '\n\t'),
       m.a
  FROM (          SELECT 1200 AS s, 2 AS n, '\n\tActionType : Ask\n\t\tScriptID : 1210\n\t' AS a
        UNION ALL SELECT 1200, 4, '\n\tActionType : Ask\n\t\tScriptID : 1207\n\t'
        UNION ALL SELECT 1207, 1, '\n\tActionType : CheckLevelWarReward\n\t\tType : Level1\n\t'
        UNION ALL SELECT 1207, 2, '\n\tActionType : CheckLevelWarReward\n\t\tType : Level2\n\t'
        UNION ALL SELECT 1207, 3, '\n\tActionType : CheckLevelWarReward\n\t\tType : Level3\n\t'
        UNION ALL SELECT 1207, 4, '\n\tActionType : CheckLevelWarReward\n\t\tType : Level4\n\t'
        UNION ALL SELECT 1207, 5, '\n\tActionType : QuitDialogue\n\t'
        UNION ALL SELECT 1210, 1, '\n\tActionType : Ask\n\t\tScriptID : 1211\n\t'
        UNION ALL SELECT 1210, 2, '\n\tActionType : QuitDialogue\n\t'
        UNION ALL SELECT 1211, 1, '\n\tActionType : TradeSealingStone\n\t'
        UNION ALL SELECT 1211, 2, '\n\tActionType : QuitDialogue\n\t') AS m
 WHERE NOT EXISTS (SELECT 1 FROM `Triggers` t
                    WHERE t.`NPC` = X'B4F7CEAC'
                      AND t.`Conditions` REGEXP CONCAT('ScriptID : ', m.s, '[^0-9]+AnswerID : ', m.n, '([^0-9]|$)'));

-- ---------------------------------------------------------------------------
-- Smith (NPC 스미스, NPCID 103, zone 2003 - Soldier Guild), script 2100.
--
-- Client row 2100: five donations / "I've come about a team" / goodbye. The
-- server had the donations, then Sell, Buy, Ask 2121 (teams), a test-server
-- reward and goodbye as answers 6-10, so "team" opened his shop and "goodbye"
-- the sell window. Sell, Buy and the test reward go; teams becomes answer 6
-- and goodbye 7. Script 2121 (team menu) and 2122 (leave team) were right.
-- ---------------------------------------------------------------------------

DELETE FROM `Triggers`
 WHERE `TriggerID` IN (838, 839, 841)
   AND `NPC` = X'BDBAB9CCBDBA'
   AND `Conditions` REGEXP 'ScriptID : 2100[^0-9]+AnswerID : (6|7|9)([^0-9]|$)'
   AND (`Actions` REGEXP 'ActionType : (Sell|Buy)[[:space:]]*$'
     OR `Actions` LIKE '%GiveTestServerReward%');

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 8', 'AnswerID : 6')
 WHERE `TriggerID` = 840
   AND `NPC` = X'BDBAB9CCBDBA'
   AND `Conditions` REGEXP 'ScriptID : 2100[^0-9]+AnswerID : 8([^0-9]|$)'
   AND `Actions` REGEXP 'ScriptID : 2121([^0-9]|$)';

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 10', 'AnswerID : 7')
 WHERE `TriggerID` = 842
   AND `NPC` = X'BDBAB9CCBDBA'
   AND `Conditions` REGEXP 'ScriptID : 2100[^0-9]+AnswerID : 10([^0-9]|$)'
   AND `Actions` LIKE '%QuitDialogue%';

-- ---------------------------------------------------------------------------
-- Terry (NPC 特里, NPCID 302, zone 12 - Eslania NW, beginner items), script 5600.
--
-- The server had show goods (Sell) / sell to her (Buy) / goodbye, while the
-- client row read show goods / Blood Contract / goodbye, so "Blood Contract"
-- opened the sell window. Client row 5600 now has four options - show goods /
-- sell items / Blood Contract / goodbye - so goodbye moves 3 -> 4 and answer 3
-- asks 5606.
--
-- The Blood Contract (scripts 5606-5608) is the gamble: each try costs
-- 10000 Rey x 1.5^tries and adds 1-3 to a running total; landing on 3, 6 or 9
-- gives a Contract of Blood and resets it. 5606 answer 3 resets the total.
-- ---------------------------------------------------------------------------

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 3', 'AnswerID : 4')
 WHERE `TriggerID` = 506
   AND `NPC` = X'CCD8C0EF'
   AND `Conditions` REGEXP 'ScriptID : 5600[^0-9]+AnswerID : 3([^0-9]|$)'
   AND `Actions` LIKE '%QuitDialogue%';

INSERT INTO `Triggers` (`TriggerType`, `NPC`, `QuestID`, `Conditions`, `Actions`)
SELECT 'NPC', X'CCD8C0EF', 0,
       CONCAT('ConditionType : AnsweredBy\n\t\tScriptID : ', m.s, '\n\t\tAnswerID : ', m.n, '\n\t'),
       m.a
  FROM (          SELECT 5600 AS s, 3 AS n, '\n\tActionType : Ask\n\t\tScriptID : 5606\n\t' AS a
        UNION ALL SELECT 5606, 1, '\n\tActionType : AskVariable\n\t\tScriptID : 5607\n\t\tVariable : GambleAccumulation:GambleAccumulation(), GambleTryCount:GambleTryCount(), GambleMoney:GambleMoney()\n\t'
        UNION ALL SELECT 5606, 2, '\n\tActionType : QuitDialogue\n\t'
        UNION ALL SELECT 5606, 3, '\n\tActionType : GambleSystem\n\t\tSelectID : 1\n\t\tNextScript : 5606\n\t'
        UNION ALL SELECT 5607, 1, '\n\tActionType : GambleSystem\n\t\tSelectID : 0\n\t\tNextScript : 5608\n\t'
        UNION ALL SELECT 5607, 2, '\n\tActionType : QuitDialogue\n\t'
        UNION ALL SELECT 5608, 1, '\n\tActionType : AskVariable\n\t\tScriptID : 5607\n\t\tVariable : GambleAccumulation:GambleAccumulation(), GambleTryCount:GambleTryCount(), GambleMoney:GambleMoney()\n\t'
        UNION ALL SELECT 5608, 2, '\n\tActionType : QuitDialogue\n\t') AS m
 WHERE NOT EXISTS (SELECT 1 FROM `Triggers` t
                    WHERE t.`NPC` = X'CCD8C0EF'
                      AND t.`Conditions` REGEXP CONCAT('ScriptID : ', m.s, '[^0-9]+AnswerID : ', m.n, '([^0-9]|$)'));

-- ---------------------------------------------------------------------------
-- Robin Baxter (NPC 洛宾, NPCID 428, zone 64 - Perona SW), script 8100.
--
-- Adds silver-plating (SilverCoating, as Smilovich and Hasbro have it) after
-- repair: bike 5 -> 6, pet storage 6 -> 7 and goodbye 7 -> 8 (highest first),
-- then silver-plating becomes answer 5. Client row 8100 has the same eight.
-- ---------------------------------------------------------------------------

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 7', 'AnswerID : 8')
 WHERE `TriggerID` = 831
   AND `NPC` = X'C2E5B1F6'
   AND `Conditions` REGEXP 'ScriptID : 8100[^0-9]+AnswerID : 7([^0-9]|$)'
   AND `Actions` LIKE '%QuitDialogue%';

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 6', 'AnswerID : 7')
 WHERE `TriggerID` = 830
   AND `NPC` = X'C2E5B1F6'
   AND `Conditions` REGEXP 'ScriptID : 8100[^0-9]+AnswerID : 6([^0-9]|$)'
   AND `Actions` LIKE '%PetDeposit%';

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 5', 'AnswerID : 6')
 WHERE `TriggerID` = 829
   AND `NPC` = X'C2E5B1F6'
   AND `Conditions` REGEXP 'ScriptID : 8100[^0-9]+AnswerID : 5([^0-9]|$)'
   AND `Actions` LIKE '%RedeemMotorcycle%';

INSERT INTO `Triggers` (`TriggerType`, `NPC`, `QuestID`, `Conditions`, `Actions`)
SELECT 'NPC', X'C2E5B1F6', 0,
       'ConditionType : AnsweredBy\n\t\tScriptID : 8100\n\t\tAnswerID : 5\n\t',
       '\n\tActionType : SilverCoating\n\t'
  FROM DUAL
 WHERE NOT EXISTS (SELECT 1 FROM `Triggers` t
                    WHERE t.`NPC` = X'C2E5B1F6'
                      AND t.`Conditions` REGEXP 'ScriptID : 8100[^0-9]+AnswerID : 5([^0-9]|$)');

-- ---------------------------------------------------------------------------
-- Old Woman (NPC SlayerShop, NPCID 637, zone 64 - Perona SW), script 20000.
--
-- She now only teaches skills and buys the player's items. Her shop (Sell),
-- collecting goods (TakeOutGoods) and the lair trade (Ask 19003) go, along
-- with her 19003 answers, which nothing reaches any more (the VampShop has its
-- own 19003 triggers and keeps them). Learn skills becomes answer 1, selling
-- to her stays 2 and goodbye becomes 3. Client row 20000 has the same three.
-- PrepareShop / RegenShop stay: selling to her goes through her shop.
-- ---------------------------------------------------------------------------

DELETE FROM `Triggers`
 WHERE `NPC` = 'SlayerShop'
   AND ((`TriggerID` = 1956 AND `Conditions` REGEXP 'ScriptID : 20000[^0-9]+AnswerID : 1([^0-9]|$)'
                            AND `Actions` REGEXP 'ActionType : Sell[[:space:]]*$')
     OR (`TriggerID` = 1955 AND `Actions` LIKE '%TakeOutGoods%')
     OR (`TriggerID` = 1968 AND `Actions` REGEXP 'ScriptID : 19003([^0-9]|$)')
     OR (`TriggerID` BETWEEN 1980 AND 1987 AND `Conditions` REGEXP 'ScriptID : 19003([^0-9]|$)'));

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 4', 'AnswerID : 1')
 WHERE `TriggerID` = 1960
   AND `NPC` = 'SlayerShop'
   AND `Conditions` REGEXP 'ScriptID : 20000[^0-9]+AnswerID : 4([^0-9]|$)'
   AND `Actions` REGEXP 'ScriptID : 20001([^0-9]|$)';

UPDATE `Triggers`
   SET `Conditions` = REPLACE(`Conditions`, 'AnswerID : 6', 'AnswerID : 3')
 WHERE `TriggerID` = 1988
   AND `NPC` = 'SlayerShop'
   AND `Conditions` REGEXP 'ScriptID : 20000[^0-9]+AnswerID : 6([^0-9]|$)'
   AND `Actions` LIKE '%QuitDialogue%';
