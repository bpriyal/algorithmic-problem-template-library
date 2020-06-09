class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_n = s.size()-1;
        int t_n = t.size()-1;
        
        while (t_n >= 0 && s_n >= 0) {
            if (s[s_n] == t[t_n]) {
                --s_n;
                --t_n;
            } else {
                --t_n;
            }
        }
        if (s_n == -1) return true;
        return false;
    }
};