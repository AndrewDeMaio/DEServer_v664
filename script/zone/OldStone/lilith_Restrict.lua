
function IsAbleToUseItem(Creature, ItemClass, ItemType)
	Result = true

	if ItemClass == 39 then		-- 轨颇捞绢 �?荤侩  陛瘤
		Result = false
	elseif ItemClass == 51 then		-- 浇饭捞绢 目敲�?荤侩  陛瘤
		Result = false
	elseif ItemClass == 52 then		-- 轨颇捞绢 目敲�?荤侩  陛瘤
		Result = false
	elseif ItemClass == 93 then		-- 酒快胶磐�?窍葛�?埔带�?荤侩  陛瘤
		Result = false
	end
	
	if ItemClass == 7 then			-- 官捞�?陛瘤
		Result = false
	elseif ItemClass == 98 then		-- 轨颇 喇酒捞袍 陛瘤
		Result = false
	elseif ItemClass == 99 then		-- 酒快 喇酒捞袍 陛瘤
		Result = false
	end
	
	if ( Result == false ) then
		DEScriptZone:SendSystemMessage(Creature, 0, "This item cannot be used in current dungeon.")
	end
			
	return Result
end

function IsAbleToUseSkill(Creature, SkillType)
	Result = true

	if SkillType == 185 then		-- 家匡眉牢  陛瘤
		Result = false
	elseif SkillType == 115 then	-- 喉矾�?磐澄  陛瘤(轨颇 �?
		Result = false
	elseif SkillType == 114 then	-- 喉矾�?付农 陛瘤(轨颇 �?
		Result = false
	end

	if SkillType == 102 then	-- 冠零 函脚 陛瘤
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

