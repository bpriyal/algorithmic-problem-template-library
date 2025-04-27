class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int result = 0;
      unordered_map<char, int> charToIdxMap;
      int left = 0, right = 0;
      for (right = 0; right < s.size(); ++right) {
        if (charToIdxMap[s[right]] > 0) {
          left = max(left, charToIdxMap[s[right]]);
        }
        charToIdxMap[s[right]] = right + 1;
        result = max(result, right - left + 1);
      }
      return result;
    }
};