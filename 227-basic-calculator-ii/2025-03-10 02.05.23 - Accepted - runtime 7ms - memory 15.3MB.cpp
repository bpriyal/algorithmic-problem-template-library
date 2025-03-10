class Solution {
    int extractNum(const string& s, int& startIdx, int size) {
      int num = 0;
      while (startIdx < size) {
        auto c = s[startIdx];
        if (c == ' ') {
          ++startIdx;
          continue;
        }
        if (!isdigit(c)) break;
        num = num * 10 + (c - '0');
        ++startIdx;
      }
      return num;
    }
public:
    int calculate(string s) {
      int size = s.size();
      stack<int> st;

      int i = 0;
      while (i < size) {
        auto c = s[i];
        if (c == ' ') ++i;
        else if (c == '+' || c == '-') {
          auto num = extractNum(s, ++i, size);
          st.emplace(c == '-' ? -1 * num : num);
        } else if (c == '*' || c == '/') {
          auto op1 = st.top(); st.pop();
          auto op2 = extractNum(s, ++i, size);
          st.emplace(c == '*'? op1 * op2 : op1 / op2);
        } else if (isdigit(c)) {
          auto num = extractNum(s, i, size);
          st.emplace(num);
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