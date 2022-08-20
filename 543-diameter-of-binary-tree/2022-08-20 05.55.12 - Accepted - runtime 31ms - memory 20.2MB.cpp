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
    int diameter;
    
    int util(TreeNode* root) {
        if (!root) return 0;
        
        int leftHeight = util(root->left);
        int rightHeight = util(root->right);
        
        diameter = max(diameter, leftHeight + rightHeight);
        
        return max(leftHeight, rightHeight) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        
        util(root);
        
        return diameter;
    }
};