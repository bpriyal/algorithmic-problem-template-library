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

        // for (int i = 0; i < cols; ++i) {
        //     result = min(result, util(matrix, 0, i));
        // }

        for (int i = 0; i < cols; ++i) dp[rows - 1][i] = matrix[rows - 1][i];

        for (int i = rows - 2; i >= 0; --i) {
            for (int j = cols - 1; j >= 0; --j) {
                dp[i][j] = matrix[i][j] + min({j > 0? dp[i + 1][j - 1] : INT_MAX, dp[i + 1][j], j >= cols? dp[i + 1][j + 1] : INT_MAX});
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};