class Solution {
public:
    bool isPowerOfTwo(long int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        while (n) {
            if (n%2 != 0 && n != 1) return false;
            n /= 2;
        }
        return true;
    }
};