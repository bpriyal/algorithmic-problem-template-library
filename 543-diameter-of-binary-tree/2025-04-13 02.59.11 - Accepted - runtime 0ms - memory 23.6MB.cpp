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
    int maxDiameter = INT_MIN;
    int util(TreeNode* root) {
      if (!root) return 0;
      auto leftHeight = util(root->left);
      auto rightHeight = util(root->right);

      maxDiameter = max(maxDiameter, leftHeight + rightHeight);

      return max(leftHeight, rightHeight) + 1;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
      util(root);
      return maxDiameter;
    }
};