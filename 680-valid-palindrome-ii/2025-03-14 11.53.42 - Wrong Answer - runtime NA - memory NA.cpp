class Solution {
public:
    bool validPalindrome(string s) {
      int size = s.size();
      int i = 0, j = size - 1;
      int deletionsAllowed = 1;

      while (i < j) {
        if (s[i] == s[j]) {
          ++i;
          --j;
        } else {
          if (!deletionsAllowed) return false;
          --deletionsAllowed;
          if (s[i + 1] == s[j]) ++i;
          else if (s[i] == s[j - 1]) --j;
          else return false;
        }
      }

      return true;
    }
};