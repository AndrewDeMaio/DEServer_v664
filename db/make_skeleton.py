#!/usr/bin/env python3
"""Build the DARKEDEN deployment skeleton: every table's definition, the data of
the tables the game is *built* from, and nothing a player ever created.

    python3 make_skeleton.py [-o out.sql] [--verify]

Which tables keep their rows is decided by rule, not by hand:

  * `<name>Object`        an item instance somebody owns              -> empty
  * `<name>Log`           a log                                       -> empty
  * `Effect<name>`        an effect running on a creature             -> empty
    (except EffectItemInfo, a definition, and EffectPKZoneRegen, which is a
    list of map rectangles in spite of the name)
  * RUNTIME, below        characters, accounts, guilds, wars, counters -> empty
  * everything else       MonsterInfo, MaceInfo, ARInfo, Script, NPC,
                          Triggers, ShopTemplate, the balance tables   -> kept

A handful of definition tables carry a live column (how many of a unique item
exist, who owns a castle). Their rows are kept and the live columns are reset at
the end of the script, so a deployment starts from zero without losing the
definition. See RESETS.

The dump is taken with --default-character-set=binary: 468 of the tables are
latin1 and hold CP949 Korean bytes, so any conversion would corrupt them.
"""
import argparse
import datetime
import os
import re
import subprocess
import sys

DB = "DARKEDEN"
HOST, USER, PASSWORD = "127.0.0.1", "elcastle", "elca005"
CONN = ["-h" + HOST, "-u" + USER, "-p" + PASSWORD]

# Tables the game writes while it runs: created by players, by the war and event
# systems, or by the operators. They ship empty.
RUNTIME = set("""
Player Slayer Vampire Ousters SkillSave OustersSkillSave VampireSkillSave
UserStatus LoginPlayerData LogoutPlayerData LoginPayType DeleteChar NameChange
ChangeWorld CreatureSprite
FriendList FriendWaitList FriendGlobalOption NicknameBook
GuildInfo GuildMember GuildUnionInfo GuildUnionMember GuildUnionOffer
CoupleInfo ContributeInfo ContributeDegree ContributeRewardCount
LevelWarHistory RaceWarHistory RaceWarPCList FlagWarHistory FlagWarStat FlagSet
OlympicStat WarScheduleInfo
TimeLimitItems RankBonusData ReinforceRegisterInfo ItemList SimpleQuest
GQuestSave CanEnterGDRLair AttendCheck HeadCount
RedistributeAttr50Count ResetAttributeCount GoldMedalCount WeekItemGive
EventNewbie EventComeback EventComebackSchedule EventComebackSupplyItem
EventNewStart EventNewStartSchedule EventNewStartSupplyItem EventPresentItemLog
EventPresentItemSchedule EventQuestAdvance EventQuestRewardRecord
EventQuestRewardSchedule EventLevelUp EventLotto EventBallInfo
Event200501Main Event200501Recommend Event200507Main Event200507Recommend
Event200604 MapleEvent BlitzEvent SpecialEvent UnderworldEvent
DonationGuild200501 DonationPersonal200501 DonationWedding200505
GMGhost OpCreate TestClientUser LogUserInfo UserIPInfo SpeedHackPlayer
DSGMemberList SMSAddressBook MofusPowerPoint PrivateAgreementRemain
MiniGameScores Messages WebLogin WebMarketKey WebTemp uds_msg list
PCRoomDBInfo PCRoomIPInfo PCRoomInfo PCRoomLottoObject PCRoomPayList PCRoomUserInfo
HarmonicInfo FameLimitInfo CheckMoneyInfo EnemyErase NonPKServerList
CarryingReceiverInfo2
""".split())

# `Effect*` tables that are definitions, not effects running on a creature
EFFECT_KEEP = {"EffectItemInfo", "EffectPKZoneRegen"}

# Definition rows with a live column in them
RESETS = [
    ("CardCount", "CARDCOUNT = 0", "how many of each card have been drawn"),
    ("GiftBoxCount", "BOXCOUNT = 0", "how many of each gift box have been opened"),
    ("LuckyBagCount", "BAGCOUNT = 0", "how many of each lucky bag have been opened"),
    ("ResurrectItemCount", "Count = 0", "how many resurrect items have been used"),
    ("EventItemCount", "Count = 0", "how many of each event item have been handed out"),
    ("EventItemCount2", "Count = 0", "the same, per race"),
    ("UniqueItemInfo", "CurrentNumber = 0", "how many of each unique item exist"),
    ("CastleInfo", "GuildID = 0, TaxBalance = 0", "which guild holds the castle and its tax purse"),
]

# Rows that describe *this* installation and have to be edited after import
DEPLOYMENT = ["GameServerInfo", "GameServerGroupInfo", "WorldInfo", "WorldDBInfo",
              "CastleStatInfo", "ClientVersion", "IPAllowInfo", "IPBlockInfo"]


def mysql(sql, db=DB):
    p = subprocess.run(["mysql"] + CONN + ["-N", "-B", db, "-e", sql],
                       capture_output=True, text=True)
    if p.returncode:
        sys.exit("mysql failed: " + p.stderr)
    return [line.split("\t") for line in p.stdout.splitlines()]


def dump(args):
    p = subprocess.run(["mysqldump"] + CONN + ["--default-character-set=binary"] + args,
                       capture_output=True)
    if p.returncode:
        sys.exit("mysqldump failed: " + p.stderr.decode("latin-1"))
    return p.stdout


def is_runtime(t):
    if t.endswith("Object") or t.endswith("Log"):
        return True
    if t.startswith("Effect") and t not in EFFECT_KEEP:
        return True
    return t in RUNTIME


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--out", default=os.path.expanduser("~/DEServer_v664/db/DARKEDEN_skeleton.sql"))
    ap.add_argument("--verify", action="store_true", help="import into a scratch database and check it")
    a = ap.parse_args()

    tables = [r[0] for r in mysql("select table_name from information_schema.tables "
                                  "where table_schema='%s' and table_type='BASE TABLE' order by table_name" % DB)]
    base = [t for t in tables if not is_runtime(t)]
    runtime = [t for t in tables if is_runtime(t)]
    n_trig = int(mysql("select count(*) from information_schema.triggers "
                       "where trigger_schema='%s'" % DB)[0][0])
    counts = {}
    for i in range(0, len(tables), 60):
        chunk = tables[i:i + 60]
        for name, n in mysql(" union all ".join("select '%s',count(*) from `%s`" % (t, t) for t in chunk)):
            counts[name] = int(n)
    kept_rows = sum(counts[t] for t in base)
    print("%d tables: %d keep their rows (%d rows), %d ship empty (%d rows dropped)"
          % (len(tables), len(base), kept_rows, len(runtime), sum(counts[t] for t in runtime)))

    schema = dump(["--no-data", "--skip-add-drop-table", "--skip-add-locks",
                   "--triggers", "--routines", "--events", DB])
    data = dump(["--no-create-info", "--skip-triggers", "--skip-add-locks",
                 "--complete-insert", DB] + base)

    # triggers and routines are created as whoever runs the script, not as
    # elcastle@127.0.0.1 (an account the target server may not have)
    schema = re.sub(rb"/\*!5\d{4} DEFINER=[^*]*\*/", b"", schema)
    schema = re.sub(rb"CREATE DEFINER=`[^`]*`@`[^`]*` (PROCEDURE|FUNCTION)", rb"CREATE ", schema)
    got = len(re.findall(rb"TRIGGER `", schema))
    if got != n_trig:
        sys.exit("expected %d triggers in the schema dump, found %d" % (n_trig, got))

    stamp = datetime.date.today().isoformat()
    head = ("""-- DARKEDEN skeleton - the database a fresh deployment starts from.
--
-- Generated %s by db/make_skeleton.py from the live schema.
--
--   * every one of the %d tables is created, with its indexes and its triggers
--     (the trg_*_cid_ins/upd triggers keep OwnerCharID in step with OwnerID)
--   * the %d tables the game is built from keep their rows (%d rows):
--     MonsterInfo, MaceInfo, ARInfo, the balance and skill tables, Script, NPC,
--     Triggers, ZoneInfo, ShopTemplate and the rest of the content
--   * the %d tables the game writes while it runs are created empty:
--     MaceObject and every other *Object, Player, Slayer, Vampire, Ousters,
--     the skill saves, guilds, wars, events, counters and logs
--
-- Deploy with db/deploy_db.py: it imports this file into an empty database,
-- then runs every migration in db/migrations/ the database has not had yet, and
-- keeps count in the SchemaVersion table. By hand:
--
--     mysql -h127.0.0.1 -u<user> -p --default-character-set=latin1 < %s
--
-- It creates the database if it does not exist and does NOT drop anything, so
-- running it over a populated DARKEDEN fails on the first CREATE TABLE instead
-- of destroying it.
--
-- The dump is binary: 468 tables are latin1 and hold CP949 Korean bytes, and
-- the dump says SET NAMES binary itself, so the server stores them untouched.
-- Run the CLIENT as latin1, not binary: under binary the mysql client cannot
-- parse its own DELIMITER command and cuts every BEGIN ... END body short.
--
-- After importing, edit the rows that describe this installation:
--     %s
-- GameServerInfo holds the IP and ports the client connects to (127.0.0.1,
-- 13855/9997 here), WorldDBInfo the per-world database, ClientVersion the
-- version the client must report.
--
-- Accounts: Player ships empty, so nobody can log in until an account exists.
""" % (stamp, len(tables), len(base), kept_rows, len(runtime),
       os.path.basename(a.out), ", ".join(DEPLOYMENT))).encode("ascii")

    head += ("""--
CREATE DATABASE IF NOT EXISTS `%s` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci;
USE `%s`;

""" % (DB, DB)).encode("ascii")

    resets = [b"\n--\n-- Live columns on definition rows, back to zero for a fresh world.\n--\n"]
    for table, sets, why in RESETS:
        resets.append(("-- %s\nUPDATE `%s` SET %s;\n" % (why, table, sets)).encode("ascii"))

    body = head + schema + b"\n" + data + b"".join(resets)
    with open(a.out, "wb") as f:
        f.write(body)
    print("wrote %s (%.1f MB)" % (a.out, len(body) / 1048576.0))

    if a.verify:
        verify(a.out, tables, base, runtime, counts, n_trig)


def verify(path, tables, base, runtime, counts, n_trig):
    test = DB + "_SKELCHECK"
    print("verifying into %s ..." % test)
    mysql("drop database if exists `%s`; create database `%s`" % (test, test), db="mysql")
    with open(path, "rb") as f:
        body = f.read()
    # import into the scratch database instead of DARKEDEN
    body = body.replace(b"CREATE DATABASE IF NOT EXISTS `%s`" % DB.encode(),
                        b"CREATE DATABASE IF NOT EXISTS `%s`" % test.encode(), 1)
    body = body.replace(b"USE `%s`;" % DB.encode(), b"USE `%s`;" % test.encode(), 1)
    # latin1, not binary: see the header text above. The dump sets NAMES binary.
    p = subprocess.run(["mysql"] + CONN + ["--default-character-set=latin1"],
                       input=body, capture_output=True)
    if p.returncode or p.stderr.replace(b"mysql: [Warning] Using a password on the command line interface can be insecure.", b"").strip():
        sys.exit("import failed: " + p.stderr.decode("latin-1")[:2000])

    got_tables = [r[0] for r in mysql("select table_name from information_schema.tables "
                                      "where table_schema='%s' and table_type='BASE TABLE'" % test)]
    got_trig = int(mysql("select count(*) from information_schema.triggers "
                         "where trigger_schema='%s'" % test)[0][0])
    bad = []
    if sorted(got_tables) != sorted(tables):
        bad.append("table list differs: %d vs %d" % (len(got_tables), len(tables)))
    if got_trig != n_trig:
        bad.append("triggers: %d vs %d" % (got_trig, n_trig))

    got_counts = {}
    for i in range(0, len(tables), 60):
        chunk = tables[i:i + 60]
        for name, n in mysql(" union all ".join("select '%s',count(*) from `%s`" % (t, t) for t in chunk), db=test):
            got_counts[name] = int(n)
    for t in runtime:
        if got_counts.get(t):
            bad.append("%s should be empty, has %d" % (t, got_counts[t]))
    reset_tables = {r[0] for r in RESETS}
    for t in base:
        if t in reset_tables:
            continue
        if got_counts.get(t, -1) != counts[t]:
            bad.append("%s has %d rows, live has %d" % (t, got_counts.get(t, -1), counts[t]))
    # the reset tables keep their rows, only the counter changes
    for t, sets, why in RESETS:
        if got_counts.get(t, -1) != counts[t]:
            bad.append("%s has %d rows, live has %d" % (t, got_counts.get(t, -1), counts[t]))
    col = {"CardCount": "CARDCOUNT", "GiftBoxCount": "BOXCOUNT", "LuckyBagCount": "BAGCOUNT",
           "ResurrectItemCount": "Count", "EventItemCount": "Count", "EventItemCount2": "Count",
           "UniqueItemInfo": "CurrentNumber", "CastleInfo": "GuildID"}
    for t, c in col.items():
        left = mysql("select count(*) from `%s` where `%s` <> 0" % (t, c), db=test)[0][0]
        if left != "0":
            bad.append("%s.%s not reset (%s rows)" % (t, c, left))
    # a CP949 string survived the round trip byte for byte
    a_hex = mysql("select hex(HName) from MonsterInfo order by MType limit 1")[0][0]
    b_hex = mysql("select hex(HName) from MonsterInfo order by MType limit 1", db=test)[0][0]
    if a_hex != b_hex:
        bad.append("MonsterInfo.HName bytes differ")

    mysql("drop database `%s`" % test, db="mysql")
    if bad:
        sys.exit("VERIFY FAILED:\n  " + "\n  ".join(bad[:40]))
    print("verify OK: %d tables, %d triggers, %d content tables match the live row counts, "
          "every runtime table empty, CP949 bytes intact" % (len(tables), n_trig, len(base)))


main()
