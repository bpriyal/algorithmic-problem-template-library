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
    int maxsum;
    void maxinit(int val) {
        maxsum = val;
    }
    int max(long int a,long int b) {
        return (a > b)? a:b;
    }
    int maxPathSum_util(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left_path = maxPathSum_util(root->left);
        int right_path = maxPathSum_util(root->right);
        cout<<left_path<<"-"<<right_path<<endl;
        int one_child_max = max(max(left_path,right_path) + root->val,root->val);
        
        int top_max = max(one_child_max,left_path+right_path+root->val);
        maxsum = max(top_max,maxsum);
        cout<<"MaxSum:"<<"top_max"<<top_max<<maxsum<<endl;
        return one_child_max;
        
    }
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        maxinit(root->val);
        maxPathSum_util(root);
        return maxsum;
    }
};