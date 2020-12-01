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
    int maxDepthVal;
    void util(TreeNode* root,int depth) {
        if (root == nullptr) {
            return;
        }
        maxDepthVal = max(maxDepthVal,depth);
        util(root->left,depth+1);
        util(root->right,depth+1);
    }
public:
    int maxDepth(TreeNode* root) {
        maxDepthVal = 0;
        util(root,1);
        return maxDepthVal;
    }
};