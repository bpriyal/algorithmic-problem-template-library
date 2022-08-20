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
    vector<long> cache;
    int result;
    
    void util(TreeNode* root, int targetSum) {
        if (!root) return;
        
        cache.emplace_back(0);
        
        for(auto& element : cache) {
            element += root->val;
            if (element == targetSum) ++result;   
        }
        
        util(root->left, targetSum);
        util(root->right, targetSum);
        
        for(auto& element : cache) {
            element -= root->val;
        }
        
        cache.pop_back();
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        result = 0;
        util(root, targetSum);
        
        return result;
    }
};