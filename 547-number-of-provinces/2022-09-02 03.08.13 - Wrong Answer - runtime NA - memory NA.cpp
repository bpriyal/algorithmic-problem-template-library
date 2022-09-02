class Solution {
    int row, col;
    
    void util(vector<vector<int>>& isConnected, int i, int j) {
        if (i < 0 || i >= row || j < 0 || j >= col || isConnected[i][j] == 0 || isConnected[i][j] == 2) return;
        
        isConnected[i][j] = 2;
        
        util(isConnected, i + 1, j);
        util(isConnected, i, j + 1);
        util(isConnected, i - 1, j);
        util(isConnected, i, j - 1);
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        row = isConnected.size();
        col = isConnected[0].size();
        int result = 0;
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (isConnected[i][j] == 1) {
                    ++result;
                    util(isConnected, i, j);
                }
            }
        }
        
        return result;
    }
};