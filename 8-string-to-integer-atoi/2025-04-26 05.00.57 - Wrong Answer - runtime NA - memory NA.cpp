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
        } else if (s[i] == '+' || s[i] == '-') {
          if (isDigitFound) break;
          else isPositive = s[i] == '+';
        } else if (isdigit(s[i])) {
          int incomingNumber = s[i] - '0';
          if (number > INT_MAX / 10 || (number == INT_MAX / 10 && incomingNumber > INT_MAX % 10)) {
            return isPositive ? INT_MAX : INT_MIN;
          }
          // if (isPositive) {
          //   if (number > INT_MAX / 10 || (number == INT_MAX / 10 && incomingNumber > INT_MAX % 10)) return INT_MAX;
          // } else {
          //   cout << incomingNumber << ", " << INT_MIN % 10 << endl;
          //   if (-number < INT_MIN / 10 || (number == INT_MIN / 10 && incomingNumber > abs(INT_MIN % 10))) return INT_MIN;
          // }
          
          number = number * 10 + (s[i] - '0');
          isDigitFound = true;
        } else break;
      }

      return number * (isPositive ? 1 : -1);
    }
};