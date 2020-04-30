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
    stack<TreeNode*> callstack;
    bool flag = false;
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return flag;
        }
        int size = arr.size();
        int i = 0;
        callstack.push(root);
        
        while(!callstack.empty()) {
            root = callstack.top();
            callstack.pop();
            
            if (root->val == arr[i]) {
                ++i;
                if (!root->left && !root->right && i==size) return true;
                callstack.push(root->left);
                callstack.push(root->right);
            } 
        }
        return false;
    }
};