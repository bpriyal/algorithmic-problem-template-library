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
    int sum = 0;
    void dfs(TreeNode* root,bool isLeft) {
        //cout<<root->val<<endl;
        if (root == nullptr) {
            return;
        }
        if (!root->left && !root->right && isLeft) {
            sum += root->val;
            return;
        }
        if (root->left) {
            dfs(root->left,true);
        }
        if (root->right) {
            dfs(root->right,false);
        }
        return;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root,false);
        return sum;
    }
};