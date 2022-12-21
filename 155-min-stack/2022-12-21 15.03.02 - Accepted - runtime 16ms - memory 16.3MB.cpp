class MinStack {
    stack<pair<int, int>> cache;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (cache.empty()) cache.emplace(val, val);
        else cache.emplace(val, min(cache.top().second, val));
    }
    
    void pop() {
        cache.pop();
    }
    
    int top() {
        return cache.top().first;
    }
    
    int getMin() {
        return cache.top().second;
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