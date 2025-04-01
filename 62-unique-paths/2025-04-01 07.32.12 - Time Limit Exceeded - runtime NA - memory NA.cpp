class Solution {
    int result = 0;
    void util(int m , int n, int row, int col) {
      if (row >= m || col >= n) return;
      if (row == m - 1 && col == n - 1) ++result;
      util(m, n, row + 1, col);
      util(m, n, row, col + 1);
    }
public:
    int uniquePaths(int m, int n) {
      util(m, n, 0, 0);
      return result;
    }
};