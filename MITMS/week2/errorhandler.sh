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

