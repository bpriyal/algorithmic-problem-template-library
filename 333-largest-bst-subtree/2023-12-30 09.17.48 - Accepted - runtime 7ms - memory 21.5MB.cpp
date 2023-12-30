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
struct Result {
    Result(int minVal_, int maxVal_, int maxSize_) : _minVal(minVal_), _maxVal(maxVal_), _maxSize(maxSize_) {}
    int _minVal;
    int _maxVal;
    int _maxSize;
};
class Solution {
    Result _largestBSTSubtree(TreeNode* root) {
        if (!root) return Result(INT_MAX, INT_MIN, 0);
        auto left = _largestBSTSubtree(root->left);
        auto right = _largestBSTSubtree(root->right);
        if (left._maxVal < root->val && right._minVal > root->val) {
            return Result(min(root->val, left._minVal), max(root->val, right._maxVal), left._maxSize + right._maxSize + 1);
        }
        return { INT_MIN, INT_MAX, max(left._maxSize, right._maxSize)};
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        return _largestBSTSubtree(root)._maxSize;
    }
};