#include <map>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::map<int, int> ans;
        for (int i = 0; i < nums.size(); i++){
            int key = nums[i];
            // printf("%i", ans[key]);
            if (ans[key] == 1){
                return true;
            }
            ans[key]++;
        }
        return false;
    }
};