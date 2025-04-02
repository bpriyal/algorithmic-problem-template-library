class Solution {
    int rows, cols;
    void util(vector<vector<char>>& grid, int row, int col) {
      if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') return;
      grid[row][col] = '0';
      util(grid, row + 1, col);
      util(grid, row, col + 1);
      util(grid, row - 1, col);
      util(grid, row, col - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
      // graph problem
      rows = grid.size();
      cols = grid[0].size();
      int islands = 0;

      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
          if (grid[i][j] == '1') {
            ++islands;
            util(grid, i, j);
          }
        }
      }
      return islands; 
    }
};