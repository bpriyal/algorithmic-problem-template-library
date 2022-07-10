class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sizeS = s.size();
        int sizeT = t.size();
        
        if (sizeS != sizeT) return false;
        
        unordered_map<char, char> cache;
        
        for(int i = 0;i < sizeS;++i) {
            if (cache.find(s[i]) == cache.end()) cache[s[i]] = t[i];
            else {
                if (cache[s[i]] != t[i]) return false;
            }
        }
        
        return true;
    }
};