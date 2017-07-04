#!/bin/bash

quit () {
    echo "Usage: $0 <path to executable> <number of games>";
    exit;
}

if [ "$#" -ne 2 ] || [ ! "$1" ];
then
    quit;
fi

if  [[ ! "$2" =~ ^-?[0-9]+$ ]];
then
    echo "Invalid second argument.";
    quit;
fi

if [ "$2" -le 0 ];
then
    echo "Invalid number of games.";
    quit;
fi

if [ ! -x "$1" ];
then
    echo "File not found or invalid permissions.";
    quit;
fi

gen () {
    while [ 1 ];
    do
	let "a = $RANDOM % 10";
	let "b = $RANDOM % 10";
	echo "$a";
	echo "$b";
    done
}

let "i = 0";
let "win = 0";
let "loss = 0";
let "crash = 0";
let "r = 0";
let "last = -1";

while [ "$i" -ne "$2" ];
do
    cmd="./$1 `expr $RANDOM % 9 + 1` `expr $RANDOM % 9 + 1`";
    eval "gen | $cmd > /dev/null 2>&1";
    let "r = $?";
    if [ "$r" -eq 2 ];
    then
	let "win = win + 1";
    elif [ "$r" -eq 1 ];
    then
	let "loss = loss + 1";
    else
	crashes["$crash"]="CRASH (returned $r): '$cmd'\n";
	let "crash = crash + 1";
    fi
    let "i = i + 1";
    let "progress = i * 100 / $2"
    if [ "$last" -ne "$progress" ];
    then
	let "last = progress";
	clear;
	echo "$last %";
    fi
done
clear;
let "progress = win * 100 / (win + loss)";
let "last = 0";
echo;
if [ "$crash" -gt 0 ];
then
while [ "$last" -le "$crash" ];
do
    echo -e ${crashes["$last"]};
    let "last = last + 1";
done
fi
echo "RESULTS:";
echo;
echo "AI WINS:      $win";
echo "AI LOSSES:    $loss";
echo "CRASHES:      $crash";
echo;
echo "AI WIN RATIO: $progress %";
echo;
