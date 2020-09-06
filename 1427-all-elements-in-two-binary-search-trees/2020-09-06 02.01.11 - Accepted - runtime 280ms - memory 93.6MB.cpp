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
    void inorder(TreeNode *root,list<int> &l) {
        if (root) {
            inorder(root->left,l);
            l.push_back(root->val);
            inorder(root->right,l);
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        list<int> l1;
        list<int> l2;
        inorder(root1,l1);
        inorder(root2,l2);
        l1.merge(l2);
        return vector<int>(l1.begin(),l1.end());
    }
};