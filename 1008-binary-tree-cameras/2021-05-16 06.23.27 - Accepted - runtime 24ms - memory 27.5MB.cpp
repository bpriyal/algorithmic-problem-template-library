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
    /*
    0 -> all subtrees are covered but not this one
    1 -> all subtrees are covered including this one but no camera here
    2 -> all subtrees are covered including this with a camera here 
    */
    vector<int> util(TreeNode* root) {
        if (root == nullptr) {
            return {0,0,9999};
        }
        
        vector<int> l = util(root->left);
        vector<int> r = util(root->right);
        int lmax = min(l[1],l[2]);
        int rmax = min(r[1],r[2]);
        
        int case1 = l[1]+r[1];
        int case2 = min(l[2]+rmax,lmax+r[2]);
        int case3 = 1+min(l[0],lmax)+min(r[0],rmax);
        
        return {case1,case2,case3};
    }
public:
    int minCameraCover(TreeNode* root) {
        vector<int> result = util(root);
        return min(result[1],result[2]);
    }
};