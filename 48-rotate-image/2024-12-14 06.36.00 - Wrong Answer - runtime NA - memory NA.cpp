class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int r = 0; r < rows / 2; ++r) {
            for (int c = 0; c < cols; ++c) {
                swap(matrix[r][c], matrix[rows - 1 - r][c]);
            }
        }

        for (int r = 0; r <= rows / 2; ++r) {
            for (int c = r + 1; c < cols; ++c) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
    }
};