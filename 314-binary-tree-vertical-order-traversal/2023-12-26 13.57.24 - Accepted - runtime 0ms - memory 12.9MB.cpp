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
    std::map<int, vector<int>> _cache;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> verticalOrder;
        if (!root) return verticalOrder;
        queue<pair<TreeNode*, int>> traverse;
        traverse.emplace(root, 0);
        while (!traverse.empty()) {
            int size = traverse.size();
            for (int i = 0; i < size; ++i) {
                const auto [treeNode, column] = traverse.front();
                traverse.pop();
                // populate map
                if (!_cache.contains(column)) _cache.emplace(column, vector<int>());
                _cache[column].emplace_back(treeNode->val);
                // populate queue
                if (treeNode->left) traverse.emplace(treeNode->left, column - 1);
                if (treeNode->right) traverse.emplace(treeNode->right, column + 1);
            }
        }
        for (const auto& [ignore, elements] : _cache) {
            verticalOrder.emplace_back(elements);
        }
        return verticalOrder;
    }
};
