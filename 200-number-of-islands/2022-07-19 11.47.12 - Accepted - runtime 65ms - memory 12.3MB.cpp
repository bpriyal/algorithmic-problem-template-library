class Solution {
    int row, col;
    void util(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0') return;
        grid[i][j] = '0';
        
        util(grid, i - 1, j);
        util(grid, i + 1, j);
        util(grid, i, j - 1);
        util(grid, i, j + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        
        int result = 0;
        
        for(int i = 0;i < row;++i) {
            for(int j = 0;j < col;++j) {
                if (grid[i][j] == '1') {
                    ++result;
                    util(grid, i, j);
                }
            }
        }
        
        return result;
    }
};