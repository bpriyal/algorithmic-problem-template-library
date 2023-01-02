class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int right = 0, left = 0;
        unordered_map<char, int> cache;
        int result = 0;

        for (right = 0; right < size; ++right) {
            ++cache[s[right]];

            while (cache[s[right]] > 1) {
                --cache[s[left]];
                ++left;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};