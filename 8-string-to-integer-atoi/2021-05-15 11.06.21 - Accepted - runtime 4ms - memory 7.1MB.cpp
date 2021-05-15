class Solution {
public:
    int myAtoi(string s) {
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
        long n = s.length(), x = 0, f = 0, sign = 0, dig = 0;
        
        for(long i = 0; i < n; ++i){
            if(isdigit(s[i])) x = x*10 + s[i] - '0', dig = 1;
            else {
                if((s[i] == '-' || s[i] == '+') && !dig && !sign) sign = 1,f = s[i] == '-' ? 1 : 0;
                else if(iswspace(s[i]) && !dig && !sign) continue;
                else break;
            }
            if(x > INT_MAX) break;
        }
        
        if(f) x = -x;
        
        return min(max(x, (long) INT_MIN), (long) INT_MAX);
    }
};