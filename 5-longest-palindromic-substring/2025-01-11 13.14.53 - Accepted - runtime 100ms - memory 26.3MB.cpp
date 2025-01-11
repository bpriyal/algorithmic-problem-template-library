class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        pair<int, int> result;

        for (int i = 0; i < size; ++i) dp[i][i] = true; // All substrings of size 1 are palindromes

        for (int i = 0; i < size - 1; ++i) { // Substrings of length 2
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                result = {i, i + 1};
            }
        }

        for (int diff = 2; diff < size; ++diff) {
            for (int i = 0; i < size - diff; ++i) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    result = {i, j};
                }
            }
        }

        return s.substr(result.first, result.second - result.first + 1);
    }
};