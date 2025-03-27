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
      int i = 0;
      return util(s, i);
    }
};