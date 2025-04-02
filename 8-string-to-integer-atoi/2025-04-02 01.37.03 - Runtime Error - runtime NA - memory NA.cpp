class Solution {
public:
    int myAtoi(string s) {
      int size = s.size();
      bool positive = true;
      int result = 0;
      bool firstNumberFound = false;

      for (int i = 0; i < size; ++i) {
        if (s[i] == '+' || s[i] == ' ') {
          if (firstNumberFound) break;
          continue;
        }
        else if (s[i] == '-') {
          if (firstNumberFound) break;
          positive = false;
        }
        else if (isdigit(s[i])) {
          firstNumberFound = true;
          result = result * 10 + s[i] - '0';
        } else if (isalpha(s[i])) break;
      }
      return positive ? result : -result;
    }
};