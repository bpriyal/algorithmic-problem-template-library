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
        
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        dp.resize(row,vector<int>(col,-1));
        
        util(obstacleGrid,0,0);
        
        return dp[0][0];
    }
};