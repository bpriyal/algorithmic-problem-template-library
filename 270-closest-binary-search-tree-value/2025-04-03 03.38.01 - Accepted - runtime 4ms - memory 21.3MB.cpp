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
      cout << root->val << endl;
      double candidate = abs(root->val - target);
      double existingDiff = abs(closestVal - target);
      cout << "candidate: " << candidate << ", existingDiff: " << existingDiff << endl;
      if (candidate == existingDiff) closestVal = min(closestVal, root->val);
      else if (candidate < existingDiff) closestVal = root->val;

      if (root->val == target) return;
      else if (root->val < target) util(root->right, target);
      else util(root->left, target);
    }
public:
    int closestValue(TreeNode* root, double target) {
      closestVal = root->val;
      util(root, target);
      return closestVal;
    }
};