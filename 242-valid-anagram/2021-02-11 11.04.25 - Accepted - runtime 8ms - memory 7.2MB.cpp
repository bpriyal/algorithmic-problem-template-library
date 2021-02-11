class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> cache(26,0);
        for(char c:s) {
            ++cache[c-'a'];
        }
        
        for(char c:t) {
            --cache[c-'a'];
        }
        
        for(int n:cache) {
            if (n != 0) {
                return false;
            }
        }
        return true;
    }
};