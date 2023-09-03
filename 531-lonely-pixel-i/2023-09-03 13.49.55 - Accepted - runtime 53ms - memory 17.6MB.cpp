class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int rows = picture.size();
        int cols = picture[0].size();
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);
        vector<pair<int, int>> blackPixelPos;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (picture[i][j] == 'B') {
                    ++rowCount[i];
                    ++colCount[j];
                    blackPixelPos.emplace_back(i, j);
                }
            }
        }
        int result = 0;
        for (const auto& [x, y] : blackPixelPos) if (rowCount[x] == 1 && colCount[y] == 1) ++ result;
        return result;
    }
};