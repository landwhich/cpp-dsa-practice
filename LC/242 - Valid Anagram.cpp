#include <string>
#include <map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        size_t size = s.length();
        if (size != t.length()) return false;
        std::map<char, uint16_t> sCount;
        std::map<char, uint16_t> tCount;
        
        for (int i = 0; i < size; i++){
            sCount[s[i]]++;
            tCount[t[i]]++;
        }
        for (char c = 'a'; c < 26 + 'a'; c++){
            // printf("%c %i %i\n", c, sCount[c], tCount[c]);
            if (sCount[c] != tCount[c]) return false;
        }
        return true;
    }
};