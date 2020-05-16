class Solution {
public:
    int maxPower(string s) {
        int curr = 1;
        int power = 1;
        for(int i =0;i<s.size()-1;++i) {
            if (s[i] == s[i+1]) ++curr;
            else {
                if (curr > power) power = curr;
                curr = 1;
            }
        }
        return power;
    }
};