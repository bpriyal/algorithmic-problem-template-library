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
    TreeNode* util(TreeNode* root, int key) {
        if (!root) return nullptr;
        
        if (root->val == key) {
            TreeNode* temp = root;
            
            if (root->left)
                root = root->left;
            else {
                root = root->right;
                delete temp;
                temp = nullptr;
                return root;
            }
            
            TreeNode* temp2 = root;
            while(temp2->right) {
                temp2 = temp2->right;
            }
            temp2->right = temp->right;
            delete temp;
            temp = nullptr;
            
            return root;
        }
        else if (root->val < key) root->right = util(root->right, key);
        else root->left = util(root->left, key);
        
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return util(root, key);
    }
};