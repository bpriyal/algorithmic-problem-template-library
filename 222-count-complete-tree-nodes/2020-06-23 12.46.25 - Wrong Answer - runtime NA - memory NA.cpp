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
    static int count;
    void util(TreeNode* root) {
        if (root == nullptr) return;
        ++count;
        if (root->left) util(root->left);
        if (root->right) util(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        util(root);
        return count;
    }
};
int Solution::count = 0;