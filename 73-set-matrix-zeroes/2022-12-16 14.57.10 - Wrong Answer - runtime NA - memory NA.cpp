class Solution {
    int rows, cols;
    int flag = INT_MAX - 5;
    void util(vector<vector<int>>& matrix, int i, int j) {
        // set cols as -1
        for (int k = 0; k < rows; ++k) {
            if (matrix[k][j] != 0) {
                matrix[k][j] = flag;
            }
        }

        for (int k = 0; k < cols; ++k) {
            if (matrix[i][k] != 0) {
                matrix[i][k] = flag;
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
                    matrix[i][0] = flag;
                    matrix[0][j] = flag;
                }
            }
        }

        for (int i = 1; i < rows; ++i) {
            if (matrix[i][0] == flag) {
                for (int j = 0; j < cols; ++j) matrix[i][j] = 0;
            }
        }

        for (int i = 1; i < cols; ++i) {
            if (matrix[0][i] == flag) {
                for (int j = 0; j < rows; ++j) matrix[j][i] = 0;
            }
        }

        if (matrix[0][0] == flag) {
            for (int i = 0; i < cols; ++i) matrix[0][i] = 0;
            for (int i = 0; i < rows; ++i) matrix[i][0] = 0;
        }
    }
};