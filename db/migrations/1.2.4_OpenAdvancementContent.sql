-- 1.2.4_OpenAdvancementContent.sql
--
-- Turn on the advancement ("job promotion") content switch.
--
-- AttrInfo 207 is VariableManager ADVANCE_ENABLE ("advancement content open: 0 close / 1 open"). It shipped
-- as 0, and GQuestInfoManager::load() only reads data/EventGQuest.xml - the file that holds the three
-- advancement quests (1010 slayer "Ring of Evolution" via Terry/Rebecca, and the vampire and ousters
-- equivalents) - when that switch is on. With it off the quests do not exist on the server at all, so
-- Terry has nothing to offer a level-150 slayer and nobody can ever gain an advancement level.
--
-- Read at gameserver boot (VariableManager::load replays AttrInfo over the code defaults): restart the
-- gameserver after running this. Quest availability is re-evaluated on login and on level-up, so
-- characters already at 150 see the quest in their quest window after relogging.
--
-- Rollback: UPDATE AttrInfo SET attr1 = 0 WHERE attrID = 207;

SET NAMES utf8mb4;

UPDATE AttrInfo SET attr1 = 1 WHERE attrID = 207 AND attr1 IN (0, 1);
