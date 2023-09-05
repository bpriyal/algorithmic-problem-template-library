class Solution {
    vector<vector<pair<int, int>>> extractNonZeroes(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<pair<int, int>>> optimizedStore(rows);
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (mat[r][c] != 0) optimizedStore[r].emplace_back(mat[r][c], c);
            }
        }
        return optimizedStore;
    }
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int row1 = mat1.size();
        int col1 = mat1[0].size();
        int row2 = mat2.size();
        int col2 = mat2[0].size();
        
        auto optimizedMat1 = extractNonZeroes(mat1);
        auto optimizedMat2 = extractNonZeroes(mat2);

        vector<vector<int>> result(row1, vector<int>(col2, 0));

        for (int r = 0; r < row1; ++r) {
            for (const auto& [element1, col1] : optimizedMat1[r]) {
                for (const auto& [element2, col2] : optimizedMat2[col1]) {
                    result[r][col2] += element1 * element2;
                }
            }
        }

        return result;
    }
};