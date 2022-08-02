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
    bool result;
    int util(TreeNode* root) {
        if (!root || !result) return 0;
        
        int left = util(root->left);
        int right = util(root->right);
        
        result = abs(left-right) <= 1;
        
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        result = true;
        util(root);
        return result;
    }
};