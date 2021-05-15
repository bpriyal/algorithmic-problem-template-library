class Solution {
public:
    int myAtoi(string str) {
        /*int size = s.size();
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
            if (INT_MAX/10-(s[i]-'0') < sum) {
                return sign == 1? INT_MAX:INT_MIN;
            }
            
            sum = sum*10+s[i]-'0';
            ++i;
        }
        return sign*sum;*/
        
        int ret = 0, sign = 1, i = str.find_first_not_of(' '), base = INT_MAX / 10;
    if (str[i] == '+' || str[i] == '-') sign = str[i++] == '+' ?: -1;
    while (isdigit(str[i])) {
        if (ret > base || (ret == base && str[i] - '0' > 7)) 
            return sign > 0 ? INT_MAX : INT_MIN;
        ret = 10 * ret + (str[i++] - '0');
    }
    return sign * ret;
    }
};