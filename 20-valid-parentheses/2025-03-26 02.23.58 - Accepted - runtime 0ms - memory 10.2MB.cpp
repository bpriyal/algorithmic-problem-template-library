class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      unordered_map<char, char> closeOpenMap = {{')', '('}, {']', '['}, {'}', '{'}};

      for (const char& c : s) {
        if (c == '(' || c == '{' || c == '[') st.emplace(c);
        else {
          if (st.empty() || st.top() != closeOpenMap[c]) return false;
          st.pop();
        }
      }

      return st.empty();
    }
};