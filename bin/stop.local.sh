#!/bin/bash
# Stop local servers started by start.local.sh.
# With no arguments, stops all servers.
# Arguments can be: game, login, shared.
set -u

servers=()

if [ "$#" -eq 0 ]; then
    servers=(gameserver loginserver sharedserver)
else
    for arg in "$@"; do
    	case "$arg" in
        	game)
            	servers+=(gameserver)
                ;;
          	login)
            	servers+=(loginserver)
                ;;
          	shared)
            	servers+=(sharedserver)
                ;;
            *)
           echo "Unknown server: $arg"
           echo "Usage: $0 [game] [login] [shared]"
           exit 1
           ;;
    	esac
  	done
fi

for n in "${servers[@]}"; do
    pid=$(pgrep -f "[.]/$n -f" | head -1)
    if [ -n "$pid" ]; then 
    	if kill "$pid" 2>/dev/null; then
			echo "$n: stopped (pid $pid)"
		else
			echo "$n: failed to stop (pid $pid)"
		fi
	else
		echo "$n: not running"
	fi
done

sleep 1

for n in "${servers[@]}"; do
	if pgrep -f "[.]/$n -f" >/dev/null 2>&1; then
		echo "warning: $n still running (use kill -9 if stuck)"
	fi
done

exit 0
