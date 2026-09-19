dofile("../script/zone/IcenDungeon/IcenDungeon_MonsterInfo.lua")
dofile("../script/zone/IcenDungeon/IcenDungeon_BlockInfo.lua")

BossStage_Boss = 
{
	{
		MonsterInfo = Onibla,
		MonsterPos = 
		{
			{61,11},
			{63,11},
			{65,11}
		}
	}
}

-- After the race war Onibla's servants attack in waves in front of the green gates: the pocket between the two
-- gate ramps, which stay blocked by RaceWarBlockPos. Each wave spawns once the previous one is dead, and the gates
-- open to Onibla after the last one. Counts set by the user 2026-09-14: 2 Villain Lady, then 1 Agony Child +
-- 1 Agony's Hound, then 3 Oni Spaniel + 12 Big Tor.
OniblaWaves =
{
	{
		Message = "Villain Ladies emerge before the green gates!",
		Groups =
		{
			{
				MonsterInfo = VillaninLady,
				MonsterPos = { {61,66}, {65,66} }
			}
		}
	},
	{
		Message = "An Agony Child and its Hound rush the gates!",
		Groups =
		{
			{
				MonsterInfo = AgonyChild,
				MonsterPos = { {63,65} }
			},
			{
				MonsterInfo = AgonysHound,
				MonsterPos = { {63,67} }
			}
		}
	},
	{
		Message = "Oni Spaniels and Big Tors charge the gates!",
		Groups =
		{
			{
				MonsterInfo = OniSpaniel,
				MonsterPos = { {61,65}, {63,65}, {65,65} }
			},
			{
				MonsterInfo = Bigtore,
				MonsterPos = { {63,69}, {65,68}, {61,69}, {65,70}, {63,71}, {61,71}, {59,68}, {67,68}, {59,66}, {59,70}, {65,72}, {67,66} }
			}
		}
	}
}

-- The boss room itself now holds only Onibla (BossStage_Boss); its old monster groups moved to OniblaWaves.
BossStage_Monster = {}

-- Race war guards, spawned for every race with nobody in the dungeon. User's counts (2026-09-14): every side holds
-- 1 Gussion, 1 Morgoth, 1 Chief Mum Rimmon and 1 Chief Mount Crag, 4 per race (the Ousters side's Shaman Oaf became
-- a Mum Rimmon; Lich Jel, Hell Grouper, Nod Copila and Ruin Guardian were removed).
NoneSlayer_MonsterPos =
{
	{ MonsterInfo = CloneGussion,     MonsterPos = { {45,71} } },
	{ MonsterInfo = CloneMorgothInfo, MonsterPos = { {38,78} } },
	{ MonsterInfo = ChiefMumRimmon,   MonsterPos = { {45,78} } },
	{ MonsterInfo = ChiefMountCrag,   MonsterPos = { {40,70} } }
}

NoneVampire_MonsterPos =
{
	{ MonsterInfo = CloneGussion,     MonsterPos = { {62,114} } },
	{ MonsterInfo = CloneMorgothInfo, MonsterPos = { {59,111} } },
	{ MonsterInfo = ChiefMumRimmon,   MonsterPos = { {66,105} } },
	{ MonsterInfo = ChiefMountCrag,   MonsterPos = { {67,110} } }
}

NoneOusters_MonsterPos =
{
	{ MonsterInfo = CloneGussion,     MonsterPos = { {82,72} } },
	{ MonsterInfo = CloneMorgothInfo, MonsterPos = { {87,78} } },
	{ MonsterInfo = ChiefMumRimmon,   MonsterPos = { {81,77} } },
	{ MonsterInfo = ChiefMountCrag,   MonsterPos = { {89,72} } }
}

	STAGE_STATE_INIT				= 0
	STAGE_STATE_WAIT_TIME			= 1
	STAGE_STATE_RACE_WAR			= 2
	STAGE_STATE_OPEN_ONIBLA_ROOM	= 30
	STAGE_STATE_ATTACK_ONIBLA		= 31
	STAGE_STATE_GATE_WAVES		= 32
	STAGE_STATE_WARP_TO_GET_OUT		= 4
	STAGE_STATE_FINISH				= 5
	
	-- 입장 제한
	CanEntrance = false
	-- 종족별 인원
	SlayerCount = 0
	VampireCount = 0
	OustersCount = 0
	-- 시간 관련
	DoungeonStartTime = 0
	DoungeonFirstStartTime = 10 * 60		-- 단위 : seconds
	DoungeonReStartTime = 10 * 60			-- 단위 : seconds
	DoungeonWaitTime = 10 * 60				-- 단위 : seconds
	IcenDungeonRaceWarTime = 100 * 60	    -- 단위 : seconds 
	EntranceStageBoss = 1 * 10				-- 단위 : seconds
	
	LogFileName = "IcenDungeon4F.log"

	-- 왼쪽 문의 위치
	LeftDoorPosX = 37
	LeftDoorPosY = 87
	-- 오른쪽 문의 위치
	RightDoorPosX = 77
	RightDoorPosY = 99

	JoinRaceMax = 24
	VillaninLadyGhostList = {}
	VillaninLadyMax = 40 + 1

	StageStat = STAGE_STATE_INIT
	BossDeadStat = false

	IsOpenLeftSecretRoom = true
	IsOpenRightSecretRoom = true
	IsOpenBossRoom = true
	IsOpenBossRoomExit = true
	
	NoneSlayer_MonsterList = {}
	NoneVampire_MonsterList = {}
	NoneOusters_MonsterList = {}
	BossStage_BossList = {}
	BossStage_MonsterList = {}
	WaveMonsterList = {}
	WaveIndex = 0
	WaveInProgress = false
	WaveDelay = 10							-- seconds before each gate wave (after the race war or a cleared wave)
	
function OnInitializeVariables(ZoneCreateInfo)

	ZoneCreateInfo.Name = "IcenDungeon"	
	ZoneCreateInfo.TemplateZoneID = 1622
	
	-- 종족별로 다른경우에는 ??
	ZoneCreateInfo.StartPosX = 64
	ZoneCreateInfo.StartPosY = 78

	-- indivisual(개인), party(파티), lobby(로비, 로비에 들어간 후 참여)
	ZoneCreateInfo.EntranceType = "indivisual"
	--ZoneCreateInfo.EntranceType = "party"
	ZoneCreateInfo.StaticZone = true
	
	--  아무도 없는 상태에서 최대 지속 시간 
--	ZoneCreateInfo.EmptyTimeOut = 10 -- unit : seconds
	
	DEScriptZone:SetTimer(1, 1000 * DoungeonFirstStartTime, 1)

	-- *command openEisen / eisenStatus (CGSayHandler.cpp) reach this zone only through these
	-- whiteboard keys. They are created here, before any C++ access, so the C++ side only
	-- updates existing keys. Timer 101 publishes the stage and serves open requests.
	DEScript:WriteIntegerOnWhiteBoard("Eisen.OpenRequest", 0)
	DEScript:WriteIntegerOnWhiteBoard("Eisen.Stage", StageStat)
	DEScriptZone:SetTimer(101, 1000 * 5, 1)
end 

function OnInitialize()
	DoungeonStartTime = DEScript:GetCurrentTime()
	DEScriptZone:SetPKZone(false)
end

function OnTerminate()

end

function OnSetStartPos(CreatureInfo, PositionInfo)
    if DEScript:IsSlayer(CreatureInfo) then
		PositionInfo.X = 42
        PositionInfo.Y = 74
	elseif DEScript:IsVampire(CreatureInfo) then
		PositionInfo.X = 63
        PositionInfo.Y = 109
	elseif DEScript:IsOusters(CreatureInfo) then
		PositionInfo.X = 85
        PositionInfo.Y = 75
	end
end

function SendRemainTime(Creature, remainTime, timerDesc)
	if timerDesc == nil then
		timerDesc = "Time left:";
	end
			
	DEScriptZone:SendSystemMessage(Creature, 7, timerDesc.." ["..remainTime.."]")
end

function OnBeforeEnterZone(Creature)
--	DEScriptZone:BroadcastGCSay(Creature, "너무 깜깜해~~~~~~~~~~~~~~~~~", 5592405)  -- 5592405 = 0x00555555 BGR
--	return false
	
	if CanEntrance == false then
		DEScriptZone:SendSystemMessage(Creature, 0, "It's not the time to enter.") 
	end
	
	if SlayerCount > JoinRaceMax -1 and CanEntrance == true then
		DEScriptZone:SendSystemMessage(Creature, 0, "The number of Slayers has already exceeded the limit. ") 
		return false		
	end
	if VampireCount > JoinRaceMax -1 and CanEntrance == true then
		DEScriptZone:SendSystemMessage(Creature, 0, "The number of Vampires has already exceeded the limit. ") 
		return false
	end
	if OustersCount > JoinRaceMax -1 and CanEntrance == true then
		DEScriptZone:SendSystemMessage(Creature, 0, "The number of Ousters has already exceeded the limit.") 
		return false
	end
	
	return CanEntrance
end

function OnAfterEnterZone(Creature)
	if DEScript:IsSlayer(Creature) then
		SlayerCount = SlayerCount + 1
	elseif DEScript:IsVampire(Creature) then
		VampireCount = VampireCount + 1
	elseif DEScript:IsOusters(Creature) then
		OustersCount = OustersCount + 1
	end
	
	DoungeonRemainTime = DoungeonWaitTime - ( DEScript:GetCurrentTime() - DoungeonStartTime )
	SendRemainTime(Creature, DoungeonRemainTime * 10)

end

function OnBeforeLeaveZone(Creature)
end

function OnAfterLeaveZone(Creature)
	SendRemainTime(Creature, 0)
	
	if DEScript:IsSlayer(Creature) then
		SlayerCount = SlayerCount - 1
	elseif DEScript:IsVampire(Creature) then
		VampireCount = VampireCount - 1
	elseif DEScript:IsOusters(Creature) then
		OustersCount = OustersCount - 1
	end
			
	if StageStat == STAGE_STATE_RACE_WAR then
		
		MonsterCount = table.maxn(NoneSlayer_MonsterList) +
			table.maxn(NoneVampire_MonsterList) +
			table.maxn(NoneOusters_MonsterList)

		if NoneRaceCheck() == 1 and MonsterCount == 0 then
			
			StartMisssionOniblaRoom()
		end
	end
	
end

function OnKillCreature(AttackerCreature, DeadCreature)

	if StageStat == STAGE_STATE_RACE_WAR or StageStat == STAGE_STATE_FINISH then
		CheckMissionAllKill(DeadCreature.ObjectID, NoneSlayer_MonsterList)
		CheckMissionAllKill(DeadCreature.ObjectID, NoneVampire_MonsterList)
		CheckMissionAllKill(DeadCreature.ObjectID, NoneOusters_MonsterList)
	end
	
	if StageStat == STAGE_STATE_RACE_WAR then
	
		MonsterCount = table.maxn(NoneSlayer_MonsterList) +
			table.maxn(NoneVampire_MonsterList) +
			table.maxn(NoneOusters_MonsterList)

		if NoneRaceCheck() == 1 and MonsterCount == 0  then
			
			StartMisssionOniblaRoom()
		end
	end

	if StageStat == STAGE_STATE_GATE_WAVES or StageStat == STAGE_STATE_FINISH then
		CheckMissionAllKill(DeadCreature.ObjectID, WaveMonsterList)
	end

	if StageStat == STAGE_STATE_GATE_WAVES then
		for i, G in ipairs(VillaninLadyGhostList) do
			if G == DeadCreature.ObjectID then
				table.remove(VillaninLadyGhostList, i)
				break
			end
		end

		if WaveInProgress and table.maxn(WaveMonsterList) == 0 then
			GateWaveCleared()
		end
	end

	if StageStat == STAGE_STATE_ATTACK_ONIBLA or StageStat == STAGE_STATE_FINISH then	
		CheckMissionAllKill(DeadCreature.ObjectID, BossStage_MonsterList)
		CheckMissionAllKill(DeadCreature.ObjectID, BossStage_BossList)
	end
		
	if StageStat == STAGE_STATE_ATTACK_ONIBLA then
		MonsterAllKill = false
		BossAllKill = false
		
		if table.maxn(BossStage_MonsterList) == 0 then
			MonsterAllKill = true
		end
		
		if table.maxn(BossStage_BossList) == 0 then
			BossAllKill = true
		end
		
		if MonsterAllKill and BossAllKill then
			EndBossStage()
		end
		
		if BossAllKill and BossDeadStat == false then
			OnTraverseCreature = OnGiveRewardItem
			DEScriptZone:TraverseCreature()
			
			BossDeadStat = true
		end
		
		table.foreach(
			VillaninLadyGhostList, 
			function(i, G) 
				if G == DeadCreature.ObjectID then 
					table.remove(VillaninLadyGhostList, i) 
				end 
			end 
		)
	end
end

function OnAddMonster(Monster)
end

function OnResurrectCreature(CreatureInfo, ZoneCoordInfo)
	
	-- 지정된 위치로 부활 	
	ZoneCoordInfo.ZoneID = 32
	ZoneCoordInfo.X = 148
	ZoneCoordInfo.Y = 120
		
	return true
end

function SetRaceWarBlock()
	for index, Element in ipairs(RaceWarBlockPos) do
		DEScriptZone:SetBlocked(Element[1],Element[2])
	end
end

function SetLeftSecretBlock()
	for index, Element in ipairs(LeftSecretBlockPos) do
		DEScriptZone:SetBlocked(Element[1],Element[2])
	end
end

function SetRightSecretBlock()
	for index, Element in ipairs(RightSecretBlockPos) do
		DEScriptZone:SetBlocked(Element[1],Element[2])
	end
end

function SetBossRoomExitBlock()
	for index, Element in ipairs(BossRoomExitBlockPos) do
		DEScriptZone:SetBlocked(Element[1],Element[2])
	end
end

-- 보스방 블록
function CloseBossRoom()
	if IsOpenBossRoom == false then
		return
	end
	
	IsOpenBossRoom = false
	
	EffectCreateInfo =
	{
		EffectCastCreature = nil,
		
		EffectClass = 592,
		
		PosX = 0,
		PosY = 0,
		
		NextTime = 0,
		Deadline = 99999999
	}
	
	EffectCreateInfo2 =
	{
		EffectCastCreature = nil,
		
		EffectClass = 591,
		
		PosX = 0,
		PosY = 0,
		
		NextTime = 0,
		Deadline = 99999999
	}

	for index, Element in ipairs(BossRoomLeftBlockPos) do
		DEScriptZone:SetBlocked(Element[1],Element[2])
		
		EffectCreateInfo.PosX = Element[1]
		EffectCreateInfo.PosY = Element[2]
		
		Element[3] = DEScriptZone:AddEffectToTile(EffectCreateInfo)
	end
	
	for index2, Element2 in ipairs(BossRoomRightBlockPos) do
		DEScriptZone:SetBlocked(Element2[1],Element2[2])
		
		EffectCreateInfo2.PosX = Element2[1]
		EffectCreateInfo2.PosY = Element2[2]
		
		Element2[3] = DEScriptZone:AddEffectToTile(EffectCreateInfo2)
	end
	
	DEScriptZone:SetBlocked(71, 60)
	
	SetRaceWarBlock()
	
end

function CloseBossRoomExit()
	if IsOpenBossRoomExit == false then
		return
	end
	
	IsOpenBossRoomExit = false

	EffectCreateInfo =
	{
		EffectCastCreature = nil,
		
		EffectClass = 592,
		
		PosX = 0,
		PosY = 0,
		
		NextTime = 0,
		Deadline = 99999999
	}
	
	for index, Element in ipairs(BossRoomLeftExitBlockPos) do
		DEScriptZone:SetBlocked(Element[1],Element[2])
		
		EffectCreateInfo.PosX = Element[1]
		EffectCreateInfo.PosY = Element[2]
		
		Element[3] = DEScriptZone:AddEffectToTile(EffectCreateInfo)
	end
		
	SetBossRoomExitBlock()
end

function CloseRightSecretRoom()
	if IsOpenRightSecretRoom == false then
		return
	end
	
	IsOpenRightSecretRoom = false
	
	EffectCreateInfo =
	{
		EffectCastCreature = nil,
		
		EffectClass = 594,
		
		PosX = 0,
		PosY = 0,
		
		NextTime = 0,
		Deadline = 99999999
	}

	for index, Element in ipairs(RightSecretRoomBlockPos) do
		DEScriptZone:SetBlocked(Element[1],Element[2])
	end
	
	for index, EffectElement in ipairs(RightSecretRoomEffectPos) do
		EffectCreateInfo.PosX = EffectElement[1]
		EffectCreateInfo.PosY = EffectElement[2]
		EffectElement[3] = DEScriptZone:AddEffectToTile(EffectCreateInfo)
	end
	
	SetRightSecretBlock()
end

function CloseLeftSecretRoom()
	if IsOpenLeftSecretRoom == false then
		return
	end
	
	IsOpenLeftSecretRoom = false

	EffectCreateInfo =
	{
		EffectCastCreature = nil,
		
		EffectClass = 596,
		
		PosX = 0,
		PosY = 0,
		
		NextTime = 0,
		Deadline = 99999999
	}

	for index, Element in ipairs(LeftSecretRoomBlockPos) do
		DEScriptZone:SetBlocked(Element[1],Element[2])
	end
	
	for index, EffectElement in ipairs(LeftSecretRoomEffectPos) do
		EffectCreateInfo.PosX = EffectElement[1]
		EffectCreateInfo.PosY = EffectElement[2]
		EffectElement[3] = DEScriptZone:AddEffectToTile(EffectCreateInfo)
	end
	
	SetLeftSecretBlock()
end

function EndBossStage()
	DEScript:WriteFileLog(LogFileName, "Finish Onibla Dungeon")
	WriteCurrentUser()
		
	DEScriptZone:BroadcastSystemMessageInZone(4, "Eisen Dungeon entrance is now open.")
	OpenBossRoomExit()
end

function IcenSendRemainTime(CreatureInfo)
	SendRemainTime(CreatureInfo, 10 * IcenDungeonRaceWarTime, "Eisen Dungeon B4F")
end

function OnTimer(TimerID)
	if TimerID == 1 then
		DEScriptZone:KillTimer(1)
		
		StageStat = STAGE_STATE_WAIT_TIME
		
		SlayerCount = 0
		VampireCount = 0
		OustersCount = 0
		
		BossDeadStat = false

		-- every run starts with empty monster lists (object IDs from the previous run are gone)
		NoneSlayer_MonsterList = {}
		NoneVampire_MonsterList = {}
		NoneOusters_MonsterList = {}
		BossStage_BossList = {}
		BossStage_MonsterList = {}
		WaveMonsterList = {}
		VillaninLadyGhostList = {}
		WaveIndex = 0
		WaveInProgress = false
		
		CloseBossRoom()
		CloseBossRoomExit()
		CloseLeftSecretRoom()
		CloseRightSecretRoom()
		
		CanEntrance = true
		DEScriptZone:SetPKZone(false)
		
		-- DEScriptZone:BroadcastSystemMessage(0, "아이센 지하  4층이 오픈 되었습니다.") by viva
		EisenReminderCount = 0
		DEScriptZone:BroadcastSystemMessage(0, "Eisen Dungeon B4F is now open! Enter through the hidden door on Eisen Dungeon B3F within " .. math.floor(DoungeonWaitTime / 60) .. " minutes.")
		
		DoungeonStartTime = DEScript:GetCurrentTime()
		DEScriptZone:SetTimer(2, 1000 * DoungeonWaitTime, 1)
				
		DEScriptZone:SetTimer(100, 1000 * 120, 1)	-- world reminder while entry is open
	end
	
	if TimerID == 2 then
		DEScriptZone:KillTimer(2)
		DEScriptZone:KillTimer(100)
		
		StageStat = STAGE_STATE_RACE_WAR
		
		CanEntrance = false
		DEScriptZone:SetPKZone(true)
		
		if NoneRaceCheck() ~= 0 then
			AloneRacePlay()

		end

		DEScript:WriteFileLog(LogFileName, "Start RaceWar")
		WriteCurrentUser()
				
		DEScriptZone:BroadcastSystemMessageInZone(4, "Such pests! Prove yourselves!")
		
		OnTraverseCreature = IcenSendRemainTime
		DEScriptZone:TraverseCreature()
		DEScriptZone:SetTimer(4, 1000 * IcenDungeonRaceWarTime, 1)
	end
	
	if TimerID == 3 then
		DEScriptZone:KillTimer(3)

		if StageStat == STAGE_STATE_OPEN_ONIBLA_ROOM then
		
			StageStat = STAGE_STATE_ATTACK_ONIBLA
			
			DEScript:WriteFileLog(LogFileName, "Appear Onibla")
			WriteCurrentUser()
			
			DEScriptZone:BroadcastSystemMessageInZone(4, "Oni Blythe has appeared.")
		
			BossRoomMonsterStanding()
		end
	end
	
	if TimerID == 4 then
		DEScriptZone:KillTimer(4)
		
		StageStat = STAGE_STATE_WARP_TO_GET_OUT
		DEScriptZone:KillTimer(6)
		WaveInProgress = false
		
		DEScript:WriteFileLog(LogFileName, "Warp To Get Out")
		WriteCurrentUser()
		
		OnTraverseCreature = OnWarpToGetOut
		DEScriptZone:TraverseCreature()
		
		DEScriptZone:SetTimer(5, 1000 * 10, 1)
	end
	
	if TimerID == 5 then
		DEScriptZone:KillTimer(5)
		
		StageStat = STAGE_STATE_FINISH

		OnTraverseMonster = OnKillMonster
		DEScriptZone:TraverseMonster()
			
		DEScriptZone:SetTimer(1, 1000 * DoungeonReStartTime, 1)
	end
	
	if TimerID == 6 then
		DEScriptZone:KillTimer(6)
		SpawnGateWave()
	end

	if TimerID == 101 then
		DEScript:WriteIntegerOnWhiteBoard("Eisen.Stage", StageStat)
		if DEScript:ReadIntegerOnWhiteBoard("Eisen.OpenRequest", 0) == 1 then
			DEScript:WriteIntegerOnWhiteBoard("Eisen.OpenRequest", 0)
			if StageStat == STAGE_STATE_INIT or StageStat == STAGE_STATE_FINISH then
				DEScript:WriteFileLog(LogFileName, "Opened by *command openEisen")
				OnTimer(1)
				DEScript:WriteIntegerOnWhiteBoard("Eisen.Stage", StageStat)
			end
		end
	end
	
	if TimerID == 100 then
	
		if StageStat == STAGE_STATE_WAIT_TIME then
			EisenReminderCount = (EisenReminderCount or 0) + 1
			local MinutesLeft = math.floor(DoungeonWaitTime / 60) - 2 * EisenReminderCount
			if MinutesLeft > 0 then
				DEScriptZone:BroadcastSystemMessage(0, "Eisen Dungeon B4F closes to new entry in " .. MinutesLeft .. " minutes.")
			end
		end
	end
end

function OnSay(CreatureInfo, Mesg)
	-- English client dialogue gives the door spells in English; accept those too,
	-- ignoring case, surrounding spaces and a trailing . or !
	local Phrase = string.lower((string.gsub(Mesg, "^%s*(.-)[%s%.!]*$", "%1")))


	HaveItemInfo1 = 
	{
		ItemClass = 91,
		ItemType = 34,
		ItemCount = 1
	}
	
	HaveItemInfo2 = 
	{
		ItemClass = 91,
		ItemType = 34,
		ItemCount = 1
	}
	
	if Mesg == "피와 육체가 하나의 줄기를 이룬다" or Phrase == "blood and flesh form a single stem" then
		if IsOpenLeftSecretRoom == false and DEScriptZone:HaveItem(CreatureInfo, HaveItemInfo1) and CanDoorOpen(LeftDoorPosX, LeftDoorPosY, CreatureInfo.X, CreatureInfo.Y) then
			TakeItemInfo1 = {}
			TakeItemInfo1 = HaveItemInfo1
		
			DEScriptZone:TakeItem(CreatureInfo, TakeItemInfo1)
			OpenLeftSecretRoom()
			LeftSecretRoomAction()	
		end
	end
	
	if Mesg == "암흑과 어둠의 비밀이 그대를 비춘다" or Phrase == "the secret of blackness and darkness shines upon you" then
		if IsOpenRightSecretRoom == false and DEScriptZone:HaveItem(CreatureInfo, HaveItemInfo2) and CanDoorOpen(RightDoorPosX, RightDoorPosY, CreatureInfo.X, CreatureInfo.Y) then
			TakeItemInfo2 = {}
			TakeItemInfo2 = HaveItemInfo2
		
			DEScriptZone:TakeItem(CreatureInfo, TakeItemInfo2)
			OpenRightSecretRoom()
			RightSecretRoomAction()
		end			
	end
	
	return true
end

function CanDoorOpen(DoorX, DoorY, CreatureX, CreatureY)
	Distance = (DoorX - CreatureX) * (DoorX - CreatureX) + (DoorY - CreatureY) * (DoorY - CreatureY)
	
	if Distance <= (5*5) then
		return true
	end
	
	return false
end

function NoneRaceCheck()
	OnlyOneRace = 3 

	if SlayerCount == 0 then
		OnlyOneRace = OnlyOneRace - 1
	end
	if VampireCount == 0 then
		OnlyOneRace = OnlyOneRace - 1
	end
	if OustersCount == 0 then
		OnlyOneRace = OnlyOneRace - 1
	end
	
	return OnlyOneRace
end

function AloneRacePlay()
	 
	if SlayerCount == 0 then
		MonsterDispose(NoneSlayer_MonsterPos, NoneSlayer_MonsterList)
	end	
	if VampireCount == 0 then
		MonsterDispose(NoneVampire_MonsterPos, NoneVampire_MonsterList)
	end 
	if OustersCount == 0 then
		MonsterDispose(NoneOusters_MonsterPos, NoneOusters_MonsterList)
	end	
	
end

function BossRoomMonsterStanding()
	for i, MonsterArrangeInfo in pairs(BossStage_Monster) do
		AddMonsterInfo = MonsterArrangeInfo.MonsterInfo
		
		for index, MonsterPos in ipairs(MonsterArrangeInfo.MonsterPos) do
			AddMonsterInfo.X = MonsterPos[1]
			AddMonsterInfo.Y = MonsterPos[2]
			
			AddedMonster = DEScriptZone:AddMonster(AddMonsterInfo)
			
			table.insert(BossStage_MonsterList, AddedMonster.ObjectID)
		end	
	end
	
	for i, BossMonsterArrangeInfo in pairs(BossStage_Boss) do
		AddBossMonsterInfo = BossMonsterArrangeInfo.MonsterInfo
		
		for index, MonsterPos in ipairs(BossMonsterArrangeInfo.MonsterPos) do
			AddBossMonsterInfo.X = MonsterPos[1]
			AddBossMonsterInfo.Y = MonsterPos[2]
			
			AddedBossMonster = DEScriptZone:AddMonster(AddBossMonsterInfo)
			
			table.insert(BossStage_BossList, AddedBossMonster.ObjectID)
		end	
	end
end

function MonsterDispose(MonsterPos, MonsterList)
	for i, MonsterArrangeInfo in pairs(MonsterPos) do
		AddMonsterInfo = MonsterArrangeInfo.MonsterInfo
		
		for index, MonsterPos in ipairs(MonsterArrangeInfo.MonsterPos) do
			AddMonsterInfo.X = MonsterPos[1]
			AddMonsterInfo.Y = MonsterPos[2]
			
			AddedMonster = DEScriptZone:AddMonster(AddMonsterInfo)
			
			table.insert(MonsterList, AddedMonster.ObjectID)
		end	
	end
end

-- 몬스터 다 잡았니?
function CheckMissionAllKill(DeadCreatureObjectID, MissionMonsterList)
	for index, ObjectID in pairs(MissionMonsterList) do
		if ObjectID == DeadCreatureObjectID then
			table.remove(MissionMonsterList, index)
		end
	end
	
	if table.maxn(MissionMonsterList) == 0 then
		return true
	end
	
	return false
end

function BossRoomAction()
	DEScriptZone:BroadcastSystemMessageInZone(4, "Oni Blythe is awakening.")
	DEScriptZone:SetTimer(3, 1000 * EntranceStageBoss, 1)
end

function ClearRaceWarBlock()
	for index, Element in ipairs(RaceWarBlockPos) do
		DEScriptZone:ClearBlocked(Element[1],Element[2])
	end
end

function ClearLeftSecretBlock()
	for index, Element in ipairs(LeftSecretBlockPos) do
		DEScriptZone:ClearBlocked(Element[1],Element[2])
	end
end

function ClearRightSecretBlock()
	for index, Element in ipairs(RightSecretBlockPos) do
		DEScriptZone:ClearBlocked(Element[1],Element[2])
	end
end

function ClearBossRoomExitBlock()
	for index, Element in ipairs(BossRoomExitBlockPos) do
		DEScriptZone:ClearBlocked(Element[1],Element[2])
	end
end

function OpenBossRoom()
	if IsOpenBossRoom == true then
		return 
	end
		
	IsOpenBossRoom = true

	for index, Element in ipairs(BossRoomLeftBlockPos) do
		DEScriptZone:ClearBlocked(Element[1],Element[2])
		
		if Element[3] ~= nil then
			DEScriptZone:RemoveEffect(Element[3])
		end
	end
	
	for index2, Element2 in ipairs(BossRoomRightBlockPos) do
		DEScriptZone:ClearBlocked(Element2[1],Element2[2])
		
		if Element2[3] ~= nil then
			DEScriptZone:RemoveEffect(Element2[3])
		end
	end		
	
	DEScriptZone:ClearBlocked(71, 60)
	
	ClearRaceWarBlock()
end

function OpenBossRoomExit()
	if IsOpenBossRoomExit == true then
		return
	end
	
	IsOpenBossRoomExit = true

	for index, Element in ipairs(BossRoomLeftExitBlockPos) do
		DEScriptZone:ClearBlocked(Element[1],Element[2])
		
		if Element[3] ~= nil then
			DEScriptZone:RemoveEffect(Element[3])
		end
	end	
	
	ClearBossRoomExitBlock()
end

function LeftSecretRoomAction()

	DEScript:WriteFileLog(LogFileName, "Open BlackAstral Room")
	WriteCurrentUser()
	
	DEScriptZone:BroadcastSystemMessageInZone(4, "Black Astral's room is now open.")
		
	EffectCreateInfo =
	{
		EffectCastCreature = nil,
		
		EffectClass = 597,
		
		PosX = 36,
		PosY = 86,
		
		NextTime = 0,
		Deadline = 16
	}
	
	DEScriptZone:AddEffectToTile(EffectCreateInfo)
		
	AddMonsterInfo = BlackAstralMagicCrystal
	AddMonsterInfo.X = 12
	AddMonsterInfo.Y = 62
	
	AddedMonster = DEScriptZone:AddMonster(AddMonsterInfo)
end

function OpenLeftSecretRoom()
	if IsOpenLeftSecretRoom == true then
		return
	end
	
	IsOpenLeftSecretRoom = true
	
	ClearLeftSecretBlock()

	for index, Element in ipairs(LeftSecretRoomBlockPos) do
		DEScriptZone:ClearBlocked(Element[1],Element[2])
	end
	
	for index, EffectElement in ipairs(LeftSecretRoomEffectPos) do
		if EffectElement[3] ~= nil then
			DEScriptZone:RemoveEffect(EffectElement[3])
		end
	end
end

function RightSecretRoomAction()
	DEScript:WriteFileLog(LogFileName, "Open WhiteAstral Room")
	WriteCurrentUser()

	DEScriptZone:BroadcastSystemMessageInZone(4, "White Astral's room is now open.")
	
	EffectCreateInfo =
	{
		EffectCastCreature = nil,
		
		EffectClass = 595,
		
		PosX = 78,
		PosY = 99,
		
		NextTime = 0,
		Deadline = 16
	}
	
	DEScriptZone:AddEffectToTile(EffectCreateInfo)

	AddMonsterInfo = WhiteAstralSpellCrystal
	AddMonsterInfo.X = 113
	AddMonsterInfo.Y = 61
	
	AddedMonster = DEScriptZone:AddMonster(AddMonsterInfo)
end

function OpenRightSecretRoom()
	if IsOpenRightSecretRoom == true then
		return
	end
	
	IsOpenRightSecretRoom = true
	
	ClearRightSecretBlock()

	for index, Element in ipairs(RightSecretRoomBlockPos) do
		DEScriptZone:ClearBlocked(Element[1],Element[2])
	end	
	
	for index, EffectElement in ipairs(RightSecretRoomEffectPos) do
		if EffectElement[3] ~= nil then
			DEScriptZone:RemoveEffect(EffectElement[3])
		end
	end
end


function OnKillMonster(Monster)
	if Monster ~= nil then
		DEScript:SetHP(Monster, 0)
	end
end

function OnWarpToGetOut(Creature)

	if DEScript:IsSlayer(Creature) then
		WarpID = 12
		WarpX = 195
		WarpY = 129
	elseif DEScript:IsVampire(Creature) then
		WarpID = 1003
		WarpX = 80
		WarpY = 52
	elseif DEScript:IsOusters(Creature) then
		WarpID = 1311
		WarpX = 45
		WarpY = 87	
	end
	
	DEScriptZone:TransportCreature(Creature, 
		WarpID, 
		WarpX  + math.random(-7, 7), 
		WarpY  + math.random(-7, 7)
	)

end

function IsAbleToUseItem(Creature, ItemClass, ItemType)
--	print("IsAbleToUseItem() Creature.Name="..Creature.Name.." ItemClass="..ItemClass.." ItemType="..ItemType)

	Result = true
	
	if ItemClass == 7 then			-- 바이크 금지
		Result = false
	elseif ItemClass == 98 then		-- 뱀파 윙아이템 금지
		Result = false
	elseif ItemClass == 98 then		-- 아우 윙아이템 금지
		Result = false
	elseif ItemClass == 39 then		-- 뱀파이어 씰 사용  금지
		Result = false
	elseif ItemClass == 51 then		-- 슬레이어 커플링 사용  금지
		Result = false
	elseif ItemClass == 52 then		-- 뱀파이어 커플링 사용  금지
		Result = false
	elseif ItemClass == 93 then		-- 아우스터즈 하모닉 팬던트 사용  금지
		Result = false
	end
	
	if Result == false then
		DEScriptZone:SendSystemMessage(Creature, 4, "Items cannot be used in this place.")
	end
			
	return Result
end

function IsAbleToUseSkill(Creature, SkillType)
--	print("IsAbleToUseSkill() Creature.Name="..Creature.Name.." SkillType="..SkillType)

	Result = true

	if SkillType == 102 then		-- 박쥐 변신 금지
		Result = false
	elseif SkillType == 185 then	-- 소울체인  금지
		Result = false
	elseif SkillType == 115 then	-- 블러디 터널  금지(뱀파 씰)
		Result = false
	elseif SkillType == 114 then	-- 블러디 마크 금지(뱀파 씰)
		Result = false
	end
		
	if Result == false then
		DEScriptZone:SendSystemMessage(Creature, 4, "This skill cannot be used in this place.")
	end
	
	return Result
	
end

function OnBeforeUseMonsterSkill(CreatureInfo, SkillType)
	return true
end


function OnAfterUseMonsterSkill(CreatureInfo, SkillType)
	if VillaninLadyMax > table.maxn(VillaninLadyGhostList) then
	
		if ( SkillType == 497 ) then
		
			MaxSummonGhost = math.min(4, VillaninLadyMax - table.maxn(VillaninLadyGhostList))
	
			M = DEScriptZone:GetMonster(CreatureInfo.ObjectID)
		
			OffsetArray = 
			{
				{ -2, -2 },
				{  2, 2 },
				{  2, -2 },
				{ -2, 2 }
			}
		
			for index = 1, math.random(1, MaxSummonGhost), 1 do
				Offset = OffsetArray[index]
			
				AddMonsterInfo = VillaninLadyGhost
				AddMonsterInfo.X = M.X + Offset[1]
				AddMonsterInfo.Y = M.Y + Offset[2]
			
				AddedMonster = DEScriptZone:AddMonster(AddMonsterInfo)
				
				table.insert(VillaninLadyGhostList, AddedMonster.ObjectID)
			end
		end
	end
end

function OnGiveRewardItem(Creature)

	GiveItemInfo = 
	{
		ItemClass = 91,
		ItemType = 31,
		ItemCount = 1,
		Options = "",
		LimitedTime = 0
	}

	if DEScriptZone:GiveItem(Creature, GiveItemInfo) then
	end
end

function StartMisssionOniblaRoom()

	if StageStat ~= STAGE_STATE_RACE_WAR then
		return
	end

	-- The race war is over: three waves attack in front of the green gates before they open to Onibla.
	DEScript:WriteFileLog(LogFileName, "Start Gate Waves")
	WriteCurrentUser()

	StageStat = STAGE_STATE_GATE_WAVES
	WaveIndex = 0
	WaveInProgress = false
	WaveMonsterList = {}

	DEScriptZone:BroadcastSystemMessageInZone(4, "Onibla's servants gather before the green gates...")
	DEScriptZone:SetTimer(6, 1000 * WaveDelay, 1)
end

function SpawnGateWave()
	if StageStat ~= STAGE_STATE_GATE_WAVES or WaveInProgress then
		return
	end

	WaveIndex = WaveIndex + 1
	local Wave = OniblaWaves[WaveIndex]
	if Wave == nil then
		GateWavesDone()
		return
	end

	DEScript:WriteFileLog(LogFileName, "Gate Wave "..WaveIndex)
	WriteCurrentUser()

	DEScriptZone:BroadcastSystemMessageInZone(4, Wave.Message)

	WaveMonsterList = {}
	MonsterDispose(Wave.Groups, WaveMonsterList)
	WaveInProgress = true

	-- Nothing could be placed: go straight on instead of waiting on an empty wave. This must not re-arm timer 6,
	-- because the KillTimer(6) queued by the running timer 6 handler would cancel it on the next heartbeat.
	if table.maxn(WaveMonsterList) == 0 then
		WaveInProgress = false
		SpawnGateWave()
	end
end

function GateWaveCleared()
	WaveInProgress = false

	if WaveIndex < table.maxn(OniblaWaves) then
		DEScriptZone:BroadcastSystemMessageInZone(4, "The wave is broken, but more are coming!")
		DEScriptZone:SetTimer(6, 1000 * WaveDelay, 1)
	else
		GateWavesDone()
	end
end

function GateWavesDone()
	DEScript:WriteFileLog(LogFileName, "Start To Attack Onibla")
	WriteCurrentUser()

	StageStat = STAGE_STATE_OPEN_ONIBLA_ROOM

	DEScriptZone:BroadcastSystemMessageInZone(4, "The green gates are open!")
	OpenBossRoom()
	BossRoomAction()
end

function WriteCurrentUser()

	DEScript:WriteFileLog(
		LogFileName, 
		"StageState="..StageStat..",SlayerCount="..SlayerCount..",VampireCount="..VampireCount..",OustersCount="..OustersCount
	)
end