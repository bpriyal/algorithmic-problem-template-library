class Solution {
    vector<vector<string>> result;
    int wordLength;

    bool isSymmetric(const vector<string>& tempGrid, int currentRow) {
        for (int i = 0; i < wordLength; ++i) {
            for (int j = i + 1; j <= currentRow; ++j) {
                if (tempGrid[i][j] != tempGrid[j][i]) return false;
            }
        }
        return true;
    }

    void formGrid(const vector<string>& words, vector<string>& tempGrid, int row) {
        if (row == wordLength) result.emplace_back(tempGrid);

        for (const auto& word : words) {
            tempGrid.emplace_back(word);
            if (isSymmetric(tempGrid, row)) formGrid(words, tempGrid, row + 1);
            tempGrid.pop_back();
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        wordLength = words[0].size();
        vector<string> tempGrid;
        formGrid(words, tempGrid, 0);
        return result;
    }
};