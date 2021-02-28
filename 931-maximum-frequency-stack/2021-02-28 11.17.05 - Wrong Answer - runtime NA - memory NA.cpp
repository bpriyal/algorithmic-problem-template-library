class FreqStack {
    vector<int> cache;
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        cache.push_back(x);
    }
    
    int pop() {
        int temp = cache.back();
        cache.pop_back();
        return temp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */