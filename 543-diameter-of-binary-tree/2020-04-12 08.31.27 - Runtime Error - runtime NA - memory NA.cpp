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
private:
    int max(int a,int b){
        return a >= b ? a : b;
    }
    int height(TreeNode* root){
        if (root == NULL) return 0;
        return max(height(root->left),height(root->right))+1;
    }
public:
    int diameter;
    int diameterOfBinaryTree(TreeNode* root) {
        int currdiameter = height(root->right) + height(root->left);
        if (currdiameter > diameter){
            diameter = currdiameter;
        }
        int temp;
        if(root->left){
            temp = diameterOfBinaryTree(root->left);
        }
        if(root->right){
            temp = diameterOfBinaryTree(root->right);
        }
        return diameter;
    }
};