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
    vector<TreeNode*> result;
    TreeNode* util(TreeNode* root, const vector<int>& to_delete) {
      if (!root) return nullptr;
      root->left = util(root->left, to_delete);
      root->right = util(root->right, to_delete);
      if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
        if (root->left) result.emplace_back(root->left);
        if (root->right) result.emplace_back(root->right);
        return nullptr;
      }
      return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
      util(root, to_delete);
      if (find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end()) result.emplace_back(root);
      return result;
    }
};