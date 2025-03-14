class Solution {
    bool isPalindrome(const string& s, int i, int j) {
      while (i < j) {
        if (s[i] != s[j]) return false;
        ++i;
        --j;
      }
      return true;
    }
public:
    bool validPalindrome(string s) {
      int size = s.size();
      int i = 0, j = size - 1;

      while (i <= j) {
        if (s[i] == s[j]) {
          ++i;
          --j;
        } else {
          return (s[i] == s[j - 1] && isPalindrome(s, i, j - 1)) || (s[i + 1] == s[j] && isPalindrome(s, i + 1, j));
        }
      }

      return true;
    }
};