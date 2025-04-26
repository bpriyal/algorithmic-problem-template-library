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
    int size;
    int extractNum(const string& s, int& i) {
      int num = 0;
      bool isNegative = false;
      if (s[i] == '-') {
        isNegative = true;
        ++i;
      }
      while (i < size && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        ++i;
      }
      return num * (isNegative ? -1 : 1);
    }
    TreeNode* util(const string& s, int& i) {
      if (i == size) return nullptr;
      auto node = new TreeNode(extractNum(s, i));
      if (s[i] == '(') node->left = util(s, ++i);
      if (s[i] == '(') node->right = util(s, ++i);
      ++i;
      return node;
    }
public:
    TreeNode* str2tree(string s) {
      size = s.size();
      int i = 0;
      return util(s, i);
    }
};