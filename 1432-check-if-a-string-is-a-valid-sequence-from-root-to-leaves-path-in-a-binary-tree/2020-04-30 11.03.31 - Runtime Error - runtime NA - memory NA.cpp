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
public:
    bool dfs(TreeNode* root,int i,const vector<int> arr) {
        if (root == nullptr) return false;
        
        if (root->val == arr[i] && !root->left && !root->right && i == arr.size()-1) return true;
        
        return (i<arr.size() && root->val ==arr[i] && (dfs(root->right,i+1,arr) || dfs(root->left,i+1,arr)));
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root,0,arr);
    }
};