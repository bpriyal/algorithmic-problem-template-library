class FreqStack {
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> group;
    int maxFreq;
public:
    FreqStack() {
        maxFreq = INT_MIN;
    }
    
    void push(int x) {
        auto it = freq.find(x);
        if (it != freq.end()) {
            ++freq[x];
        } else {
            freq[x] = 1;
        }
        
        if (freq[x] > maxFreq) {
            maxFreq = freq[x];
        }
        
        auto it1 = group.find(freq[x]);
        if (it1 != group.end()) {
            group[freq[x]].push(x);
        } else {
            stack<int> st;
            st.push(x);
            group[freq[x]] = st;
        }
    }
    
    int pop() {
        int temp = group[maxFreq].top();
        group[maxFreq].pop();
        --freq[temp];
        if (group[maxFreq].empty()) {
            --maxFreq;
        }
        return temp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */