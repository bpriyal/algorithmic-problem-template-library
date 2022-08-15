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
    TreeNode* util(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        
        if (root->val < val) root->right = util(root->right, val);
        else root->left = util(root->left, val);
        
        return root;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return util(root, val);
    }
};