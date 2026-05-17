# 1.3
gcc uaf.c -o uaf && ./uaf # program runs fine
gcc -fsanitize=address -g uaf.c -o uaf && ./uaf 
# hard to read err output due to addressing but free and 
# malloc errs easy to understand

# 1.4 linux needed for this
strace ls -l

# 2 

# Come back to the course with a linux laptop to complete these
# https://missing.csail.mit.edu/2026/debugging-profiling/
