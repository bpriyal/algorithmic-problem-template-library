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
    int size;
    TreeNode* util(const vector<int> &preorder,const vector<int> &inorder,int i,int l,int r) {
        if (l > r || i >= size) {
            return nullptr;
        }
        int index;
        for(int x = l;x <= r;++x) {
            if (preorder[i] == inorder[x]) {
                index = x;
                break;
            }
        }
        
        TreeNode* node = new TreeNode(preorder[i]);
        node->left = util(preorder,inorder,i+1,l,index-1);
        node->right = util(preorder,inorder,i+2,index+1,r);
        
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size = preorder.size();
        
        return util(preorder,inorder,0,0,size-1);
    }
};