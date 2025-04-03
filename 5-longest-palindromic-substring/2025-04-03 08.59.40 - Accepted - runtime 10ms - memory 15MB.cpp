class Solution {
    int size;
    string maxString;
    void util(const string& s, int i, int j) {
      while (i >= 0 && j < size) {
        if (s[i] != s[j]) break;
        --i;
        ++j;
      }
      ++i;
      --j;
      if (maxString.size() <= j - i) maxString = s.substr(i, j - i + 1);
    }
public:
    string longestPalindrome(string s) {
      size = s.size();
      // int resultStartIdx = 0, resultSize = 1;

      // vector<vector<bool>> dp(size, vector<bool>(size, false));

      // for (int i = 0; i < size; ++i) {
      //   dp[i][i] = true;
      //   if (i != size - 1 && s[i] == s[i + 1]) {
      //     resultStartIdx = i;
      //     resultSize = 2;
      //     dp[i][i + 1] = true;
      //   }
      // }

      // for (int depth = 2; depth < size; ++depth) {
      //   for (int i = 0; i < size - depth; ++i) {
      //     dp[i][i + depth] = (s[i] == s[i + depth]) && dp[i + 1][i + depth -1];
      //     if (dp[i][i + depth]) {
      //       resultStartIdx = i;
      //       resultSize = depth + 1;
      //     }
      //   }
      // }

      // return s.substr(resultStartIdx, resultSize);

      for (int i = 0; i < size; ++i) {
        util(s, i, i);
        if (i != size - 1 && s[i] == s[i + 1]) util(s, i, i + 1);
      }
      return maxString;
    }
};