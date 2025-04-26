class Solution {
public:
    string decodeString(string s) {
      stack<int> intSt;
      stack<string> strSt;
      int currentNum = 0;
      string currentStr;

      for (int i = 0; i < s.size(); ++i) {
        auto c = s[i];
        if (isdigit(c)) currentNum = currentNum * 10 + (c - '0');
        else if (isalpha(c)) currentStr = currentStr + c;
        else if (c == '[') {
          intSt.emplace(currentNum);
          strSt.emplace(currentStr);
          currentNum = 0;
          currentStr = "";
        } else if (c == ']') {
          auto num = intSt.top(); intSt.pop();
          auto str = strSt.top(); strSt.pop();
          for (int j = 0; j < num; ++j) {
            str += currentStr;
          }
          currentStr = str;
        }
      }
      return currentStr;
    }
};