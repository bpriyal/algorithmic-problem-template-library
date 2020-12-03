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
    
    TreeNode* increasingBSTUtil(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return root;
        TreeNode *l=NULL, *temp=NULL, *r = NULL, *head=NULL;
        
        if(root->left)
            l = increasingBST(root->left);
            temp = l;
        
            while(temp && temp->right) temp = temp->right;
            if(temp) temp->right = root;
        
        root->left = NULL;
        
        if(root->right)
            r = increasingBST(root->right);
            root->right = r;
        
        if(l==NULL) return root;
        return l;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return root;
        TreeNode *temp = root;
        while(temp->left) temp=temp->left;
        
        TreeNode * head=temp;
        increasingBSTUtil(root);
        return head;
    }
};