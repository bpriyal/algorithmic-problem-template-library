class Solution {
    int n;
    unordered_map<int, int> idToSizeMap;
    int dfs(vector<vector<int>>& grid, int row, int col, int id) {
      if (row < 0 || row == n || col < 0 || col == n || grid[row][col] != 1) return 0;
      grid[row][col] = id;
      return dfs(grid, row + 1, col, id) +
             dfs(grid, row - 1, col, id) + 
             dfs(grid, row, col + 1, id) + 
             dfs(grid, row, col - 1, id) + 1;
    }
    int checkVicinity(vector<vector<int>>& grid, int row, int col) {
      unordered_set<int> ids;
      auto getIds = [&](int row, int col) {
        if (row < 0 || row == n || col < 0 || col == n || grid[row][col] == 0) return;
        ids.emplace(grid[row][col]);
      };
      getIds(row + 1, col);
      getIds(row - 1, col);
      getIds(row, col + 1);
      getIds(row, col - 1);
      int result = 0;
      for (const auto& id : ids) result += idToSizeMap[id];
      return result;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
      n = grid.size();
      int islandId = 2;
      int result = 0;

      // calculate island sizes, mark them with id and store the id -> size in a map
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 1) {
            idToSizeMap.emplace(islandId, dfs(grid, i, j, islandId));
            result = max(result, idToSizeMap[islandId]);
            ++islandId;
          }
        }
      }

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 0) {
            result = max(result, checkVicinity(grid, i, j) + 1);
          }
        }
      }

      return result;
    }
};