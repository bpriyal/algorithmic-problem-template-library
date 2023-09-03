class Solution {
    int getModulo(int mod) {
        return mod < 0? 26 + mod : mod;
    }
    bool areGroupShifted(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        if (size1 != size2) return false;

        int i = 0;
        while (i + 1 < size1) { // since size1 == size2
            if (getModulo((word1[i + 1] - word1[i]) % 26) != getModulo((word2[i + 1] - word2[i]) % 26)) return false;
            ++i;
        }
        return true;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        int size = strings.size();
        vector<bool> visited(size, false);

        for (int i = 0; i < size; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            vector<string> subResult;
            subResult.emplace_back(strings[i]);
            for (int j = i + 1; j < size; ++j) {
                if (visited[j]) continue;
                if (areGroupShifted(strings[i], strings[j])) {
                    visited[j] = true;
                    subResult.emplace_back(strings[j]);
                }
            }
            result.emplace_back(subResult);
        }
        return result;
    }
}; 

// 25 - 0 = 25 % 26 = 25
// 0 - 1 = -1 % 26 = 25 

