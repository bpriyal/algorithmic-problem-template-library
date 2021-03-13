class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> cache;
        
        if (s.size() < k) {
            return false;
        }
        
        for(int i = 0;i <= s.size() - k;++i) {
            cache.insert(s.substr(i,k));
        }
        
        return cache.size() >= pow(2,k)? true:false; 
    }
};