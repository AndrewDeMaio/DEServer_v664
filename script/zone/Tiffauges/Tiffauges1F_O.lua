dofile("../script/zone/Tiffauges/Tiffauges1F_Restrict.lua")
dofile("../script/zone/Tiffauges/Tiffauges1F_O_MonsterInfo.lua")
dofile("../script/zone/Tiffauges/Tiffauges1F_TrapPos.lua")
dofile("../script/zone/Tiffauges/Tiffauges1F_Util.lua")

CloneGusionBossMonster = nil

TimeToReturnRealWorld = (1000 * 60 * 30) -- ex : 1000 * 60 = 1 minutes

MonsterList =
{
	{
		SummonMonsterInfo = BalBerithInfo,
		MaxMonsterCount = 50
	},
	{
		SummonMonsterInfo = BerithInfo,
		MaxMonsterCount = 25
	},
	{
		SummonMonsterInfo = ValkyrjaInfo,
		MaxMonsterCount = 40
	}
}

MonsterCount = {}

function SetToSummonBossTime()
	-- 10분 ~ 15분 사이 보스 소환
	DEScriptZone:SetTimer(10, 1000 * 60 * math.random(10, 15), 1)	
end

function SetNextOpenTime()
	-- 40분 ~ 120분사이에 랜덤하게 열림
	DEScriptZone:SetTimer(20, 1000 * 60 * math.random(40, 120), 1)
end

function OnInitializeVariables(ZoneCreateInfo)

	ZoneCreateInfo.Name = "Tiffauges1F_O"
	ZoneCreateInfo.TemplateZoneID = 1802

	ZoneCreateInfo.StartPosX = 128
	ZoneCreateInfo.StartPosY = 146
	
	ZoneCreateInfo.EntranceType = "indivisual"
	ZoneCreateInfo.StaticZone = true
	
	--  아무도 없는 상태에서 최대 지속 시간 
	ZoneCreateInfo.EmptyTimeOut = 30 -- 30 sec
end 

function OnInitialize()

	PositionInfo = {}
	
	for index, MonsterInfo in pairs(MonsterList) do
		AddMonsterInfo = MonsterInfo.SummonMonsterInfo
		
		RegenMonsters(AddMonsterInfo.MType)
	end

	DEScript:WriteIntegerOnWhiteBoard("Tiffauges.1F.Open", 0)	 
	DEScript:WriteIntegerOnWhiteBoard("Tiffauges.1F.EnterSlayer", 0)
	DEScript:WriteIntegerOnWhiteBoard("Tiffauges.1F.EnterVampire", 0)
	DEScript:WriteIntegerOnWhiteBoard("Tiffauges.1F.EnterOusters", 0)
	 
	 SetNextOpenTime()
	
end

function OnTerminate()

end

function OnBeforeEnterZone(Creature)

	if DEScript:IsGod(Creature) == false and DEScript:ReadIntegerOnWhiteBoard("Tiffauges.1F.OpenStat", 0) == 0 then
		DEScriptZone:SendSystemMessage(Creature, 0, "The portal to the past is now closed.")
		
		return false;
	end

	return true;	
end

function OnAfterEnterZone(Creature)
	
end

function OnBeforeLeaveZone(Creature)

end

function OnAfterLeaveZone(Creature)

end

function OnAttackCreature(AttackerCreature, DefenderCreature)
	
end

function OnKillCreature(AttackerCreature, DeadCreature)
	
	if CloneGusionBossMonster ~= nil and DeadCreature.ObjectID == CloneGusionBossMonster.ObjectID then
		--print("Tiffauges2F 이계, 보스 사망, 공격자 = "..AttackerCreature.Name)
		
		CloneGusionBossMonster = nil
	else
		if DEScript:IsMonster(DeadCreature) then
		
			if MonsterCount[DeadCreature.MType] ~= nil then
				MonsterCount[DeadCreature.MType] = MonsterCount[DeadCreature.MType] - 1
			end
			
			RegenMonsters(DeadCreature.MType)
			
		end
	end
end

function OnAddMonster(Monster)

	if MonsterCount[Monster.MType] == nil then
		MonsterCount[Monster.MType] = 1
	else
		MonsterCount[Monster.MType] = MonsterCount[Monster.MType] + 1
	end 
end

function OnResurrectCreature(CreatureInfo, ZoneCoordInfo)

	if DEScript:ReadIntegerOnWhiteBoard("Tiffauges.1F.OpenStat", 0) == 0 then
		-- 과거가 닫히면 부활시 바로 현세로 옮겨간다.
		ZoneCoordInfo.ZoneID = GetReturnZoneID(CreatureInfo)
	else
		ZoneCoordInfo.ZoneID = DEScriptZone:GetZoneID()
	end
	
	ZoneCoordInfo.X = 125
	ZoneCoordInfo.Y = 136
	
	return true;	

end

function OnSay(CreatureInfo, Mesg)
	if DEScript:IsGod(CreatureInfo) == false then
		return true
	end
	
	if Mesg == "*go RealWorld" then
		OnWarpZone(CreatureInfo)
		
		return false
	elseif Mesg == "*command GetWorldStat" then
		OtherWorldOpenStat = DEScript:ReadIntegerOnWhiteBoard("Tiffauges.1F.OpenStat", 0)
		
		if OtherWorldOpenStat == 0 then
			DEScriptZone:SendSystemMessage(CreatureInfo, 0, "The past is closed.")
		else
			DEScriptZone:SendSystemMessage(CreatureInfo, 0, "The past is open.")
		end
	
		return false
	end
		
	return true
end

function OnTimer(TimerID)
	
	if TimerID == 1 then
		DEScriptZone:KillTimer(1)
		
		OnTraverseCreature = NotifyWarpToWorld
		DEScriptZone:TraverseCreature()
		
		DEScriptZone:SetTimer(2, 1000 * 15, 1)	-- 15초 후에 이동
		DEScript:WriteIntegerOnWhiteBoard("Tiffauges.1F.OpenStat", 0)
	end

	if TimerID == 2 then
		DEScriptZone:KillTimer(2)
		
		OnTraverseCreature = OnWarpZone
		DEScriptZone:TraverseCreature()
		
		DEScriptZone:KillTimer(100)	-- 트랩 종료
		
		if CloneGusionBossMonster ~= nil then
			-- 보스 없애기
			DEScript:SetHP(CloneGusionBossMonster, 0)	
			CloneGusionBossMonster = nil
		end	
	end
	
	if TimerID == 10 then
		if CloneGusionBossMonster == nil then
			DEScriptZone:KillTimer(10)
			
			-- 현재 없는 경우에만 보스 소환한다.
			CloneGusionBossMonster = DEScriptZone:AddMonster(CloneGusionBoss)
			
			DEScriptZone:BroadcastSystemMessageInZone(0, "Boss Clone Guison has appeared.")
		end
	end	
	
	if TimerID == 20 then
		DEScript:WriteIntegerOnWhiteBoard("Tiffauges.1F.Open", 1)
		DEScript:WriteIntegerOnWhiteBoard("Tiffauges.1F.OpenStat", 1)
		
		SetNextOpenTime()
		SetToSummonBossTime()
	 	
	 	DEScriptZone:SetTimer(1, TimeToReturnRealWorld, 1)	-- 돌아갈 시간 설정
	 	
	 	DEScriptZone:SetTimer(21, 1000 * 1, 1)	-- 종족별 입장 했는지 체크
		DEScriptZone:SetTimer(100, 1000 * 5, 1)	-- 트랩 시작
	end

	if TimerID == 21 then	
		EnterSlayer = DEScript:ReadIntegerOnWhiteBoard("Tiffauges.1F.EnterSlayer", 0)
		EnterVampire = DEScript:ReadIntegerOnWhiteBoard("Tiffauges.1F.EnterVampire", 0)
		EnterOusters = DEScript:ReadIntegerOnWhiteBoard("Tiffauges.1F.EnterOusters", 0)
		
		if (EnterSlayer == 0 or EnterSlayer == 2) and 
			(EnterVampire == 0 or EnterVampire == 2) and 
			(EnterOusters == 0 or EnterOusters == 2) then
			DEScriptZone:KillTimer(21)
			
			DEScript:WriteIntegerOnWhiteBoard("Tiffauges.1F.Open", 0)
		end 
	end
	
	ProcessTrap(TimerID)
end

function GetReturnZoneID(Creature)

	if DEScript:IsSlayer(Creature) then
		WarpZoneID = DEScriptZone:CreateInstanceDoungeon("Tiffauges/Tiffauges1F_R_S")
	elseif DEScript:IsVampire(Creature) then
		WarpZoneID = DEScriptZone:CreateInstanceDoungeon("Tiffauges/Tiffauges1F_R_V")
	elseif DEScript:IsOusters(Creature) then
		WarpZoneID = DEScriptZone:CreateInstanceDoungeon("Tiffauges/Tiffauges1F_R_O")
	else
		WarpZoneID = 0
	end
	
	return WarpZoneID 
end

function OnWarpZone(Creature)
	-- 이계 -> 현세 이동시킴
	
	WarpZoneID = GetReturnZoneID(Creature)
	if ( WarpZoneID == 0 ) then
		return
	end
    
	DEScriptZone:TransportCreature(Creature, WarpZoneID, Creature.X, Creature.Y)

end

TrapActivationInfo = 
{
--	Stage = 1,
	TrapPosList = MissionRoom1F_TrapPosList,
	
	ActivationTime =
	{
		{30, 60}
	}
}

function InstallTrap(TrapType, TrapBaseX, TrapBaseY, TrapNextTime, TrapDeadLine)
	EffectCreateInfo =
	{
		EffectCastCreature = nil,
		
		EffectClass = 584,
		
		PosX = TrapBaseX,
		PosY = TrapBaseY,
		
		NextTime = TrapNextTime,
		Deadline = TrapDeadLine
	}
	
	if TrapType == 1 then
		EffectCreateInfo.EffectClass = 584
	elseif TrapType == 2 then
		EffectCreateInfo.EffectClass = 585
	else
		EffectCreateInfo.EffectClass = 584
	end
			
	DEScriptZone:AddEffectToTile(EffectCreateInfo)

end
	
function ProcessTrap(TimerID)
	
	TrapBaseTimerID = 100

	if TimerID == TrapBaseTimerID then

		TrapGroup = math.random(1, table.maxn(TrapActivationInfo.TrapPosList))
		for index, TrapPos in ipairs(TrapActivationInfo.TrapPosList[TrapGroup]) do
			InstallTrap(2, TrapPos[1], TrapPos[2], math.random(0, 30), 30) 
		end
		
		TrapTime = math.random(
			TrapActivationInfo.ActivationTime[1][1],
			TrapActivationInfo.ActivationTime[1][2]
		)
		
		DEScriptZone:SetTimer(TrapBaseTimerID, 1000 * TrapTime, 1)
		
	end
end

