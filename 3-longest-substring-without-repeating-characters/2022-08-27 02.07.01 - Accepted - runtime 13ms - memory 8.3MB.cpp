class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        vector<int> cache(256, -1);
        int start = -1;
        int result = 0;
        
        for (int i = 0; i < size; ++i) {
            if (cache[s[i]] > start) {
                start = cache[s[i]];
            }
            
            cache[s[i]] = i;
            result = max(result, i - start);
        }
        
        return result;
    }
};