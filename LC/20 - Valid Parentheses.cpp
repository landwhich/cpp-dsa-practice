#include <map>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.size() % 2) return false;
        std::stack<char> buff;
        std::unordered_map<char, char> para = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        for (int i = 0; i < s.size(); i++){
            // std::cout << s[i];
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') buff.push(s[i]);
            else if (buff.empty()) return false;
            else if (para[s[i]] == buff.top()) buff.pop();
            else {return false;}
        }
        return (buff.empty() ? true : false);
    }
};