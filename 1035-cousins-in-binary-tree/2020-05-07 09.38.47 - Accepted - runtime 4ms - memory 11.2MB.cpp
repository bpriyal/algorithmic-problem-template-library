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
    TreeNode *x_parent = nullptr;
    TreeNode *y_parent = nullptr;
    int x_depth = -1,y_depth = -1;
    
    bool util(TreeNode* root, int x, int y, int depth) {
        if (root == NULL) return false;
        if (root->left) {
            if (root->left->val == x) {
                x_parent = root;
                x_depth = depth + 1;
            } else if (root->left->val == y) {
                y_parent = root;
                y_depth = depth + 1;
            }
        }
        if (root->right) {
            if (root->right->val == x) {
                x_parent = root;
                x_depth = depth + 1;
            } else if (root->right->val == y) {
                y_parent = root;
                y_depth = depth + 1;
            }
        }
        if (x_parent && y_parent && x_parent == y_parent) return false;
        if (x_depth != -1 && y_depth != -1 && x_depth == y_depth) return true;
        return (util(root->left,x,y,depth+1) || util(root->right,x,y,depth+1));
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;
        return util(root,x,y,0);
    }
};