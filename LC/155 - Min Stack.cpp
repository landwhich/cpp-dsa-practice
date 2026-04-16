#include <stack>

class MinStack {
    std::stack<std::pair<int, int>> _data;
    int _min;
public:
    MinStack(){}

    void push(int val) {
        _min = _data.empty() ? val : (_min < val ? _min : val);
        _data.push({val, _min});
    }

    void pop() {
        if (_data.empty()) return;
        std::pair<int,int> top = _data.top();
        _data.pop();
        if (top.second == _min && !_data.empty()) _min = _data.top().second;
    }

    int top() {
        return _data.top().first;
    }
    
    int getMin() {
        return _data.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */