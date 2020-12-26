class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if (size == 0 || s[0] == '0') {
            return 0;
        }
        vector<int> dp(size+1,0);
        dp[0] = dp[1] = 1;
        
        for(int i = 2;i <= size;++i) {
            if (s[i-1] != 0) {
                dp[i] = dp[i-1];
            }
            
            if (s[i-2] == 1 || (s[i-2] == 2 && s[i-1] < 7)) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[size];
    }
};