class Solution {
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
          if (sign == '+' || sign == '-') {
            st.emplace(sign == '+' ? currentNum : -currentNum);
          } else if (sign == '*' || sign == '/') {
            auto op1 = st.top();
            st.pop();
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