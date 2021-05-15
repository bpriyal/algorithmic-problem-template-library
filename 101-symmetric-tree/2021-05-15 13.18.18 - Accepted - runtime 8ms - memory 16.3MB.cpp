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
    bool isSymmetric(TreeNode* root1,TreeNode* root2) {
        if ((root1 && !root2) || (!root1 && root2)) {
            return false;
        } else if (!root1 && !root2) {
            return true;
        } else if (root1->val != root2->val) {
            return false;
        }
        
        return isSymmetric(root1->left,root2->right) && isSymmetric(root1->right,root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        /*vector<int> l;
        vector<int> r;
        
        utilleft(root->left,l);
        utilright(root->right,r);
        
        return l == r;*/
        
        return isSymmetric(root->left,root->right);
    }
};