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

      auto leftResult = util(root->left, p, q);
      auto rightResult = util(root->right, p, q);
      auto mid = root == p || root == q;

      if (leftResult + rightResult + mid >= 2) lca = root;
      
      return leftResult + rightResult + mid > 0;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      util(root, p, q);
      return lca;
    }
};

// Time Compleixty = O(N)
// Space Compleixty = O(logH) => O(N)