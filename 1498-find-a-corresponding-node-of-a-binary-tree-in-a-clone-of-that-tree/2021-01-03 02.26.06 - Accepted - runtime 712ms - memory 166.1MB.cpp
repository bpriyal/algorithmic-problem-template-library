/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    vector<char> decision;
    bool dfs(TreeNode *node,TreeNode* target) {
        if (node == nullptr) {
            return false;
        }
        if (node == target) {
            return true;
        }
        decision.push_back('l');
        if (dfs(node->left,target)) {
            return true;
        } else {
            decision.pop_back();
        }
        
        decision.push_back('r');
        if (dfs(node->right,target)) {
            return true;
        } else {
            decision.pop_back();
        }
        
        return false;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original,target);
        TreeNode *result = cloned;
        
        for(char c:decision) {
            if (c == 'l') {
                result = result->left;
            } else {
                result = result->right;
            }
        }
        return result;
    }
};