class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        unordered_set<char> cache;
        
        int result = INT_MIN;
        int run = 0;
        
        for(char c : s) {
            if (cache.find(c) != cache.end()) {
                result = max(result, run);
                cache.clear();
                cache.insert(c);
                run = 1;
            } else {
                ++run;
                cache.insert(c);
            }
        }
        
        result = max(result, run);
        
        return result;
    }
};