class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 0) return 0;
        int run = 1;
        while(n > 0) {
            n = n - run;
            ++run;
        }
        if (n < 0) return run-2 ;
        return run-1;
    }
};