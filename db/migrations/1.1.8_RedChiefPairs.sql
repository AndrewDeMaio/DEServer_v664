-- 1.1.8_RedChiefPairs.sql
--
-- Every zone that spawns a brown chief now also spawns the red chief of the same
-- monster. One of each, with the same 1800-second regen delay as the brown ones.
--
-- The client alone decides a monster's look. It uses the MonsterType as the
-- creature.en.inf row and takes that row's ChangeColorSet. Two chief sets share
-- these sprites:
--
--   type  monster    client color            spawned by EventMonsterList in
--   461   Soldier    44  red                 12, 32
--   462   Soldier    474 brown               12, 32, 61-64
--   464   Dead Body  474 brown               12, 32, 61-64
--   564   Dead Body  120 red                 62, 64
--
-- Added here:
--
--   zone  name          adds
--   12    Eslania NW    564
--   32    Drobeta NW    564
--   61    Perona NE     461, 564
--   62    Perona NW     461
--   63    Perona SE     461, 564
--   64    Perona SW     461
--
-- The appended comment has no '(' or ',': parseEventMonsterList() reads
-- everything between '(' and ')' as an entry and skips the rest.
--
-- The game server reads ZoneInfo at startup: restart it after this runs.
--
-- Safe to run twice: each UPDATE skips a row that already carries the marker.

SET NAMES utf8mb4;

UPDATE `ZoneInfo`
   SET `EventMonsterList` = CONCAT(IFNULL(`EventMonsterList`, ''), CHAR(10),
                                   '#RedChiefPair 1.1.8 ( 564,1,1800 )', CHAR(10))
 WHERE `ZoneID` IN (12, 32)
   AND IFNULL(`EventMonsterList`, '') NOT LIKE '%RedChiefPair 1.1.8%';

UPDATE `ZoneInfo`
   SET `EventMonsterList` = CONCAT(IFNULL(`EventMonsterList`, ''), CHAR(10),
                                   '#RedChiefPair 1.1.8 ( 461,1,1800 )( 564,1,1800 )', CHAR(10))
 WHERE `ZoneID` IN (61, 63)
   AND IFNULL(`EventMonsterList`, '') NOT LIKE '%RedChiefPair 1.1.8%';

UPDATE `ZoneInfo`
   SET `EventMonsterList` = CONCAT(IFNULL(`EventMonsterList`, ''), CHAR(10),
                                   '#RedChiefPair 1.1.8 ( 461,1,1800 )', CHAR(10))
 WHERE `ZoneID` IN (62, 64)
   AND IFNULL(`EventMonsterList`, '') NOT LIKE '%RedChiefPair 1.1.8%';
