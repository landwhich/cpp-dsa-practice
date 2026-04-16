#include <stack>

class Solution {
public: 
    std::stack<int> _data;
    int evalRPN(std::vector<std::string>& tokens) {
    for (int i = 0; i < tokens.size(); i++){
    unsigned char c = static_cast<unsigned char>(tokens[i][0]);
    if (std::isalnum(c) || tokens[i].size() > 1){
        _data.push(std::stoi(tokens[i]));
    }
    else { 
        int a = _data.top(); _data.pop();
        int b = _data.top(); _data.pop();
        switch (c){
        case '+':
        _data.push(a + b);
        break;
        case '-':
        _data.push(b - a);
        break;
        case '*':
        _data.push(a * b);
        break;
        case '/':
        _data.push(b / a);
        break;
    }}}
    return _data.top();
    }
};