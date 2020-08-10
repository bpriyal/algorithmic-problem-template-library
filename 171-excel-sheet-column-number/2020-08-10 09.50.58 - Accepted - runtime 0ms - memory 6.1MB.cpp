class Solution {
public:
    long long int titleToNumber(string s) {
        int size = s.size();
        long long int multiplier = 1,result = 0;
        for(int i=size-1;i>=0;--i) {
            result += multiplier*(s[i]-'A'+1);
            multiplier *= 26;
        }
        return result;
    }
};