/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
//         if either one of them is root
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        
        // call left and right
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        // if found p and q at left and right side then LCA is root
        if(l && r) return root;
        
        // means both either resides in left side or right side
        
        if(l) return l;
        
        if(r) return r;
        
        // else not exists
        return NULL;
    }
};