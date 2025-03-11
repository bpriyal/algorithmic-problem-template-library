class Solution {
    // int extractNum(const string& s, int& startIdx, int size) {
    //   int num = 0;
    //   while (startIdx < size) {
    //     auto c = s[startIdx];
    //     if (c == ' ') {
    //       ++startIdx;
    //       continue;
    //     }
    //     if (!isdigit(c)) break;
    //     num = num * 10 + (c - '0');
    //     ++startIdx;
    //   }
    //   return num;
    // }
public:
    int calculate(string s) {
      int size = s.size();

      int currentNum = 0;
      int lastNum = 0;
      int result = 0;
      char sign = '+';

      for (int i = 0; i < size; ++i) {
        auto currentChar = s[i];

        if (isdigit(currentChar)) {
          currentNum = currentNum * 10 + (currentChar - '0');
        } 
        if ((!isdigit(currentChar) && !iswspace(currentChar)) || i == size - 1) {
          if (sign == '+' || sign == '-') {
            result += lastNum;
            lastNum = sign == '+' ? currentNum : -currentNum;
          } else if (sign == '*' || sign == '/') {
            lastNum = sign == '*' ? lastNum * currentNum : lastNum / currentNum;
          }
          currentNum = 0;
          sign = currentChar;
        }
      }

      result += lastNum;
      return result;
    }
};