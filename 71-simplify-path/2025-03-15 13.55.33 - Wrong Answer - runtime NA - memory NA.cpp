class Solution {
    string getPeriods(string path, int& start, int size) {
      stringstream periods;
      while (start < size && path[start] != '/') {
        periods << path[start];
        ++start;
      }
      return periods.str();
    }
public:
    string simplifyPath(string path) {
      int size = path.size();
      stack<string> st;
      string current;

      for (int i = 0; i < size; ++i) {
        auto cchar = path[i];
        if (cchar == '/') {
          if (!current.empty()) {
            st.emplace(current);
            current = "";
          }
        }
        else if (cchar == '.' && (i == 0 || path[i - 1] == '/')) {
          auto periods = getPeriods(path, i, size);
          cout << "periods: " << periods << endl;
          if (periods.size() == 2 && !st.empty()) st.pop();
          else if (periods.size() > 2) st.emplace(periods);
        } else {
          current += cchar;
        }
      }

      if (!current.empty()) st.emplace(current);

      if (st.empty()) return "/";

      string result;
      while (!st.empty()) {
        cout << st.top() <<endl;
        result = "/" + st.top() + result;
        st.pop();
      }

      return result;
    }
};