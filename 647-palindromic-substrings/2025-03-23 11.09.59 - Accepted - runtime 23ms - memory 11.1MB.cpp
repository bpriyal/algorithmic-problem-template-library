class Solution {
public:
    int countSubstrings(string s) {
      int size = s.size();
      vector<vector<bool>> dp(size, vector<bool>(size, false));
      int count = 0;

      // base cases
      for (int i = 0; i < size; ++i, ++count) dp[i][i] = true;
      for (int i = 0; i < size - 1; ++i) {
        dp[i][i + 1] = (s[i] == s[i + 1]);
        if (dp[i][i + 1]) ++count;
      }
      
      for (int len = 3; len <= size; ++len) {
        int i = 0;
        int j = i + len - 1;
        while (j < size) {
          dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
          count += dp[i][j];
          ++i;
          ++j;
        }
      }

      return count;
    }
};