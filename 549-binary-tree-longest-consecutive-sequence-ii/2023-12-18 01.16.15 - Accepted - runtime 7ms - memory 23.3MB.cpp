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
    pair<int, int> _longestConsecutive(TreeNode* root) {
         if (!root) return {0, 0};
         pair<int, int> incrDecrPair = {1, 1};
         if (root->left) {
             auto left = _longestConsecutive(root->left);
             if (root->left->val - 1 == root->val) {
                 incrDecrPair.first = left.first + 1;
             } else if (root->left->val + 1 == root->val) {
                 incrDecrPair.second = left.second + 1;
             }
         }
         if (root->right) {
            auto right = _longestConsecutive(root->right);
            if (root->right->val - 1 == root->val) {
                 incrDecrPair.first = max(incrDecrPair.first, right.first + 1);
             } else if (root->right->val + 1 == root->val) {
                 incrDecrPair.second = max(incrDecrPair.second, right.second + 1);
             }
         }
         _result = max(_result, incrDecrPair.first + incrDecrPair.second - 1);
         return incrDecrPair;
    }
public:
    int longestConsecutive(TreeNode* root) {
        _longestConsecutive(root);
        return _result;
    }
};