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
    int result;
    void util(TreeNode *root) {
        if (root == nullptr) {
            return; 
        }
        ++cache[root->val];
        if (!root->left && !root->right) {
            int numberOfOddParity = 0;
            for (int n:cache) {
                if (n%2 != 0) {
                    ++numberOfOddParity;
                    if (numberOfOddParity > 1) {
                        --cache[root->val];
                        return;
                    }
                }
            }
            ++result;
            --cache[root->val];
            return;
        }
        util(root->left);
        util(root->right);
        --cache[root->val];
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        cache.resize(10,0);
        result = 0;
        util(root);
        return result;
    }
};