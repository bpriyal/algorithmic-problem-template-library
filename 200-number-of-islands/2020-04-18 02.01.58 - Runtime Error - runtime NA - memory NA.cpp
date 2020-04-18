class Solution {
    void dfsUtil(const vector<vector<char>> grid,int i, int j){
        visited[i][j] = true;
        if (i!=0 && grid[i-1][j]=='1' && visited[i-1][j]==false) {
            dfsUtil(grid,i-1,j);
        }
        if (i!=row-1 && grid[i+1][j]=='1' && visited[i+1][j]==false){
            dfsUtil(grid,i+1,j);
        }
        if (j!=0 && grid[i][j-1]=='1' && visited[i][j-1]==false){
            dfsUtil(grid,i,j-1);
        }
        if (j!=col-1 && grid[i][j+1]=='1' && visited[i][j+1]==false){
            dfsUtil(grid,i,j+1);
        }
    }
public:
    bool visited[100][100] = {false};
    int row,col;
    void init(int rows,int cols){
        row=rows;
        col=cols;
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        init(rows,cols);
        int i,j,count=0;
        for (i=0;i<row;++i) {
            for (j=0;j<col;++j){
                if (grid[i][j]=='1' && visited[i][j]==false){
                    count++;
                    dfsUtil(grid,i,j);
                }
            }
        }
        return count;
    }
};