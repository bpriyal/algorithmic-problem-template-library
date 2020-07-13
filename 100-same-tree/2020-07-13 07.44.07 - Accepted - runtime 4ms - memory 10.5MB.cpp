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
    void preorderWithNull(TreeNode* root,vector<int> &vec) {
        if (root) {
            vec.push_back(root->val);
            preorderWithNull(root->left,vec);
            preorderWithNull(root->right,vec);
        } else {
            vec.push_back(INT_MAX);
        }
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> tree1;
        vector<int> tree2;
        preorderWithNull(p,tree1);
        preorderWithNull(q,tree2);
        if (tree1 == tree2) return true;
        return false;
    }
};