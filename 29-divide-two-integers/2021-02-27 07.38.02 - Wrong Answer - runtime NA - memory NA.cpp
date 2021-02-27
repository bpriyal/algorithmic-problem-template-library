class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        bool isOneNegative = (dividend < 0 && divisor > 0) || (divisor < 0 && dividend >= 0);
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend >= divisor) {
            dividend -= divisor;
            ++result;
        }
        if (isOneNegative) {
            return -result;
        } else {
            return result;
        }
    }
};