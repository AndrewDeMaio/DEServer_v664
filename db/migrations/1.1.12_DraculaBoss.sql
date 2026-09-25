-- 1.1.12_DraculaBoss.sql
--
-- Vlad II Dracul (MType 1196), the Dracula Castle boss, on 2F (zone 6052), and the reward he hands out.
--
-- The castle went in as zones 6050-6052 with monsters 1195 and 1197-1201; 1196, the boss they belong to, was
-- left out. Every value here is v9's row for him, unchanged apart from the English name and HasTreasure:
-- level 255, PROTECTION 1500 and DECREASEDAMAGE 99 make him far tougher than the castle trash, which was
-- halved from v9 when the floors were built. Retune him after a test fight if he turns out to be a wall
-- rather than a boss.
--
-- DirectiveSet 219 is v9's AI for him, verbatim except for line endings: five skills in fourteen directives,
-- Bloody Carpe and Bloody Scarify 2 at range, Talon of Dracule in melee, Rapid Gliding to close the gap, and
-- a summon that can never fire because MonsterSummonInfo is NULL - that is true in v9 too. The parser only
-- looks for "DIRECTIVE BEGIN" / "DIRECTIVE END" and the (IDENTIFIER:parameter) pairs between them
-- (Directive.cpp:328), so whitespace and line endings are free.
--
-- He drops nothing: HasTreasure = 0 is checked in MonsterManager::addItem() before any drop code runs, so it
-- switches off the MonsterClass 127 table, the level-150+ Forbidden Blood roll that phase 1b added, and the
-- event drops all at once. MonsterClass stays 127 so the row still says where his v9 loot table was; the
-- data/Class127.*.bin files are deleted, which MonsterInfo::load() tolerates by skipping the monster.
--
-- Instead, killing him hands a Dracula Box to every player in the zone, fought or not - the same treatment as
-- the Eisen B4F Astral chests. Opening it gives one of five things, each a 1 in 5 chance:
--
--     Elixir Fragment            CommonQuestItem 63   - added here
--     Ethereal Chain             EtherealChain 0
--     a Contract                 ContractOfBlood 0-6, picked at random
--     a Combining Forge          MixingItem 31/32/33 (weapon / armor / accessory), picked at random
--     a level-appropriate item   getRandomMysteriousItem() on a random weapon, armor or accessory class for
--                                the opener's race - the gamble shops' own roll, so it can only ever give
--                                something that character could equip
--
-- Item numbering: both new items take the next free type on this server rather than v9's. v9 calls the box
-- EventGiftBoxInfo 133 and has two CommonQuestItem rows named 'Elixir' (64 and 69), but this server's
-- EventGiftBoxInfo ends at 53 and its CommonQuestItemInfo at 62, and the client's item.en.inf classes are
-- dense arrays - using v9's numbers would mean 80 filler rows on the client for nothing. The client rows are
-- built to match these numbers and ship separately from this migration.
--
-- Ships with gameserver code:
--   * skills 544-546 (SKILL_DRACULE_TALON_OF_DRACULE, SKILL_DRACULE_BLOODY_SCARIFY_2,
--     SKILL_DRACULE_BLOODY_CARPE) and their handlers, which came in with the castle. Without that build the
--     AI set will not resolve three of its skill names.
--   * MonsterManager::killCreature(), which hands out the box.
--   * CGUseItemFromInventoryHandler::executeEventGiftBox(), which opens it.
--
-- The spawn is a placeholder. v9 ran him as a daily 19:00-19:10 event; this gives 2F, which has no other
-- spawns, one boss with an hour between deaths (EventMonsterList regen delay is in seconds,
-- MonsterManager.cpp:534). 2F is reached from 1F at (198-202,39-42) and leads back at (6-13,126-136).
--
-- The game server reads MonsterInfo, DirectiveSet, ZoneInfo and the item info tables at startup: restart it
-- after this runs.
--
-- Safe to run twice: every row is written with ON DUPLICATE KEY UPDATE, so a second run rewrites them to
-- exactly what is here, and the ZoneInfo update only matches 6052 while its spawn list is empty or already
-- this one.

SET NAMES utf8mb4;

INSERT INTO `MonsterInfo`
    (`MType`, `SType`, `HName`, `EName`, `Level`, `STR`, `DEX`, `INTE`, `BSize`,
     `Fame`, `Exp`, `MColor`, `SColor`, `Align`, `AOrder`, `Moral`, `Delay`,
     `ADelay`, `Sight`, `MeleeRange`, `MissileRange`, `RegenPortal`,
     `RegenInvisible`, `RegenBat`, `UnburrowChance`, `MMode`, `AIType`,
     `Enhance`, `SlayerTreasure`, `VampireTreasure`, `Master`, `ClanType`,
     `MonsterSummonInfo`, `DefaultEffects`, `Chief`, `NormalRegen`,
     `HasTreasure`, `MonsterClass`, `SkullType`)
VALUES
    (1196, 1196, _latin1 X'BAEDB6F3B5E520B5E5B6F3C5A7', 'Vlad II Dracul', 255, 2500, 2000, 3500, 2,
     0, 800, 1, 1, 2, 4, 6, 1000,
     900, 20, 1, 9, 0,
     0, 128, 128, 'WALK', 219,
     '(HP,400)(TOHIT,800)(DEFENSE,100)(PROTECTION,1500)(DECREASEDAMAGE,99)(NEXTRATIO,0)', NULL, NULL, 1, 1,
     NULL, 'IMMUNE_TO_BLOOD_DRAIN,IMMUNE_TO_PARALYZE,IMMUNE_TO_POISON,IMMUNE_TO_ACID,IMMUNE_TO_CURSE,IMMUNE_TO_HALLUCINATION,DETECT_INVISIBILITY,IMMUNE_TO_KNOCKBACK', 1, 0,
     0, 127, 0)
ON DUPLICATE KEY UPDATE
    `SType`             = VALUES(`SType`),
    `HName`             = VALUES(`HName`),
    `EName`             = VALUES(`EName`),
    `Level`             = VALUES(`Level`),
    `STR`               = VALUES(`STR`),
    `DEX`               = VALUES(`DEX`),
    `INTE`              = VALUES(`INTE`),
    `BSize`             = VALUES(`BSize`),
    `Fame`              = VALUES(`Fame`),
    `Exp`               = VALUES(`Exp`),
    `MColor`            = VALUES(`MColor`),
    `SColor`            = VALUES(`SColor`),
    `Align`             = VALUES(`Align`),
    `AOrder`            = VALUES(`AOrder`),
    `Moral`             = VALUES(`Moral`),
    `Delay`             = VALUES(`Delay`),
    `ADelay`            = VALUES(`ADelay`),
    `Sight`             = VALUES(`Sight`),
    `MeleeRange`        = VALUES(`MeleeRange`),
    `MissileRange`      = VALUES(`MissileRange`),
    `RegenPortal`       = VALUES(`RegenPortal`),
    `RegenInvisible`    = VALUES(`RegenInvisible`),
    `RegenBat`          = VALUES(`RegenBat`),
    `UnburrowChance`    = VALUES(`UnburrowChance`),
    `MMode`             = VALUES(`MMode`),
    `AIType`            = VALUES(`AIType`),
    `Enhance`           = VALUES(`Enhance`),
    `SlayerTreasure`    = VALUES(`SlayerTreasure`),
    `VampireTreasure`   = VALUES(`VampireTreasure`),
    `Master`            = VALUES(`Master`),
    `ClanType`          = VALUES(`ClanType`),
    `MonsterSummonInfo` = VALUES(`MonsterSummonInfo`),
    `DefaultEffects`    = VALUES(`DefaultEffects`),
    `Chief`             = VALUES(`Chief`),
    `NormalRegen`       = VALUES(`NormalRegen`),
    `HasTreasure`       = VALUES(`HasTreasure`),
    `MonsterClass`      = VALUES(`MonsterClass`),
    `SkullType`         = VALUES(`SkullType`);

INSERT INTO `DirectiveSet` (`ID`, `Name`, `Content`, `DeadContent`)
VALUES (219, 'Vlad II Dracul',
'DIRECTIVE BEGIN
 (CONDITION:ImInBadPosition)
 (ACTION:MoveRandom,10)
DIRECTIVE END
DIRECTIVE BEGIN
 (CONDITION:FindWeakEnemy)
 (ACTION:ChangeEnemy,15)
DIRECTIVE END
DIRECTIVE BEGIN
 (CONDITION:ImDying)
 (CONDITION:EnemyRangeInMissile)
 (ACTION:UseSkill,SKILL_DRACULE_BLOODY_CARPE,30)
DIRECTIVE END
DIRECTIVE BEGIN
 (CONDITION:ImDying)
 (CONDITION:EnemyRangeInMissile)
 (ACTION:UseSkill,SKILL_DRACULE_BLOODY_SCARIFY_2,20)
DIRECTIVE END
DIRECTIVE BEGIN
 (CONDITION:ImDying)
 (CONDITION:EnemyRangeInMissile)
 (ACTION:UseSkill,SKILL_DRACULE_BLOODY_CARPE,20)
DIRECTIVE END
DIRECTIVE BEGIN
 (CONDITION:ImDying)
 (CONDITION:EnemyRangeInMissile)
 (CONDITION:PossibleSummonMonsters)
 (ACTION:UseSkill,SKILL_SUMMON_MONSTERS,10)
DIRECTIVE END
DIRECTIVE BEGIN
 (CONDITION:EnemyRangeMissile)
 (ACTION:UseSkill,SKILL_DRACULE_BLOODY_CARPE,30)
DIRECTIVE END
DIRECTIVE BEGIN
 (CONDITION:EnemyRangeMissile)
 (ACTION:UseSkill,SKILL_DRACULE_BLOODY_SCARIFY_2,40)
DIRECTIVE END
DIRECTIVE BEGIN
 (CONDITION:EnemyRangeMelee)
 (ACTION:UseSkill,SKILL_DRACULE_TALON_OF_DRACULE,30)
DIRECTIVE END
DIRECTIVE BEGIN
 (CONDITION:EnemyRangeMelee)
 (ACTION:UseSkill,SKILL_DRACULE_BLOODY_CARPE,30)
DIRECTIVE END
DIRECTIVE BEGIN
 (CONDITION:EnemyRangeMelee)
 (ACTION:UseSkill,SKILL_DRACULE_BLOODY_SCARIFY_2,30)
DIRECTIVE END
DIRECTIVE BEGIN
    (CONDITION:EnemyRangeMelee)
    (ACTION:UseSkill,SKILL_DRACULE_TALON_OF_DRACULE,50)
DIRECTIVE END
DIRECTIVE BEGIN
    (CONDITION:ImOK)
    (CONDITION:EnemyRangeMissile)
    (ACTION:UseSkill,SKILL_RAPID_GLIDING,50)
DIRECTIVE END
DIRECTIVE BEGIN
 (CONDITION:EnemyRangeMissile)
 (ACTION:Approach)
DIRECTIVE END', '')
ON DUPLICATE KEY UPDATE
    `Name`        = VALUES(`Name`),
    `Content`     = VALUES(`Content`),
    `DeadContent` = VALUES(`DeadContent`);

UPDATE `ZoneInfo`
   SET `EventMonsterList` = '(1196,1,3600)'
 WHERE `ZoneID` = 6052
   AND (`EventMonsterList` IS NULL
        OR `EventMonsterList` = ''
        OR `EventMonsterList` = '(1196,1,3600)');

INSERT INTO `CommonQuestItemInfo`
    (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `ItemLevel`, `BonusRatio`, `Race`)
VALUES
    (63, _latin1 X'BFA4B8AFBCAD20C1B6B0A2', 'Elixir Fragment', 1, 1, 1, 0, 0, 0, 7)
ON DUPLICATE KEY UPDATE
    `Name`       = VALUES(`Name`),
    `EName`      = VALUES(`EName`),
    `Price`      = VALUES(`Price`),
    `Volume`     = VALUES(`Volume`),
    `Weight`     = VALUES(`Weight`),
    `Ratio`      = VALUES(`Ratio`),
    `ItemLevel`  = VALUES(`ItemLevel`),
    `BonusRatio` = VALUES(`BonusRatio`),
    `Race`       = VALUES(`Race`);

INSERT INTO `EventGiftBoxInfo`
    (`ItemType`, `Name`, `EName`, `Price`, `Volume`, `Weight`, `Ratio`, `Race`)
VALUES
    (54, _latin1 X'B5E5B6F3C5A7B6F320BBF3C0DA', 'Dracula Box', 0, 5, 1, 0, 7)
ON DUPLICATE KEY UPDATE
    `Name`   = VALUES(`Name`),
    `EName`  = VALUES(`EName`),
    `Price`  = VALUES(`Price`),
    `Volume` = VALUES(`Volume`),
    `Weight` = VALUES(`Weight`),
    `Ratio`  = VALUES(`Ratio`),
    `Race`   = VALUES(`Race`);
