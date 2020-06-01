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
public:
    TreeNode *invertTree_util(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode *temp = root->left;
        root->left = invertTree_util(root->right);
        root->right = invertTree_util(temp);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return invertTree_util(root);
    }
};