class Solution {
    vector<vector<int>> dp;
    int row,col;
    
    int util(const vector<vector<int>> &matrix,int i,int j,int last) {
        if (i >= row || i < 0 || j >= col || j < 0 || last >= matrix[i][j]) {
            return 0;
        }
        if (dp[i][j] != 0) {
            return dp[i][j] + 1;
        }
        
        int _max = 1;
        _max = max(_max,util(matrix,i+1,j,matrix[i][j]));
        
        _max = max(_max,util(matrix,i-1,j,matrix[i][j]));
        
        _max = max(_max,util(matrix,i,j+1,matrix[i][j]));
        
        _max = max(_max,util(matrix,i,j-1,matrix[i][j]));
        
        dp[i][j] = _max;
        return dp[i][j]+1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        int result = 1;
        dp.resize(row,vector<int>(col,0));
        
        for(int i = 0;i < row;++i) {
            for(int j = 0;j <col;++j) {
                util(matrix,i,j,-1);
                result = max(dp[i][j],result);
            }
        }
        
        return result;
    }
};