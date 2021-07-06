class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();
        
        if (row*col != r*c) {
            return mat;
        }
        
        int counter = 0;
        int newRow = 0,newCol = 0;
        vector<vector<int>> result(r,vector<int>(c,0));
        
        for(int i = 0;i < row;++i) {
            for(int j = 0;j < col;++j) {
                ++counter;
                result[newRow][newCol] = mat[i][j];
                if (counter%c == 0) {
                    ++newRow;
                    newCol = 0;
                } else {
                    ++newCol;
                }
            }
        }
        
        return result;
    }
};