class Solution {
public:
    bool buddyStrings(string A, string B) {
        int sizea = A.size();
        int sizeb = B.size();
        if (sizea != sizeb) {
            return false;
        }
        
        vector<int> cache1(26),cache2(26);
        int diff = 0;
        bool freq = false;
        for(int i = 0;i<sizea;++i) {
            if(A[i] != B[i]) {
                ++diff;
            }
            ++cache1[A[i]-'a'];
            ++cache2[B[i]-'a'];
            if (cache1[A[i]-'a'] >= 2) {
                freq = true;
            }
        }
        
        return (cache1 == cache2 && (diff == 2 || (diff == 0 && freq)));
    }
};