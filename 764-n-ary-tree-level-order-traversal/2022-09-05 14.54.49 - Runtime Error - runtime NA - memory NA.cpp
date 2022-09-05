/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> run;
            for (int i = 0; i < size; ++i) {
                run.push_back(q.front()->val);
                
                for (auto ele : q.front()->children) q.push(ele);
                
                q.pop();
            }
            
            result.emplace_back(run);
        }
        
        return result;
    }
};