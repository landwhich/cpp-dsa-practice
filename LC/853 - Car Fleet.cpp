#include <stack>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    std::vector<std::pair<int,int>> cars;
    for (int i = 0; i < position.size(); i++) { cars.push_back({position[i], speed[i]}); }
    // sort by desc
    sort(cars.begin(), cars.end(), [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
        return a.first < b.first;
    });
    std::stack<std::pair<int,int>> s;
    for (auto& car : cars) { s.push(car); }

    int ans{0};
    float prevTime{ std::numeric_limits<float>::min() };
    // core loop
    while (!s.empty()){
        float timeToFinish = (target - s.top().first) / static_cast<float>(s.top().second);
        if (timeToFinish > prevTime){ prevTime = timeToFinish; ++ans; } 
        s.pop();
    }
    return ans;
    }
};