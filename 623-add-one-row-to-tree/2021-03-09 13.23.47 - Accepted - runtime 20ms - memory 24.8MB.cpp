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
    void util(TreeNode* root,int v,int d,int currLevel) {
        if (root == nullptr) {
            return;
        }
        if (currLevel == d-1) {
            TreeNode* newLeft = new TreeNode(v);
            newLeft->left = root->left;
            root->left = newLeft;
            
            TreeNode* newRight = new TreeNode(v);
            newRight->right = root->right;
            root->right = newRight;
            
            return;
        }
        util(root->left,v,d,currLevel+1);
        util(root->right,v,d,currLevel+1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* temp = new TreeNode(v);
            temp->left = root;
            return temp;
        }
        util(root,v,d,1);
        return root;
    }
};