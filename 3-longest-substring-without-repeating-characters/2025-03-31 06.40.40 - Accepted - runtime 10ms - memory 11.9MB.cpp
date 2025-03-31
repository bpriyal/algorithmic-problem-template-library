class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int size = s.size();
      if (size == 0) return 0;
      unordered_map<char, int> cache;
      int result = 0;
      // int i = 0, j = 1;
      // int result = 1;
      // cache.emplace(s[i]);

      // while (j < size) {
      //   while (cache.contains(s[j])) {
      //     cache.erase(s[i]);
      //     ++i;
      //   }
      //   if ()
      //   cache.emplace(s[j]);
      //   ++j;
      //   result = max(result, j - i);
      // }
      // return result;
      for (int j = 0, i = 0; j < size; ++j) {
        if (cache[s[j]] > 0) {
          i = max(cache[s[j]], i);
        }
        result = max(result, j - i + 1);
        cache[s[j]] = j + 1;
      }
      return result;
    }
};