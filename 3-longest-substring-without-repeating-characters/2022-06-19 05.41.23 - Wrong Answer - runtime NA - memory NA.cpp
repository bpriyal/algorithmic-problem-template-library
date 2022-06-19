class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        vector<int> dp(size + 1);
        unordered_map<char, int> cache;
        int result = 0;
        
        if (size < 2) return size;
        
        dp[size] = 0;
        
        for(int i = size - 1;i >= 0;--i) {
            if (cache.find(s[i]) != cache.end()) {
                dp[i] = dp[i+1];
            } else {
                dp[i] = dp[i+1] + 1;
            }
            result = max(result,dp[i]);
            cache[s[i]] = i;
            
            cout<<dp[i]<<"\t";
        }
        
        return result;
    }
};