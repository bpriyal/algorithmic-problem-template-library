class Solution {
public:
    bool isSubsequence(string s, string t) {
      int i = 0, j = 0;
      int sizeS = s.size();
      int sizeT = t.size();

      // if (sizeT < sizeS) return false;

      // for (int j = 0; j < sizeT; ++j) {
      //   if (s[i] == t[j]) ++i; 
      // }

      // return i == sizeS;

      unordered_map<char, vector<int>> charToIdxMap;
      for (int i = 0; i < sizeT; ++i) {
        auto [it, success] = charToIdxMap.try_emplace(t[i], vector<int>());
        it->second.emplace_back(i);
      }

      int currentIdx = -1;
      for (int i = 0; i < sizeS; ++i) {
        auto it = charToIdxMap.find(s[i]);
        if (it == charToIdxMap.end()) return false;

        bool isMatched = false;
        for (const auto& idx : it->second) {
          if (currentIdx < idx) {
            isMatched = true;
            currentIdx = idx;
            break;
          }
        }
        if (!isMatched) return false;
      }

      return true;
    }
};