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