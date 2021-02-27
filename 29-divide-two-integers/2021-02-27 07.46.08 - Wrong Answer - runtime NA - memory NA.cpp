class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        bool isOneNegative = (dividend < 0 && divisor > 0) || (divisor < 0 && dividend >= 0);
        dividend = abs(dividend);
        divisor = abs(divisor);
        //printf("Dividend:%d||divisor:%d\n",dividend,divisor);
        while (dividend >= divisor) {
            dividend -= divisor;
            ++result;
            //cout<<result<<endl;
        }
        if (isOneNegative) {
            return -result;
        } else {
            return result;
        }
    }
};