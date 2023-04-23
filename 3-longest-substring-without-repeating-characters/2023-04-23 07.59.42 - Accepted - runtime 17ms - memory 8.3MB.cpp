class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        unordered_map<char, int> cache;
        int left = 0, longestSubstr = 0;
        
        for (int right = 0; right < size; ++right) {
            ++cache[s[right]];
            while (cache[s[right]] >  1) {
                --cache[s[left]];
                ++left;
            }
            longestSubstr = max(longestSubstr, right - left + 1);
        }
        return longestSubstr;
    }
};