class Solution {
    int rows, cols;
    const vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool isValidMove(const vector<vector<char>>& grid, int row, int col) {
      return row >= 0 && row < rows && col >= 0 && col < cols && (grid[row][col] == '#' || grid[row][col] == 'O');
    }
    int bfs(vector<vector<char>>& grid, int row, int col) {
      queue<pair<int, int>> q;
      q.emplace(make_pair(row, col));
      int distance = 0;

      while (!q.empty()) {
        int size = q.size();
        ++distance;
        for (int i = 0; i < size; ++i) {
          auto [r, c] = q.front();
          q.pop();
          
          for (auto& d : dir) {
            int newRow = r + d[0];
            int newCol = c + d[1];
            if (isValidMove(grid, newRow, newCol)) {
              if (grid[newRow][newCol] == '#') return distance;
              grid[newRow][newCol] = 'X';
              q.emplace(make_pair(newRow, newCol));
            }
          }
        }
      }
      return -1;
    }
public:
    int getFood(vector<vector<char>>& grid) {
      rows = grid.size();
      cols = grid[0].size();
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
          if (grid[i][j] == '*') {
            return bfs(grid, i, j);
          }
        }
      }
      return -1;
    }
};