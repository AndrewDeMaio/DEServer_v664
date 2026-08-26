#!/usr/bin/env python3
"""
Detect packets whose on-the-wire payload differs between server and client.

This catches the LCLoginOK class of bug. The server compiles every packet field
unconditionally; the client wraps many in #if __CONTENTS(__FLAG), and 92 of its
134 flags are __OFF for the region it actually builds (__DESIGNED_INTERNATION,
set in Build/DEClient.Common.props). When the server writes a field the client
does not read, the stream desyncs and the client reports "too large PacketSize".

Usage
  python3 tools/packetaudit.py                 report drift against the baseline
  python3 tools/packetaudit.py --verbose       list every candidate in full
  python3 tools/packetaudit.py --update-baseline   accept current state as clean

Exit status is 1 only when a mismatch appears that is NOT in the baseline, so
this is safe to run on every build without becoming noise.

Three correctness rules are load-bearing here; do not "simplify" them away:
  1. Encoding is decided by BOM / null density. Never try utf-16 first --
     decoding a latin-1 file as utf-16 SUCCEEDS and yields one long garbage
     line with no nulls to detect it. That produced a 187-entry phantom report.
  2. Comparison is by DIRECTION. CG/CL = client writes -> server reads;
     GC/LC = server writes -> client reads. Comparing read-to-read is
     meaningless: a CL packet's client-side read() is dead code.
  3. The server's own #ifdefs are applied too. Its Makefiles define only
     __LINUX__ _REENTRANT __DEBUG__ plus one of __GAME_SERVER__ /
     __LOGIN_SERVER__ / __SHARED_SERVER__; counting __NETMARBLE_SERVER__ or
     __XTEA__ code invents mismatches (e.g. CLLogin's Cpsso fields).

Known limit: it cannot resolve runtime if/else branches, so output is a
candidate list, not a verdict. CLLogin (two write variants), LCPCList (m_Agree
behind a runtime IsNetmarble test) and CLSelectPC (a (BYTE) cast) are all
verified-good false positives.
"""
import argparse
import os
import re
import sys

REGION = "__DESIGNED_INTERNATION"
HERE = os.path.dirname(os.path.abspath(__file__))
BASELINE = os.path.join(HERE, "packetaudit.baseline")

DIR_PAIRS = [
    ("Packet/Cpackets", "Core/Cpackets"),
    ("Packet/Gpackets", "Core/Gpackets"),
    ("Packet/Lpackets", "Core/Lpackets"),
    ("Packet", "Core"),
]

SERVER_DEFINED = {
    "__LINUX__", "_REENTRANT", "__DEBUG__",
    "__GAME_SERVER__", "__LOGIN_SERVER__", "__SHARED_SERVER__",
}

SERVER_NEVER_DEFINED = {
    "__NETMARBLE_SERVER__", "__XTEA__", "__UPDATE_SERVER__", "__COMBAT__",
    "__GAME_CLIENT__", "__WINDOWS__", "__THAILAND_SERVER__", "__JAPAN_SERVER__",
}

STREAM_OP = re.compile(r"\b([io]Stream)\s*\.\s*(read|write)\s*\((.*)")
CONTENTS_IF = re.compile(r"^\s*#\s*if\s+__CONTENTS\s*\((.+?)\)\s*(?://.*)?$")
PLAIN_IF = re.compile(r"^\s*#\s*if(n?def)?\b(.*)$")
ELSE_RE = re.compile(r"^\s*#\s*else\b")
ELIF_RE = re.compile(r"^\s*#\s*elif\b")
ENDIF_RE = re.compile(r"^\s*#\s*endif\b")
FUNC_RE = re.compile(r"::(read|write)\s*\(")


def find_trees():
    """Locate the two source trees on either WSL or Windows."""
    client = os.environ.get("DECLIENT_DIR")
    server = os.environ.get("DESERVER_SRC")
    if client and server:
        return client, server

    candidates = [
        ("/mnt/d/GitHub/DEClient_v664", "/mnt/d/GitHub/DEServer_v664/src"),
        (r"D:\GitHub\DEClient_v664", r"D:\GitHub\DEServer_v664\src"),
        # When run from the synced ext4 copy, the client is still only on /mnt/d.
        ("/mnt/d/GitHub/DEClient_v664", os.path.abspath(os.path.join(HERE, "..", "src"))),
    ]
    for c, s in candidates:
        if os.path.isdir(c) and os.path.isdir(s):
            return c, s
    sys.exit("could not locate the client and server trees; "
             "set DECLIENT_DIR and DESERVER_SRC")


def load(path):
    """Decode a source file. See rule 1 in the module docstring."""
    raw = open(path, "rb").read()
    if raw[:2] in (b"\xff\xfe", b"\xfe\xff"):
        text = raw.decode("utf-16")
    elif raw[:3] == b"\xef\xbb\xbf":
        text = raw.decode("utf-8-sig", errors="replace")
    elif raw[:2048].count(b"\x00") > len(raw[:2048]) // 4:
        text = raw.decode("utf-16-le", errors="replace")
    else:
        text = raw.decode("latin-1")
    text = text.replace("\r\n", "\n").replace("\r", "\n")
    return re.sub(r"\n{3,}", "\n\n", text)


def region_flags(client):
    """Flag -> True/False for the region the client actually builds."""
    lines = load(os.path.join(client, "DXLib", "ContentsFilter.h")).split("\n")
    start = None
    for i, line in enumerate(lines):
        if re.match(r"\s*#\s*ifdef\s+%s\b" % REGION, line):
            start = i
            break
    if start is None:
        sys.exit("could not find %s in ContentsFilter.h" % REGION)

    flags, depth = {}, 0
    for line in lines[start + 1:]:
        if re.match(r"\s*#\s*if", line):
            depth += 1
        elif ENDIF_RE.match(line):
            if depth == 0:
                break
            depth -= 1
        m = re.match(r"\s*#\s*define\s+(__\w+)\s+__(ON|OFF)\b", line)
        if m:
            flags[m.group(1)] = (m.group(2) == "ON")
    return flags


def evaluate(expr, flags):
    """Evaluate a __CONTENTS(...) argument; None when undecidable."""
    expr = expr.strip()
    if re.fullmatch(r"__\w+", expr):
        return flags.get(expr)
    for sep, combine in ((r"\|\|", any), (r"&&", all)):
        parts = re.split(sep, expr)
        if len(parts) > 1:
            vals = [flags.get(p.strip()) for p in parts]
            return None if any(v is None for v in vals) else combine(vals)
    return None


def fields(path, flags, apply_guards):
    """Active stream fields in read() and write(), as {func: [names]}."""
    text = load(path)
    out = {"read": [], "write": []}
    current, brace, stack, unknown = None, 0, [], []

    for line in text.split("\n"):
        stripped = line.strip()

        m = CONTENTS_IF.match(line)
        if m:
            val = evaluate(m.group(1), flags) if apply_guards else True
            if val is None:
                unknown.append(m.group(1))
                val = True
            stack.append([val, True])
            continue

        m = PLAIN_IF.match(line)
        if m and stripped.startswith("#"):
            val = True
            if not apply_guards:
                negate = (m.group(1) == "ndef")
                sym = re.match(r"\s*(__?\w+)", m.group(2) or "")
                if sym:
                    name = sym.group(1)
                    if name in SERVER_NEVER_DEFINED:
                        val = negate
                    elif name in SERVER_DEFINED:
                        val = not negate
            stack.append([val, False])
            continue

        if ELIF_RE.match(line):
            if stack:
                stack[-1][0] = True
            continue
        if ELSE_RE.match(line):
            if stack:
                stack[-1][0] = (not stack[-1][0]) if stack[-1][1] else True
            continue
        if ENDIF_RE.match(line):
            if stack:
                stack.pop()
            continue

        active = all(entry[0] for entry in stack)

        if current is None:
            m = FUNC_RE.search(line)
            if m:
                current, brace = m.group(1), 0
        if current is not None:
            brace += line.count("{") - line.count("}")
            m = STREAM_OP.search(line)
            if m and active and not stripped.startswith("//"):
                arg = m.group(3).split(")")[0].split(",")[0].strip()
                out[current].append(arg)
            if brace <= 0 and stripped == "}":
                current = None
    return out, unknown


def audit(client, server):
    flags = region_flags(client)
    findings, compared = [], 0

    for cdir, sdir in DIR_PAIRS:
        cpath = os.path.join(client, *cdir.split("/"))
        spath = os.path.join(server, *sdir.split("/"))
        if not (os.path.isdir(cpath) and os.path.isdir(spath)):
            continue
        for name in sorted(os.listdir(cpath)):
            if not name.endswith(".cpp") or "Handler" in name:
                continue
            server_file = os.path.join(spath, name)
            if not os.path.isfile(server_file):
                continue

            prefix = name[:2]
            if prefix in ("CG", "CL"):
                direction, producer, consumer = "client -> server", "client", "server"
            elif prefix in ("GC", "LC"):
                direction, producer, consumer = "server -> client", "server", "client"
            else:
                continue  # GS/SG/LG/GL are server-to-server

            compared += 1
            cf, unknown = fields(os.path.join(cpath, name), flags, True)
            sf, _ = fields(server_file, flags, False)

            sent = (cf if producer == "client" else sf)["write"]
            recv = (cf if consumer == "client" else sf)["read"]
            if sent != recv:
                findings.append((name, direction, producer, consumer,
                                 sent, recv, unknown))
    return flags, compared, findings


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--verbose", action="store_true", help="list every candidate")
    ap.add_argument("--update-baseline", action="store_true",
                    help="accept the current mismatches as the known set")
    args = ap.parse_args()

    client, server = find_trees()
    flags, compared, findings = audit(client, server)
    names = sorted(f[0] for f in findings)

    if args.update_baseline:
        with open(BASELINE, "w") as fh:
            fh.write("\n".join(names) + "\n")
        print("baseline updated: %d known mismatches" % len(names))
        return 0

    known = set()
    if os.path.exists(BASELINE):
        known = {l.strip() for l in open(BASELINE) if l.strip()}

    new = [f for f in findings if f[0] not in known]
    fixed = sorted(known - set(names))

    on = sum(1 for v in flags.values() if v)
    print("packet audit: %d client-facing packets, %d candidates "
          "(%d known, %d NEW), %d flags %d/%d ON"
          % (compared, len(findings), len(findings) - len(new), len(new),
             len(flags), on, len(flags)))

    if fixed:
        print("  resolved since baseline: %s" % ", ".join(fixed))

    show = findings if args.verbose else new
    for name, direction, producer, consumer, sent, recv, unknown in show:
        tag = "" if name in known else "  <-- NEW"
        print("\n%-32s %s%s" % (name, direction, tag))
        print("  %s writes %d, %s reads %d" % (producer, len(sent), consumer, len(recv)))
        extra = [f for f in sent if f not in recv]
        missing = [f for f in recv if f not in sent]
        if extra:
            print("    written but not read : %s" % ", ".join(extra))
        if missing:
            print("    read but not written : %s" % ", ".join(missing))
        if not extra and not missing:
            print("    same fields, different order")

    if new:
        print("\n%d NEW payload mismatch(es). These are candidates, not verdicts --"
              % len(new))
        print("runtime if/else branches cannot be resolved statically. Check each,")
        print("then re-run with --update-baseline once reviewed.")
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
