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
    void inorder(TreeNode* root, vector<int>& list) {
        if (!root) return;
        inorder(root->left, list);
        list.emplace_back(root->val);
        inorder(root->right, list);
    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> list1, list2;
        inorder(root1, list1);
        inorder(root2, list2);
        int size1 = list1.size(), size2 = list2.size();
        int itr1 = 0, itr2 = size2 - 1;

        while (itr1 < size1 && itr2 >= 0) {
            int sum = list1[itr1] + list2[itr2];
            if (sum == target) return true;
            else if (sum < target) ++itr1;
            else --itr2;
        }
        return false;
    }
};