class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int size = s.size();
        int left = 0, right = 0;
        unordered_map<char, int> cache;
        int result = 0;

        for (right = 0; right < size; ++right) {
            ++cache[s[right]];

            while (cache.size() > 2) {
                --cache[s[left]];
                if (!cache[s[left]]) cache.erase(s[left]);
                ++left;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};