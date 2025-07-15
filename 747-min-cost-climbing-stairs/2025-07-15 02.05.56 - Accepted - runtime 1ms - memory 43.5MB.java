class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        if (n == 0) return 0;
        int[] dp = new int[n + 1];
        for (int i = 0; i < n + 1; ++i) dp[i] = -1;
        dp[0] = cost[0];
        dp[1] = cost[1];
        return helper (cost, n, dp);
    }

    int helper (int[] cost, int ind, int[] dp) {
        if (ind < 0) return Math.min(dp[0], dp[1]);
        int c = ind == cost.length ? 0 : cost[ind];
        if (dp[ind] == -1) {
            int sum1 = c + helper (cost, ind - 1, dp);
            int sum2 = c + helper (cost, ind - 2, dp);
            dp[ind] = Math.min(sum1, sum2);
        }
        return dp[ind];
    }
}