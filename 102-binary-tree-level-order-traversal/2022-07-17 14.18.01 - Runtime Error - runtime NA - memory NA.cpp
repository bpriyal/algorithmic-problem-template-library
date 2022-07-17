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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        vector<vector<int>> result;
        
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for(int i = size; i > 0;--i) {
                TreeNode* temp = q.front();
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                
                level.push_back(temp->val);
                q.pop();
            }
            
            result.push_back(level);
        }
        
        return result;
    }
};