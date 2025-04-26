class Solution {
    int rows, cols;
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      rows = matrix.size();
      cols = matrix[0].size();
      int top = 0, bottom = rows - 1;
      while (top <= bottom) {
        int mid = top + (bottom - top) / 2;
        if (target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size() - 1]) {
          return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
        } else if (target < matrix[mid][0]) bottom = mid - 1;
        else top = mid + 1;
      }
      return false; 
    }
};