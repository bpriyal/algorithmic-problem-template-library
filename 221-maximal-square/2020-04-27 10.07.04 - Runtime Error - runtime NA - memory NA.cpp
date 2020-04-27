class Solution {
public:
    int min(int a,int b,int c) {
        return (a > b)? ((b > c)? c : b) : ((a>c)? c : a);
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int sup[row][col];
        int i,j;
        for (i=0;i<col;++i) {
            sup[0][i] = static_cast<int>(matrix[0][i])-48;
        }
        for (i=1;i<row;++i) {
            sup[i][0] = static_cast<int>(matrix[i][0])-48;
        }
        
        for (i=1;i<row;++i) {
            for (j=1;j<col;++j) {
                if (matrix[i][j] == '1') {
                    sup[i][j] = min(sup[i][j-1],sup[i-1][j],sup[i-1][j-1]) + 1;
                } else {
                    sup[i][j] = 0;
                }
            }
        }
        int max =sup[0][0];
        for (i=0;i<row;++i) {
            for (j=0;j<col;++j) {
                if (max < sup[i][j]) {
                    max = sup[i][j];
                }
            }
        }
        return max*max;
        return 0;
    }
};