class Solution {
    int rows, cols;
    vector<vector<int>> dp;
    int util(vector<vector<int>>& grid, int i, int j, int run) {
        if (i >= rows || j >= cols || i < 0 || j < 0 || grid[i][j] == 0 || grid[i][j] == -1 || dp[i][j] == INT_MAX) return INT_MAX;
        
        if (grid[i][j] == 2) {
            return run;
        }
        
        if (dp[i][j] != 0) return dp[i][j] + 1;
        
        grid[i][j] = -1;
        
        int a = util(grid, i + 1, j, run + 1);
        int b = util(grid, i - 1, j, run + 1);
        int c = util(grid, i, j + 1, run + 1);
        int d = util(grid, i, j - 1, run + 1);
        
        int res = min({a, b, c ,d});
        
        grid[i][j] = 1;
        dp[i][j] = res;
        
        return res;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        dp.resize(rows, vector<int>(cols, 0));
        
        int result = 0;
        
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    result = max(result, util(grid, i, j, 0));
                    if (result == INT_MAX) return -1;
                }
            }
        }
        
        return result;
    }
};