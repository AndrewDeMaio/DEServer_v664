-- 1.1.10_SuperiorChiefs.sql
--
-- The older chief set (MonsterInfo 462-481, except 463 and 477) becomes the
-- "Superior" chiefs. It has the same sprites as the newer red "Chief" set (564-603), but its
-- toughness comes from Enhance (HP +150-300%) rather than base stats.
--
-- The client draws a monster from its creature.en.inf row, keyed by MonsterType.
-- The client was changed alongside this migration (2026-09-22): rows 462, 464-476
-- and 478-481 are named "Superior <monster>" with ChangeColorSet 474 (brown).
-- This migration gives the server rows the same names, keeping each EName's
-- "[n]" suffix (the monster's loot class). Left alone:
--
--   461  Chief Soldier       red (44), the red partner of 462
--   463  Poisoned Dead Body  green (110)
--   477  Chaos Knight        dark gray (390)
--
-- The server uses EName only for log lines and for the loot file name of
-- MonsterClass 0 monsters. Every row here is MonsterClass 1-9 (loot from
-- data/Class<n>.*.bin), so drops do not change. HName keeps its Korean value: it
-- is the name the server gives a chief, and the client replaces it with the
-- creature.en.inf name.
--
-- EXP. Kill EXP (computeMonsterExp) is (STR+DEX+INT) * (0.75 + Level/200) *
-- (1 + Exp/100), and Enhance does not count toward it, so the Superiors paid no
-- more than a monster with their base stats, whatever their extra HP. Every
-- Superior gets Exp 200, which triples its kill value:
--
--   type  Superior           Level  Enhance HP  kill value  after
--   462   Soldier               9   +300%          83        249   (red 461: 83)
--   464   Dead Body             5   +300%          39        117   (red 564: 81)
--   465   Blood Warlock        45   +300%         204        612
--   466   Kid                   7   +150%          70        210
--   467   Golemer              50   +300%         225        675
--   468   Dirty Strider        32   +300%         168        504
--   469   Alkan                19   +300%         109        327
--   470   Chaos Guardian       75   +300%         337       1011
--   471   Shadow Wing          55   +300%         240        720
--   472   Mutant               25   +300%         131        393
--   473   Estroider            35   +300%         166        498
--   474   Moderas              28   +300%         137        411
--   475   Dark Screamer        71   +300%         314        942
--   476   Chaos Knight         65   +300%         287        861
--   478   Lord Darkness        95   +300%         437       1311
--   479   Hell Wizard          68   +300%         300        900
--   480   Dark Guardian       100   +300%         696       2088
--   481   Lord Chaos          100   +300%         531       1593
--
-- The server then multiplies these values by the AttrInfo EXP ratios.
-- Slayers get a smaller per-hit bonus from the same column:
-- x(1 + Exp/EnhanceHP * 0.5) when EnhanceHP >= 100, which is x1.33 at +300% and x1.67 for
-- the Kid at +150%.
--
-- Zones spawn 462 and 464 (ZoneInfo.EventMonsterList of 12, 32, 61-64). The
-- Gilles de Rais lair summons 467 and 471 (GDRLairManager.cpp). No zone spawns
-- the rest.
--
-- The game server reads MonsterInfo at startup: restart it after this runs.
--
-- Safe to run twice: every UPDATE sets fixed values.

SET NAMES utf8mb4;

UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Soldier [1]'        WHERE `MType` = 462;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Dead Body [1]'      WHERE `MType` = 464;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Blood Warlock [4]'  WHERE `MType` = 465;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Kid [1]'            WHERE `MType` = 466;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Golemer [4]'        WHERE `MType` = 467;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Dirty Strider [3]'  WHERE `MType` = 468;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Alkan [2]'          WHERE `MType` = 469;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Chaos Guardian [7]' WHERE `MType` = 470;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Shadow Wing [5]'    WHERE `MType` = 471;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Mutant [2]'         WHERE `MType` = 472;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Estroider [3]'      WHERE `MType` = 473;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Moderas [3]'        WHERE `MType` = 474;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Dark Screamer [6]'  WHERE `MType` = 475;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Chaos Knight [6]'   WHERE `MType` = 476;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Lord Darkness [9]'  WHERE `MType` = 478;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Hell Wizard [6]'    WHERE `MType` = 479;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Dark Guardian [8]'  WHERE `MType` = 480;
UPDATE `MonsterInfo` SET `Exp` = 200, `EName` = 'Superior Lord Chaos [8]'     WHERE `MType` = 481;
