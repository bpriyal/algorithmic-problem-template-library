class Solution {
    vector<pair<int, int>> directions = {make_pair(-1, -1), make_pair(-1, 0), make_pair(-1, 1), make_pair(0, -1), make_pair(0, 1), make_pair(1, -1), make_pair(1, 0), make_pair(1, 1)};
    int size;
    bool isValid(const vector<vector<int>>& grid, int r, int c) {
      return r >= 0 && r < size && c >= 0 && c < size && grid[r][c] == 0;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      size = grid.size();
      queue<pair<int, int>> q;

      if (grid[0][0] == 0) {
        q.emplace(0, 0);
        grid[0][0] = 1;
      }

      while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();
        int distance = grid[row][col];

        for (const auto& [r, c] : directions) {
          int er = row + r;
          int ec = col + c;
          if (isValid(grid, er, ec)) {
            if (er == size - 1 && ec == size - 1) return distance + 1;
            grid[er][ec] = distance + 1;
            q.emplace(er, ec);
          }
        }
      }

      return -1;
    }
};