#!/bin/bash
#-----------------------------------------------------------------------------
# Start the three servers against a local MySQL using the *.local.conf files.
#
# Differences from start.sh that matter:
#
#   stdbuf -oL -eL   Redirected stdout is block buffered, so on an abnormal exit
#                    the last few KB are lost -- the log just stops mid-sentence
#                    and hides the actual failure. Line buffering keeps the log
#                    live and preserves the tail through a crash.
#
#   setsid           Fully detaches, so the servers survive the shell that
#                    launched them going away.
#
#   staggered start  sharedserver and loginserver must be listening before
#                    gameserver registers itself with them.
#
# Logs go to ../log/<name>.log (which is the repo's log/ directory).
#-----------------------------------------------------------------------------
set -u

BIN="$(cd "$(dirname "$0")" && pwd)"
LOG="$BIN/../log"
CONF="$BIN/../conf"
mkdir -p "$LOG"

start_one() {
    local name=$1 wait=$2
    if pgrep -f "[.]/$name -f" > /dev/null 2>&1; then
        echo "$name: already running (pid $(pgrep -f "[.]/$name -f" | head -1))"
        return
    fi
    cd "$BIN" || return 1
    setsid nohup stdbuf -oL -eL "./$name" -f "../conf/$name.local.conf" \
        > "$LOG/$name.log" 2>&1 < /dev/null &
    echo "$name: starting (log: log/$name.log)"
    sleep "$wait"
}

# gameserver registers with the other two, so they go up first
start_one sharedserver 10
start_one loginserver  10
start_one gameserver   0

echo
echo "waiting for listeners..."
for i in $(seq 1 60); do
    up=$(ss -ltn 2>/dev/null | grep -cE ':(9909|9993|13855)\b')
    [ "$up" -ge 3 ] && break
    sleep 5
done

echo
ss -ltn 2>/dev/null | grep -E ':(9909|9993|13855)\b' | awk '{print "  listening " $4}'
echo
for n in sharedserver loginserver gameserver; do
    pid=$(pgrep -f "[.]/$n -f" | head -1)
    [ -n "$pid" ] && echo "  $n: pid $pid" || echo "  $n: NOT RUNNING"
done
