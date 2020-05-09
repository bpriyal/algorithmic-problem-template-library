class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        long int i;
        for (i=1;i*i<=num;++i) {
            if ( num%i == 0 && num/i == i) {
                return true;
            }
        }
        return false;
    }
};