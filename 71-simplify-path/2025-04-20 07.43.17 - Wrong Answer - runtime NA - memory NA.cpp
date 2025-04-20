class Solution {
    string getDotCount(const string& path, int& i) {
      string result;
      // while (path[i] == '.') {
      //   result += '.';
      //   ++i;
      // }
      // return result;
      while (i < path.size() && path[i] != '/') {
        result += path[i];
        ++i;
      }
      return result;
    }

public:
    string simplifyPath(string path) {
      string result;
      int size = path.size();
      stack<string> st;
      string currentDir;

      for (int i = 0; i < size; ++i) {
        if (path[i] == '/') {
          if (!currentDir.empty()) st.emplace(currentDir);
          currentDir = "";
        } else if (currentDir.empty() && path[i] == '.') {
          auto dotStr = getDotCount(path, i);
          auto dotStrSize = dotStr.size();
          if (dotStrSize == 1) continue;
          else if (dotStrSize == 2) {
            if (!st.empty()) st.pop();
          } else {
            st.emplace(dotStr);
          }
        } else {
          currentDir += path[i];
        }
      }

      if (!currentDir.empty()) st.emplace(currentDir);
      
      vector<string> temp;
      while (!st.empty()) {
        temp.emplace_back(st.top());
        st.pop();
      }
      reverse(temp.begin(), temp.end());

      result += "/";
      for (int i = 0; i < temp.size(); ++i) {
        result += temp[i];
        if (i != temp.size() - 1) result += "/";
      }

      return result;
    }
};