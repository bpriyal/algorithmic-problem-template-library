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
public:
    TreeNode* newNode(int val) {
        TreeNode *newnode = new TreeNode(val);
        return newnode;
    }
    
    TreeNode* bst_util(TreeNode* root,int val) {
        if (root == nullptr) {
            return newNode(val);
        }
        if (val < root->val) {
            root->left = bst_util(root->left,val);
        } else {
            root->right = bst_util(root->right,val);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* root = nullptr;
        for (auto x : preorder) {
            if (root == nullptr) {
                root = newNode(x);
                continue;
            }
            if (x < root->val) {
                root->left = bst_util(root->left,x);
            } else {
                root->right = bst_util(root->right,x);
            }
        }
        return root;
    }
};