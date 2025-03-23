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
      if (n <= 1) return n;
      // return util(n);

      // Iterative
      int first = 1;
      int second = 2;

      for (int i = 3; i <= n; ++i) {
        int third = first + second;
        first = second;
        second = third;
      }

      return second;
    }
};