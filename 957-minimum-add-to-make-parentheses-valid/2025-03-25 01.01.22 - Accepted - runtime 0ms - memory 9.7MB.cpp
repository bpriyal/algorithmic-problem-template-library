class Solution {
public:
    int minAddToMakeValid(string s) {
      stack<char> st;
      int count = 0;

      for (char c : s) {
        if (c == '(') st.emplace(c);
        else {
          if (!st.empty()) st.pop();
          else ++count;
        }
      }

      count += st.size();
      return count;
    }
};