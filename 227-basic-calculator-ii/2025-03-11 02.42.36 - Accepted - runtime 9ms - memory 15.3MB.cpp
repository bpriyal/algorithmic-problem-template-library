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
      stack<int> st;

      int currentNum = 0;
      char sign = '+';

      for (int i = 0; i < size; ++i) {
        auto currentChar = s[i];

        if (isdigit(currentChar)) {
          currentNum = currentNum * 10 + (currentChar - '0');
        } 
        if ((!isdigit(currentChar) && !iswspace(currentChar)) || i == size - 1) {
          // cout << currentChar << endl;
          if (sign == '+' || sign == '-') {
            // cout << sign << ", " << currentNum << endl;
            st.emplace(sign == '+' ? currentNum : -currentNum);
          } else if (sign == '*' || sign == '/') {
            // cout << sign << ", " << currentNum << endl;
            auto op1 = st.top(); st.pop();
            st.emplace(sign == '*' ? op1 * currentNum : op1 / currentNum);
          }
          currentNum = 0;
          sign = currentChar;
        }
      }

      int result = 0;
      while (!st.empty()) {
        result += st.top();
        st.pop();
      }
      return result;
    }
};