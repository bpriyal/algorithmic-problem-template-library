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
    vector<vector<int>> result;
    
    void util(TreeNode* root, int target, vector<int>& current, int& sum) {
        if (!root) return;
        
        current.push_back(root->val);
        sum += root->val;
        
        if (!root->left && !root->right && sum == target) {
            result.push_back(current);
        }
        
        util(root->left, target, current, sum);
        util(root->right, target, current, sum);
        
        current.pop_back();
        sum -= root->val;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> current;
        int sum = 0;
        util(root, targetSum, current, sum);
        
        return result;
    }
};