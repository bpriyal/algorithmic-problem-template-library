class Solution {
    int util(int m , int n, int row, int col) {
      if (row >= m || col >= n) return 0;
      if (row == m - 1 && col == n - 1) return 1;
      return util(m, n, row + 1, col) + util(m, n, row, col + 1);
    }
public:
    int uniquePaths(int m, int n) {
      return util(m, n, 0, 0);
    }
};