class Solution {
    int getHash(const string& str) {
        int hash = 0;
        for (char c : str) hash += (c - 'a');
        return hash;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> cache;
        for (const auto& str : strs) {
            cache[getHash(str)].emplace_back(str);
        }
        vector<vector<string>> anagrams;
        for (const auto& [hash, anagram] : cache) anagrams.emplace_back(anagram);
        return anagrams;
    }
};