class Solution {
public:
    string simplifyPath(string path) {
      int size = path.size();
      deque<string> st;
      string current;

      for (int i = 0; i < size; ++i) {
        auto cchar = path[i];
        if (cchar == '/') {
          if (!current.empty()) {
            if (current == "..") {
              if(!st.empty()) st.pop_back();
            } else if (current != ".") st.emplace_back(current);
            current = "";
          }
        }
        else {
          current += cchar;
        }
      }

      if (!current.empty()) {
        if (current == "..") {
          if(!st.empty()) st.pop_back();
        } else if (current != ".") st.emplace_back(current);
      }

      string result = "/";
      while (!st.empty()) {
        result += st.front() + (st.size() == 1 ? "" : "/");
        st.pop_front();
      }
      
      return result;
    }
};