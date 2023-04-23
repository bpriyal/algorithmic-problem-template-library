class Solution {
    vector<int> getCount(const string& str) {
        vector<int> counts(26, 0);
        for (char c : str) ++counts[c - 'a'];
        return counts;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<bool> visited(size, false);
        vector<vector<string>> anagrams;

        for (int i = 0; i < size; ++i) {
            if (visited[i]) continue;
            vector<string> anagram;
            anagram.emplace_back(strs[i]);
            visited[i] = true;
            vector<int> primaryStrCount = getCount(strs[i]);
            for (int j = i + 1; j < size; ++j) {
                if (visited[j]) continue;
                if (getCount(strs[j]) == primaryStrCount) {
                    anagram.emplace_back(strs[j]);
                    visited[j] = true;
                }
            }
            anagrams.emplace_back(anagram);
        }

        return anagrams;
    }
};