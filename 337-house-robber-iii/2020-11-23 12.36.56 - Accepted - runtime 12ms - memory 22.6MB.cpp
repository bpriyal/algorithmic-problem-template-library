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
    pair<int,int> util(TreeNode* root,int &run) {
        if (root == nullptr) {
            return make_pair(0,0);
        }
        int nodeAdded = INT_MIN,nodeNotAdded = INT_MIN;
        
        pair<int,int> left = util(root->left,run);
        pair<int,int> right = util(root->right,run);
        
        nodeNotAdded = left.first + right.first;
        nodeAdded = left.second + right.second + root->val;
        
        run = max({nodeNotAdded,nodeAdded,run});
        
        return make_pair(max(nodeNotAdded,nodeAdded),nodeNotAdded);
    }
public:
    int rob(TreeNode* root) {
        int run = 0;
        util(root,run);
        return run;
    }
};