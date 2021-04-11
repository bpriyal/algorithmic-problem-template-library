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
    int depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(depth(root->left),depth(root->right)) + 1;
    }
    
    void dfs(TreeNode *root,const int &maxDepth,int currDepth) {
        if (root == nullptr) {
            return;
        }
        if (currDepth == maxDepth) {
            result += root->val;
        }
        dfs(root->left,maxDepth,currDepth+1);
        dfs(root->right,maxDepth,currDepth+1);
    }
public:
    Solution() {
        result = 0;
    }
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = depth(root);
        dfs(root,maxDepth,1);
        return result;
    }
};