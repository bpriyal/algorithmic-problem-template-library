class Solution {
    string getHash(const string& str) {
      string hash;
      for (int i = 0; i < str.size() - 1; ++i) {
        hash += (str[i + 1] - str[i] + 26) % 26 + 'a';
      }
      return hash;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
      int size = strings.size();
      unordered_map<string, vector<string>> cache;

      for (const auto& str : strings) {
        auto [it, success] = cache.try_emplace(getHash(str), vector<string>());
        it->second.emplace_back(str);
      }

      vector<vector<string>> result;
      for (const auto& [hash, strs] : cache) result.emplace_back(strs);

      return result;
    }
};

/*
abc bcd xyz

az ba
a b ..... z
*/