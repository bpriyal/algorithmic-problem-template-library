class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int size = words.size();
        unordered_map<string, int> cache;
        
        int result = 0;
        int numberCommonLetterPair = 0;
        
        for(auto& it : words) ++cache[it];
        
        for(auto& it : cache) {
            const string &s = it.first;
            
            if (s[0] == s[1]) numberCommonLetterPair = max(numberCommonLetterPair, it.second);
            else {
                int revFrequency = 0;
                string reverse = {s[1], s[0]};
                
                if (const auto& it = cache.find(reverse); it != cache.end()) {
                    revFrequency = cache[reverse];
                    cache.erase(it);
                }
                result += (min(it.second, revFrequency)) * 4;
            }
        }
        
        cout<<result<<endl;
        
        result += numberCommonLetterPair * 2;
        
        return result;
    }
};