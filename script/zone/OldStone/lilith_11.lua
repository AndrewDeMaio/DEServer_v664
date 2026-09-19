dofile("../script/zone/OldStone/lilith_11Restrict.lua")
dofile("../script/zone/OldStone/lilith_11Util.lua")
dofile("../script/zone/OldStone/lilith_11TrapPos.lua")
dofile("../script/zone/OldStone/lilith_11MonsterInfo.lua")
dofile("../script/zone/OldStone/lilith_11string.lua")

WarpToOtherWorldZoneID = 0
NumOfCurrentUser = 0
PlayerNameList = {}
PlayerName = ""

CurrentMissionRoom = 0	-- 시작 전
DoungeonStartTime = 0	-- 0 seconds
DoungeonLimitTime = 1 * 25 -- 60 minutes
DoungeonClear = false 
DoungeonTrapType = 2	-- 1 : 현세트랩, 2 : 이계트랩

--지우면 안된다--
MissionRoomSummonList = {}
MissionRoom1MonsterList = {}
--지우면 안된다--

MissionRoom1_MonsterPos = 
{
	{
		MonsterInfo = WolfStone,
		MonsterPos =
		{
			{22,13}
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
	local MSEEAGE = string.format("[Notice]%s cleared the Gentis Dungeon!",PlayerName)
	DEScriptZone:BroadcastSystemMessage(1, MSEEAGE)
	DEScriptZone:SetTimer(5, 1000 * 4, 1)

end

function StartMissionFailed()
	-- 10초후 티모르 호수로 이동
	OnTraverseCreature = OnGiveRewardItem
	DEScriptZone:TraverseCreature()

	DEScriptZone:BroadcastSystemMessageInZone(0, "Returning to Ruper Island.")
	DEScriptZone:SetTimer(3, 1000 * 1, 1)
	
end

function OnInitializeVariables(ZoneCreateInfo)

	ZoneCreateInfo.Name = "lilith_11"	
	ZoneCreateInfo.TemplateZoneID = 6100
	
	-- 종족별로 다른경우에는 ??
	ZoneCreateInfo.StartPosX = 21
	ZoneCreateInfo.StartPosY = 31

	-- indivisual(개인), party(파티), lobby(로비, 로비에 들어간 후 참여)
	ZoneCreateInfo.EntranceType = "indivisual"
	--ZoneCreateInfo.EntranceType = "party"
	ZoneCreateInfo.StaticZone = false
	
	--  아무도 없는 상태에서 최대 지속 시간 
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
	table.insert(PlayerNameList, Creature.Name)
	if NumOfCurrentUser == 0 then
		-- 처음 들어오는 캐릭터를 기준으로 남은 시간 설정
		--DoungeonLimitTime = DEScript:ReadIntegerOnWhiteBoard("lilith.2F.RemainTime."..DEScriptZone:GetZoneID())
		
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
	
	return true;	-- 설정된 부활 위치로 이동
	
end

function OnSay(CreatureInfo, Mesg)

	return true
end

function OnTimer(TimerID)

	if TimerID == 1 then
	
		remainTime = GetRemainTime()
		 
		--DEScriptZone:BroadcastSystemMessageInZone(0, " "..remainTime.." seconds left")
		if DoungeonClear == false and remainTime < 0 then
			-- 던전 클리어 실패
			
			DEScriptZone:KillTimer(1)
			
			StartMissionFailed()
		end
		
		if remainTime < 60 * 5 then
			-- 5 분이하가 남았을  때,
		
		end
	end
	
	if TimerID == 3 then
		OnTraverseCreature = OnWarpToGetOut
		DEScriptZone:TraverseCreature()	
	end
	
	if TimerID == 5 then
		-- 미션 성공시
		DEScriptZone:KillTimer(5)
		
		DEScriptZone:BroadcastSystemMessageInZone(0, "The spirit of the Lycan warrior is at rest. Leave this place.")
		DEScriptZone:SetTimer(3, 1000 * 1, 1)
	end
	
	ProcessTrap(TimerID)
end

function OnGiveRewardItem(Creature)
	GiveItemInfo = 
	{
		ItemClass = 91,
		ItemType = 62,
		ItemCount = 1,
		Options = "",
		LimitedTime = 0
	}
	DEScriptZone:GiveItem(Creature, GiveItemInfo)

end