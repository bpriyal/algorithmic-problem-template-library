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
    void util(TreeNode* root, int val, int depth, int currDepth) {
        if (!root) return;
        
        if (currDepth == depth - 1) {
            TreeNode* leftSubTree = root->left;
            TreeNode* rightSubTree = root->right;
            
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            
            root->left->left = leftSubTree;
            root->right->right = rightSubTree;
            
            return;
        }
        
        util(root->left, val, depth, currDepth + 1);
        util(root->right, val, depth, currDepth + 1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            
            return newRoot;
        }
        
        util(root, val, depth, 1);
        return root;
    }
};