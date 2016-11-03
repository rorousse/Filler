#!/bin/bash

echo $1
for str in 'players/abanlin.filler' 'players/carli.filler' 'players/grati.filler' 'players/hcao.filler' 'players/superjeannot.filler' 
	do let "count = 0"
		for n in `seq 1 5`
		do ./filler_vm -f $1 -p1 ../rorousse.filler -p2 $str > lol
		line=`sed -n 2p filler.trace`
		echo "$line"
		if [ "$line" = "../rorousse.filler won" ];
		then
			let "count = $count + 1"
		fi
	done
	let "win = (count * 100) / 5" 
	echo $win % de win
done