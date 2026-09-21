-- 1.1.4_MenegrothExactSpawns.sql
--
-- Menegroth B1F-B6F (zones 1701-1718, the same six floors for each race) spawn
-- only their own floor's monsters. Cabracam is not in these lists: the altars
-- summon it (MenegrothDoungeonZoneManager), and that is unchanged.
--
-- The floors listed their monsters in ZoneInfo.MonsterList. That list refills by
-- SPRITE, not by type: MonsterManager::regenerateCreatures() replaces a dead monster
-- with a random pick from every MonsterInfo row with NormalRegen = 1 and the same
-- SType. The level 350/200/100 chiefs share the floor monsters' sprites, so they
-- got picked too:
--
--   floor  sprite  listed        also picked by the refill
--   B1F    265     928-930       814, 824  Cerberus [14], level 350 (the client
--                                          calls them Guardian Leader / Hell
--                                          Garden Kid)
--   B2F    266     931-933       815       Manticoret [14], level 350
--   B3F    267     934-936       816, 825  BogletH [15] / Manticoret [14], 350
--   B4F    268     937-939       817       BogletB [15], level 200
--   B5F    269     940-942       818       Massacre [14], level 200
--   B6F    270     943-945       819       Plumpy Boar [14], level 100
--
-- EventMonsterList spawns and refills the exact type in each entry, so the lists
-- move there with the same counts. The delay of 1 second means a dead monster
-- comes back on the next 5-second regen tick, as it did before. The chiefs'
-- NormalRegen is left alone: zone 1013 uses 817 through its MonsterList.
--
-- Side effect: the counts in each entry now hold. Before, the first spawn filled
-- the whole floor with the first type in the list (55 level-30 Cerberus on B1F).
--
-- EventMonsterList only runs while AttrInfo 26 (ACTIVE_CHIEF_MONSTER) is 1,
-- which it is. Turning it off would leave these floors empty.
--
-- The game server reads ZoneInfo at startup: restart it after this runs.
--
-- Safe to run twice: each UPDATE only matches a row whose MonsterList still
-- holds the old list and whose EventMonsterList is empty.

SET NAMES utf8mb4;

UPDATE `ZoneInfo`
   SET `EventMonsterList` = '#Cerberus(928,30,1)(929,15,1)(930,10,1)',
       `MonsterList` = ''
 WHERE `ZoneID` IN (1701, 1707, 1713)
   AND `MonsterList` LIKE '%(928,30)(929,15)(930,10)'
   AND (`EventMonsterList` IS NULL OR `EventMonsterList` IN ('', CHAR(9)));

UPDATE `ZoneInfo`
   SET `EventMonsterList` = '#Manticoret(931,30,1)(932,15,1)(933,10,1)',
       `MonsterList` = ''
 WHERE `ZoneID` IN (1702, 1708, 1714)
   AND `MonsterList` LIKE '%(931,30)(932,15)(933,10)'
   AND (`EventMonsterList` IS NULL OR `EventMonsterList` IN ('', CHAR(9)));

UPDATE `ZoneInfo`
   SET `EventMonsterList` = '#BogletH(934,30,1)(935,15,1)(936,10,1)',
       `MonsterList` = ''
 WHERE `ZoneID` IN (1703, 1709, 1715)
   AND `MonsterList` LIKE '%(934,30)(935,15)(936,10)'
   AND (`EventMonsterList` IS NULL OR `EventMonsterList` IN ('', CHAR(9)));

UPDATE `ZoneInfo`
   SET `EventMonsterList` = '#BogletB(937,30,1)(938,15,1)(939,10,1)',
       `MonsterList` = ''
 WHERE `ZoneID` IN (1704, 1710, 1716)
   AND `MonsterList` LIKE '%(937,30)(938,15)(939,10)'
   AND (`EventMonsterList` IS NULL OR `EventMonsterList` IN ('', CHAR(9)));

UPDATE `ZoneInfo`
   SET `EventMonsterList` = '#Massacre(940,25,1)(941,15,1)(942,10,1)',
       `MonsterList` = ''
 WHERE `ZoneID` IN (1705, 1711, 1717)
   AND `MonsterList` LIKE '%(940,25)(941,15)(942,10)'
   AND (`EventMonsterList` IS NULL OR `EventMonsterList` IN ('', CHAR(9)));

UPDATE `ZoneInfo`
   SET `EventMonsterList` = '#PlumpyBoar(943,25,1)(944,15,1)(945,10,1)',
       `MonsterList` = ''
 WHERE `ZoneID` IN (1706, 1712, 1718)
   AND `MonsterList` LIKE '%(943,25)(944,15)(945,10)'
   AND (`EventMonsterList` IS NULL OR `EventMonsterList` IN ('', CHAR(9)));
