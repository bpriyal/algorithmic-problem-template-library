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
    int count = 0;
    
    void leafNode(const unordered_map<int,int> &cache) {
        int n = 0;
        for(auto it = cache.begin();it != cache.end(); ++it) {
            if (it->second % 2 != 0) ++n;
            if (n > 1) return;
        }
        ++count;
    }
    
    /*void util(TreeNode *root,unordered_map<int,int> cache) {
        if (root == nullptr) return;
        ++cache[root->val];
        if (root->left == nullptr && root->right == nullptr) leafNode(cache);
        else {
            util(root->left,cache);
            util(root->right,cache);
        }
    }*/
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> cache;
        //util(root,cache);
        stack<pair<TreeNode*,unordered_map<int,int>>> s;
        s.push(make_pair(root,cache));
        while(!s.empty()) {
            pair<TreeNode *,unordered_map<int,int>> p = s.top();
            s.pop();
            TreeNode *curr = p.first;
            unordered_map<int,int> cachee = p.second;
            ++cachee[curr->val];
            if (curr->left == nullptr && curr->right == nullptr) leafNode(cachee);
            if (curr->right) s.push(make_pair(curr->right,cachee));
            if (curr->left) s.push(make_pair(curr->left,cachee));
        }
        return count;
    }
};