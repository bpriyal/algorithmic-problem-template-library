class Solution {
    int rows, cols;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
      rows = mat.size();
      cols = mat[0].size();
      int direction = 1;
      int row = 0, col = 0;
      vector<int> result;

      while (row < rows && col < cols) {
        if (direction == 1) { // Upwards
          int i = row, j = col;
          while (i >= 0 && j < cols) result.emplace_back(mat[i--][j++]);
          ++i, --j; // reset to tail cell
          if (j == cols - 1) {
            row = i + 1;
            col = j;
          } else {
            row = i;
            col = j + 1;
          }
        } else {
          int i = row, j = col;
          while (i < rows && j >= 0) result.emplace_back(mat[i++][j--]);
          --i, ++j; // reset to tail cell
          if (i == rows - 1) {
            row = i;
            col = j + 1;
          } else {
            row = i + 1;
            col = j;
          }
        }
        direction = 1 - direction;
      }

      return result;
    }
};