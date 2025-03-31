class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      int size = strs.size();
      unordered_map<string, vector<string>> cache;

      for (const auto& str : strs) {
        auto sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        auto [it, success] = cache.try_emplace(sortedStr, vector<string>());
        it->second.emplace_back(str);
      }

      vector<vector<string>> result;
      for (const auto& [key, list] : cache) result.emplace_back(list);

      return result;
    }
};