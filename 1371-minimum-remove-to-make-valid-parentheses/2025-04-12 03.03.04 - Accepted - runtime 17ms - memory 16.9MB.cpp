class Solution {
public:
    string minRemoveToMakeValid(string s) {
      int size = s.size();
      unordered_set<int> indexesToRemove;
      stack<int> st;

      for (int i = 0; i < size; ++i) {
        if (s[i] == '(') st.emplace(i);
        else if (s[i] == ')') {
          if (st.empty()) indexesToRemove.emplace(i);
          else st.pop();
        }
      }

      while (!st.empty()) {
        indexesToRemove.emplace(st.top());
        st.pop();
      }

      stringstream result;

      for (int i = 0; i < size; ++i) {
        if (!indexesToRemove.count(i)) result << s[i];
      }
      return result.str();
    }
};