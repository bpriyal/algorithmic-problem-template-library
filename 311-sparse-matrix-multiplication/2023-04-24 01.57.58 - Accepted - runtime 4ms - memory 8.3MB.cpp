class Solution {
    vector<vector<pair<int, int>>> optimizeMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<pair<int, int>>> optimizedMatrix(rows);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j]) optimizedMatrix[i].push_back({mat[i][j], j});
            }
        }
        return optimizedMatrix;
    }
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int row1 = mat1.size();
        int col1 = mat1[0].size();
        int row2 = mat2.size();
        int col2 = mat2[0].size();

        vector<vector<int>> resultant(row1, vector<int>(col2, 0));

        // NAIVE BRUTE FORCE
        // for (int i = 0; i < row1; ++i) {
        //     for (int j = 0; j < col2; ++j) {
        //         for (int k = 0; k < col1; ++k) {
        //             resultant[i][j] += mat1[i][k] * mat2[k][j];
        //         }
        //     }
        // }

        // OPTIMIZATION TO CHECK FOR ZEROS
        // for (int rowIndex = 0; rowIndex < row1; ++rowIndex) {
        //     for (int elementIdx = 0; elementIdx < col1; ++elementIdx) {
        //         if (mat1[rowIndex][elementIdx]) {
        //             for (int colIndex = 0; colIndex < col2; ++colIndex) {
        //                 resultant[rowIndex][colIndex] += mat1[rowIndex][elementIdx] * mat2[elementIdx][colIndex];
        //             }
        //         }
        //     }
        // }

        vector<vector<pair<int, int>>> optMat1 = optimizeMatrix(mat1);
        vector<vector<pair<int, int>>> optMat2 = optimizeMatrix(mat2);

        for (int rowIndex = 0; rowIndex < row1; ++rowIndex) {
            for (auto [value1, col1] : optMat1[rowIndex]) {
                for (auto [value2, col2] : optMat2[col1]) {
                    resultant[rowIndex][col2] += mat1[rowIndex][col1] * mat2[col1][col2];
                }
            }
        }

        return resultant;
    }
};