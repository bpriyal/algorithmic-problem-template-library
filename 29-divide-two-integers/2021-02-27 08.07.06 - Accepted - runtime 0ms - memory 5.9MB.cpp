class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        
        bool negative = (dividend <= 0) != (divisor < 0);
        
        // use negative numbers
        if(dividend > 0) dividend = -dividend;
        if(divisor > 0) divisor = -divisor;
        
        int ans = 0;
        int curr;
        int k;
        
        while(dividend <= divisor)
        {
            curr = divisor;
            k = 1;
            while(curr > -1073741825 && curr + curr >= dividend) // -1073741825 is MIN_INT / 2
            {
                curr += curr;
                k += k;
            }
            dividend -= curr;
            ans += k;
        }
        
        return negative ? -ans : ans;
    }
};