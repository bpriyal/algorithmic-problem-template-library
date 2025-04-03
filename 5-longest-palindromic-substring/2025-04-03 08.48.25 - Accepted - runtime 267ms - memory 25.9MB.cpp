class Solution {
    int size;
    int maxPal = 0;
    void util(const string& s, int i, int j) {
      while (i >= 0 && j < size) {
        if (s[i] != s[j]) break;
        --i;
        ++j;
      }
      maxPal = max(maxPal, j - i -1);
    }
public:
    string longestPalindrome(string s) {
      size = s.size();
      int resultStartIdx = 0, resultSize = 1;

      vector<vector<bool>> dp(size, vector<bool>(size, false));

      for (int i = 0; i < size; ++i) {
        dp[i][i] = true;
        if (i != size - 1 && s[i] == s[i + 1]) {
          resultStartIdx = i;
          resultSize = 2;
          dp[i][i + 1] = true;
        }
      }

      for (int depth = 2; depth < size; ++depth) {
        for (int i = 0; i < size - depth; ++i) {
          dp[i][i + depth] = (s[i] == s[i + depth]) && dp[i + 1][i + depth -1];
          if (dp[i][i + depth]) {
            resultStartIdx = i;
            resultSize = depth + 1;
          }
        }
      }

      return s.substr(resultStartIdx, resultSize);
    }
};