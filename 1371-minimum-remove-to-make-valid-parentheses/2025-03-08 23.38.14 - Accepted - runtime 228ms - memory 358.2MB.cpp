class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<string> st;
        string result;

        for (int i = 0; i < s.size(); ++i) {
          if (isalpha(s[i])) st.emplace(string(1, s[i]));
          else if (s[i] == '(') st.emplace(string(1, s[i]));
          else if (s[i] == ')') {
            string temp = "";
            while (!st.empty()) {
              auto top = st.top();
              if (top == "(") {
                temp = top + temp + s[i];
                st.pop();
                st.emplace(temp);
                break;
              } else {
                temp = top + temp;
                st.pop();
              }
            }
            if (st.empty()) st.emplace(temp);
          }
        }

        while (!st.empty()) {
          auto top = st.top();
          if (top != "(") result = top + result;
          st.pop();
        }
        return result;
    }
};