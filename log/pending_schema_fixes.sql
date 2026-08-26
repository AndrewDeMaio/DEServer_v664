-- Pending schema fixes, generated from the source-vs-DB diff.
-- Effect* columns are varchar(10) NOT NULL in every table that
-- already has them, so the type here is copied, not guessed.
-- Blocker: EffectLoaderManager::load() during Ousters::load().

ALTER TABLE EffectAccuraForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectAccuraForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectBehemothForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectBehemothForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectExtremeForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectExtremeForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectGentisDungeon ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectGreyfellForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectGreyfellForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectLifeForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectLifeForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectMirForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectMirForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectMysteryPotion ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectOdinForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectOdinForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectPromotionAngelFlutter ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectPromotionBatWing ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectPromotionButterflyWing ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectRankBonusExpBlue ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectRankBonusExpRed ADD COLUMN Name varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectSoviusForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectSoviusForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectTituosForceScroll ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';
ALTER TABLE EffectTituosForceScroll2 ADD COLUMN OwnerID varchar(10) NOT NULL DEFAULT '';

-- NEEDS TYPE REVIEW (not emitted as SQL):
--   ContributeRewardCount.Race
--   MakePCLog.EndDate
--   PVPSystemObject.SignDate
--   PVPSystemObject.SignName
--   PVPSystemPartyObject.PartyID
--   SimpleQuest.YearTime
