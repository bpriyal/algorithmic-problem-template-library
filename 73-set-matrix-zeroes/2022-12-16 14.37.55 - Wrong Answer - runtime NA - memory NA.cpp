class Solution {
    int rows, cols;
    void util(vector<vector<int>>& matrix, int i, int j) {
        // set cols as -1
        for (int k = 0; k < rows; ++k) {
            if (matrix[k][j] != 0) {
                matrix[k][j] = INT_MAX;
            }
        }

        for (int k = 0; k < cols; ++k) {
            if (matrix[i][k] != 0) {
                matrix[i][k] = INT_MAX;
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
                if (matrix[i][j] == INT_MAX) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};