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
    void _longestConsecutive(TreeNode* root, int lastVal, int sequenceLen) {
        if (!root) return;
        if (sequenceLen == 0 || lastVal + 1 == root->val) ++sequenceLen;
        else sequenceLen = 1;
        _result = max(_result, sequenceLen);
        _longestConsecutive(root->left, root->val, sequenceLen);
        _longestConsecutive(root->right, root->val, sequenceLen);
    }
public:
    int longestConsecutive(TreeNode* root) {
        _longestConsecutive(root, -1, 0);
        return _result;
    }
};