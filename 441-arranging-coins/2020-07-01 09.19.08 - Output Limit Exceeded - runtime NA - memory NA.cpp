class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 0) return 0;
        int run = 1;
        while(n > 0) {
            n = n - run;
            ++run;
            printf("run:%d||n:%d\n",run,n);
        }
        cout<<n;
        if (n < 0) return run-2 ;
        return run-1;
    }
};