class Solution {
public:
    int myAtoi(string s) {
      int size = s.size();
      bool positive = true;
      int result = 0;
      int index = 0;
      int sign = 1;
      
      while (index < size && s[index] == ' ') ++index;
      if (index < size && s[index] == '+') {
        sign = 1;
        ++index;
      } else if (index < size && s[index] == '-') {
        sign = -1;
        ++index;
      }

      while (index < size && isdigit(s[index])) {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[index] - '0' >= INT_MAX % 10)) {
          return sign == 1 ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (s[index] - '0');
        ++index;
      }

      return sign * result;
    }
};