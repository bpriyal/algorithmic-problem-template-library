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
      cout <<"num: " << num << endl;
      return num;
    }
public:
    int calculate(string s) {
      int size = s.size();
      stack<string> st;

      int i = 0;
      while (i < size) {
        auto c = s[i];
        if (c == ' ') ++i;
        else if (c == '+' || c == '-') {
          st.emplace(string(1, c));
          ++i;
        } else if (c == '*' || c == '/') {
          auto op1 = stoi(st.top()); st.pop();
          auto op2 = extractNum(s, ++i, size);
          st.emplace(to_string(c == '*'? op1 * op2 : op1 / op2));
          cout << "st.top: " << st.top() << endl;
        } else if (isdigit(c)) {
          auto num = extractNum(s, i, size);
          st.emplace(to_string(num));
        }
      }

      while (!st.empty()) {
        if (st.size() == 1) return stoi(st.top());
        auto op2 = stoi(st.top()); st.pop();
        auto op = st.top(); st.pop();
        auto op1 = stoi(st.top()); st.pop();
        st.emplace(to_string(op == "+"? op1 + op2 : op1 - op2));
        cout << "st.top1: " << ",op2: " << op2 << ", op1: " << op1 << ", op:" << op << st.top() << endl;
      }
      return -1;
    }
};