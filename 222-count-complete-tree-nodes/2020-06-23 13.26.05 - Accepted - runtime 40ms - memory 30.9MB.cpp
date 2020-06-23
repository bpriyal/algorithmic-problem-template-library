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
    int count = 0;
    void util(TreeNode* root) {
        if (root == nullptr) return;
        ++count;
        if (root->left) util(root->left);
        if (root->right) util(root->right);
    }
public:
    /*int countNodes(TreeNode* root) {
        util(root);
        return count;
    }*/
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int hl = 0, hr = 0;
        TreeNode *r = root;
        TreeNode *l = root;
        while(l) {
            ++hl;
            l = l->left;
        }
        while(r) {
            ++hr;
            r = r->right;
        }
        if (hl == hr) return (1<<hl)-1;
        return 1 + countNodes(root->left)  + countNodes(root->right);
    }
};