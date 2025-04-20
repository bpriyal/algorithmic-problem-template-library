class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
      int m = mat.size();
      int n = mat[0].size();
      int row = 0, col = 0;
      int direction = 1; // up
      vector<int> result;

      while (row < m && col < n) {
        int r = row, c = col;
        if (direction == 1) { // up
          while (r >= 0 && c < n) {
            result.emplace_back(mat[r][c]);
            --r;
            ++c;
          }
          ++r; --c; // reset to last pos
          if (c != n - 1) ++c;
          else ++r;
        } else { // down
          while (r < m && c >= 0) {
            result.emplace_back(mat[r][c]);
            ++r;
            --c;
          }
          --r; ++c;
          if (r == m - 1) ++c;
          else ++r;
        }
        row = r;
        col = c;
        direction = 1 - direction;
      }

      return result;
    }
};