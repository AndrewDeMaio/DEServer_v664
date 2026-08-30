#!/bin/bash
# Stop the three local servers started by start.local.sh.
# Matches on the ./<name> -f form so it cannot hit an unrelated process.
set -u

for n in gameserver loginserver sharedserver; do
    pid=$(pgrep -f "[.]/$n -f" | head -1)
    if [ -n "$pid" ]; then
        kill "$pid" 2>/dev/null && echo "$n: stopped (pid $pid)"
    else
        echo "$n: not running"
    fi
done

sleep 2
left=$(pgrep -cf "[.]/(gameserver|loginserver|sharedserver) -f" 2>/dev/null || echo 0)
[ "$left" -gt 0 ] && echo "warning: $left still running (use kill -9 if stuck)"
exit 0
