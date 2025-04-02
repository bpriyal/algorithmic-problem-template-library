class Solution {
    vector<int> dp;
    int util(int n) {
      if (n < 0) return 0;
      if (n == 0) return 1;
      if (dp[n] != -1) return dp[n];
      cout << n << endl;
      dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
      return dp[n];
    }
public:
    int climbStairs(int n) {
      dp.resize(n + 1, -1);
      // return util(n);

      if (n <= 2) return n;
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