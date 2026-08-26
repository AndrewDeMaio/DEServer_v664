-- Missing AttrInfo rows that silently zeroed ALL experience gain.
--
-- Under __METRO_SERVER__ (defined at src/Core/types/ServerType.h:8) the exp
-- pipeline ends with an UNCONDITIONAL multiply -- the isPCRoomPlay() guarded
-- version directly above it is commented out:
--
--     Point = getPercentValueEx( Point, pGamePlayer->getPCRoomExpBonus() );
--
-- getPCRoomExpBonus() switches on getPayPlayRoomType(). A normal home
-- connection is PAY_PLAY_ROOM_TYPE_HOME (0), which reads HOME_EXP_BONUS
-- (variable 170). That row did not exist, so VariableManager returned 0 from
-- its zero-initialised vector, every exp value was multiplied by 0%, and no
-- character of any race could gain experience.
--
-- Affected: increaseDomainExp (Slayer), increaseVampExp, increaseOustersExp,
-- and shareAttrExp (STR/DEX/INT) -- SkillUtil.cpp:5730-5733, 6295, 6815, 7076.
--
-- 100 = 100% = no adjustment, the correct neutral value for a home connection.
-- PCROOM_FREE_EXP_BONUS (65) already existed at 100.

INSERT INTO AttrInfo (attrID, attr1, attr2) VALUES
  (170, 100, 0),   -- HOME_EXP_BONUS
  (171, 100, 0)    -- PCROOM_CHARGE_EXP_BONUS
ON DUPLICATE KEY UPDATE attr1 = VALUES(attr1);
