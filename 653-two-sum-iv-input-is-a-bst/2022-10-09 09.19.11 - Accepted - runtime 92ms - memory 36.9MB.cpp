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
    vector<int> cache;
    void inorder(TreeNode* root) {
        if (!root) return;
        
        inorder(root->left);
        cache.push_back(root->val);
        inorder(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        
        int i = 0;
        int j = cache.size() - 1;
        
        while (i < j) {
            int twoSum = cache[i] + cache[j];
            
            if (twoSum == k) return true;
            else if (twoSum < k) ++i;
            else --j;
        }
        
        return false;
    }
};