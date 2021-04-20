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
    vector<int> result;
    
    void util(Node* root) {
        if (root == nullptr) {
            return;
        }
        
        result.push_back(root->val);
        
        for (Node* n:root->children) {
            util(n);
        }
    }
public:
    vector<int> preorder(Node* root) {
        util(root);
        return result;
    }
};