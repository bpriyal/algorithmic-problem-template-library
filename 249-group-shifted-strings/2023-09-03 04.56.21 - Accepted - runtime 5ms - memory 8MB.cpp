class Solution {
    static const int _mod = 26;
    string getHash(string word) {
        int size = word.size();
        string hashKey;
        for (int i = 0; i < size - 1; ++i) hashKey += 'a' + (word[i + 1] - word[i] + _mod) % _mod;
        return hashKey;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> cache;
        vector<vector<string>> result;
        for (const auto& str : strings) {
            auto [it, success] = cache.try_emplace(getHash(str), vector<string>());
            it->second.emplace_back(str);
        }
        for (const auto& [key, vectorOfStrings] : cache) result.emplace_back(vectorOfStrings);
        return result;
    }
}; 

