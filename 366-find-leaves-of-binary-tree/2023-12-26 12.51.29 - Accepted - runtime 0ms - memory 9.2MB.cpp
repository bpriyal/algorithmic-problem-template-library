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
    vector<pair<int, int>> heightValPair;
    int getHeight(TreeNode* root, vector<vector<int>>& result) {
        if (!root) return -1;
        int currentHeight = 1 + max(getHeight(root->left, result), getHeight(root->right, result));
        if (result.size() == currentHeight) result.emplace_back(vector<int>());
        result[currentHeight].emplace_back(root->val);
        // heightValPair.emplace_back(currentHeight, root->val);
        return currentHeight;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        getHeight(root, result);
        // sort(heightValPair.begin(), heightValPair.end());
        // int size = heightValPair.size();
        // int i = 0, height = 0;
        // while (i < size) {
        //     vector<int> subResult;
        //     while (i < size && heightValPair[i].first == height) {
        //         subResult.emplace_back(heightValPair[i].second);
        //         ++i;
        //     }
        //     ++height;
        //     result.emplace_back(subResult);
        // }
        return result;
    }
};