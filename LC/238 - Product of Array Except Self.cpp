#include <vector>
#include <map>



class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<int> left(size);
        std::vector<int> right(size);
        left[0] = nums[0];
        right[size - 1] = nums[size - 1];
        
        // map<int, int> lut;
        bool zero = false;

        for (int i = 1; i < size; i++){
            if (nums[i] == 0){
            // optimize w zero handling
                if (zero) {std::vector<int> zeroAns(nums.size(), 0); return zeroAns;}
                zero = true;
                continue;
            }
            left[i] = nums[i] * left[i - 1];
        }
        for (int i = size - 2; i > 0; i--){
            if (nums[i] == 0) continue;
            right[i] = nums[i] * right[i + 1];
        }

        std::vector<int> ans(size); 
        ans[0] = right[1];
        ans[size - 1] = left[size - 2];
        for (int i = 1; i < size - 1; i++){
            // if (lut.count(nums[i])) {ans[i] = lut[nums[i]]; continue;}
            ans[i] = left[i - 1] * right[i + 1];
            // lut[nums[i]] = ans[i];
        }
        return ans;
    }
};