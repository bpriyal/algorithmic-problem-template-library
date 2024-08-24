class MaxStack {
    set<pair<int, int>> stack;
    set<pair<int, int>> values;
    int count;
public:
    MaxStack() {
      count = 0;
    }
    
    void push(int x) {
      stack.emplace(count, x);
      values.emplace(x, count);
      ++count;
    }
    
    int pop() {
      auto it = std::prev(stack.end());
      values.erase({(*it).second, (*it).first});
      auto result = (*it).second;
      stack.erase(it);
      return result;
    }
    
    int top() {
      return stack.rbegin()->second;
    }
    
    int peekMax() {
      return values.rbegin()->first;
    }
    
    int popMax() {
      auto it = std::prev(values.end());
      stack.erase({(*it).second, (*it).first});
      auto result = (*it).first;
      values.erase(it);
      return result;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */