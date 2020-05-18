class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_cache(26,0);
        vector<int> s2_cache(26,0);
        int s1_size = s1.size();
        int s2_size = s2.size();
        if (s1_size > s2_size) return false;
        for(int i=0;i<s1_size;++i) {
            ++s1_cache[s1[i]-'a'];
            ++s2_cache[s2[i]-'a'];
        }
        for(int i = s1_size;i<s2_size;++i) {
            if (s1_cache == s2_cache) return true;
            ++s2_cache[s2[i]-'a'];
            --s2_cache[s2[i-s1_size]-'a'];
        }
        if(s1_cache == s2_cache) return true;
        return false;
    }
};