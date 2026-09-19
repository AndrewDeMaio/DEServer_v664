#!/usr/bin/env python3
"""Bring a DARKEDEN database up to date: the skeleton, then every migration it
has not had yet.

    ./deploy_db.py                  deploy (the default)
    ./deploy_db.py status           show the version and what is pending
    ./deploy_db.py --dry-run        say what a deploy would do, change nothing

How it decides what to run
--------------------------
The database carries its own version in the `SchemaVersion` table:

  * the skeleton alone (DARKEDEN_skeleton.sql) is schema 1.0.0
  * each file in migrations/ is named  <Major>.<Minor>.<Bug>_<Description>.sql
    and raises the schema to the version in its name: running
    1.1.0_CharIDUpdate.sql makes the database 1.1.0

A deploy imports the skeleton if the database is missing or empty, then runs,
in version order, every migration newer than the recorded version. A migration
is recorded only after it ran without error, so a failed one is simply run
again next time (migrations are written to be safe to repeat).

A database that already has tables but no SchemaVersion table was built before
this script existed. It is never guessed at: say what it is with
`--baseline 1.0.0` once, and it is tracked from then on.

Connection: --host/--port/--user/--password/--db, or $DE_DB_HOST, $DE_DB_PORT,
$DE_DB_USER, $DE_DB_PASSWORD, $DE_DB_NAME. With no password given it is asked
for.
"""
import argparse
import hashlib
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from dbconn import MySQL, add_connection_args, quote  # noqa: E402

HERE = os.path.dirname(os.path.abspath(__file__))
SKELETON_VERSION = (1, 0, 0)
MIGRATION_RE = re.compile(r"^(\d+)\.(\d+)\.(\d+)_([A-Za-z0-9][A-Za-z0-9_-]*)\.sql$")

VERSION_TABLE = """
CREATE TABLE IF NOT EXISTS `SchemaVersion` (
  `Major`     int unsigned NOT NULL,
  `Minor`     int unsigned NOT NULL,
  `Bug`       int unsigned NOT NULL,
  `Script`    varchar(128) NOT NULL DEFAULT '',
  `Checksum`  char(64)     NOT NULL DEFAULT '',
  `AppliedAt` datetime     NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`Major`, `Minor`, `Bug`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4
  COMMENT='which skeleton and migrations this database has had; written by db/deploy_db.py';
"""


def vstr(v):
    return "%d.%d.%d" % v


def parse_version(text):
    m = re.match(r"^(\d+)\.(\d+)\.(\d+)$", text.strip())
    if not m:
        sys.exit("not a version (want Major.Minor.Bug): %r" % text)
    return tuple(int(x) for x in m.groups())


def sha256(path):
    with open(path, "rb") as f:
        return hashlib.sha256(f.read()).hexdigest()


def find_migrations(folder):
    """[(version, filename, path)] in version order."""
    if not os.path.isdir(folder):
        sys.exit("no migrations folder at " + folder)
    found, seen = [], {}
    for name in sorted(os.listdir(folder)):
        if not name.endswith(".sql"):
            continue
        m = MIGRATION_RE.match(name)
        if not m:
            print("  ! ignoring %s: not named <Major>.<Minor>.<Bug>_<Description>.sql" % name)
            continue
        v = tuple(int(x) for x in m.groups()[:3])
        if v in seen:
            sys.exit("two migrations claim version %s: %s and %s" % (vstr(v), seen[v], name))
        if v <= SKELETON_VERSION:
            sys.exit("%s: a migration must be newer than the skeleton (%s)" % (name, vstr(SKELETON_VERSION)))
        seen[v] = name
        found.append((v, name, os.path.join(folder, name)))
    return sorted(found)


class Deployer:
    def __init__(self, my, args):
        self.my = my
        self.db = args.db
        self.dry = args.dry_run
        self.skeleton = args.skeleton
        self.migrations = find_migrations(args.migrations)

    # ---- what the database looks like now
    def table_count(self):
        n = self.my.scalar("SELECT COUNT(*) FROM information_schema.TABLES "
                           "WHERE TABLE_SCHEMA = %s" % quote(self.db), db=False)
        return int(n)

    def has_version_table(self):
        n = self.my.scalar("SELECT COUNT(*) FROM information_schema.TABLES WHERE TABLE_SCHEMA = %s "
                           "AND TABLE_NAME = 'SchemaVersion'" % quote(self.db), db=False)
        return int(n) > 0

    def applied(self):
        """{version: (script, checksum, applied_at)}"""
        if not self.has_version_table():
            return {}
        rows = self.my.query("SELECT Major, Minor, Bug, Script, Checksum, AppliedAt FROM SchemaVersion")
        return {(int(r[0]), int(r[1]), int(r[2])): (r[3], r[4], r[5]) for r in rows}

    def record(self, version, script, checksum):
        self.my.query(VERSION_TABLE)
        self.my.query("INSERT INTO SchemaVersion (Major, Minor, Bug, Script, Checksum) "
                      "VALUES (%d, %d, %d, %s, %s) ON DUPLICATE KEY UPDATE "
                      "Script = VALUES(Script), Checksum = VALUES(Checksum), AppliedAt = NOW()"
                      % (version + (quote(script), quote(checksum))))

    # ---- the steps
    def import_skeleton(self):
        if not os.path.isfile(self.skeleton):
            sys.exit("no skeleton at " + self.skeleton)
        print("importing %s into `%s` ..." % (os.path.basename(self.skeleton), self.db))
        if self.dry:
            return
        with open(self.skeleton, "rb") as f:
            body = f.read()
        # the dump names the database it was taken from; aim it at ours
        name = self.db.encode()
        body, n1 = re.subn(rb"CREATE DATABASE IF NOT EXISTS `[^`]+`", b"CREATE DATABASE IF NOT EXISTS `" + name + b"`", body, count=1)
        body, n2 = re.subn(rb"(?m)^USE `[^`]+`;", b"USE `" + name + b"`;", body, count=1)
        if n1 != 1 or n2 != 1:
            sys.exit("the skeleton has no CREATE DATABASE / USE header; is it a make_skeleton.py dump?")
        ok, err = self.my.feed(body, db=False)
        if not ok:
            sys.exit("skeleton import FAILED:\n" + err)
        # a skeleton regenerated from a migrated database brings its own history
        if not self.applied():
            self.record(SKELETON_VERSION, os.path.basename(self.skeleton), sha256(self.skeleton))
        print("  schema %s" % vstr(max(self.applied())))

    def status(self, applied):
        current = max(applied) if applied else None
        print("database `%s`: %s" % (self.db, "schema " + vstr(current) if current else "no SchemaVersion table"))
        for v in sorted(applied):
            script, checksum, when = applied[v]
            print("  %-8s %-40s %s" % (vstr(v), script, when))
        by_version = {v: (name, path) for v, name, path in self.migrations}
        for v in sorted(applied):
            if v in by_version and applied[v][1] and sha256(by_version[v][1]) != applied[v][1]:
                print("  ! %s has changed since it was applied; the database has the OLD contents"
                      % by_version[v][0])
        if current:
            for v, name, _ in self.migrations:
                if v < current and v not in applied:
                    print("  ! %s is older than the schema but was never applied; it will NOT run" % name)
        pending = [m for m in self.migrations if current is None or m[0] > current]
        if pending:
            print("pending: " + ", ".join(name for _, name, _ in pending))
        else:
            print("pending: nothing")
        return pending

    def deploy(self, baseline, upto):
        tables = self.table_count()
        if tables == 0:
            self.import_skeleton()
            if self.dry:
                for v, name, _ in self.migrations:
                    if upto is None or v <= upto:
                        print("would apply " + name)
                return
        elif not self.has_version_table():
            if baseline is None:
                sys.exit("`%s` has %d tables but no SchemaVersion table, so its version is unknown.\n"
                         "If it matches the skeleton, say so once:  --baseline %s"
                         % (self.db, tables, vstr(SKELETON_VERSION)))
            print("declaring `%s` to be schema %s" % (self.db, vstr(baseline)))
            if not self.dry:
                self.record(baseline, "baseline declared by hand", "")
        elif baseline is not None:
            sys.exit("`%s` already tracks its version; --baseline is only for a database that does not" % self.db)

        applied = self.applied()
        if self.dry and not applied and baseline is not None:
            applied = {baseline: ("baseline", "", "")}
        pending = self.status(applied)
        for v, name, path in pending:
            if upto is not None and v > upto:
                print("stopping before %s (--to %s)" % (name, vstr(upto)))
                break
            if self.dry:
                print("would apply " + name)
                continue
            print("applying %s ..." % name)
            with open(path, "rb") as f:
                ok, err = self.my.feed(f.read())
            if not ok:
                sys.exit("%s FAILED, the schema stays at %s:\n%s\n"
                         "Fix the cause and deploy again; migrations are safe to repeat."
                         % (name, vstr(max(self.applied())), err))
            self.record(v, name, sha256(path))
            print("  schema %s" % vstr(v))
        if not self.dry:
            print("`%s` is at schema %s" % (self.db, vstr(max(self.applied()))))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", nargs="?", default="deploy", choices=["deploy", "status"])
    ap.add_argument("--dry-run", action="store_true", help="show what would happen, change nothing")
    ap.add_argument("--baseline", metavar="VERSION",
                    help="a populated database with no SchemaVersion table IS this version")
    ap.add_argument("--to", metavar="VERSION", help="stop after this version instead of the newest")
    ap.add_argument("--skeleton", default=os.path.join(HERE, "DARKEDEN_skeleton.sql"))
    ap.add_argument("--migrations", default=os.path.join(HERE, "migrations"))
    add_connection_args(ap)
    a = ap.parse_args()

    d = Deployer(MySQL(a), a)
    if a.command == "status":
        if d.table_count() == 0:
            print("database `%s` is missing or empty; a deploy would import the skeleton" % a.db)
            print("pending: " + (", ".join(n for _, n, _ in d.migrations) or "nothing"))
        else:
            d.status(d.applied())
        return
    d.deploy(parse_version(a.baseline) if a.baseline else None,
             parse_version(a.to) if a.to else None)


main()
