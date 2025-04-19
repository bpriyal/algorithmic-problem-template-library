/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
      if (!root) return;
      if (root->left) parentMap.emplace(root->left, root);
      if (root->right) parentMap.emplace(root->right, root);
      dfs(root->left, parentMap);
      dfs(root->right, parentMap);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      unordered_map<TreeNode*, TreeNode*> parentMap;
      // parentMap.emplace(root, nullptr);
      dfs(root, parentMap);

      queue<TreeNode*> q;
      q.emplace(target);
      int distance = 0;
      unordered_set<TreeNode*> visited;
      visited.emplace(target);

      while (!q.empty()) {
        if (distance == k) break;
        int size = q.size();

        for (int i = 0; i < size; ++i) {
          auto node = q.front();
          q.pop();

          auto it = parentMap.find(node);
          if (it != parentMap.end() && !visited.count(it->second)) {
            q.emplace(it->second);
          }
          if (node->left && !visited.count(node->left)) {
            q.emplace(node->left);
          }
          if (node->right && !visited.count(node->right)) {
            q.emplace(node->right);
          }
        }
        ++distance;
      }

      vector<int> result;
      while (!q.empty()) {
        result.emplace_back(q.front()->val);
        q.pop();
      }
      return result;
    }
};