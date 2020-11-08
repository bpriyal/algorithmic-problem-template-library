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
    int result = 0;
    int util(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftSum = util(root->left);
        int rightSum = util(root->right);
        result += abs(leftSum-rightSum);
        return leftSum+rightSum+root->val;
    }
public:
    int findTilt(TreeNode* root) {
        util(root);
        return result;
    }
};