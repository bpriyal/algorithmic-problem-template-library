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
    TreeNode* searchAndDelete(TreeNode* root,int key) {
        if (!root) {
            return nullptr;
        }
        if (root->val == key) {
            if (root->left) {
                TreeNode* temp = root;
                root = root->left;
                TreeNode* temp2 = root;
                while(temp2->right != nullptr) {
                    temp2 = temp2->right;
                }
                temp2->right = temp->right;
                delete(temp);
            } else if (root->right) {
                TreeNode* temp = root;
                root = root->right;
                TreeNode* temp2 = root;
                while(temp2->left != nullptr) {
                    temp2 = temp2->left;
                }
                temp2->left = temp->left;
                delete(temp);
            } else {
                return nullptr;
            }
        }
        if (key < root->val) {
            root->left = searchAndDelete(root->left,key);
        } 
        if (key > root->val) {
            root->right = searchAndDelete(root->right,key);
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return searchAndDelete(root,key);
    }
};