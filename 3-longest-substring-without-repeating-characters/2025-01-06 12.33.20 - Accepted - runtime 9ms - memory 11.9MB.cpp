class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int i = 0, j = 0, result = 0;
        unordered_map<char, int> cache;
        for (j = 0; j < size; ++j) {
            auto it = cache.find(s[j]);
            if (it != cache.end()) {
                i = max(i, it->second + 1);
            }
            cache[s[j]] = j;
            result = max(result, j - i + 1);
        }
        return result;
    }
};