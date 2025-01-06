class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int i = -1, j = 0, result = 0;
        std::unordered_set<char> cache;
        for (j = 0; j < size; ++j) {
            if (cache.count(s[j])) {
                do { 
                    ++i;
                    cache.erase(s[i]);
                } while (s[i] != s[j]);
            } 
            cache.emplace(s[j]);
            result = max(result, j - i);
        }
        return result;
    }
};