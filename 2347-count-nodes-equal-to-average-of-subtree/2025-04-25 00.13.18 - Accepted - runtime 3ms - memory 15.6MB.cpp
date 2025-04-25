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
    int nodes;
    pair<int, int> util(TreeNode* root) {
      if (!root) return {0, 0};
      auto [sumLeft, nodesLeft] = util(root->left);
      auto [sumRight, nodesRight] = util(root->right);
      int avg = (sumLeft + sumRight + root->val) / (nodesLeft + nodesRight + 1);
      nodes += avg == root->val;
      return { sumLeft + sumRight + root->val, nodesLeft + nodesRight + 1 };
    }
public:
    int averageOfSubtree(TreeNode* root) {
      nodes = 0;
      util(root);
      return nodes;
    }
};