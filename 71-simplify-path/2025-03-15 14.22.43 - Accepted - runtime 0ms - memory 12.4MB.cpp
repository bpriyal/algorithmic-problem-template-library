class Solution {
public:
    string simplifyPath(string path) {
      int size = path.size();
      stack<string> st;
      string current;

      for (int i = 0; i < size; ++i) {
        auto cchar = path[i];
        if (cchar == '/') {
          if (!current.empty()) {
            if (current == "..") {
              if(!st.empty()) st.pop();
            } else if (current != ".") st.emplace(current);
            current = "";
          }
        }
        else {
          current += cchar;
        }
      }

      if (!current.empty()) {
        if (current == "..") {
          if(!st.empty()) st.pop();
        } else if (current != ".") st.emplace(current);
      }

      if (st.empty()) return "/";

      string result;
      while (!st.empty()) {
        result = "/" + st.top() + result;
        st.pop();
      }

      return result;
    }
};