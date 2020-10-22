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
    int result;
    void util(TreeNode* root,int depth) {
        if (root == nullptr || depth >= result) {
            return;
        }
        if (!root->left && !root->right) {
            result = min(result,depth);
            return;
        }
        util(root->left,depth+1);
        util(root->right,depth+1);
    }
public:
    Solution():result(INT_MAX) {}
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        util(root,1);
        return result;
    }
};