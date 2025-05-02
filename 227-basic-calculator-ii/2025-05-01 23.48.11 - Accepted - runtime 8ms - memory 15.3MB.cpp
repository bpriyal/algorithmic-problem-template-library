class Solution {
public:
    int calculate(string s) {
      int size = s.size();
      stack<int> st;
      int currentNum = 0;
      int sign = '+';

      for (int i = 0; i < size; ++i) {
        char c = s[i];
        if (isdigit(c)) currentNum = currentNum * 10 + (c - '0');
        if (i == size - 1 || (!iswspace(c) && !isdigit(c))) {
          if (sign == '+') {
            st.emplace(currentNum);
          } else if (sign == '-') {
            st.emplace(-currentNum);
          } else if (sign == '*' || sign == '/') {
            auto top = st.top(); st.pop();
            st.emplace(sign == '*' ? top * currentNum : top / currentNum);
          }
          currentNum = 0;
          sign = c;
        }
      }
      int result = 0;
      while (!st.empty()) { result += st.top(); st.pop(); }
      return result;
    }
};