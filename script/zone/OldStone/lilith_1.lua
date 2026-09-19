dofile("../script/zone/OldStone/lilith_Restrict.lua")
dofile("../script/zone/OldStone/lilith_Util.lua")
dofile("../script/zone/OldStone/lilith_TrapPos.lua")
dofile("../script/zone/OldStone/lilith_MonsterInfo.lua")
dofile("../script/zone/OldStone/lilith_string.lua")

MaxScriptZoneCount = 10
DoungeonOpened = true
WarpToOtherWorldZoneID = 0

CurrentMissionRoom = 0	-- ?úÏûë ??
DoungeonStartTime = 0	-- 0 seconds
DoungeonLimitTime = 60 * 60 -- 20 minutes
DoungeonClear = false 
DoungeonTrapType = 1	-- 1 : ?ÑÏÑ∏?∏Îû©, 2 : ?¥Í≥Ñ?∏Îû©

StringPool = {
	STRID_MONSTER_NAME_CLONEGUSION = 740,
	STRID_MONSTER_NAME_CLONEMORGOTH = 741,
	STRID_MONSTER_NAME_LSLAYER = 737,
	STRID_MONSTER_NAME_LVAMPIRE = 738,
	STRID_MONSTER_NAME_LOUSTERS = 739
}
--ÏßÄ?∞Î©¥ ?àÎêú??-
MissionRoomSummonList = {}
MissionRoom1MonsterList = {}
--ÏßÄ?∞Î©¥ ?àÎêú??-

MissionRoom1_MonsterPos = 
{
	{
		MonsterInfo = ServantPalus,
		MonsterPos =
		{
			{20,26},
			{24,26},
			{28,30},
			{27,34},
			{24,37},
			{20,37}
		}
	}
}		

--ÏßÄ?∞Î©¥ ?àÎêú??-
TrapActivationInfoList = 


{
	-- MissionRoom1
	{
	},
	-- MissionRoom2
	{
		Stage = 0,
		TrapPosList = MissionRoom2_TrapPosList,
		
		ActivationTime =
		{
			{10, 30},
			{5, 20}
		}
	},
	-- MissionRoom3
	{
	},
	-- MissionRoom4
	{
		Stage = 0,
		TrapPosList = MissionRoom4_TrapPosList,
		
		ActivationTime =
		{
			{10, 30},
			{5, 20}
		}
	},
	-- MissionRoom5
	{
		Stage = 0,
		TrapPosList = MissionRoom5_TrapPosList,
		
		ActivationTime =
		{
			{10, 30},
			{5, 20}
		}
	},
	-- MissionRoom6
	{
	},
	-- MissionRoomBoss
	{
		Stage = 0,
		TrapPosList = MissionRoomBoss_TrapPosList,
		
		ActivationTime =
		{
			{10,30},
			{5,20},
			{5,10}
		}
	},
}
--ÏßÄ?∞Î©¥ ?àÎêú??-

function StartMissionRoom1()

	CurrentMissionRoom = 1
	
	for i, MonsterArrangeInfo in pairs(MissionRoom1_MonsterPos) do
		AddMonsterInfo = MonsterArrangeInfo.MonsterInfo
		
		for index, MonsterPos in ipairs(MonsterArrangeInfo.MonsterPos) do
			AddMonsterInfo.X = MonsterPos[1]
			AddMonsterInfo.Y = MonsterPos[2]
			
			AddedMonster = DEScriptZone:AddMonster(AddMonsterInfo)
			
			table.insert(MissionRoom1MonsterList, AddedMonster.ObjectID)
			if MonsterArrangeInfo.SummonFunc ~= nil then
				MissionRoomSummonList[AddedMonster.ObjectID] = MonsterArrangeInfo.SummonFunc
			end
		end	
	end

end

function StartMissionSuccess()
	DoungeonClear = true	
	
	OnTraverseCreature = OnGiveRewardItem
	DEScriptZone:TraverseCreature()
	
	DEScriptZone:BroadcastSystemMessageInZone(0, "Moving to floor 2.")
	DEScriptZone:SetTimer(5, 1000 * 1, 1)
			MonsterAllKill = true
end

function StartMissionFailed()
	-- 10Ï¥àÌõÑ ?∞Î™®Î•??∏ÏàòÎ°??¥Îèô
	
	DEScriptZone:BroadcastSystemMessageInZone(0, "Mission failed. Returning to Ruper Island.")
	DEScriptZone:SetTimer(3, 1000 * 10, 1)
	
end


function OnInitializeVariables(ZoneCreateInfo)

	ZoneCreateInfo.Name = "lilith_1"
	ZoneCreateInfo.TemplateZoneID = 6110
	
	-- Ï¢ÖÏ°±Î≥ÑÎ°ú ?§Î•∏Í≤ΩÏö∞?êÎäî ??
	ZoneCreateInfo.StartPosX = 22
	ZoneCreateInfo.StartPosY = 31

	-- indivisual(Í∞úÏù∏), party(?åÌã∞), lobby(Î°úÎπÑ, Î°úÎπÑ???§Ïñ¥Í∞???Ï∞∏Ïó¨)
	--ZoneCreateInfo.EntranceType = "indivisual"
	ZoneCreateInfo.EntranceType = "party"
	ZoneCreateInfo.StaticZone = false
	
	--  ?ÑÎ¨¥???ÜÎäî ?ÅÌÉú?êÏÑú ÏµúÎ? ÏßÄ???úÍ∞Ñ 
	ZoneCreateInfo.EmptyTimeOut = 10 -- 15 sec
end 

function OnInitialize()
	
	if ( DEScriptZone:GetScriptZoneCount() > MaxScriptZoneCount ) then
		DoungeonOpened = false
		
		return
	end
	
	DoungeonOpened = true
	
	DoungeonStartTime = DEScript:GetCurrentTime()
		
	StartMissionRoom1()

	DEScriptZone:SetTimer(1, 1000 * 5)
	
end

function OnTerminate()
	
end

function OnBeforeEnterZone(Creature)
	if DoungeonOpened == false then
		-- ?òÏ†Ñ ?ùÏÑ± ?úÌïú Ï¥àÍ≥º
		DEScriptZone:SendSystemMessage(Creature, 0, "The Gentis Dungeon is full. Try again later.")
		
		DEScriptZone:SetIgnoreEmptyTimeOut(true)
		
		return false;
	end
	
	PlayerLevel = DEScript:GetLevel(Creature)
	AdvLevel = DEScript:GetAdvancementClassLevel(Creature)

	if (PlayerLevel + AdvLevel ) < 181 then
		DEScriptZone:SendSystemMessage(Creature, 0, "Your level plus advancement level must be at least 181 to enter.")
		
		return false
	end

	HaveItemInfo = 
	{
		-- key
		ItemClass = 91,
		ItemType = 61,
		ItemCount = 1
	}

	if DEScriptZone:HaveItem(Creature, HaveItemInfo) then
		TakeItemInfo = {}
		TakeItemInfo = HaveItemInfo

		DEScriptZone:TakeItem(Creature, TakeItemInfo)

		return true
	end

	DEScriptZone:SendSystemMessage(Creature, 0, "You need a Stone Key to enter.")

	return false
	
end

function OnAfterEnterZone(Creature)
	remainTime = GetRemainTime() * 10 -- 1/10 seconds
	
	SendRemiainTime(Creature, remainTime) 
end

function OnBeforeLeaveZone(Creature)
	
	SendRemiainTime(Creature, 0)
end

function OnAfterLeaveZone(Creature)
	
end

function OnAttackCreature(AttackerCreature, DefenderCreature)
	
	if DefenderCreature.ObjectID == 0 then
		return
	end
	
	if DEScript:IsMonster(DefenderCreature) then
		if MissionRoomSummonList[DefenderCreature.ObjectID] ~= nil then
			local f = MissionRoomSummonList[DefenderCreature.ObjectID]
			f(AttackerCreature, DefenderCreature)
		end		
	end
end

function OnKillCreature(AttackerCreature, DeadCreature)
	if CurrentMissionRoom == 1 then
		if CheckMissionAllKill(DeadCreature.ObjectID, MissionRoom1MonsterList) then
			StartMissionSuccess()
		end
	end	
end

function OnAddMonster(Monster)

end

function OnResurrectCreature(CreatureInfo, ZoneCoordInfo)
	
	ZoneCoordInfo.ZoneID = 6000
	ZoneCoordInfo.X = 107
	ZoneCoordInfo.Y = 51
	
	return true;	-- ?§Ï†ï??Î∂Ä???ÑÏπòÎ°??¥Îèô
	
end

function OnSay(CreatureInfo, Mesg)
	
	return true
end

function OnTimer(TimerID)

	if TimerID == 1 then
	
		remainTime = GetRemainTime()
		 
		--DEScriptZone:BroadcastSystemMessageInZone(0, " "..remainTime.." seconds left")
		if DoungeonClear == false and remainTime < 0 then
			-- ?òÏ†Ñ ?¥Î¶¨???§Ìå®
			
			DEScriptZone:KillTimer(1)
			
			StartMissionFailed()
		end
		
		if remainTime < 60 * 5 then
			-- 5 Î∂ÑÏù¥?òÍ? ?®Ïïò?? ??
		
		end
	end
	
	if TimerID == 2 then
		WarpToOtherWorldZoneID = DEScriptZone:CreateInstanceDoungeon("OldStone/lilith_2")
		
		DEScript:WriteIntegerOnWhiteBoard("lilith.2F.RemainTime."..WarpToOtherWorldZoneID, GetRemainTime())
		
		OnTraverseCreature = OnWarpToOtherWorld
		DEScriptZone:TraverseCreature()	
	end
	
	if TimerID == 3 then
		OnTraverseCreature = OnWarpToGetOut
		DEScriptZone:TraverseCreature()	
	end
	
	if TimerID == 5 then
		-- ÎØ∏ÏÖò ?±Í≥µ??
		DEScriptZone:KillTimer(5)
		
		OnTraverseCreature = NotifyWarpToWorld
		DEScriptZone:TraverseCreature()

		DEScriptZone:SetTimer(2, 1000 * 5, 1)

	end
	
	ProcessTrap(TimerID)
end


function OnWarpToOtherWorld(Creature)
 	-- ?ÑÏÑ∏ -> ?¥Í≥Ñ ?¥Îèô

	if WarpToOtherWorldZoneID ~= 0 then
		DEScriptZone:TransportCreature(Creature, WarpToOtherWorldZoneID, 21, 31)
	end
end

function OnGiveRewardItem(Creature)


end