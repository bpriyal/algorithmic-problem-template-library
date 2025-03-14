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
    bool isFound(TreeNode* root, TreeNode* toSearch) {
      if (!root) return false;
      if (root == toSearch) return true;
      return isFound(root->left, toSearch) || isFound(root->right, toSearch);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      bool pFound = isFound(root, p);
      bool qFound = isFound(root, q);

      if (pFound && qFound) {
        lca = root;
        lowestCommonAncestor(root->left, p, q);
        lowestCommonAncestor(root->right, p, q);
      }
      return lca;
    }
};