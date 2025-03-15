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
    pair<bool, bool> util(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (!root) return { false, false };

      auto leftResult = util(root->left, p, q);
      auto rightResult = util(root->right, p, q);

      if (root == p && (leftResult.second || rightResult.second)) lca = root;
      else if (root == q && (leftResult.first || rightResult.first)) lca = root;
      else if (leftResult.first && rightResult.second) lca = root;
      else if (leftResult.second && rightResult.first) lca = root;

      if ((root == p && (leftResult.second || rightResult.second)) ||
          (root == q && (leftResult.first || rightResult.first)) ||
          (leftResult.first && rightResult.second) ||
          (leftResult.second && rightResult.first)) {
        lca = root;
      }
      return { (root == p || leftResult.first || rightResult.first), (root == q || leftResult.second || rightResult.second) };
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      util(root, p, q);
      return lca;
    }
};

// Time Compleixty = O(N)
// Space Compleixty = O(logH) => O(N)