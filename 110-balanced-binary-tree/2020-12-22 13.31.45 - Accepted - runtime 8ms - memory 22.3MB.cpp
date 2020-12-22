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
    bool result;
    int util(TreeNode* root) {
        if (root == nullptr || !result) {
            return 0;
        }
        int hl = util(root->left);
        int hr = util(root->right);
        result = result && abs(hl-hr) <= 1;
        return max(hl,hr) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        result = true;
        util(root);
        return result;
    }
};