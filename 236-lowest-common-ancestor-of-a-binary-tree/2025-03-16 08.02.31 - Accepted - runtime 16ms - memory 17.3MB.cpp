/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* lca = nullptr;
    int util(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (!root) return 0;

      int left = util(root->left, p, q);
      int right = util(root->right, p, q);
      int mid = root == p || root == q;

      if (left + right + mid >= 2) lca = root;

      return left + right + mid > 0;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      util(root, p, q);
      return lca;
    }
};