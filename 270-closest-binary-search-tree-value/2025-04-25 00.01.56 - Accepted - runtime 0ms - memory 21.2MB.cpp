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
    double closest;
    void util(TreeNode* root, double target) {
      if (!root) return;
      double currentDiff = abs(root->val - target);
      double existingDiff = abs(closest - target);
      if (currentDiff == existingDiff) closest = closest > root->val ? root->val : closest;
      else if (currentDiff < existingDiff) closest = root->val;
      util(root->left, target);
      util(root->right, target);
    }
public:
    int closestValue(TreeNode* root, double target) {
      closest = root->val;
      util(root, target);
      return closest;
    }
};