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
    vector<int> cache;
    int count = 0;
    void dfs(TreeNode* root,int sum) {
        if (root == nullptr) {
            return;
        }
        //cout<<root->val<<endl;
        for(int i = 0;i<cache.size();++i) {
            cache[i] += root->val;
            if (cache[i] == sum) {
                //cout<<"increase"<<endl;
                ++count;
            }
        }
        if (root->val == sum) {
            ++count;
        }
        cache.push_back(root->val);
        dfs(root->left,sum);
        dfs(root->right,sum);
        for(int i = 0;i<cache.size();++i) {
            cache[i] -= root->val;
        }
        cache.pop_back();
    }
public:
    int pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        return count;
    }
};