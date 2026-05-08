#! /bin/bash
set -euox pipefail

cp "test.txt" "$(basename test.txt .txt)$(date +%Y-%m-%d).txt"