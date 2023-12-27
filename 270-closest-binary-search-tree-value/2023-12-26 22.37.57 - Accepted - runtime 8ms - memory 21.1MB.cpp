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
    double _leastDiff = std::numeric_limits<double>::max();
    int _closestVal = std::numeric_limits<int>::max();
    void _closestValue(TreeNode* root, double target) {
        if (!root) return;
        double diff = abs(target - root->val);
        if (diff < _leastDiff || (diff == _leastDiff && root->val < _closestVal)) {
            _leastDiff = diff;
            _closestVal = root->val;
        }
        if (root->val < target) _closestValue(root->right, target);
        else _closestValue(root->left, target);
    }
public:
    int closestValue(TreeNode* root, double target) {
        _closestValue(root, target);
        return _closestVal;
    }
};