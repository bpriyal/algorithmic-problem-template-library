class Solution {
    int row,col;
    vector<vector<int>> dp;
    int check(vector<vector<int>> &matrix,int i,int j) {
        if (i < 0 || j < 0) {
            return -1;
        }
        if (i >= row || j >= col) {
            return -2;
        }
        return matrix[i][j];
    }
    int util(vector<vector<int>> &matrix,int i,int j) {
        //printf("%d||%d\n",i,j);
        if (i < 0 || j < 0) {
            return -1;
        }
        if (i >= row || j >= col) {
            return -2;
        }
        if (dp[i][j] < 0) {
            return dp[i][j];
        }
        
        bool isPacific = false;
        bool isAtlantic = false;
        
        int t = matrix[i][j];
        
        if (matrix[i][j] >= check(matrix,i-1,j)) {
            matrix[i][j] = INT_MAX;
            int temp = util(matrix,i-1,j);
            matrix[i][j] = t;
            if (temp == -3) {
                dp[i][j] = -3;
                return dp[i][j];
            }
            isPacific = temp == -1 || isPacific;
            isAtlantic = temp == -2 || isAtlantic;
        }
        
        if (matrix[i][j] >= check(matrix,i+1,j)) {
            matrix[i][j] = INT_MAX;
            int temp = util(matrix,i+1,j);
            matrix[i][j] = t;
            if (temp == -3) {
                dp[i][j] = -3;
                return dp[i][j];
            }
            isPacific = temp == -1 || isPacific;
            isAtlantic = temp == -2 || isAtlantic;
        }
        if (matrix[i][j] >= check(matrix,i,j-1)) {
            matrix[i][j] = INT_MAX;
            int temp = util(matrix,i,j-1);
            matrix[i][j] = t;
            if (temp == -3) {
                dp[i][j] = -3;
                return dp[i][j];
            }
            isPacific = temp == -1 || isPacific;
            isAtlantic = temp == -2 || isAtlantic;
        }
        if (matrix[i][j] >= check(matrix,i,j+1)) {
            matrix[i][j] = INT_MAX;
            int temp = util(matrix,i,j+1);
            matrix[i][j] = t;
            if (temp == -3) {
                dp[i][j] = -3;
                return dp[i][j];
            }
            isPacific = temp == -1 || isPacific;
            isAtlantic = temp == -2 || isAtlantic;
        }
        
        if (isPacific && isAtlantic) {
            dp[i][j] = -3;
            //cout<<"here"<<endl;
        } else if (isPacific) {
            dp[i][j] = -1;
        } else if (isAtlantic) {
            dp[i][j] = -2;
        }
        
        return dp[i][j];
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        row = matrix.size();
        
        vector<vector<int>> result;
        if (row == 0) {
            return result;
        }
        
        col = matrix[0].size();
    
        dp.resize(row,vector<int>(col,0));
        
        for(int i = 0;i < row;++i) {
            for(int j = 0;j < col;++j) {
                util(matrix,i,j);
                if (dp[i][j] == -3) {
                    vector<int> temp = {i,j};
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};