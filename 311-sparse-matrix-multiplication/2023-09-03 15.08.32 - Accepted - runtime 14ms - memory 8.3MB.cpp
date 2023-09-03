class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int row1 = mat1.size();
        int col1 = mat1[0].size();
        int row2 = mat2.size();
        int col2 = mat2[0].size();
        vector<vector<int>> result;

        for (int i = 0; i < row1; ++i) {
            vector<int> subResult(col2);
            for (int k = 0; k < col2; ++k) {
                for (int j = 0; j < col1; ++j) {
                    subResult[k] += mat1[i][j] * mat2[j][k];
                }
            }
            result.emplace_back(subResult);
        }
        return result;
    }
};

// [[7,-7,0],[0,0,0],[0,3,0]]
// [1, -5] [12]
//         [-1]

// [12 5]