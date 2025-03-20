class Solution {
  int shortestPath = INT_MAX;
  int size;
  vector<vector<bool>> visited;
  void util(const vector<vector<int>>& grid, int r, int c, int nodes) {
    if (r < 0 || r >= size || c < 0 || c >= size || visited[r][c] || grid[r][c] == 1) return;
    if (r == size - 1 && c == size - 1) shortestPath = min(shortestPath, nodes);
    visited[r][c] = true;

    util(grid, r + 1, c - 1, nodes + 1);
    util(grid, r + 1, c    , nodes + 1);
    util(grid, r + 1, c + 1, nodes + 1);
    util(grid, r - 1, c - 1, nodes + 1);
    util(grid, r - 1, c    , nodes + 1);
    util(grid, r - 1, c + 1, nodes + 1);
    util(grid, r    , c - 1, nodes + 1);
    util(grid, r    , c + 1, nodes + 1);

    visited[r][c] = false;
  }
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    size = grid.size();
    visited.resize(size, vector<bool>(size, false));
    util(grid, 0, 0, 1);
    return shortestPath == INT_MAX ? -1 : shortestPath;
  }
};