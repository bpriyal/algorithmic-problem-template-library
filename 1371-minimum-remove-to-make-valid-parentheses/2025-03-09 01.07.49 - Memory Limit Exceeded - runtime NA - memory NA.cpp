class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // Solution 1
        // stack<string> st;
        // string result;

        // for (int i = 0; i < s.size(); ++i) {
        //   if (isalpha(s[i])) st.emplace(string(1, s[i]));
        //   else if (s[i] == '(') st.emplace(string(1, s[i]));
        //   else if (s[i] == ')') {
        //     string temp = "";
        //     while (!st.empty()) {
        //       auto top = st.top();
        //       if (top == "(") {
        //         temp = top + temp + s[i];
        //         st.pop();
        //         st.emplace(temp);
        //         break;
        //       } else {
        //         temp = top + temp;
        //         st.pop();
        //       }
        //     }
        //     if (st.empty()) st.emplace(temp);
        //   }
        // }

        // while (!st.empty()) {
        //   auto top = st.top();
        //   if (top != "(") result = top + result;
        //   st.pop();
        // }
        // return result;

        // Solution 2, only push '(' on to the stack.
        // stack<int> st;
        // unordered_set<int> indexesToRemove;
        // string result;

        // for (int i = 0; i < s.size(); ++i) {
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
        // for (int i = 0; i < s.size(); ++i) {
        //   if (!indexesToRemove.count(i)) result += s[i];
        // }
        // return result;

        //solution 3
        string result;
        int balance = 0;
        for (int i = 0; i < s.size(); ++i) {
          if (s[i] == '(') ++balance;
          else if (s[i] == ')') {
            if (balance == 0) continue;
            --balance;
          }
          result = result + s[i];
        }
        cout<< result<<balance<<endl;
  
        string temp;
        for (int i = result.size() - 1; i >= 0; --i) {
          if (result[i] == '(' && balance > 0) {
            --balance;
            continue;
          }
          temp = result[i] + temp;
        }
        return temp;
    }
};

// Time Complexity: O(n), amortized 
// Space Complexity: O(n)