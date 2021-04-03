class Solution {
    bool isValid(const string &s) {
        stack<int> st;
        
        for(char c:s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        int result = 0;
        for(int i = 0;i < size;++i) {
            for(int j = 2;j <= size;j+=2) {
                if (isValid(s.substr(i,j))) {
                    result = max(result,j);
                }
            }
        }
        
        return result;
    }
};