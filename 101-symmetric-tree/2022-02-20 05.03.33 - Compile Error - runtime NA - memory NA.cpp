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
    bool util(TreeNode* lTree, TreeNode* rTree) {
        if (lTree == nullptr && rTree == nullptr) return true;
        if (lTree == nullptr || rTree == nullptr) return false;
        if (left->val != right->val) return false;
        if (!util(lTree->left, lTree->right) || !util(rTree->left, rTree->right)) return false;
        
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return util(root->left, root->right);
    }
};