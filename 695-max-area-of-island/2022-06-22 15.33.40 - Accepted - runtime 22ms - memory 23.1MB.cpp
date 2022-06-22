class Solution {
    int row, col;
    int util(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= row || c  < 0 || c >= col || grid[r][c] == 0 || grid[r][c] == -1) {
            return 0;
        }
        
        grid[r][c] = -1;
        
        return 1 + util(grid, r + 1, c) + util(grid, r - 1, c) + util(grid, r, c + 1) + util(grid, r, c - 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int result = 0;
        
        for(int i = 0;i < row;++i) {
            for(int j = 0;j < col; ++j) {
                if (grid[i][j] != 0 || grid[i][j] != -1) {
                    result = max(result, util(grid, i, j));
                }
            }
        }
        
        return result;
    }
};