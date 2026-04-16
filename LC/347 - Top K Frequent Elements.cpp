#include <vector>
#include <map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
            std::priority_queue<std::pair<int,int>>pq;
    std::map<int,int>map_nums;
    std::vector<int>res;


    for(int i=0;i<nums.size();i++)
    {
        map_nums[nums[i]]++;
    }


    for(auto i=map_nums.begin();i!=map_nums.end();i++)
    {
        pq.push(std::make_pair(i->second,i->first));
    }

    for(int i=0;i<k;i++)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
    }
};