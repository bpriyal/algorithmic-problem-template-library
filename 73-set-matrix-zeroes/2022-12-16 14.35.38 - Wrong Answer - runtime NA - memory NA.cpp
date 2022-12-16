class Solution {
    int rows, cols;
    void util(vector<vector<int>>& matrix, int i, int j) {
        // set cols as -1
        for (int k = 0; k < rows; ++k) {
            if (matrix[k][j] != 0) {
                matrix[k][j] = -1;
            }
        }

        for (int k = 0; k < cols; ++k) {
            if (matrix[i][k] != 0) {
                matrix[i][k] = -1;
            }
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    util(matrix, i, j);
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};