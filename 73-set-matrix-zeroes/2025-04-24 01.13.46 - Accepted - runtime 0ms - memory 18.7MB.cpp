class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int rows = matrix.size();
      int cols = matrix[0].size();

      bool isFirstRowZero = false;
      bool isFirstColZero = false;
      for (int i = 0; i < cols; ++i) if (matrix[0][i] == 0) { isFirstRowZero = true; break; }
      for (int i = 0; i < rows; ++i) if (matrix[i][0] == 0) { isFirstColZero = true; break; }

      for (int r = 1; r < rows; ++r) {
        for (int c = 1; c < cols; ++c) {
          if (matrix[r][c] == 0) {
            matrix[r][0] = 0;
            matrix[0][c] = 0;
          }
        }
      }

      for (int i = 1; i < cols; ++i) {
        if (matrix[0][i] == 0) {
          for (int j = 1; j < rows; ++j) matrix[j][i] = 0;
        }
      }

      for (int i = 1; i < rows; ++i) {
        if (matrix[i][0] == 0) {
          for (int j = 1; j < cols; ++j) matrix[i][j] = 0;
        }
      }

      if (isFirstRowZero) {
        for (int i = 0; i < cols; ++i) matrix[0][i] = 0;
      }

      if (isFirstColZero) {
        for (int i = 0; i < rows; ++i) matrix[i][0] = 0;
      }
    }
};