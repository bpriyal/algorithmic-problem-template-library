class Solution {
    vector<int> dp;
    int util(int n) {
      if (n < 0) return 0;
      if (n == 0) return 1;
      if (dp[n] != -1) return dp[n];
      dp[n] = util(n - 1) + util(n - 2);
      return dp[n];
    }
public:
    int climbStairs(int n) {
      dp.resize(n + 1, -1); 
      // return util(n);

      // Iterative
      dp[1] = 1;
      dp[2] = 2;

      for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
      }

      return dp[n];
    }
};