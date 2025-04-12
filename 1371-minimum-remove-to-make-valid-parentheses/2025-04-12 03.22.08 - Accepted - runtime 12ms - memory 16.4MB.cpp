class Solution {
public:
    string minRemoveToMakeValid(string s) {
      int size = s.size();
      // unordered_set<int> indexesToRemove;
      // stack<int> st;

      // for (int i = 0; i < size; ++i) {
      //   if (s[i] == '(') st.emplace(i);
      //   else if (s[i] == ')') {
      //     if (st.empty()) indexesToRemove.emplace(i);
      //     else st.pop();
      //   }
      // }

      // while (!st.empty()) {
      //   indexesToRemove.emplace(st.top());
      //   st.pop();
      // }

      // stringstream result;

      // for (int i = 0; i < size; ++i) {
      //   if (!indexesToRemove.count(i)) result << s[i];
      // }
      // return result.str();

      stringstream ss;
      int balance = 0;
      for (int i = 0; i < size; ++i) {
        if (s[i] == '(') ++balance;
        else if (s[i] == ')') {
          if (balance == 0) continue;
          --balance;
        }
        ss << s[i];
      }

      string result = ss.str();
      if (balance == 0) return result;
      stringstream ss1;
      for (int i = result.size() - 1; i >= 0; --i) {
        if (result[i] == '(' && balance > 0) {
          --balance;
          continue;
        }
        ss1 << result[i];
      }
      result = ss1.str();
      reverse(result.begin(), result.end());
      return result;
    }
};