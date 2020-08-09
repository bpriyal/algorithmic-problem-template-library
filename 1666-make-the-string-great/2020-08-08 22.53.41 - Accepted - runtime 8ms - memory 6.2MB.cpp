class Solution {
public:
    string makeGood(string s) {
        while(true) {
            int i = 0;
            bool flag = false;
            while(i < s.size()-1) {
                if (s[i] == s[i+1]+'a'-'A' || s[i] == s[i+1]+'A'-'a') {
                    s.erase(i,2);
                    if (s.empty()) {
                        return s;
                    }
                    flag = true;
                }
                ++i;
            }
            if (!flag) break;
        }
        return s;
    }
};