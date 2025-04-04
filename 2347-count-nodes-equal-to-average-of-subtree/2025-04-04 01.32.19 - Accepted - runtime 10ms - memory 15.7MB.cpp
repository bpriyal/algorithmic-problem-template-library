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
    int count = 0;
    pair<int, int> util(TreeNode* root) {
      if (!root) return {0, 0};
      auto [leftSum, leftCount] = util(root->left);
      auto [rightSum, rightCount] = util(root->right);

      auto subTreeSum = leftSum + rightSum + root->val;
      auto subTreeCount = leftCount + rightCount + 1;
      if (subTreeSum / subTreeCount == root->val) ++count;

      return {subTreeSum, subTreeCount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
      util(root);
      return count;
    } 
};