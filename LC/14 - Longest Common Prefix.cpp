#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (!strs.size()) return "";

        std::string cmpstr = strs[0];
        std::string tmpstr = "";
        for (int i = 1; i < strs.size(); i++){
            tmpstr = "";
            for(int j = 0; j < std::fmin(cmpstr.size(), strs[i].size()); j++){
                if (cmpstr[j] == strs[i][j]){
                    tmpstr += strs[i][j];
                    continue;
                }
                if (!tmpstr.size()) return "";
                break;
            }
            cmpstr = tmpstr;
        }
        return cmpstr;
    }
};