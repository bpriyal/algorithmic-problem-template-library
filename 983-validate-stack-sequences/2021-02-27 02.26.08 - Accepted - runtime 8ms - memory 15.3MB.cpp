class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int size = pushed.size();
        stack<int> st;
        int currPushed = 0;
        for(int ele:popped) {
            if (!st.empty() && st.top() == ele) {
                st.pop();
                continue;
            }
            while (currPushed < size && pushed[currPushed] != ele) {
                st.push(pushed[currPushed]);
                ++currPushed;
            }
            if (currPushed < size) {
                ++currPushed;
            } else {
                return false;
            }
        }
        return true;
    }
};