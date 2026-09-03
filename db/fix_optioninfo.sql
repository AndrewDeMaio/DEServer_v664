-- =====================================================================
-- Revert the OptionInfo import. It must NOT be merged.
--
-- The gameserver refused to boot:
--     DuplicatedException : DupOptionLevel(OptionInfoSet):
--                           level=98, OptionType=205
--     <- OptionInfoManager::load()
--
-- OptionInfoSet::addOptionType enforces that (Class, OptionLevel) is unique
-- within an option class. My import keyed on OptionType -- the table's PRIMARY
-- KEY -- which does not imply that invariant, so 10 of the 41 imported rows
-- landed on slots our rows already occupied.
--
-- Looking at the collisions shows merging is wrong in principle, not merely
-- unlucky: our DB already fills those slots under DIFFERENT OptionType numbers
--     Class 23 Level 98  ours=183  original=205
--     Class 22 Level 97  ours=179  original=209
--     Class 21 Level 97  ours=175  original=213
-- The two databases number the same options differently. They are alternative
-- encodings of the same content, so the sets must not be mixed -- and ours is
-- the one the rest of our data and the running client already agree with.
--
-- OptionInfo is item enchant options; nothing in Menegroth or the rare skills
-- needs it, so reverting costs us nothing.
-- =====================================================================

USE DARKEDEN;

DELETE FROM `OptionInfo` WHERE `OptionType` IN (
  198,199,200,201,202,203,204,205,206,207,208,209,
  210,211,212,213,214,215,216,217,218,219,220,221,
  222,223,224,225,226,227,228,229,230,231,232,233,
  234,235,236,237,238
);

-- Expect 196 -- the count we booted with before the import.
SELECT COUNT(*) AS optioninfo_rows FROM `OptionInfo`;
