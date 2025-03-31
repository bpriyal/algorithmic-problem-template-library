class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int size = s.size();
      if (size == 0) return 0;
      unordered_set<char> cache;
      int i = 0, j = 1;
      int result = 1;
      cache.emplace(s[i]);

      while (j < size) {
        while (cache.contains(s[j])) {
          cache.erase(s[i]);
          ++i;
        }
        cache.emplace(s[j]);
        ++j;
        // cout << "i: " << i << ", j: " << j << endl;
        result = max(result, j - i);
      }
      return result;
    }
};