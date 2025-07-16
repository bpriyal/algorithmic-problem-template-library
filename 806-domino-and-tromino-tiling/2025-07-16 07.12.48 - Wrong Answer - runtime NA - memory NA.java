class Solution {
    public int numTilings(int n) {
        int[][] dp = new int[n + 1][3];
        for (int i = 0; i < n; ++i) for (int j = 0; j < 3; ++j) dp[i][j] = -1;
        return util(n, 0, 0, dp, 0);
    }

    int util (int n, int val, int currSum, int[][] dp, int count) {
        if (currSum == n) return 1;
        if (currSum > n) return 0;
        // if (val != 0 && dp[currSum][val - 1] != -1) return dp[currSum][val - 1];
        int ways1 = util (n, 1, currSum + 1, dp, count + 1);
        int ways2 = util (n, 2, currSum + 2, dp, count + 1);
        int ways3 = 2 * util (n, 3, currSum + 3, dp, count + 1);
        // dp[currSum][val] = ways1 + ways2 + ways3;
        return ways1 + ways2 + ways3;
    }
}