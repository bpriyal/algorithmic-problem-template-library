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
class BSTIterator {
    stack<TreeNode*> st;

    void _inorderLeft(TreeNode* root) {
      while (root) {
        st.emplace(root);
        root = root->left;
      }
    }
public:
    BSTIterator(TreeNode* root) {
      _inorderLeft(root);
    }
    
    int next() {
      auto* node = st.top(); st.pop();
      _inorderLeft(node->right);
      return node->val;
    }
    
    bool hasNext() {
      return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */