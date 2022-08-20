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
    
    void addLeftNodes(TreeNode* root) {
        if (!root) return;
        
        st.push(root);
        while (root->left) {
            st.push(root->left);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        addLeftNodes(root);
    }
    
    int next() {
        cout<<"in here"<<endl;
        auto temp = st.top();
        cout<<"before func"<<endl;
        st.pop();
        
        addLeftNodes(temp->right);
        cout<<"returning"<<endl;
        return temp->val;
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