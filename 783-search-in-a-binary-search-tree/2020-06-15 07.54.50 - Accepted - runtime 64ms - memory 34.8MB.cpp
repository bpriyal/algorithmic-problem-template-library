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
    TreeNode* searchUtil(TreeNode* root,int val) {
        if (root == nullptr) return nullptr;
        if (root->val == val) return root;
        if (root->val > val) return searchUtil(root->left,val);
        return searchUtil(root->right,val);
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return searchUtil(root,val);
    }
};