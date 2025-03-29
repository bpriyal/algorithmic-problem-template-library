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
      if (root->left) {
        // cout << "root: " << root->left->val << ", parent: " << root->val << endl;
        parentMap.try_emplace(root->left, root);
        dfs(root->left, parentMap);
      }
      if (root->right) {
        parentMap.try_emplace(root->right, root);
        dfs(root->right, parentMap);
      }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      unordered_map<TreeNode*, TreeNode*> parentMap;
      dfs(root, parentMap); // build parent links
      queue<pair<TreeNode*, int>> q;
      q.emplace(target, 0);
      vector<int> result;

      unordered_set<TreeNode*> visited;
      while (!q.empty()) {
        const auto& [node, distance] = q.front(); q.pop();
        if (visited.count(node)) continue;
        visited.emplace(node);
        if (distance == k) result.emplace_back(node->val);
        if (distance > k) break;

        if (auto it = parentMap.find(node); it != parentMap.end()) {
          // cout << "node: " << node->val << ", parent: " << it->second->val << endl;
          q.emplace(it->second, distance + 1);
        }
        if (node->left) q.emplace(node->left, distance + 1);
        if (node->right) q.emplace(node->right, distance + 1);
      }

      return result;
    }
};