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
    string result;
    bool util(TreeNode* root) {
        if (!root) return false;
        
        result += "(" + to_string(root->val);
        
        bool l = util(root->left);
        if (!l && root->right) result += "()";
        bool r = util(root->right);
        
        result += ")";
        
        return true;
    }
public:
    string tree2str(TreeNode* root) {
        result = "";
        util(root);
        return result.substr(1, result.size() - 2);
    }
};