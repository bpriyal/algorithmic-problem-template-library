class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int row1 = mat1.size();
        int col1 = mat1[0].size();
        int row2 = mat2.size();
        int col2 = mat2[0].size();

        vector<vector<int>> resultant(row1, vector<int>(col2));

        // for (int i = 0; i < row1; ++i) {
        //     for (int j = 0; j < col2; ++j) {
        //         for (int k = 0; k < col1; ++k) {
        //             resultant[i][j] += mat1[i][k] * mat2[k][j];
        //         }
        //     }
        // }

        for (int rowIndex = 0; rowIndex < row1; ++rowIndex) {
            for (int elementIdx = 0; elementIdx < col1; ++elementIdx) {
                if (mat1[rowIndex][elementIdx]) {
                    for (int colIndex = 0; colIndex < col2; ++colIndex) {
                        resultant[rowIndex][colIndex] += mat1[rowIndex][elementIdx] * mat2[elementIdx][colIndex];
                    }
                }
            }
        }
        return resultant;
    }
};