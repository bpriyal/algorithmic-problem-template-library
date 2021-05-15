class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        return say(countAndSay(n - 1));
    }
    
    string say(string s) {
        string rez;
        int cnt = 1;
        for (int i = 0; i < s.size(); i++) {
            if (i == s.size() - 1 || s[i] != s[i + 1]) {
                rez += '0' + cnt;
                rez += s[i];
                cnt = 0;
            }
            cnt++;
        }
        return rez;
    }
};