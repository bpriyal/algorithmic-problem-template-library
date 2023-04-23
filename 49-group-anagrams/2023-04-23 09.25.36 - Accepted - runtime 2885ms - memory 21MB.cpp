class Solution {
    inline void getCount(const string& str, vector<int>& counts) {
        for (char c : str) ++counts[c - 'a'];
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<bool> visited(size, false);
        vector<vector<int>> cache(size, vector<int>(26, 0));
        for (int i = 0; i < size; ++i) getCount(strs[i], cache[i]);
        vector<vector<string>> anagrams;

        for (int i = 0; i < size; ++i) {
            if (visited[i]) {
                // cout<<"skipped1"<<endl;
                continue;
            }
            vector<string> anagram;
            anagram.emplace_back(strs[i]);
            visited[i] = true;
            for (int j = i + 1; j < size; ++j) {
                if (visited[j]) {
                    // cout<<"skipped2"<<endl;
                    continue;
                }
                if (cache[j] == cache[i]) {
                    anagram.emplace_back(strs[j]);
                    visited[j] = true;
                }
            }
            anagrams.emplace_back(anagram);
        }

        return anagrams;
    }
};