/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int getNumber(const string& s, int& i) {
      int number = 0;
      bool isNegative = false;
      if (s[i] == '-') {
        ++i;
        isNegative = true;
      }
      while (isdigit(s[i])) {
        number = number * 10 + (s[i] - '0');
        ++i;
      }
      return isNegative ? -1 * number : number;
    }

    TreeNode* util(string s, int& i) {
      if (i == s.size()) return nullptr;

      TreeNode* node = new TreeNode(getNumber(s, i));
      if (s[i] == '(') node->left = util(s, ++i);
      if (s[i] == '(') node->right = util(s, ++i);

      ++i; // to skip the close bracket
      return node;
    }
public:
    TreeNode* str2tree(string s) {
      // int i = 0;
      // return util(s, i);

      int size = s.size();
      stack<TreeNode*> st;
      st.emplace(new TreeNode());
      auto* head = st.top();

      for (int i = 0; i < size; ++i) {
        cout << i << endl;
        auto* node = st.top();
        if (s[i] == '-' || isdigit(s[i])) node->val = getNumber(s, i);
        if (s[i] == '(') {
          auto* child = new TreeNode();
          if (!node->left) node->left = child;
          else node->right = child;
          st.emplace(child);
        } else if (s[i] == ')') {
          st.pop();
        }
      }

      return head;
    }
};