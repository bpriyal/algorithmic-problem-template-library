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
    int sum = 0;
    void dfs(TreeNode* root,string s) {
        if (!root) {
            return;
        }
        char c = root->val? '1':'0';
        if (!root->left && !root->right) {
            s+=c;
            //cout<<s<<endl;
            int size = s.size();
            for(int i=0;i<size;++i) {
                sum += (s[i]=='1')? pow(2,size-i-1):0;
            }
            //cout<<sum<<endl;
            return;
        }
        if (root->left) {
            dfs(root->left,s+c);
        }
        if (root->right) {
            dfs(root->right,s+c);
        }
        return;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root,"");
        return sum;
    }
};