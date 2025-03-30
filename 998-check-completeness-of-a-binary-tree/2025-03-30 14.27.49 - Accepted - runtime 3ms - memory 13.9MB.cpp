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
      int expectedNodes = 1;
      bool isLast = false;

      while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
          auto* node = q.front();
          q.pop();
          if (node->left) {
            if (isLast) return false;
            q.emplace(node->left);
          } else {
            if (node->right) return false;
            isLast = true;
          }
          if (node->right) {
            if (isLast) return false;
            q.emplace(node->right);
          }
          else isLast = true;
        }
      }
      return true;
    }
};