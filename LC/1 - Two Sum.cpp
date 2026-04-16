#include <map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> ans;
        for (int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];
            if (ans.count(rem)) {return {ans[rem], i};}
            ans[nums[i]] = i;
        }
        return {0,0};
    }
};