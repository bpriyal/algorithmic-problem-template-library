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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      unordered_map<int, vector<int>> colToNodeMap;
      queue<pair<TreeNode*, int>> q;
      q.emplace(make_pair(root, 0));
      int maxCol = INT_MIN;
      int minCol = INT_MAX;

      while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
          auto [node, col] = q.front();
          q.pop();
          auto [it, success] = colToNodeMap.try_emplace(col, vector<int>());
          it->second.emplace_back(node->val);
          maxCol = max(maxCol, col);
          minCol = min(minCol, col);

          if (node->left) q.emplace(make_pair(node->left, col - 1));
          if (node->right) q.emplace(make_pair(node->right, col + 1));
        }
      }

      vector<vector<int>> result;
      for (int i = minCol; i <= maxCol; ++i) {
        sort(colToNodeMap[i].begin(), colToNodeMap[i].end());
        result.emplace_back(colToNodeMap[i]);
      }
      return result;
    }
};