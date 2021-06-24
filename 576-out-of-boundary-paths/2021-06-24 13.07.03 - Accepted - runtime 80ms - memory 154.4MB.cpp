class Solution {
    constexpr int modulo() {
        return pow(10,9) + 7;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long>>> dp(51,vector<vector<long>>(50,vector<long>(50,0)));
        const int mod = modulo();
        for(int i = 1;i <= maxMove;++i) {
            for(int j = 0;j < m;++j) {
                for(int k = 0;k < n;++k) {
                    dp[i][j][k] = ((j == 0? 1:dp[i-1][j-1][k])%mod + (j == m-1? 1:dp[i-1][j+1][k])%mod +
                                  (k == 0? 1:dp[i-1][j][k-1])%mod + (k == n-1? 1:dp[i-1][j][k+1])%mod)%mod;
                }
            }
        }
        
        return dp[maxMove][startRow][startColumn];
    }
};