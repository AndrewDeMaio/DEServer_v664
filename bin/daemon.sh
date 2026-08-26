# !/bin/sh

if [ $# -ne 3 ]; then
	echo "Usage: $0 file"
	exit 1;
fi

while : 
do 
	echo "$(date +"%Y-%m-%d %H:%M:%S")   $1 was started."
	$PWD/$1 $2 $3
	sleep 120 
done 
