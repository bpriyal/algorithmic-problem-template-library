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
public:
    BSTIterator(TreeNode* root) {
      auto temp = root;
      while (temp) {
        st.emplace(temp);
        temp = temp->left;
      }
    }
    
    int next() {
      auto top = st.top();
      st.pop();
      if (st.empty()) {
        auto temp = top->right;
        while (temp) {
          st.emplace(temp);
          temp = temp->left;
        }
      }
      return top->val;
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