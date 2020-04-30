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
public:
    stack<TreeNode*> callstack;
    stack<int> index;
    bool flag = false;
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return flag;
        }
        int size = arr.size();
        int i = 0,curr;
        callstack.push(root);
        index.push(i);
        
        while(!callstack.empty()) {
            root = callstack.top();
            callstack.pop();
            i = index.top();
            index.pop();
            //cout<<"received:"<<root->val<<"EXPECTED:"<<arr[curr]<<endl;
            if (root->val == arr[i]) {
                ++i;
                if (i == size-1) {
                    //cout<<"ggggggggg"<<endl;
                    if (!root->left && !root->right) {
                        return true;
                    } else {
                        cout<<"here"<<endl;
                        return false;
                    }
                }
                
                if(root->left) {
                    cout<<"pushing left"<<root->left->val<<endl;
                    callstack.push(root->left);
                    index.push(i);
                }
                if(root->right) {
                    cout<<"pushing right"<<root->right->val<<endl;
                    callstack.push(root->right);
                    index.push(i);
                }
            } 
        }
        return false;
    }
};