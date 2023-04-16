class Solution {
    vector<vector<string>> result;
    int wordLength;
    unordered_map<string, vector<string>> _cache;

    // bool isSymmetric(const vector<string>& tempGrid, int currentRow) {
    //     for (int i = 0; i < wordLength; ++i) {
    //         for (int j = i + 1; j <= currentRow; ++j) {
    //             if (tempGrid[i][j] != tempGrid[j][i]) return false;
    //         }
    //     }
    //     return true;
    // }

    void builPrefixCache(const vector<string>& words) {
        for (const auto& word : words) {
            for (int i = 0; i < word.size(); ++i) {
                string key = word.substr(0, i);
                //cout<<"key: "<<key<<endl;
                _cache[key].emplace_back(word);
            }
        }
    }

    vector<string> getPrefixWords(const vector<string>& words, const string& prefix) {
        // vector<int> prefixWords;
        // for (int i = 0; i < words.size(); ++i) {
        //     if (mismatch(prefix.begin(), prefix.end(), words[i].begin()).first == prefix.end()) prefixWords.emplace_back(i);
        // }
        // return prefixWords;
        return _cache[prefix];
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
        for (const auto& word : getPrefixWords(words, prefix)) {
            //cout<<word<<endl;
            tempGrid.emplace_back(word);
            formGrid(words, tempGrid, row + 1, getPrefix(tempGrid, row));
            tempGrid.pop_back();
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        wordLength = words[0].size();
        builPrefixCache(words);
        vector<string> tempGrid;
        formGrid(words, tempGrid, 0, "");
        return result;
    }
};