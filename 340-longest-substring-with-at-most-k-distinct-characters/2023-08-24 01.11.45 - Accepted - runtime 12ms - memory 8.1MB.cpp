class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int size = s.size();
        int left = 0, result = 0;
        unordered_map<char, int> cache;
        for (int right = 0; right < size; ++right) {
            ++cache[s[right]];
            while (cache.size() > k) {
                --cache[s[left]];
                if (!cache[s[left]]) cache.erase(s[left]);
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};