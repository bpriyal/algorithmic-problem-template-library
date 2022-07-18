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
    int last;
    bool inorder(TreeNode* root) {
        if (!root) return true;
        
        if (root->left) inorder(root->left);
        
        if (root->val <= last) return false;
        last = root->val;
        
        if (root->right) inorder(root->right);
        
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        last = std::numeric_limits<int>::min();
        return inorder(root);
    }
};