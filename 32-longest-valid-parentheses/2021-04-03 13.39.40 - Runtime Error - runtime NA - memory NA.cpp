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
        /*int result = 0;
        for(int i = 0;i < size;++i) {
            for(int j = 2;i+j <= size;j+=2) {
                if (s[i+j-1] == ')' && isValid(s.substr(i,j))) {
                    result = max(result,j);
                }
            }
        }*/
        vector<int> dp(size,0);
        int result = 0;
        for(int i = 1;i < size;++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >=2 ?dp[i-2]:0) + 2;
                } else if (i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
                    dp[i] = dp[i-dp[i-1]-2]+dp[i-1]+2;
                }
                result = max(result,dp[i]);
            }
        }
        return result;
    }
};