
function IsAbleToUseItem(Creature, ItemClass, ItemType)
	Result = true

	if ItemClass == 39 then		-- è½¨é¢‡æç»¢ ç?è¤ä¾©  é™›ç˜¤
		Result = false
	elseif ItemClass == 51 then		-- æµ‡é¥­æç»¢ ç›®æ•²å‚?è¤ä¾©  é™›ç˜¤
		Result = false
	elseif ItemClass == 52 then		-- è½¨é¢‡æç»¢ ç›®æ•²å‚?è¤ä¾©  é™›ç˜¤
		Result = false
	elseif ItemClass == 93 then		-- é…’å¿«èƒ¶ç£ä»?çªè‘›è‘?åŸ”å¸¦é£?è¤ä¾©  é™›ç˜¤
		Result = false
	end
	
	if ItemClass == 7 then			-- å®˜æå†?é™›ç˜¤
		Result = false
	elseif ItemClass == 98 then		-- è½¨é¢‡ å–‡é…’æè¢ é™›ç˜¤
		Result = false
	elseif ItemClass == 99 then		-- é…’å¿« å–‡é…’æè¢ é™›ç˜¤
		Result = false
	end
	
	if ( Result == false ) then
		DEScriptZone:SendSystemMessage(Creature, 0, "This item cannot be used in current dungeon.")
	end
			
	return Result
end

function IsAbleToUseSkill(Creature, SkillType)
	Result = true
	
	if SkillType == 185 then		-- ??‚Ü?
		Result = false
	elseif SkillType == 115 then	-- ÒÊÁÑ°¯’ì
		Result = false
	elseif SkillType == 114 then	-- ÒÊÁÑµ¤?
		Result = false
	elseif SkillType == 289 then	-- ??
		Result = false
	elseif SkillType == 119 then	-- ??
		Result = false
	elseif SkillType == 278 then	-- ¼Û¿ÕÁÑ•ç
		Result = false
	elseif SkillType == 327 then	-- ¸ñŞà?
		Result = false
	elseif SkillType == 423 then	-- ??ÁÑ?1
		Result = false
	elseif SkillType == 424 then	-- ??ÁÑ?2
		Result = false
	elseif SkillType == 427 then	-- ÒÊ?1
		Result = false
	elseif SkillType == 428 then	-- ÒÊ?2
		Result = false
	elseif SkillType == 433 then	-- ???½g1
		Result = false
	elseif SkillType == 434 then	-- ???½g2
		Result = false
	elseif SkillType == 156 then	-- ÒÊÄí??
		Result = false
	elseif SkillType == 432 then	-- ÒÊÔG
		Result = false
	elseif SkillType == 576 then	-- ????
		Result = false
	elseif SkillType == 634 then	-- ???´±
		Result = false
	end
	
	if ( Result == false ) then
		DEScriptZone:SendSystemMessage(Creature, 0, "This skill cannot be used in current dungeon.")
	end
			
	return Result
	
end

function OnUseItemInGear(Creature, ItemClass, ItemType)
	return IsAbleToUseItem(Creature, ItemClass, ItemType)
end

function OnUseItemInQuick(Creature, ItemClass, ItemType)
	return IsAbleToUseItem(Creature, ItemClass, ItemType)
end

function OnUseItemInInventory(Creature, ItemClass, ItemType)
	return IsAbleToUseItem(Creature, ItemClass, ItemType)
end

function OnUseInventorySkill(Creature, SkillType)
	return IsAbleToUseSkill(Creature, SkillType)
end

function OnUseObjectSkill(Creature, SkillType)
	return IsAbleToUseSkill(Creature, SkillType)
end

function OnUseNamedSkill(Creature, SkillType)
	return IsAbleToUseSkill(Creature, SkillType)
end

function OnUseSelfSkill(Creature, SkillType)
	return IsAbleToUseSkill(Creature, SkillType)
end

function OnUseTileSkill(Creature, SkillType)
	return IsAbleToUseSkill(Creature, SkillType)
end

