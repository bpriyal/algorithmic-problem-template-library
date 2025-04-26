class Solution {
public:
    bool isNumber(string s) {
      int size = s.size();
      bool seenDigit = false;
      bool seenDot = false;
      bool seenExponent = false;
      for (int i = 0; i < size; ++i) {
        if (isdigit(s[i])) {
          seenDigit = true;
        }
        else if (s[i] == '+' || s[i] == '-') {
          if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
        } else if (s[i] == 'e' || s[i] == 'E') {
          if (seenExponent || !seenDigit) return false;
          seenExponent = true;
          seenDigit = false;
        } else if (s[i] == '.') {
          if (seenDot || seenExponent) return false;
          seenDot = true;
        } else return false; // anything else return false
      }
      return seenDigit;
    }
};