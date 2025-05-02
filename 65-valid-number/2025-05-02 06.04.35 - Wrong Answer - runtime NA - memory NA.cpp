class Solution {
public:
    bool isNumber(string s) {
      int size = s.size();
      bool seenDigit = false, seenDot = false, seenExp = false, seenSign = false;

      for (int i = 0; i < size; ++i) {
        char c = s[i];
        if (isdigit(c)) {
          seenDigit = true;
        } else if (c == '-' || c == '+') {
          if (seenDigit || seenSign) return false;
          seenSign = true;
        } else if (c == '.') {
          if (seenExp || seenDot) return false;
          seenDot = true;
        } else if (isalpha(c)) {
          if (c == 'e' || c == 'E') {
            if (seenExp || !seenDigit) return false;
            seenExp = true;
            seenDigit = false; // reset, there should be a new digit
            seenDot = false;
            seenSign = false;
          } else return false;
        }
      }
      return seenDigit;
    }
};