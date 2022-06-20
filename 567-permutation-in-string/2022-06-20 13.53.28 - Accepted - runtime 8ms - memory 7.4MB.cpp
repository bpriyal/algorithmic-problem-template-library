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
        
        vector<int> cache1(26, 0);
        vector<int> cache2(26, 0);
        int count = 0;
        
        for(int i = 0;i < size1;++i) {
            ++cache1[s1[i]-'a'];
            ++cache2[s2[i]-'a'];
        }
        
        for(int i = 0;i < 26;++i) {
            if (cache1[i] == cache2[i]) ++count;
        }
        
        for(int i = size1;i < size2;++i) {
            if (count == 26) return true;
            
            --cache2[s2[i - size1] - 'a'];
            if (cache2[s2[i - size1] - 'a'] == cache1[s2[i - size1] - 'a']) ++count;
            else if (cache2[s2[i - size1] - 'a'] == cache1[s2[i - size1] - 'a'] - 1) --count;
            
            ++cache2[s2[i] - 'a'];
            if (cache2[s2[i] - 'a'] == cache1[s2[i] - 'a']) ++count;
            else if (cache2[s2[i] - 'a'] == cache1[s2[i] - 'a'] + 1) --count;
        }
        
        return (count == 26);
    }
};