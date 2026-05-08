#1 I'm using zsh
echo $SHELL 

#2 perm groups are: [user, group, other]
ls -l /
man ls

# 3 finds files in downloads older than 30 * 24hrs ago. -mtime works on exactly 24h periods 
find ~/Downloads -type f -name "*.zip" -mtime +30
# a glob i used here to get all files that end in .zip
# globs are essentially a simple version of expression matching, that the shell recognizes
# * matches any string 
# ? matches any char
# [...] will match any char in the brackets

# 4
echo "$" # works
echo "!" # needs single quotes
echo '!' # works
echo -E "\n" # OR
echo -E '\n' # work (-E disables escape sequences)
# '' is entirely literal 
# "" allows for the use of var expansion and escapes

# 5
ls /nonexistent &> /temp # redirects error to /tmp
# check this out:  

# 6
cat /tmp/mydir || mkdir /tmp/mydir

# 7
cd 
# cannot be a command, and must be built into the shell, 
# as it modifies the current dir and would therefore 
# fail to change the actual shell current dir at the end of 
# its life. It's a essentially a scoping issue

# 8 check.sh
#!/bin/bash
set -euo pipefail

if [[ -f "$1" ]]; then
    echo "we found your file"
else
    echo "file not found"
fi 

# 9 
chmod +x check.sh 
# this is used to give execution perms for this file

# 10 check.sh modified
#!/bin/bash
set -euox pipefail

if [[ -f "$1" ]]; then
    echo "we found your file"
else
    echo "file not found"
fi 
# the set with -x flag means the script will ouput a command trace

# 11 
#! /bin/bash
set -euox pipefail

cp "test.txt" "$(basename test.txt .txt)$(date +%Y-%m-%d).txt"

# 12 
# see the modified.sh for details
# $1 is first element
# $0 is the script itself
# $$ is the process ID of the script
# $@ can be expanded to multiple words:
#   cargo test my_test ($1 $2 $3) 
#   -> ($@) this includes all args

# 13
find ~ -type f 2>/dev/null | awk -F/ '{print $NF}' | awk -F. 'NF>1 {print $NF}' | sort | uniq -c | sort -rn | head -10   
# find files in the root folder and send errs to null for silence
# pipe to awk to extract filenames with F/
# then check to make sure the name contains a '.' and return the last extension
# sort so that a valid pipe to uniq can be done, it filters sequetially
# sort the results by desc order and return the top 10

# 14 
find . -name "*.sh" | xargs wc -l
# get all .sh files and ouput the filename
# take the ouput files and print each files word count 
# -l for lines only 
find . -name "*.sh" -print0 | xargs -0 wc -l
# same but file names are sent with null terminators
# xargs is set to expect the null terminated names

# 15 
curl https://missing.csail.mit.edu/ | grep "<strong>1" -c
# curl returns the raw html to grep which matches their existing pattern

# 16
curl https://microsoftedge.github.io/Demos/json-dummy-data/64KB.json | jq '.[] | select (.version > 6) | .name'
# pipe curled json to jq parser
# select filters the data based on a condition
# pipe this to name to print 'name' values that fulfill the condition

# 17 filter ouput with awk, swapping the cols 1 and 3, where col $2 > 100
printf 'a 50 x\nb 150 y\nc 200 z\n' | awk '$2 > 100 {$4 = ""; print $3 " " $2 " " $1}'
# printf provides the stream 
# awk structure:
# awk 'pattern {printing and conditionals}'
# $4 = ""; checks for that the 4th col ends with nothing
# use ; to add new args
# cols can be easily swizzled using with print by swithing cols as seen above

# 18 print most common cmds from zsh_history
awk '{print $1}' ~/.zsh_history | LC_ALL=C sort | uniq -c | LC_ALL=C sort | tail -10
# straight-forward atp
# the LC_ALL=C makes the sort util able to process some non compatible names
