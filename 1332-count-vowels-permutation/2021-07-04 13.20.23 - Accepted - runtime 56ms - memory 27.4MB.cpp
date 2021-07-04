class Solution {
public:
    int countVowelPermutation(int n) {
        const int m = 5;// total of vowels;
        const int kMod = 1e9 + 7;
        vector<vector<long int> > dp(n, vector<long int>(m,1));        
        for(int i = 1; i < n; i++)
            for(int j = 0; j < m; j++){
                if(j ==0) dp[i][j] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4]) % kMod;
                else if(j == 1) dp[i][j] = (dp[i-1][0] + dp[i-1][2]) % kMod;
                else if(j == 2) dp[i][j] = (dp[i-1][1] + dp[i-1][3]) % kMod;
                else if(j == 3) dp[i][j] = dp[i-1][2];
                else if(j == 4) dp[i][j] = (dp[i-1][2] + dp[i-1][3])% kMod;
            }
        
        int ans = 0;
        for(auto e: dp.back())
            ans = (ans + e) % kMod;
        return ans;
    }
};