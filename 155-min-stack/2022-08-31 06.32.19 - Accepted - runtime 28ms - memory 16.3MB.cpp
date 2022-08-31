class MinStack {
    stack<pair<int, int>> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int _min = INT_MAX;
        if (s.empty()) _min = val;
        else {
            _min = min(val, s.top().second);
        }
        
        s.push(std::make_pair(val, _min));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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