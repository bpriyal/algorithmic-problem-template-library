class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int> cache;
        
        if (s.size() < k) {
            return false;
        }
        
        for(int i = 0;i <= s.size() - k;++i) {
            ++cache[s.substr(i,k)];
        }
        
        int count = 0;
        for(auto it = cache.begin();it != cache.end();++it) {
            ++count;
        }
        
        return count == pow(2,k)? true:false; 
    }
};