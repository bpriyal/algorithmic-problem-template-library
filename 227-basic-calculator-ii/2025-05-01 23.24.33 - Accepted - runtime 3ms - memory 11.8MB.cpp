class Solution {
public:
    int calculate(string s) {
      int size = s.size();
      int currentNum = 0;
      char sign = '+';
      int prevNum = 0;
      int result = 0;

      for (int i = 0; i < size; ++i) {
        char c = s[i];
        if (isdigit(c)) {
          currentNum = currentNum * 10 + (c - '0');
        }
        if (i == size - 1 || !isdigit(c) && !iswspace(c)) {
          if (sign == '+') {
            result += prevNum;
            prevNum = currentNum;
          } else if (sign == '-') {
            result += prevNum;
            prevNum = -currentNum;
          } else if (sign == '*' || sign == '/') {
            prevNum = (sign == '*' ? prevNum * currentNum : prevNum / currentNum);
          }
          sign = c;
          currentNum = 0;
        }
      }
      return result + prevNum;
    }
};
/*
3 + 2 * 2

currentNum = 0, prevNum = 0, sign = +, result = 0
currentNum = 3, prevNum = 0, sign = +, result = 0
currentNum = 0, prevNum = 3, sign = +, result = 0
currentNum = 2, prevNum = 3, sign = +, result = 0
currentNum = 0, prevNum = 2, sign = +, result = 3
currentNum = 2, prevNum = 2, sign = +, result = 3
*/