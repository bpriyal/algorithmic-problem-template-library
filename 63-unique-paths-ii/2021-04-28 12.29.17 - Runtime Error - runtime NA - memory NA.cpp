class Solution {
    int row,col;
    int result;
    vector<vector<int>> dp;
    int util(const vector<vector<int>>& obstacleGrid,int i,int j) {
        if (i >= row || j >= col || obstacleGrid[i][j] == 1) {
            return 0;
        }
        
        if (i == row - 1 && j == col - 1) {
            dp[i][j] = 1;
            return dp[i][j];
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        dp[i][j] = util(obstacleGrid,i+1,j) + util(obstacleGrid,i,j+1);
        
        return dp[i][j];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        row = obstacleGrid.size();
        col = obstacleGrid[0].size();
        result = 0;
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[row-1][col-1] == 1) {
            return 0;
        }
        
        dp.resize(row,vector<int>(col,0));
        
        /*util(obstacleGrid,0,0);
        
        return dp[0][0];*/
        
        dp[row-1][col-1] = 1;
        
        for(int i = row - 1;i >= 0;--i) {
            for(int j = col - 1;j >= 0;--j) {
                if (obstacleGrid[i][j] == 0 && !(i == row-1 && j == col-1)) {
                    //cout<<"here"<<endl;
                    dp[i][j] = ((i+1 < row && j < col && obstacleGrid[i+1][j] == 0)? dp[i+1][j] : 0) +
                               ((i < row && j+1 < col && obstacleGrid[i][j+1] == 0)? dp[i][j+1] : 0);
                }
            }
        }
        
        return dp[0][0];
    }
};