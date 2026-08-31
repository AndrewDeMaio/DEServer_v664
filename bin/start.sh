#! /bin/bash

#/bin/bash $PWD/daemon.sh sharedserver -f ../conf/sharedserver.conf > ShareOut.out &
#/bin/bash $PWD/daemon.sh gameserver -f ../conf/gameserver.conf > GameOut.out &
#/bin/bash $PWD/daemon.sh loginserver -f ../conf/loginserver.conf > LoginOut.out &

/bin/bash $PWD/daemon.sh sharedserver -f ../conf/sharedserver.conf &
/bin/bash $PWD/daemon.sh gameserver -f ../conf/gameserver.conf  &
/bin/bash $PWD/daemon.sh loginserver -f ../conf/loginserver.conf  &