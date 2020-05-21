class Solution {
public:
    int min(int a,int b,int c) {
        return (a > b)? ((b > c)? c:b) : ((a > c)? c:a); 
    }
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i,j,result = 0;
        for (i=0;i<row;++i) {
            result += matrix[i][0];
        }
        for(i=1;i<col;++i) {
            result += matrix[0][i];
        }
        for (i=1;i<row;++i) {
            for(j=1;j<col;++j) {
                matrix[i][j] = (matrix[i][j]) ? min(matrix[i-1][j-1],matrix[i-1][j],matrix[i][j-1]) + 1:0;
                result += matrix[i][j];
            }
        }
        return result;
    }
};