class Solution {
public:
    bool isPalindrome(string s) {
      int i = 0;
      int j = s.size() - 1;

      while (i < j) {
        auto ci = s[i];
        auto cj = s[j];
        if (!isdigit(ci) && !isalpha(ci)) ++i;
        else if (!isdigit(cj) && !isalpha(cj)) --j;
        else if (std::toupper(ci) != std::toupper(cj)) return false;
        else {
          ++i;
          --j;
        }
      }
      return true;
    }
};