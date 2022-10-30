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
    
    void util(TreeNode* root, vector<int> &cache) {
        if (!root) return;
        
        for (int number : cache) result = max(result, abs(root->val - number));
        
        cache.push_back(root->val);
        
        util(root->left, cache);
        util(root->right, cache);
        
        cache.pop_back();
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        vector<int> cache;
        result = 0;
        util(root, cache);
        return result;
    }
};