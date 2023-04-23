class Solution {
    int getHash(const string& str) {
        int hash = 0;
        for (char c : str) hash += (c - 'a' + 1);
        return hash;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> cache;
        for (auto& str : strs) {
            sort(str.begin(), str.end());
            cache[str].emplace_back(str);
        }
        vector<vector<string>> anagrams;
        for (const auto& [str, anagram] : cache) anagrams.emplace_back(anagram);
        return anagrams;
    }
};