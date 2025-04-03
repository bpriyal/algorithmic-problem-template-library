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
    int closestVal;
    void util(TreeNode* root, double target) {
      if (!root) return;
      if (abs(root->val - target) < abs(closestVal - target)) closestVal = root->val;

      if (root->val == target) return;
      else if (root->val <= target) util(root->right, target);
      else util(root->left, target);
    }
public:
    int closestValue(TreeNode* root, double target) {
      closestVal = root->val;
      util(root, target);
      return closestVal;
    }
};