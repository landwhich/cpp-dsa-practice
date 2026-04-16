#include <map>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_map<int, int> eos;
        int ans = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            int currLen = 1;
            if (eos.count(nums[i])) currLen = eos[nums[i]] + 1;
            ans = std::fmax(ans,currLen);
            eos[nums[i] + 1] = currLen;
        }
        return ans;
    }
};