class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        unordered_set<int> rowsToZero;
        unordered_set<int> colsToZero;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    rowsToZero.insert(i);
                    colsToZero.insert(j);
                }
            }
        }

        for (auto it : rowsToZero) {
            for (int i = 0; i < cols; ++i) {
                matrix[it][i] = 0;
            }
        }

        for (auto it : colsToZero) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][it] = 0;
            }
        }
    }
};