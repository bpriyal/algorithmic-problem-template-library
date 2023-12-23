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
    double _result = 0.;
    pair<double, int> _maximumAverageSubtree(TreeNode* root) {
        if (!root) return {0, 0};
        auto left = _maximumAverageSubtree(root->left);
        auto right = _maximumAverageSubtree(root->right);
        int noOfNodes = 1 + left.second + right.second;
        double sum = root->val + left.first + right.first;
        double avg = sum / noOfNodes;
        _result = max(_result, avg);
        return {sum, noOfNodes}; 
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        _maximumAverageSubtree(root);
        return _result;
    }
};