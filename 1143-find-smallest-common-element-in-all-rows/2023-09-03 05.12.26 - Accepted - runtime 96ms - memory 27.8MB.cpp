class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        map<int, int> cache;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) ++cache[mat[i][j]];
        }
        for (const auto& [key, val] : cache) if (val == rows) return key;
        return -1;
    }
};