class Solution {
    unordered_set<string> result;
    int minRemoved = INT_MAX;
    int size;
    void recurse(const string& s, int i, int leftCount, int rightCount, int leftToRemove, int rightToRemove, string& runStr) {
      if (i == size) {
        if (!leftToRemove && !rightToRemove) result.emplace(runStr);
      } else {
          if (s[i] == '(') {
            if (leftToRemove) recurse(s, i + 1, leftCount, rightCount, leftToRemove - 1, rightToRemove, runStr);
            runStr += s[i];
            recurse(s, i + 1, leftCount + 1, rightCount, leftToRemove, rightToRemove, runStr);
            runStr.pop_back();
          } else if (s[i] == ')') {
            if (rightToRemove) recurse(s, i + 1, leftCount, rightCount, leftToRemove, rightToRemove - 1, runStr);
            if (leftCount > rightCount) {
              runStr += s[i];
              recurse(s, i + 1, leftCount, rightCount + 1, leftToRemove, rightToRemove, runStr);
              runStr.pop_back();
            }
          } else {
            runStr += s[i];
            recurse(s, i + 1, leftCount, rightCount, leftToRemove, rightToRemove, runStr);
            runStr.pop_back();
          }
      }
    }
    pair<int, int> countInvalidLeftRight(const string& s) {
      int left = 0, right = 0;
      for (char c : s) {
        if (c == '(') ++left;
        else if (c == ')') {
          if (left > 0) --left;
          else ++right;
        }
      }
      return {left, right};
    }
public:
    vector<string> removeInvalidParentheses(string s) {
      size = s.size();
      string runStr;
      auto [leftToRemove, rightToRemove] = countInvalidLeftRight(s);
      recurse(s, 0, 0, 0, leftToRemove, rightToRemove, runStr);
      vector<string> res(result.begin(), result.end());
      return res;
    }
};