class Solution {
    int rows, cols;
    int columnBinarySearch(const vector<vector<int>>& matrix, int target, int row) {
      int left = 0, right = cols - 1;
      cout << row << endl;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (matrix[row][mid] == target) return true;
        else if (matrix[row][mid] < target) left = mid + 1;
        else right = mid - 1;
      }
      return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      rows = matrix.size();
      cols = matrix[0].size();

      int topRow = 0, bottomRow = rows - 1;

      while (topRow <= bottomRow) {
        int mid = topRow + (bottomRow - topRow) / 2;
        if (target >= matrix[mid][0] && target <= matrix[mid][cols - 1]) {
          return columnBinarySearch(matrix, target, mid);
        } else if (target > matrix[mid][cols - 1]) topRow = mid + 1;
        else bottomRow = mid - 1;
      }
      return false;
    }
};