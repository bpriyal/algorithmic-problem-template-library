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
    int _result;
    bool _isBST(TreeNode* root) {
        bool isBST = true;
        if (root->left && root->val <= root->left->val) isBST = false;
        if (root->right && root->val >= root->right->val) isBST = false;
        return isBST;
    }
    pair<int, bool> _largestBSTSubtree(TreeNode* root) {
        if (!root) return {0, true};
        auto left = _largestBSTSubtree(root->left);
        auto right = _largestBSTSubtree(root->right);
        if (_isBST(root) && left.second && right.second) {
            int tempResult = 1 + left.first + right.first;
            _result = max(_result, tempResult);
            cout<<root->val<<", tempResult: "<<tempResult<<endl;
            return {tempResult, true};
        }
        return { std::numeric_limits<int>::min(), false };
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        _largestBSTSubtree(root);
        return _result;
    }
};