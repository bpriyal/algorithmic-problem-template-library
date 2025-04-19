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
    int sum = 0;
    void util(TreeNode* root, int low, int high) {
      if (!root) return;
      cout << root->val << endl;
      if (root->val >= low && root->val <= high) sum += root->val;
      if (root->val >= low) util(root->left, low, high);
      if (root->val <= high) util(root->right, low, high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
      util(root, low, high);
      return sum;
    }
};