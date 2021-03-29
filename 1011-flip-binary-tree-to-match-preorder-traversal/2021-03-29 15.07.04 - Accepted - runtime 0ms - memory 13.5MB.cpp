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
    vector<int> result;
    int size;
    bool preorder(TreeNode* root,const vector<int>& voyage,int &i) {
        if (root == nullptr) {
            return true;
        }
        if (voyage[i] != root->val) {
            return false;    
        } else {
            ++i;
        }
        
        if (root->left) {
            if (root->left->val != voyage[i] && root->right) {
                result.push_back(root->val);
                swap(root->left,root->right);
            }
            bool left = preorder(root->left,voyage,i);
            if (!left) {
                return false;
            }
        }
        return preorder(root->right,voyage,i);
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        size = voyage.size();
        int i = 0;
        return preorder(root,voyage,i)? result:vector<int>(1,-1);
    }
};