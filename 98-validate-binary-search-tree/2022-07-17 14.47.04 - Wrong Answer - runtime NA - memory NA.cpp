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
    bool util(TreeNode* root, int lesserThan, int parent) {
        if (!root) return true;
        
        
            if (lesserThan == 1) {
                if (root->val >= parent) return false;
            } else if (lesserThan == 0) {
                if (root->val <= parent) return false;
            }
        
        return util(root->left, 1, root->val) && util(root->right, 0, root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return util(root, - 1, 0);
    }
};