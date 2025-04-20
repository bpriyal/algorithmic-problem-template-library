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
      vector<string> stack;
      stringstream ss(path);
      string temp;
      while (getline(ss, temp, '/')) {
        if (temp == "..") {
          if (!stack.empty()) stack.pop_back();
        }
        else if (temp != "." && !temp.empty()) stack.emplace_back(temp);
      }

      string result = "/";
      for (const auto& dir : stack) {
        result += dir;
        result += "/";
      }
      if (result.size() > 1) result.pop_back();
      return result;
    }
};