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

    vector<int> getPrefixWords(const vector<string>& words, const string& prefix) {
        vector<int> prefixWords;
        for (int i = 0; i < words.size(); ++i) {
            if (mismatch(prefix.begin(), prefix.end(), words[i].begin()).first == prefix.end()) prefixWords.emplace_back(i);
        }
        return prefixWords;
    }

    string getPrefix(const vector<string>& tempGrid, int currentRow) {
        string prefix = "";
        for (int i = 0; i <= currentRow; ++i) {
            prefix += tempGrid[i][currentRow + 1];
        }
        return prefix;
    } 

    void formGrid(const vector<string>& words, vector<string>& tempGrid, int row, string prefix) {
        if (row == wordLength) result.emplace_back(tempGrid);
        vector<int> prefixMatchedWords = getPrefixWords(words, prefix);
        for (const auto& wordPos : prefixMatchedWords) {
            tempGrid.emplace_back(words[wordPos]);
            formGrid(words, tempGrid, row + 1, getPrefix(tempGrid, row));
            tempGrid.pop_back();
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        wordLength = words[0].size();
        vector<string> tempGrid;
        formGrid(words, tempGrid, 0, "");
        return result;
    }
};