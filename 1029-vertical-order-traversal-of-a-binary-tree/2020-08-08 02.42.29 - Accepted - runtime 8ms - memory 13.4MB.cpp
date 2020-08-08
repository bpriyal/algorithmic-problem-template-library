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
    unordered_map<int,vector<pair<int,int>>> cache;
    int min = INT_MAX;
    int max = INT_MIN;
    void dfs(TreeNode* root,int row,int col) {
        if (root == nullptr) {
            return;
        }
        if (col > max) {
            max = col;
        }
        if (col < min) {
            min = col;
        }
        cache[col].push_back({row,root->val});
        dfs(root->left,row+1,col-1);
        dfs(root->right,row+1,col+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root,0,0);
        for(int i = min;i <= max;++i) {
           sort(cache[i].begin(),cache[i].end(),[](pair<int,int> &a,pair<int,int> &b) {
               if (a.first == b.first) {
                   return a.second < b.second;
               }
               return a.first < b.first;
           });
            vector<int> temp;
            for(int j = 0;j<cache[i].size();++j) {
                temp.push_back(cache[i][j].second);
            }
            result.push_back(temp);
        }
        //cout<<cache[0][1].second;
        return result;
    }
};