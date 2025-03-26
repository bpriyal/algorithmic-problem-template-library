class Solution {
public:
    bool isValid(string s) {
      int bracket = 0, curlyBracket = 0, squareBracket = 0;

      for (const char& c : s) {
        switch (c) {
          case '(': ++bracket; break;
          case ')': {
            if (bracket == 0) return false;
            --bracket;
            break;
          }
          case '[': ++squareBracket; break;
          case ']': {
            if (squareBracket == 0) return false;
            --squareBracket;
            break;
          }
          case '{': ++curlyBracket; break;
          case '}': {
            if (curlyBracket == 0) return false;
            --curlyBracket;
            break;
          }
        }
      }
      return !bracket && !curlyBracket && !squareBracket;
    }
};