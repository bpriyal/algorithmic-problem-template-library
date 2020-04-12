class MinStack {
public:
    /** initialize your data structure here. */
    
    signed long stack[10000];
    int end;
    signed long min;
    
    MinStack() {
        end=-1;
    }
    
    void push(int x) {
        ++end;
        if (end == 0){
            stack[end]= x;
            min=x;
        } else{
            if (x >= min){
                stack[end]= x;
            } else {
                stack[end] = 2*x-min;
                min = x;
            }
        }
    }
    
    void pop() {
        if (end != -1){
            if (stack[end] >= min){
            } else {
                min = 2*min-stack[end];
            }
            --end;
        }
    }
    
    int top() {
        if (end != -1){
            if (stack[end] >= min){
                return stack[end];
            } else {
                return min;
            }
        }
        return -1;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */