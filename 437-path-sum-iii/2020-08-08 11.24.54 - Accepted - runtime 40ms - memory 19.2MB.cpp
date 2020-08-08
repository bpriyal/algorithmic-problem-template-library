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
    unordered_map<int,int> cache;
    int count = 0;
    void dfs(TreeNode* root,int sum,int run) {
        if (root == nullptr) {
            return;
        }
        run += root->val;
        if (cache.find(run-sum) != cache.end()) {
            count += cache[run-sum];
        }
        ++cache[run];
        dfs(root->left,sum,run);
        dfs(root->right,sum,run);
        --cache[run];
    }
public:
    int pathSum(TreeNode* root, int sum) {
        cache[0] = 1;
        dfs(root,sum,0);
        return count;
    }
};