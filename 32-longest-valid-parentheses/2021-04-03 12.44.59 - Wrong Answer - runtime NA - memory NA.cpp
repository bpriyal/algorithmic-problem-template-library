class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        stack<char> st;
        int result = 0;
        int maxResult = 0;
        for(char c:s) {
            if (c == '(') {
                st.push(c);
                ++result;
            } else {
                if (!st.empty()) {
                    st.pop();
                    ++result;
                } else {
                    maxResult = max(result,maxResult);
                    result = 0;
                }
            }
        }
        int temp = result - st.size();
        return max(maxResult,temp);
    }
};