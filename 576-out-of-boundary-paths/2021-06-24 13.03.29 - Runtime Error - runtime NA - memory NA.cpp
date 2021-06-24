class Solution {
    constexpr int mod() {
        return pow(10,9) + 7;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(51,vector<vector<int>>(50,vector<int>(50,0)));
        
        for(int i = 1;i <= maxMove;++i) {
            for(int j = 0;j < m;++j) {
                for(int k = 0;k < n;++k) {
                    dp[i][j][k] = ((j == 0? 1:dp[i-1][j-1][k]) + (j == m-1? 1:dp[i-1][j+1][k]) +
                                  (k == 0? 1:dp[i-1][j][k-1]) + (k == n-1? 1:dp[i-1][j][k+1]))%mod();
                }
            }
        }
        
        return dp[maxMove][startRow][startColumn];
    }
};