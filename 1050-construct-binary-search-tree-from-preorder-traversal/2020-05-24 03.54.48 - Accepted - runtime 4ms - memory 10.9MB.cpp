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
    
    TreeNode* createBST(TreeNode *root,int val) {
        if (root == nullptr) {
           return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = createBST(root->left,val);
        } else {
            root->right = createBST(root->right,val);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        int size = preorder.size();
        for (int i= 1;i<size;++i) 
            root = createBST(root,preorder[i]);
        return root;
    }
};