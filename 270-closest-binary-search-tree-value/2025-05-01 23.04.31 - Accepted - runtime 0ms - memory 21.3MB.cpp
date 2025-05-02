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
public:
    int closestValue(TreeNode* root, double target) {
      double closest = root->val;
      TreeNode* temp = root;
      while (temp) {
        double existingDiff = abs(closest - target);
        double currentDiff = abs(temp->val - target);
        if (existingDiff == currentDiff) closest = min(closest, static_cast<double>(temp->val));
        else if (existingDiff > currentDiff) closest = temp->val;
        temp = target < temp->val ? temp->left : temp->right;
      }
      return closest;
    }
};