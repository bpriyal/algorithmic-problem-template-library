class Solution {
    int rows, cols;

    void flip1s(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') return;
        grid[row][col] = '0';
        flip1s(grid, row + 1, col);
        flip1s(grid, row - 1, col);
        flip1s(grid, row, col + 1);
        flip1s(grid, row, col - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        rows = grid.size();
        cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++islands;
                    flip1s(grid, i, j);
                }
            }
        }

        return islands;
    }
};