dofile("../script/zone/OldStone/lilith_Restrict.lua")
dofile("../script/zone/OldStone/lilith_Util.lua")
dofile("../script/zone/OldStone/lilith_TrapPos.lua")
dofile("../script/zone/OldStone/lilith_MonsterInfo.lua")
dofile("../script/zone/OldStone/lilith_string.lua")
dofile("../script/zone/OldStone/lilith_Restrict2.lua")

NumOfCurrentUser = 0

CurrentMissionRoom = 0	-- ?? ?
DoungeonStartTime = 0	-- 0 seconds
DoungeonLimitTime = 60 * 60 -- 60 minutes
DoungeonClear = false 
DoungeonTrapType = 2	-- 1 : ????, 2 : 中文
PlayerNameList = {}  --统计玩家名字
PlayerName = ""

local TempLogFileName = "../script/zone/OldStone/lilith_10.log"
local TempItemLogFileName = "../script/zone/OldStone/lilith_10_item.log"

--
MissionRoomSummonList = {}
MissionRoom1MonsterList = {}
--

MissionRoom1_MonsterPos = 
{
	{
		MonsterInfo = Gentis,
		MonsterPos =
		{
			{21,31}
		}
	}
}					

		

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
function OnResurrectCreature(CreatureInfo, ZoneCoordInfo)
	WriteLog(TempLogFileName, string.format("%s resurrected", CreatureInfo.Name))
	return false;
end

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
	for i,Name in pairs(PlayerNameList) do
			PlayerName = PlayerName.." "..Name
	end
	local MSEEAGE = string.format("[Notice]%s defeated Gentis!",PlayerName)
	DEScriptZone:BroadcastSystemMessage(1, MSEEAGE)
	DEScriptZone:SetTimer(5, 1000 * 4, 1)

end

function StartMissionFailed()
	-- 10?? ????????
	
	DEScriptZone:BroadcastSystemMessageInZone(0, "Mission failed. Returning to Ruper Island.")
	DEScriptZone:SetTimer(3, 1000 * 10, 1)
	
end

local L_PLAYER_ID_LIST = {}   --通关时提示玩家名字

function OnInitializeVariables(ZoneCreateInfo)

	ZoneCreateInfo.Name = "lilith_10"	
	ZoneCreateInfo.TemplateZoneID = 6191
	
	-- ???? ?????? ??
	ZoneCreateInfo.StartPosX = 21
	ZoneCreateInfo.StartPosY = 31

	-- indivisual(??), party(??), lobby(??, ?????????)
	ZoneCreateInfo.EntranceType = "indivisual"
	--ZoneCreateInfo.EntranceType = "party"
	ZoneCreateInfo.StaticZone = false
	
	--  ????? ???? ?? ???? 
	ZoneCreateInfo.EmptyTimeOut = 10 -- 15 sec
end 

function OnInitialize()
	
	DoungeonStartTime = DEScript:GetCurrentTime()
		
	StartMissionRoom1()

	DEScriptZone:SetTimer(1, 1000 * 5)
	
end

function OnTerminate()
	
end

function OnBeforeEnterZone(Creature)
	
	return true
	
end

function OnAfterEnterZone(Creature)
	local player = {Info = Creature}
	L_PLAYER_ID_LIST[ Creature.ObjectID ] = player
	table.insert(PlayerNameList,Creature.Name)
	if NumOfCurrentUser == 0 then
		-- ?? ???? ???? ???? ?? ?? ??
		DoungeonLimitTime = DEScript:ReadIntegerOnWhiteBoard("lilith.2F.RemainTime."..DEScriptZone:GetZoneID())
		
	end
	NumOfCurrentUser = NumOfCurrentUser + 1
	

	remainTime = GetRemainTime() * 10 -- 1/10 seconds
	
	SendRemiainTime(Creature, remainTime) 
end

function OnBeforeLeaveZone(Creature)
	
	SendRemiainTime(Creature, 0)
end

function OnAfterLeaveZone(Creature)
	NumOfCurrentUser = NumOfCurrentUser - 1
	
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
	
	return true;	-- ??????????
	
end

function OnSay(CreatureInfo, Mesg)

	return true
end

function OnTimer(TimerID)

	if TimerID == 1 then
	
		remainTime = GetRemainTime()
		 
		--DEScriptZone:BroadcastSystemMessageInZone(0, " "..remainTime.." seconds left")
		if DoungeonClear == false and remainTime < 0 then
			-- ?? ?????
			
			DEScriptZone:KillTimer(1)
			
			StartMissionFailed()
		end
		
		if remainTime < 60 * 5 then
			-- 5 ???? ??? ?
		
		end
	end

	if TimerID == 2 then
		WarpToOtherWorldZoneID = DEScriptZone:CreateInstanceDoungeon("OldStone/lilith_11")
		
		DEScript:WriteIntegerOnWhiteBoard("lilith.2F.RemainTime."..WarpToOtherWorldZoneID, GetRemainTime())
		
		OnTraverseCreature = OnWarpToOtherWorld
		DEScriptZone:TraverseCreature()		
	end
	
	if TimerID == 3 then
		OnTraverseCreature = OnWarpToGetOut
		DEScriptZone:TraverseCreature()	
	end
	
	if TimerID == 5 then
		-- ?? ???
		DEScriptZone:KillTimer(5)
		
		OnTraverseCreature = NotifyWarpToWorld
		DEScriptZone:TraverseCreature()

		DEScriptZone:SetTimer(2, 1000 * 5, 1)
	end
	
	ProcessTrap(TimerID)
end

function OnWarpToOtherWorld(Creature)
 	-- ?? -> ?? ??

	--if WarpToOtherWorldZoneID ~= 0 then
		DEScriptZone:TransportCreature(Creature, WarpToOtherWorldZoneID, 21, 31)
	--end
end

function OnGiveRewardItem(Creature)
			WriteLog(TempItemLogFileName, string.format("%s cleared floor 10 (reward)", Creature.Name))
			WriteLog(TempLogFileName, string.format("%s cleared floor 10", Creature.Name))
end