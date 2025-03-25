class Solution {
public:
    int minAddToMakeValid(string s) {
      int count = 0;
      int numberOpenBrackets = 0;

      for (char c : s) {
        if (c == '(') ++numberOpenBrackets;
        else {
          if (numberOpenBrackets > 0) --numberOpenBrackets;
          else ++count;
        }
      }

      count += numberOpenBrackets;
      return count;
    }
};