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
    pair<int,int> util(TreeNode* root,int &ans) {
        if (root == nullptr) {
            return {INT_MAX,INT_MIN};
        }
        pair<int,int> left,right;
        left = util(root->left,ans);
        right = util(root->right,ans);
        if (left.first != INT_MAX) {
            ans = max(ans,abs(root->val-left.first));
        }
        if (left.second != INT_MIN) {
            ans = max(ans,abs(root->val-left.second));
        }
        if (right.first != INT_MAX) {
            ans = max(ans,abs(root->val-right.first));
        }
        if (right.second != INT_MIN) {
            ans = max(ans,abs(root->val-right.second));
        }
        return {min(root->val,min(left.first,right.first)),max(root->val,max(left.second,right.second))};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int result = 0;
        util(root,result);
        return result;
    }
};