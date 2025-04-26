class Solution {
public:
    int myAtoi(string s) {
      int size = s.size();
      bool isPositive = true;
      int number = 0;
      bool isDigitFound = false;
      
      for (int i = 0; i < size; ++i) {
        if (iswspace(s[i])) {
          if (isDigitFound) break;
        } else if (isalpha(s[i])) {
          break;
        } else if (s[i] == '+' || s[i] == '-') {
          if (isDigitFound) break;
          else isPositive = s[i] == '+';
        } else if (isdigit(s[i])) {
          number = number * 10 + (s[i] - '0');
          isDigitFound = true;
        }
      }

      return number * (isPositive ? 1 : -1);
    }
};