class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int result = 0;
        int left = 0;
        int right = 0;

        vector<int> cache(26, 0);

        for (right = 0; right < size; ++right) {
            char c = s[right];

            while (cache[c - 'a']) {
                --cache[s[left] - 'a'];
                ++left;
            }

            ++cache[c - 'a'];
            result = max(result, right - left + 1);
        }

        return result;
    }
};