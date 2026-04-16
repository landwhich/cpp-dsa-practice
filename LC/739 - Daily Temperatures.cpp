#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<std::pair<int,int>> s = {};

        int len = static_cast<int>(temperatures.size());
        std::vector<int> ans(len, 0);

        s.push({temperatures[len - 1], len - 1});
        for (int i{len - 2}; i >= 0; --i){
            
            while (!s.empty() && temperatures[i] >= s.top().first) s.pop();

            if (!s.empty()) ans[i] = s.top().second - i;
            
            s.push({temperatures[i], i});
        }
        return ans;
    }
};