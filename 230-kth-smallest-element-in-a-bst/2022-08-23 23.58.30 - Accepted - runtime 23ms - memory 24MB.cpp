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
    
    void util(TreeNode* root, int& k) {
        if (!k || !root) return;
        
        util(root->left, k);
        if (--k == 0) result = root->val;
        util(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        util(root, k);
        return result;
    }
};