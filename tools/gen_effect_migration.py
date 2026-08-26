#!/usr/bin/env python3
"""
Generate the pending schema migration from the live source-vs-DB diff.

Reads ~/schema_from_source.json (produced by schemagap.py) and emits ALTER
statements for columns the source requires but the database lacks.

Only the Effect* tables are emitted as ready-to-run SQL: they are uniform
(OwnerID / Name, both varchar(10) NOT NULL in every table that already has
them) and they are the current blocker -- EffectLoaderManager::load() walks
every loader in turn during Ousters::load(), so each missing column kills the
gameserver on character load.

Everything else is listed as a comment for review, because the correct type
cannot be inferred safely. Player's Birthday/ID/PID/Passwd are deliberately
excluded: those come from the __NETMARBLE_SERVER__ path, which is not compiled.
"""
import json
import os
import subprocess
import sys

SRC_JSON = os.path.expanduser("~/schema_from_source.json")
OUT = os.path.expanduser("~/pending_schema_fixes.sql")
DB = "DARKEDEN"
MYSQL = ["mysql", "-u", "elcastle", "-pelca005", "-h", "127.0.0.1", "-N", "-B", "-e"]

# Not real DARKEDEN columns -- these come from the uncompiled netmarble path.
SKIP = {("player", "birthday"), ("player", "id"), ("player", "pid"),
        ("player", "passwd")}


def query(sql):
    out = subprocess.run(MYSQL + [sql, DB], capture_output=True, text=True)
    if out.returncode != 0:
        sys.exit("mysql failed: " + out.stderr.strip())
    return [l.split("\t") for l in out.stdout.splitlines() if l]


def main():
    required = json.load(open(SRC_JSON))

    live = {}
    for table, column in query(
        "SELECT TABLE_NAME, COLUMN_NAME FROM information_schema.COLUMNS "
        "WHERE TABLE_SCHEMA = '%s'" % DB):
        live.setdefault(table.lower(), {})[column.lower()] = table

    effect, other = [], []
    for table, columns in sorted(required.items()):
        key = table.lower()
        if key not in live:
            continue                       # missing tables handled separately
        realname = list(live[key].values())[0] if live[key] else table
        for col in sorted(columns):
            if col.lower() in live[key]:
                continue
            if (key, col.lower()) in SKIP:
                continue
            if table.startswith("Effect") and col in ("OwnerID", "Name"):
                effect.append((realname, col))
            else:
                other.append((realname, col))

    with open(OUT, "w") as fh:
        fh.write("-- Pending schema fixes, generated from the source-vs-DB diff.\n")
        fh.write("-- Effect* columns are varchar(10) NOT NULL in every table that\n")
        fh.write("-- already has them, so the type here is copied, not guessed.\n")
        fh.write("-- Blocker: EffectLoaderManager::load() during Ousters::load().\n\n")
        for table, col in effect:
            fh.write("ALTER TABLE %s ADD COLUMN %s varchar(10) NOT NULL DEFAULT '';\n"
                     % (table, col))
        fh.write("\n-- NEEDS TYPE REVIEW (not emitted as SQL):\n")
        for table, col in other:
            fh.write("--   %s.%s\n" % (table, col))

    print("Effect* columns ready to apply : %d" % len(effect))
    for table, col in effect:
        print("    %-32s %s" % (table, col))
    print("\nneeds review                   : %d" % len(other))
    for table, col in other:
        print("    %-32s %s" % (table, col))
    print("\nwritten to: %s" % OUT)


if __name__ == "__main__":
    main()
