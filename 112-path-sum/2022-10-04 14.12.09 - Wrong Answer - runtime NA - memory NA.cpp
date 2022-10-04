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
    bool util(TreeNode* root, int target, int sum) {
        if (!root) {
            return sum == target;
        }
        
        sum += root->val;
        
        bool temp = util(root->left, target, sum) || util(root->right, target, sum);
        
        sum -= root->val;
        
        return temp;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return util(root, targetSum, 0);
    }
};