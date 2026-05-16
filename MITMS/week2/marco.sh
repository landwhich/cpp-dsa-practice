#! /bin/bash

backup="/tmp/marco.txt"

if [[ ! -f "$backup" ]]; then
    echo "no file detected, creating now"
    touch $backup;
fi
pwd > $backup



