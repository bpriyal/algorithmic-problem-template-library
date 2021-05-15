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
        
        long result = 0;
    int indicator = 1;
    for(int i = 0; i<str.size();)
    {
        i = str.find_first_not_of(' ');
        if(str[i] == '-' || str[i] == '+')
            indicator = (str[i++] == '-')? -1 : 1;
        while('0'<= str[i] && str[i] <= '9') 
        {
            result = result*10 + (str[i++]-'0');
            if(result*indicator >= INT_MAX) return INT_MAX;
            if(result*indicator <= INT_MIN) return INT_MIN;                
        }
        return result*indicator;
    }
        return 0;
    }
};