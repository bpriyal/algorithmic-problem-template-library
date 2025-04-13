class Solution {
public:
    bool isPalindrome(string s) {
      int size = s.size();
      int i = 0, j = size - 1;

      while (i < j) {
        char first = s[i];
        char second = s[j];

        if (!isalpha(first) && !isdigit(first)) ++i;
        else if (!isalpha(second) && !isdigit(second)) --j;
        else {
          // Now both are alphanumeric and should match
          if (first >= 'A' && first <= 'Z') first = first + ('a' - 'A');
          if (second >= 'A' && second <= 'Z') second = second + ('a' - 'A');

          if (first != second) return false;
          ++i;
          --j;
        }
      }
      return true;
    }
};