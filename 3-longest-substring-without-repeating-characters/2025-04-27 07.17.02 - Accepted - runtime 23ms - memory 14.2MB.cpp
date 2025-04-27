class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_set<char> charToIdxMap;
      int left = 0, right = 0;
      int longestSubStr = 0;
      for (right = 0; right < s.size(); ++right) {
        while (charToIdxMap.count(s[right])) {
          charToIdxMap.erase(s[left]);
          ++left;
        }
        charToIdxMap.emplace(s[right]);
        longestSubStr = max(longestSubStr, right - left + 1);
      }
      return longestSubStr;
    }
};