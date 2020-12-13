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
    pair<unsigned int,TreeNode*> util(TreeNode* root) {
        if (root == nullptr) {
            return {0,nullptr};
        }
        pair<unsigned int,TreeNode*> left,right;
        left = util(root->left);
        right = util(root->right);
        
        int lh = left.first;
        int rh = right.first;
        
        return {max(lh,rh)+1,(lh == rh)? root : (lh > rh)? left.second : right.second};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return util(root).second;
    }
};