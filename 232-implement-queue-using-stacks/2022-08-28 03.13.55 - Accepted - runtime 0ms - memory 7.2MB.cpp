class MyQueue {
    stack<int> s1;
    stack<int> s2;
    int size;
    
    void peepPopHelper() {
        if (s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
public:
    MyQueue() {
        size = 0;
    }
    
    void push(int x) {
        s1.push(x);
        ++size;
    }
    
    int pop() {
        peepPopHelper();
        --size;
        int result = s2.top();
        s2.pop();
        return result;
    }
    
    int peek() {
        peepPopHelper();
        return s2.top();
    }
    
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */