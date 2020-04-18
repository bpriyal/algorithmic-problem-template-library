class Solution {
public:
    //vector<vector<int>> cost;
    int row,col;
    void init(int rows,int cols){
        row=rows;
        col=cols;
        //cost.resize(row,vector<int>(col,-1));
    }
    
    int min(int a,int b) {
        return (a > b)? b:a;
    }
    
    int Min_cost(const vector<vector<int>> grid, int m, int n){
        if (n<0 || m<0) return INT_MAX;
        if (n==0 && m==0) return grid[0][0];
        return grid[m][n] + min (Min_cost(grid,m,n-1),Min_cost(grid,m-1,n));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        init(rows,cols);
        //cost[0][0] = grid[0][0];
        return Min_cost(grid,row-1,col-1);
    }
};