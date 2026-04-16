#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> ans;
        std::vector<bool> seen(strs.size(), false);
        for (int i = 0; i < strs.size(); i++){
            if (seen[i]) continue;
            std::vector<std::string> temp;

            temp.push_back(strs[i]);
            seen[i] = true;
            for (int j = 1 + i; j < strs.size(); j++){
                if (seen[j]) continue;
                if (isAnagram(strs[i], strs[j])){
                    temp.push_back(strs[j]);
                    seen[j] = true;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }

    bool isAnagram(std::string base, std::string curr){
        std::map<char,int> freq;
        for(char c : base) {
            freq[c]++;
        }
        for(char c : curr){
            freq[c]--;
        }
        for(auto x : freq) {
            if(x.second != 0) {
                return false;
            }
        }
        return true;
    }
};