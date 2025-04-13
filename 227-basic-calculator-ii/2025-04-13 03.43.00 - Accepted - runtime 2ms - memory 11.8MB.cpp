class Solution {
public:
    int calculate(string s) {
      int size = s.size();
      int sign = '+';
      int result = 0;
      int currentNum = 0;
      int lastNum = 0;

      for (int i = 0; i < size; ++i) {
        if (isdigit(s[i])) {
          currentNum = currentNum * 10 + (s[i] - '0');
        }
        if (i == size - 1 || (!iswspace(s[i]) && !isdigit(s[i]))) {
          if (sign == '+') {
            result += lastNum;
            lastNum = currentNum;
          } else if (sign == '-') {
            result += lastNum;
            lastNum = -currentNum;
          } else if (sign == '*' || sign == '/') {
            lastNum = sign == '*' ? lastNum * currentNum : lastNum / currentNum;
          }

          sign = s[i];
          currentNum = 0;
        }
      }

      return result + lastNum; 
    }
};