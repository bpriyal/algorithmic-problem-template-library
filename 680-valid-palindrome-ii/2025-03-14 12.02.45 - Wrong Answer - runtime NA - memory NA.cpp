class Solution {
public:
    bool validPalindrome(string s) {
      int size = s.size();
      int i = 0, j = size - 1;
      int deletionsAllowed = 1;

      while (i <= j) {
        if (s[i] == s[j]) {
          ++i;
          --j;
        } else {
          cout << s[i] << ", " << i << "|" << s[j] << j << endl;
          if (!deletionsAllowed) return false;
          --deletionsAllowed;
          if (s[i] == s[j - 1]) { cout << "j" <<endl; --j; }
          else if (s[i + 1] == s[j]) { cout << "i" <<endl; ++i; }
          else return false;
        }
      }

      return true;
    }
};