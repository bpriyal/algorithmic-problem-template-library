class Solution {
    vector<vector<int>> dp;
    int util(int m , int n, int row, int col) {
      if (row >= m || col >= n) return 0;
      if (row == m - 1 && col == n - 1) return 1;
      if (dp[row][col] != -1) return dp[row][col];
      dp[row][col] = util(m, n, row + 1, col) + util(m, n, row, col + 1);
      return dp[row][col];
    }
public:
    int uniquePaths(int m, int n) {
      dp.resize(m, vector<int>(n, -1));
      return util(m, n, 0, 0);
    }
};