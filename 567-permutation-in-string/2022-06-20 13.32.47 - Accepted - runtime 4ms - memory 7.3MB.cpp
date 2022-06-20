class Solution {
    bool checkCache(vector<int> &cache) {
        for(int i = 0;i < 26;++i) {
            if (cache[i] != 0) return false;
        }
        
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        
        if (size2 < size1) return false;
        
        vector<int> cache(26, 0);
        
        for(int i = 0;i < size1;++i) ++cache[s1[i]-'a'];
        
        for(int i = 0;i < size1;++i) {
            --cache[s2[i]-'a'];
        }
        
        if (checkCache(cache)) return true;
        
        for(int i = size1;i < size2;++i) {
            ++cache[s2[i-size1]-'a'];
            --cache[s2[i]-'a'];
            if (checkCache(cache)) return true;
        }
        
        return false;
    }
};