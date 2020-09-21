class Solution {
    int row,col;
    void util(vector<vector<int>>& grid, int i, int j,int nonObs,int &count) {
       // printf("%d||%d||%d||%d\n",i,j,grid[i][j],nonObs);
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == -1) {
            return;
        }
        if (grid[i][j] == 2) {
            if (nonObs == 0) {
                ++count;
            }
            return;
        }
        
        --nonObs;
         grid[i][j] = -1;
        
        util(grid,i+1,j,nonObs,count);
        util(grid,i-1,j,nonObs,count);
        util(grid,i,j+1,nonObs,count);
        util(grid,i,j-1,nonObs,count);
        grid[i][j] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int r,c,nonObs=0;
        for(int i = 0;i<row;++i) {
            for(int j =0;j<col;++j) {
                if (grid[i][j] == 1) {
                    r = i;
                    c = j;
                } else if (grid[i][j] != -1) {
                    ++nonObs;
                }
            }
        }
        int count = 0;
        util(grid,r,c,nonObs,count);
        return count;
    }
};