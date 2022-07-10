class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sizeS = s.size();
        int sizeT = t.size();
        
        if (sizeS != sizeT) return false;
        
        unordered_map<char, char> cache;
        unordered_set<char> mappedCharCache;
        
        for(int i = 0;i < sizeS;++i) {
            if (cache.find(s[i]) == cache.end()) {
                if (mappedCharCache.find(t[i]) != mappedCharCache.end()) return false;
                
                cache[s[i]] = t[i];
                mappedCharCache.insert(t[i]);
            }
            else {
                if (cache[s[i]] != t[i]) return false;
            }
        }
        
        return true;
    }
};