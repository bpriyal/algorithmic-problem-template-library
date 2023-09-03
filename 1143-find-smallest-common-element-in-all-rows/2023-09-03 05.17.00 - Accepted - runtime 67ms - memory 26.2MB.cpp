class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        unordered_map<int, int> cache;
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                ++cache[mat[j][i]];
                if (cache[mat[j][i]] == rows) return mat[j][i];
            }
        }
        return -1;
    }
};