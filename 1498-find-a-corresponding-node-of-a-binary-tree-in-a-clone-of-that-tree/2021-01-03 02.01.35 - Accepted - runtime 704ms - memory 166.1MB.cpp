/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode *result;
    void dfs(TreeNode *node,int tar) {
        if (node == nullptr) {
            return;
        }
        if (node->val == tar) {
            result = node;
            return;
        }
        dfs(node->left,tar);
        dfs(node->right,tar);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        result = nullptr;
        int tar = target->val;
        dfs(cloned,tar);
        return result;
    }
};