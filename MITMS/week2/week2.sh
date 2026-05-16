#1.1
touch -- -test
# -- ignores the "-test" "flag" and treats it as a valid flag
rm -- -test # is then needed to delete said file

#1.2
ls -ahGtl 

#1.3
diff <(printenv | sort) <(export | sort)
# will be more different without the sorts 

#2.1
# marco
#! /bin/bash
backup="/tmp/marco.txt"

if [[ ! -f "$backup" ]]; then
    echo "no file detected, creating now"
    touch $backup;
fi
pwd > $backup
# polo:
#! /bin/bash

backup="/tmp/marco.txt"
if [[ ! -f "$backup" ]]; then
    echo "no file made"
    bash ./marco.sh
    if [[ ! $? -eq 0 ]]; then 
        echo "Error: marco.sh did not succeed"
        exit 1
    fi
fi
cd "$(cat $backup)" 
echo "success"
# source ./polo.sh or . ./polo.sh must be used 
# to ensure the cd takes effect despite being contained to a shell

#3.1
#!/usr/bin/env bash

log="/tmp/week2log"
echo "" > $log

while [[ true ]]; do

    n=$(( RANDOM % 100 ))

    if [[ n -eq 42 ]]; then
        echo "Something went wrong\n" >> $log
        >&2 echo "The error was using magic numbers" >> $log
        cat $log
        exit 1
    fi

    echo "Everything went according to plan\n" >> $log

done
# added error logging in the script to be printed at fail
# redirection is for commands only and 
# therefore must be accompanied by the echo 
# command for plain text

#4.1 
sleep 10000 # cancel w ctrl+z
bg # continues the command
pgrep "sleep"
pkill -af "sleep"
# flags needed to kill the ancestors in the match list

#4.2
sleep 10 & 
pid=$!
wait $pid
ls -l

#5.1
find . -type f -print0 | xargs -0 stat -f '%m %N' | sort -rn | head -1

#6.1
# use C-b (control + b) is the prefix key
# prefix + % to split horizontal or " for vertical
# prefix + <arrow key to move view>
# exit like with any terminal (exit or control + d)
# C-b + c to make a new window and C-b p / n for previous / next window
# C-b + d to detach session or + D to be given choice of session to close
tmux ls # will show all past sessions
tmux attach -t <name> # will reattach to running session "name"
tmux new -s <name> # will instantiate and join a new tmux session named: "name" instead of 0, 1, 2 etc...
tmux rename-session -t <name1> <name2> # to rename existing sessions
# see the tmux dotfile link included in the dir for further details

#7.1
alias dc=cd
