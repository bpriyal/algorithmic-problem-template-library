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
    vector<vector<int>> verticalOrder(TreeNode* root) {
      vector<vector<int>> result;
      if (!root) return result;

      map<int, vector<int>> cache;
      queue<pair<TreeNode*, int>> q;
      q.emplace(make_pair(root, 0));

      while (!q.empty()) {
        auto [node, pos] = q.front();
        q.pop();
        cache[pos].emplace_back(node->val);

        if (node->left) q.emplace(make_pair(node->left, pos - 1));
        if (node->right) q.emplace(make_pair(node->right, pos + 1));
      }

      for (const auto& [pos, elements] : cache) result.emplace_back(elements);
      return result;
    }
};