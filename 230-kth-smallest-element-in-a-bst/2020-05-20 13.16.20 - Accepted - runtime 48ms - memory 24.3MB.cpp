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
    //solution 1 : not fast enough
    /*void inorder(TreeNode* root,vector<int>& sorted) {
        if (root != nullptr) {
            inorder(root->left,sorted);
            sorted.push_back(root->val);
            inorder(root->right,sorted);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return -1;
        vector<int> sorted;
        inorder(root,sorted);
        return sorted[k-1];
    }*/
    stack<TreeNode*> s;
    int kthSmallest(TreeNode* root, int k) {
        while(true) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            --k;
            TreeNode* temp = s.top();
            s.pop();
            if (k == 0) return temp->val;
            root = temp->right;
        }
    }
};