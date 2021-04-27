class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        double x = log10(n)/log10(3);
        int whole = x;
        
        return x-whole == 0? true:false;
        
        /*if (n == 0) {
            return false;
        }
        while (n) {
            if (n == 1) {
                break;
            }
            if (n%3 != 0) {
                return false;
            }
            n /= 3;
        }
        
        return true;*/
    }
};