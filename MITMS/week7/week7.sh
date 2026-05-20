# week 7 data wrangling

# 1 easy tutorial

# 2 
# for word count
grep -E '.*a.*a.*a.*' /usr/share/dict/words | grep -v "'s$" | wc -c
# for most common two letter pair for ending
grep -E '.*a.*a.*a.*' /usr/share/dict/words | grep -v "'s$" | sed -E 's/.*(..)$/\1/' | sort | uniq -c | sort -nr   

# 3 
