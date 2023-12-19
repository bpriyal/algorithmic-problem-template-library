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
    int _result = 0;
    int _countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        bool isUnivalSubtree = true;
        if (root->left) {
            int left = _countUnivalSubtrees(root->left);
            isUnivalSubtree = isUnivalSubtree && root->val == root->left->val && left;
        }
        if (root->right) {
            int right = _countUnivalSubtrees(root->right);
            isUnivalSubtree = isUnivalSubtree && root->val == root->right->val && right;
        }
        if (isUnivalSubtree) ++_result;
        return isUnivalSubtree;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        _countUnivalSubtrees(root);
        return _result;
    }
};