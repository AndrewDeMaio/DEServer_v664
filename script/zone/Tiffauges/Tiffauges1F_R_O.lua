-- 아우스터즈용 티포쥬 1F 현세

dofile("../script/zone/Tiffauges/Tiffauges1F_R.lua")

function GetRace()
	return "Ousters"
end

function OnBeforeEnterZone(Creature)
	if not DEScript:IsOusters(Creature) then
		DEScriptZone:SendSystemMessage(Creature, 0, "Only acceptable race may enter.")
		
		return false;
	end
	
	PlayerLevel = DEScript:GetLevel(Creature)
	AdvLevel = DEScript:GetAdvancementClassLevel(Creature)
	
	if (PlayerLevel + AdvLevel ) < 130 then
		DEScriptZone:SendSystemMessage(Creature, 0, "Your level is too low to enter.")
		
		return false
	end	

	return true;	
end

function OnAfterEnterZone(Creature)

end

function OnBeforeLeaveZone(Creature)

end

function OnAfterLeaveZone(Creature)

end