class Solution {
    int dp[46] = {0};
    int util(int n) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != 0) {
            return dp[n];
        }
        return dp[n] = util(n-1) + util(n-2);
    }
public:
    int climbStairs(int n) {
       return util(n);
    }
};