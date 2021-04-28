class Solution {
    int row,col;
    int result;
    void util(const vector<vector<int>>& obstacleGrid,int i,int j) {
        if (i >= row || j >= col || obstacleGrid[i][j] == 1) {
            return;
        }
        
        if (i == row - 1 && j == col - 1) {
            ++result;
        }
        
        util(obstacleGrid,i+1,j);
        util(obstacleGrid,i,j+1);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        row = obstacleGrid.size();
        col = obstacleGrid[0].size();
        result = 0;
        
        util(obstacleGrid,0,0);
        
        return result;
    }
};