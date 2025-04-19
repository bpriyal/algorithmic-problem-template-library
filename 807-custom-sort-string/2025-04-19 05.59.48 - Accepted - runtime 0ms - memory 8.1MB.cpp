class Solution {
public:
    string customSortString(string order, string s) {
      string result;
      vector<int> cache(26, 0);
      for (char c : s) ++cache[c - 'a'];

      for (char c : order) {
        for (int i = 0; i < cache[c - 'a']; ++i) result += c;
        cache[c - 'a'] = 0;
      }

      for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < cache[i]; ++j) result += ('a' + i);
        cache[i] = 0;
      }
      return result;
    }
};