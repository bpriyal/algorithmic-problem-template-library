class Solution {
    int result;
    void util(const vector<string>& digits, int n,int run) {
        if (run > n) {
            return;
        }
        if (run > 0 && run <= n) {
            ++result;
        }
        for(auto &s:digits) {
            util(digits,n,run*10+(s[0]-'0'));
        }
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        result = 0;
        util(digits,n,0);
        return result;
    }
};