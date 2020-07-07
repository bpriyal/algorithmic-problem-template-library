class Solution {
    int rows,cols;
    int util(const vector<vector<int>> &grid,int row,int col) {
        int count = 0;
        if (row - 1 < 0 || !grid[row-1][col]) ++count;
        if (row + 1 >= rows || !grid[row+1][col]) ++count;
        if (col - 1 < 0 || !grid[row][col-1]) ++count;
        if (col + 1 >= cols || !grid[row][col+1]) ++count;
        return count;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int perimeter = 0;
        for (int i = 0;i<rows;++i) {
            for(int j = 0;j<cols;++j) {
                if (grid[i][j]) {
                    perimeter += util(grid,i,j);
                }
            }
        }
        return perimeter;
    }
};