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
    int widthOfBinaryTree(TreeNode* root) {
        if (root ==nullptr) return 0;
        TreeNode* root1 = root;
        TreeNode* root2 = root;
        int l = 0;
        int r = 0;
        int max = INT_MIN;
        while(true) {
            TreeNode* temp1 = nullptr;
            TreeNode* temp2 = nullptr;
            if (root1->left) {
                temp1 = root1->left;
                --l;
            } else if (root1->right) {
                temp1 = root1->right;
                ++l;
            } else {
                
            }
            
            if (root2->right) {
                temp2 = root2->right;
                ++r;
            } else if (root2->left) {
                temp2 = root2->left;
                --r;
            } else {
                
            }
            int run = r-l;
            if (run > max) max = run;
            if (!temp1 && !temp2) break;
            if (!temp1) {
                root1 = root2;
                continue;
            }
            if (!temp2) {
                root2 = root1;
                continue;
            }
            root1 = temp1;
            root2 = temp2;
        }
        return max;
    }
};