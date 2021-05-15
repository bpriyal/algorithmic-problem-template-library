class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        int i = 0;
        int sign = 1;
        while(s[i] == ' ') {
            i++;
        }
        
        if (i == size) {
            return 0;
        }
        
        if (s[i] == '-') {
            sign = -1;
            ++i;
        } else if (s[i] == '+') {
            ++i;
        }
        
        if (i == size) {
            return 0;
        }
        int sum = 0;
        while(isdigit(s[i])) {
        if (INT_MAX/10 < sum) {
            return sign == 1? INT_MAX:INT_MIN;
        }
            
            sum = sum*10+s[i]-'0';
            ++i;
        }
        return sign*sum;
    }
};