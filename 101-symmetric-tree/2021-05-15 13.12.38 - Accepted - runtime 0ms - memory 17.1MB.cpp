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
    void utilleft(TreeNode* root,vector<int> &v) {
        if (root == nullptr) {
            v.push_back(INT_MAX);
            return;
        }
        v.push_back(root->val);
        utilleft(root->right,v);
        utilleft(root->left,v);
    }
    
    void utilright(TreeNode* root,vector<int> &v) {
        if (root == nullptr) {
            v.push_back(INT_MAX);
            return;
        }
        v.push_back(root->val);
        utilright(root->left,v);
        utilright(root->right,v);
    }
public:
    bool isSymmetric(TreeNode* root) {
        vector<int> l;
        vector<int> r;
        
        utilleft(root->left,l);
        utilright(root->right,r);
        
        return l == r;
    }
};