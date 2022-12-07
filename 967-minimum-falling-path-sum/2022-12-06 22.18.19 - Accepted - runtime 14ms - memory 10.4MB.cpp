class Solution {
    int rows, cols;
    vector<vector<int>> dp;
    int util(const vector<vector<int>>& matrix, int row, int col ) {
        if (row >= rows || col < 0 || col >= cols) return INT_MAX;
        if (row == rows - 1) return matrix[row][col];

        if (dp[row][col] != -1) return dp[row][col];

        dp[row][col] = matrix[row][col] + min({
                                        util(matrix, row + 1, col - 1),
                                        util(matrix, row + 1, col),
                                        util(matrix, row + 1, col + 1)
                                      });

        return dp[row][col];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        rows = cols = matrix.size();
        int result = INT_MAX;
        dp.resize(rows, vector<int>(cols, -1));

        for (int i = 0; i < cols; ++i) {
            result = min(result, util(matrix, 0, i));
        }

        return result;
    }
};