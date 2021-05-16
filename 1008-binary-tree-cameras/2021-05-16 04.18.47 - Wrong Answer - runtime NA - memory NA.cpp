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
    int util(TreeNode* root,bool flag) {
        if (root == nullptr) {
            return 0;
        }
        
        int result = INT_MAX;
        // put a camera at this node
        result = min(result,util(root->left,true)+util(root->right,true)+1);
        
        //not put a camera
        if (flag) {
            result = min(result,util(root->left,false)+util(root->right,false));
        }
        
        return result;
    }
public:
    int minCameraCover(TreeNode* root) {
        if (!root->left && !root->right) {
            return 1;
        }
        return util(root,true);
    }
};