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

      unordered_map<int, vector<int>> colToElementsMap;
      int minCol = INT_MAX;
      int maxCol = INT_MIN;

      queue<pair<TreeNode*, int>> q;
      q.emplace(root, 0);

      while (!q.empty()) {
        const auto& [temp, col] = q.front();
        q.pop();

        auto [it, success] = colToElementsMap.try_emplace(col, vector<int>());
        it->second.emplace_back(temp->val);

        if (temp->left) q.emplace(temp->left, col - 1);
        if (temp->right) q.emplace(temp->right, col + 1);

        minCol = min(minCol, col);
        maxCol = max(maxCol, col);
      }

      for (int i = minCol; i <= maxCol; ++i) {
        auto it = colToElementsMap.find(i);
        if (it != colToElementsMap.end()) result.emplace_back(it->second);
      }

      return result;
    }
};