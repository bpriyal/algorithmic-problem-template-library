class Solution {
public:
    vector<vector<int>> cost;
    int row,col;
    void init(int rows,int cols){
        row=rows;
        col=cols;
        cost.resize(row,vector<int>(col,0));
    }
    
    int min(int a,int b) {
        return (a > b)? b:a;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        init(rows,cols);
        cost[0][0] = grid[0][0];
        for(int i=1;i<row;++i) {
            cost[i][0] = cost[i-1][0] + grid[i][0];
        }
        for(int i=1;i<col;++i) {
            cost[0][i] =cost[0][i-1] + grid[0][i];
        }
        
        for (int i=1;i<row;++i) {
            for (int j=1;j<col;++j) {
                cost[i][j] = grid[i][j] + min(cost[i-1][j],cost[i][j-1]);
            }
        }
        
        /*for (int i=0;i<row;++i) {
            cout<<endl;
            for (int j=0;j<col;++j) {
                cout<<cost[i][j]<<" ";
            }
        }*/
        
        return cost[row-1][col-1];
    }
};