class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> cache_s(26, 0);
        vector<int> cache_p(26,0);
        vector<int> result;
        int sizep = p.size();
        int sizes = s.size();
        
        if (sizep > sizes) return result;
        
        for(const char &c : p) ++cache_p[c - 'a'];
        
        for(int i = 0; i < sizep; ++i) ++cache_s[s[i] - 'a'];
        
        for(int i = sizep; i < sizes; ++i) {
            if (cache_s == cache_p) {
                result.push_back(i - sizep);
            }
            --cache_s[s[i-sizep] - 'a'];
            ++cache_s[s[i] - 'a'];
        }
        
        if (cache_s == cache_p) result.push_back(sizes - sizep);
        
        return result;
    }
};