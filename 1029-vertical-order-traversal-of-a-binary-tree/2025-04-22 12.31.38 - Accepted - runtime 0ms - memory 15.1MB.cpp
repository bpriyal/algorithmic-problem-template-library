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
      unordered_map<int, vector<pair<int, int>>> colToNodeMap;
      queue<pair<TreeNode*, int>> q;
      q.emplace(make_pair(root, 0));
      int maxCol = INT_MIN;
      int minCol = INT_MAX;
      int distance = 0;

      while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
          auto [node, col] = q.front();
          q.pop();
          auto [it, success] = colToNodeMap.try_emplace(col, vector<pair<int, int>>());
          it->second.emplace_back(make_pair(node->val, distance));
          maxCol = max(maxCol, col);
          minCol = min(minCol, col);

          if (node->left) q.emplace(make_pair(node->left, col - 1));
          if (node->right) q.emplace(make_pair(node->right, col + 1));
        }
        ++distance;
      }

      vector<vector<int>> result(maxCol - minCol + 1);
      for (int i = minCol; i <= maxCol; ++i) {
        sort(colToNodeMap[i].begin(), colToNodeMap[i].end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
          if (p1.second == p2.second) return p1.first < p2.first;
          return p1.second < p2.second;
        });
        for (const auto& p : colToNodeMap[i]) result[i - minCol].emplace_back(p.first);
      }
      return result;
    }
};