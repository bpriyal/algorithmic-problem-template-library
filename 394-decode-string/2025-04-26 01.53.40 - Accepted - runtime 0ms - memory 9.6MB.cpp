class Solution {
public:
    string decodeString(string s) {
      stack<string> stringSt;
      stack<int> intSt;
      string currentStr;
      string result;
      int currentNum = 0;
      for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (isalpha(c)) {
          currentStr += c;
        } else if (isdigit(c)) {
          currentNum = currentNum * 10 + (c - '0');
        } else if (c == '[') {
          intSt.emplace(currentNum);
          stringSt.emplace(currentStr);
          currentNum = 0;
          currentStr = "";
        } else if (c == ']') {
          auto num = intSt.top(); intSt.pop();
          auto str = stringSt.top(); stringSt.pop();
          for (int j = 0; j < num; ++j) {
            str += currentStr;
          }
          currentStr = str;
        }
      }
      return currentStr;
    }
};