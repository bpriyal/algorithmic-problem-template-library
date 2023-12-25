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
    bool _isLeaf(TreeNode* root) { return !root->left && !root->right; }
    void _populateLeftBoundary(TreeNode* root, vector<int>& result) {
        while (root) {
            if (!_isLeaf(root)) result.emplace_back(root->val);
            if (root->left) root = root->left;
            else root = root->right;
        }
    }

    void _populateLeaves(TreeNode* root, vector<int>& result) {
        if (!root) return;
        if (_isLeaf(root)) result.emplace_back(root->val);
        _populateLeaves(root->left, result);
        _populateLeaves(root->right, result);
    }

    void _populateRightBoundary(TreeNode* root, vector<int>& result) {
        stack<int> st;
        while (root) {
            if (!_isLeaf(root)) st.emplace(root->val);
            if (root->right) root = root->right;
            else root = root->left;
        }
        while (!st.empty()) {
            result.emplace_back(st.top());
            st.pop();
        }
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        if (!_isLeaf(root)) result.emplace_back(root->val);
        _populateLeftBoundary(root->left, result);
        _populateLeaves(root, result);
        _populateRightBoundary(root->right, result);
        return result;
    }
};