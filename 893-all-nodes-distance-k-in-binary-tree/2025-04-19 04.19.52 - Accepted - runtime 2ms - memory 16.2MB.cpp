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
    void dfs(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
      if (!root) return;
      parentMap.try_emplace(root, parent);
      dfs(root->left, root, parentMap);
      dfs(root->right, root, parentMap);
      // if (root->left) parentMap.emplace(root->left, root);
      // if (root->right) parentMap.emplace(root->right, root);
      // dfs(root->left, parentMap);
      // dfs(root->right, parentMap);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      unordered_map<TreeNode*, TreeNode*> parentMap;
      dfs(root, nullptr, parentMap);

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
          if (it != parentMap.end() && it->second && !visited.count(it->second)) {
            q.emplace(it->second);
            visited.emplace(it->second);
          }
          if (node->left && !visited.count(node->left)) {
            q.emplace(node->left);
            visited.emplace(node->left);
          }
          if (node->right && !visited.count(node->right)) {
            q.emplace(node->right);
            visited.emplace(node->right);
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

// O(N) + O(N)
// O(N) + O(N) + O(N + 1/2)