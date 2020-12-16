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
    int last;
    bool inOrder(TreeNode* root) {
        if (root) {
            bool left = inOrder(root->left);
            if (!left) {
                return false;
            }
            if (last >= root->val) {
                return false;
            }
            last = root->val;
            bool right = inOrder(root->right);
            if (!right) {
                return false;
            }
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        last = INT_MIN;
        return inOrder(root);
    }
};