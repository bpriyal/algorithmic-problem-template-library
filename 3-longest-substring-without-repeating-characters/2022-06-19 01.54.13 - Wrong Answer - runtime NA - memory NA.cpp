class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        unordered_map<char, int> cache;
        int result = INT_MIN;
        
        for(int i = 0;i < size;++i) {
            if(cache.find(s[i]) != cache.end()) {
                result = max(result, i - cache[s[i]]);
            }
            cache[s[i]] = i;
        }
        
        return result;
    }
};