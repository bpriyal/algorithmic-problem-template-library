class Solution {
    unordered_set<string> result;
    int minRemoved = INT_MAX;
    int size;
    void recurse(const string& s, int i, int leftCount, int rightCount, int remCount, string& runStr) {
      cout << runStr << endl;
      if (i == size) {
        if (leftCount == rightCount) {
          if (remCount < minRemoved) {
            cout << remCount << ", minRemoved: " << minRemoved << endl;
            minRemoved = remCount;
            result.clear();
            result.emplace(runStr);
          } else if (remCount == minRemoved) result.emplace(runStr);
        }
      } else {
          if (s[i] == '(') {
            recurse(s, i + 1, leftCount, rightCount, remCount + 1, runStr);
            runStr += s[i];
            recurse(s, i + 1, leftCount + 1, rightCount, remCount, runStr);
            runStr.pop_back();
          } else if (s[i] == ')') {
            recurse(s, i + 1, leftCount, rightCount, remCount + 1, runStr);
            if (leftCount > rightCount) {
              runStr += s[i];
              recurse(s, i + 1, leftCount, rightCount + 1, remCount, runStr);
              runStr.pop_back();
            }
          } else {
            runStr += s[i];
            recurse(s, i + 1, leftCount, rightCount, remCount, runStr);
            runStr.pop_back();
          }
      }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
      size = s.size();
      string runStr;
      recurse(s, 0, 0, 0, 0, runStr);
      vector<string> res(result.begin(), result.end());
      return res;
    }
};