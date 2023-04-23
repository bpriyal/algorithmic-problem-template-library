class Solution {
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