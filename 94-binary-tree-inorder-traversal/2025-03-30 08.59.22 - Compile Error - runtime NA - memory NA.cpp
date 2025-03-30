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
    void inorder(TreeNode* root, vector<int>& result) {
      if (!root) return;
      inorder(root->left, result);
      result.emplace_back(root->val);
      inorder(root->right, result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
      // vector<int> result;
      // inorder(root, result);
      // return result;

      vector<int> result;
      stack<TreeNode*> st;
      TreeNode* curr = root;
      while (curr != nullptr || !st.empty()) {
        while (curr) {
          st.emplace_back(curr);
          curr = curr->left;
        }
        auto* node = st.top();
        st.pop();
        result.emplace_back(node->val);
        curr = node->right;
      } 
      return result;
    }
};