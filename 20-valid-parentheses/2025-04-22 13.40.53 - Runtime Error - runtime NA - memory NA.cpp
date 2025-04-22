class Solution {
    unordered_map<char, char> bracketsMap = {{'}', '{'}, {')', '('}, {']', '['}};
public:
    bool isValid(string s) {
      int size = s.size();
      stack<char> st;
      for (int i = 0; i < size; ++i) {
        const auto& c = s[i];
        if (c == '{' || c == '[' || c == '(') st.emplace(c);
        else {
          if (st.top() != bracketsMap[c]) return false;
          st.pop();
        }
      }
      return st.empty();
    }
};