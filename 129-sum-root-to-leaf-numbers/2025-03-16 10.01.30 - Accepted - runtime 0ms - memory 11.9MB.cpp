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
    int result = 0;
    void util(TreeNode* root, int s) {
      if (!root) return;

      s = s * 10 + root->val;
      if (!root->left && !root->right) {
        result += s;
      } else {
        util(root->left, s);
        util(root->right, s);
      }
    }
public:
    int sumNumbers(TreeNode* root) {
      util(root, 0);
      return result;
    }
};