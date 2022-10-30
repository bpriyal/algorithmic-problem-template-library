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
                st.push(pushed[j++]);
            } else {
                st.pop();
                ++i;
            }
        }
        
        return st.empty();
    }
};