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
    int sum = 0;
    void util(TreeNode* root,string &number) {
        if (root == nullptr) return;
        number += to_string(root->val);
        if (!root->left && !root->right) {
            sum += stoi(number);
        } else {
            if (root->left) {
                util(root->left,number);
            } 
            if (root->right) {
                util(root->right,number);
            }
        }
        number.pop_back();
    } 
public:
    int sumNumbers(TreeNode* root) {
        string number = "";
        util(root,number);
        return sum;
    }
};