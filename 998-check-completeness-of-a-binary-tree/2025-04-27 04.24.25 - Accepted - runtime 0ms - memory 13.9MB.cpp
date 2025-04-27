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
    bool isCompleteTree(TreeNode* root) {
      queue<TreeNode*> q;
      q.emplace(root);
      bool missing = false;
      while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
          auto top = q.front();
          q.pop();
          if (top->left) {
            if (missing) return false;
            q.emplace(top->left);
          } else missing = true;

          if (top->right) {
            if (missing) return false;
            q.emplace(top->right);
          } else missing = true;
        }
      } 
      return true;
    }
};