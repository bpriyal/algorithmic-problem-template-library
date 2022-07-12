class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sizeS = s.size();
        int sizeT = t.size();
        
        if (sizeT < sizeS) return false;
        
        int i = 0;
        int j = 0;
        
        while(i < sizeS && j < sizeT) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        
        return i == sizeS;
    }
};