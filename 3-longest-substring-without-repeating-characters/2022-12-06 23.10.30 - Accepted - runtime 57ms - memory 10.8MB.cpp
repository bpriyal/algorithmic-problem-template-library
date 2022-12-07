class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int result = 0;
        int left = 0;
        int right = 0;

        unordered_set<char> cache;

        for (right = 0; right < size; ++right) {
            char c = s[right];

            while (cache.count(c)) {
                cache.erase(s[left]);
                ++left;
            }

            cache.insert(c);
            result = max(result, right - left + 1);
        }

        return result;
    }
};