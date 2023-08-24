class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int size = s.size();
        int left = 0, right = 0;
        unordered_set<char> cache;
        int result = 0;
        while (right < size) {
            while (cache.size() > 2) {
                cache.erase(s[left]);
                ++left;
            }
            cache.emplace(s[right]);
            result = right - left;
            ++right;
        }
        return result;
    }
};