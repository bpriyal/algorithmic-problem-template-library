class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i = 0;i < row;++i) {
            for(int j = 0;j < col;++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 1234567;
                    matrix[0][j] = 1234567;
                }
            }
        }
        
        for(int i = 0;i < row;++i) {
            if (matrix[i][0] == 1234567) {
                for(int j = 0;j < col;++j) {
                    if (!(i == 0 && matrix[i][j] == 1234567)) {
                        matrix[i][j] = 0;
                    }
                }   
            }
        }
        //cout<<"here"<<endl;
        for(int i = 0;i < col;++i) {
            if (matrix[0][i] == 1234567) {
                for(int j = 0;j < row;++j) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};