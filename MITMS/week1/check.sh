#!/bin/bash
set -euox pipefail

if [[ -f "$1" ]]; then
    echo "we found your file"
else
    echo "file not found"
fi 