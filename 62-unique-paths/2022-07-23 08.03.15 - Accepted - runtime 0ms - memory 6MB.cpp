class Solution {
    vector<vector<int>> dp;
    int util(int m, int n, int i, int j) {
        if (i >= m || j >= n) return 0;
        
        if (i == m - 1 && j == n - 1) return 1;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        dp[i][j] = util(m, n, i + 1, j) + util(m, n, i, j + 1);
        
        return dp[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        vector<int> cache(n, 1);
                
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                cache[j] = cache[j] + cache[j-1];
            }
        }
        
        return cache[n-1];
    }
};