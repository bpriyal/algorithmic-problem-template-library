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
    int result;
    int util(TreeNode* root) {
        if (!root) return 0;
        
        int leftHeight = util(root->left);
        int rightHeight = util(root->right);
        
        result = max(result, leftHeight + rightHeight);
        
        return max(leftHeight, rightHeight) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        result = 0;
        util(root);
        
        return result;
    }
};