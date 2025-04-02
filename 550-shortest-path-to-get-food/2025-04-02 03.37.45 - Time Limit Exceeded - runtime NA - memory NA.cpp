class Solution {
    int rows, cols;
    bool isValidMove(const vector<vector<char>>& grid, int row, int col) {
      return row >= 0 && row < rows && col >= 0 && col < cols && (grid[row][col] == 'O' || grid[row][col] == '#');
    }
    int bfs(vector<vector<char>>& grid, int row, int col) {
      // cout << row <<", " << col << endl;
      queue<pair<int, int>> q;
      q.emplace(make_pair(row, col));
      int distance = 0;

      while (!q.empty()) {
        int size = q.size();
        // cout << "size: " << size << endl;
        for (int i = 0; i < size; ++i) {
          auto [r, c] = q.front();
          if (grid[r][c] == '#') return distance;
          q.pop();
          grid[r][c] = 'X';
          // cout << "r: " << r << ", c: " << c << endl;
          if (isValidMove(grid, r + 1, c)) q.emplace(make_pair(r + 1, c));
          if (isValidMove(grid, r - 1, c)) q.emplace(make_pair(r - 1, c));
          if (isValidMove(grid, r, c + 1)) q.emplace(make_pair(r, c + 1));
          if (isValidMove(grid, r, c - 1)) q.emplace(make_pair(r, c - 1));
          // cout << q.size() << endl;
        }
        ++distance;
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