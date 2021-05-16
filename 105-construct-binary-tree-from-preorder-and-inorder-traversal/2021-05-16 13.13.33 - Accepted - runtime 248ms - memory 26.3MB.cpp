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
    unordered_map<int,int> cache;
    TreeNode* util(const vector<int>& preorder, const vector<int>& inorder,int l,int r) {
        if (l > r) {
            return nullptr;
        }
        int n;
        int _min = INT_MAX;
        int index;
        for(int i = l;i <= r;++i) {
            if (cache[inorder[i]] < _min) {
                n = inorder[i];
                _min = cache[inorder[i]];
                index = i;
            }
        }
        
        TreeNode *node = new TreeNode(n);
        node->left = util(preorder,inorder,l,index-1);
        node->right = util(preorder,inorder,index+1,r);
        
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size = preorder.size();
        for(int i = 0;i < size;++i) {
            cache[preorder[i]] = i; 
        }
        
        return util(preorder,inorder,0,size-1);
    }
};