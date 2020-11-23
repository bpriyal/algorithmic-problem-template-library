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
    int util(TreeNode* root,int run,bool prevAdded) {
        if (root == nullptr) {
            return run;
        }
        int nodeAddedLeft = INT_MIN,nodeNotAddedLeft = INT_MIN,nodeAddedRight = INT_MIN,nodeNotAddedRight = INT_MIN;
        
        /* Left side */
        if (!prevAdded) {
            nodeAddedLeft = util(root->left,run+root->val,true);
        }
        nodeNotAddedLeft = util(root->left,run,false);
        
        /* Right Side */
        if (!prevAdded) {
            nodeAddedRight = util(root->right,nodeAddedLeft,true);
        }
        nodeNotAddedRight = util(root->right,nodeNotAddedLeft,false);
        
        
        //printf("root:%d||left:%d||right:%d\n",root->val,left,right);
        return max(nodeAddedRight,nodeNotAddedRight);
    }
public:
    int rob(TreeNode* root) {
        return util(root,0,false);
    }
};