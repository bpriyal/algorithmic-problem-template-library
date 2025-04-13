class Solution {
    inline static vector<pair<int, int>> offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    int n;
    bool isValid(const vector<vector<int>>& grid, int row, int col) {
      return row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      n = grid.size();
      queue<pair<int, int>> q;
      
      if (grid[0][0] == 0) {
        q.emplace(0, 0);
        grid[0][0] = 1;
      }
      int depth = 1;

      while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
          auto [row, col] = q.front();
          q.pop();
          if (row == n - 1 && col == n - 1) return depth;

          for (const auto& offset : offsets) {
            int newRow = row + offset.first;
            int newCol = col + offset.second;
            if (isValid(grid, newRow, newCol)) {
              grid[newRow][newCol] = 1;
              q.emplace(newRow, newCol);
            }
          }
        }
        ++depth;
      }
      return -1;
    }
};