class Solution {
    int result;
    void util(int n) {
        if (n < 0) return;
        if (n == 0) {
            ++result;
            return;
        }
        
        util(n-1);
        util(n-2);
    }
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        
        int a = 1;
        int b = 2;
        
        for(int i = 3; i <=n; ++i) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        
        return b;
    }
};