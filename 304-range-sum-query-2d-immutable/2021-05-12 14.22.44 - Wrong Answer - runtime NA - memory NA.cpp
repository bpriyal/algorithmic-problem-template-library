class NumMatrix {
    vector<vector<int>> cache;
    int row,col;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        cache.resize(row,vector<int>(col,0));
        int sum = 0;
        
        for(int i = 0;i < row;++i) {
            for(int j = 0;j < col;++j) {
                cache[i][j] = sum + matrix[i][j];
                sum = cache[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        
        for(int i = row1;i <=row2;++i) {
            sum += cache[i][col2]-(col1 > 0? cache[i][col1-1]:0);
        }
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */