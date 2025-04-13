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
    vector<int> rightSideView(TreeNode* root) {
      vector<int> result;
      if (!root) return result;

      queue<TreeNode*> q;
      q.emplace(root);

      while (!q.empty()) {
        int size = q.size();
        TreeNode* temp = nullptr;
        for (int i = 0; i < size; ++i) {
          temp = q.front();
          q.pop();
          if (temp->left) q.emplace(temp->left);
          if (temp->right) q.emplace(temp->right);
        }
        result.emplace_back(temp->val);
      }

      return result;
    }
};