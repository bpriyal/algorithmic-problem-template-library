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
    Node* _cloneTree(Node* root) {
        if (!root) return nullptr;
        Node* clonedNode = new Node(root->val);
        for (Node* child : root->children) {
            clonedNode->children.emplace_back(_cloneTree(child));
        }
        return clonedNode;
    }
public:
    Node* cloneTree(Node* root) {
        return _cloneTree(root);
    }
};