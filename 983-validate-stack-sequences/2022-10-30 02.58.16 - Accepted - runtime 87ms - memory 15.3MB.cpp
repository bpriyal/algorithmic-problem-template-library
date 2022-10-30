class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int size = pushed.size();
        stack<int> st;
        int i = 0, j = 0;
        
        while (true) {
            if (st.empty() && i == size && j == size) return true;
            if (st.empty() || st.top() != popped[i]) {
                if (j == size) return false;
                cout<<"pushing: "<<pushed[j]<<endl;
                st.push(pushed[j++]);
            } else {
                cout<<"popping: "<<st.top()<<", popped[i] was: "<<popped[i]<<endl;
                st.pop();
                ++i;
            }
        }
        
        return st.empty();
    }
};