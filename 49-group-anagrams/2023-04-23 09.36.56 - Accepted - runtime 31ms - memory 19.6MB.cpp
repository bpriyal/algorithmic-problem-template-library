class Solution {
    int getHash(const string& str) {
        int hash = 0;
        for (char c : str) hash += (c - 'a' + 1);
        return hash;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> cache;
        for (const auto& str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            cache[temp].emplace_back(str);
        }
        vector<vector<string>> anagrams;
        for (const auto& [str, anagram] : cache) anagrams.emplace_back(anagram);
        return anagrams;
    }
};